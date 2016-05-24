/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 11:14:00 by joboyer           #+#    #+#             */
/*   Updated: 2016/05/24 14:26:03 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_init_jojo(t_list *fractol)
{
	t_jojo *fract;

	if (!(fract = (t_jojo*)malloc(sizeof(t_jojo))))
		ft_error(1);
	fract->x1 = 0;
	fract->x2 = 0;
	fract->y1 = 0;
	fract->y2 = 0;
	fract->zoom_x = 0;
	fract->zoom_y = 0;
	fract->image_x = 0;
	fract->image_y = 0;
	fract->x = 0;
	fract->y = 0;
	fract->z = 0;
	fract->c = 0;
	fract->bpp = 0;
	fract->sline = 0;
	fract->endian = 0;
	fract->img = NULL;
	fract->mlx = NULL;
	fract->win = NULL;
	fract->data = NULL;
	fractol->head = fract;
}

void	ft_init_value(t_list *fract)
{
	t_val *fractol;

	if (!(fractol = (t_val*)malloc(sizeof(t_val))))
		ft_error(1);
	fractol->x = 0;
	fractol->y = 0;
	fractol->c_r = 0;
	fractol->c_i = 0;
	fractol->z_r = 0;
	fractol->z_i = 0;
	fractol->i = 0;
	fractol->tmp = 0;
	fractol->cho = 0;
	fractol->couleur = NULL;
	fractol->iteration_max = 0;
	fractol->coul = 0;
	fract->val = fractol;
}

void	ft_special_value(t_list *ft)
{
	if (ft->val->cho == 0)
	{
		ft->val->z_r = 0;
		ft->val->z_i = 0;
		ft->val->c_r = ft->head->x1 + (ft->head->x2 - ft->head->x1) /
		SCREEN_X * ft->val->x;
		ft->val->c_i = ft->head->y1 + (ft->head->y2 - ft->head->y1) /
		SCREEN_Y * ft->val->y;
	}
	else if (ft->val->cho == 1)
	{
		ft->val->z_r = ft->head->x1 + (ft->head->x2 - ft->head->x1)
		/ SCREEN_X * ft->val->x;
		ft->val->z_i = ft->head->y1 + (ft->head->y2 - ft->head->y1)
		/ SCREEN_Y * ft->val->y;
	}
	else if (ft->val->cho == 2)
	{
		ft->val->z_r = ft->head->x1 + (ft->head->x2 - ft->head->x1) /
		SCREEN_X * ft->val->x;
		ft->val->z_i = 0.01;
		ft->val->c_r = ft->head->y1 + (ft->head->y2 - ft->head->y1) /
		SCREEN_Y * ft->val->y;
		ft->val->c_i = 0.285;
	}
}

void	ft_init_julia(t_list *ft)
{
	ft->val->iteration_max = 250;
	if (!ft->val->couleur)
		ft->val->couleur = (int*)malloc(sizeof(int) * 250);
	ft->head->x1 = -1;
	ft->head->x2 = 1;
	ft->head->y1 = -1.2;
	ft->head->y2 = 1.2;
	ft->val->c_r = 0.285;
	ft->val->c_i = 0.01;
	ft->head->image_x = SCREEN_X;
	ft->head->image_y = SCREEN_Y;
	ft->head->zoom_x = ft->head->image_x / (ft->head->x2 - ft->head->x1);
	ft->head->zoom_y = ft->head->image_y / (ft->head->y2 - ft->head->y1);
	ft->val->cho = 1;
	ft->val->coul = 0x262520;
}

void	ft_init_mandelbrot(t_list *ft)
{
	ft->val->iteration_max = 250;
	if (!ft->val->couleur)
		ft->val->couleur = (int*)malloc(sizeof(int) * 250);
	ft->head->x1 = -2.1;
	ft->head->x2 = 0.6;
	ft->head->y1 = -1.2;
	ft->head->y2 = 1.2;
	ft->head->image_x = SCREEN_X;
	ft->head->image_y = SCREEN_Y;
	ft->head->zoom_x = ft->head->image_x / (ft->head->x2 - ft->head->x1);
	ft->head->zoom_y = ft->head->image_y / (ft->head->y2 - ft->head->y1);
	ft->val->coul = 0x262520;
}
