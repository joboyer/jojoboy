/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 18:07:13 by joboyer           #+#    #+#             */
/*   Updated: 2016/02/19 18:07:15 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ft_mouse(int mouse, int x, int y, t_list *fract)
{
	if (mouse == 4 || mouse == 5)
	{
		zoom(mouse, x, y, fract);
		fract->val->x = 0;
		fract->val->y = 0;
		ft_draw_in_window(fract);
	}
	return (0);
}

int		ft_stop(int keyboard, t_list *fract)
{
	if (keyboard == 53)
	{
		free(fract->head);
		free(fract->val->couleur);
		free(fract->val);
		free(fract);
		exit(EXIT_FAILURE);
	}
	if (keyboard == 15 && fract->val->cho == 0)
		ft_init_mandelbrot(fract);
	else if (keyboard == 15 && fract->val->cho == 1)
		ft_init_julia(fract);
	else if (keyboard == 15 && fract->val->cho == 2)
		ft_init_x(fract);
	if (keyboard == 8)
		change_coul(fract);
	fract->val->x = 0;
	fract->val->y = 0;
	ft_draw_in_window(fract);
	return (0);
}

void	change_coul(t_list *fract)
{
	if (fract->val->couleur[0] == 0x00FFFFFF)
		ft_couleur2(fract);
	else if (fract->val->couleur[0] == 0x7F1744)
		ft_couleur3(fract);
	else if (fract->val->couleur[0] == 0x000000)
		ft_couleur(fract);
}

void	zoom(int btn, int x, int y, t_list *fract)
{
	double x12[2];
	double ecart[2];

	ecart[0] = ECRT_X;
	ecart[1] = ECRT_Y;
	x12[0] = fract->head->x1 + (double)x * (ecart[0] / (double)SCREEN_X);
	x12[1] = fract->head->y1 + (double)y * (ecart[1] / (double)SCREEN_Y);
	if (btn == 4)
	{
		ecart[0] *= 0.8;
		ecart[1] *= 0.8;
	}
	else if (btn == 5)
	{
		ecart[0] /= 0.8;
		ecart[1] /= 0.8;
	}
	fract->head->x1 = x12[0] - ecart[0] / 2;
	fract->head->x2 = x12[0] + ecart[0] / 2;
	fract->head->y1 = x12[1] - ecart[1] / 2;
	fract->head->y2 = x12[1] + ecart[1] / 2;
}

void	ft_couleur3(t_list *fract)
{
	int i;
	int green;

	i = 0;
	green = 0x000000;
	while (i < fract->val->iteration_max)
	{
		fract->val->couleur[i] = green;
		green++;
		i++;
	}
}
