/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 11:16:18 by joboyer           #+#    #+#             */
/*   Updated: 2016/02/17 11:16:23 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_draw_in_window(t_list *fract)
{
	if (!(fract->head->mlx))
	{
		ft_couleur(fract);
		fract->head->mlx = mlx_init();
		if (init_img(fract) == -1)
			ft_error(3);
	}
	ft_calcul(fract);
	if (!(fract->head->win))
	{
		fract->head->win = mlx_new_window(fract->head->mlx,
			SCREEN_X, SCREEN_Y, "fractol");
	}
	mlx_hook(fract->head->win, 6, (1L << 6), ft_mouse_move, fract);
	mlx_put_image_to_window(fract->head->mlx, fract->head->win,
		fract->head->img, 0, 0);
	mlx_mouse_hook(fract->head->win, ft_mouse, fract);
	mlx_key_hook(fract->head->win, ft_stop, fract);
	mlx_loop(fract->head->mlx);
}

int		init_img(t_list *fract)
{
	if (!(fract->head->img = mlx_new_image(fract->head->mlx,
		SCREEN_X, SCREEN_Y)))
		return (-1);
	if (!(fract->head->data = mlx_get_data_addr(fract->head->img,
					&(fract->head->bpp), &(fract->head->sline)
					, &(fract->head->endian))))
		return (-1);
	return (0);
}

void	ft_calcul(t_list *ft)
{
	while (ft->val->x <= ft->head->image_x)
	{
		ft->val->y = 0;
		while (ft->val->y < ft->head->image_y)
		{
			ft->val->i = 0;
			ft_special_value(ft);
			while (ft->val->z_r * ft->val->z_r + ft->val->z_i * ft->val->z_i <
				4 && ft->val->i < ft->val->iteration_max)
			{
				ft->val->tmp = ft->val->z_r;
				ft->val->z_r = ft->val->z_r * ft->val->z_r - ft->val->z_i *
				ft->val->z_i + ft->val->c_r;
				ft->val->z_i = 2 * ft->val->z_i * ft->val->tmp + ft->val->c_i;
				ft->val->i++;
			}
			if (ft->val->i == ft->val->iteration_max)
				ft_put_pix_img(ft, ft->val->x, ft->val->y, ft->val->coul);
			else
				ft_put_pix_img(ft, ft->val->x, ft->val->y,
					ft->val->couleur[ft->val->i]);
			ft->val->y++;
		}
		ft->val->x++;
	}
}

void	ft_couleur(t_list *fract)
{
	int i;

	i = 0;
	while (i < fract->val->iteration_max)
	{
		if (i >= 0 && i < fract->val->iteration_max / 5)
			fract->val->couleur[i] = 0x00FFFFFF;
		else if (i >= fract->val->iteration_max / 5 &&
			i < fract->val->iteration_max / 4)
			fract->val->couleur[i] = 0x41A828;
		else if (i >= fract->val->iteration_max / 4 &&
			i < fract->val->iteration_max / 3)
			fract->val->couleur[i] = 0xD00A0A;
		else if (i >= fract->val->iteration_max / 3 && i
			< fract->val->iteration_max / 2)
			fract->val->couleur[i] = 0xFEFE20;
		else if (i >= fract->val->iteration_max / 2 &&
			i <= fract->val->iteration_max)
			fract->val->couleur[i] = 0x0C3E0C;
		i++;
	}
}

void	ft_put_pix_img(t_list *fractol, int x, int y, int color)
{
	int i;

	i = ((fractol->head->bpp / 8) * x) + ((fractol->head->sline) * y);
	fractol->head->data[i] = color;
	fractol->head->data[i + 1] = color >> 8;
	fractol->head->data[i + 2] = color >> 16;
}
