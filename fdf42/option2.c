/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 16:12:10 by joboyer           #+#    #+#             */
/*   Updated: 2016/02/09 16:12:59 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_stop(int keyboard, t_list *fdf)
{
	if (keyboard == 53)
	{
		ft_free_all(fdf);
		exit(EXIT_FAILURE);
	}
	else if (keyboard == 69)
		fdf->head->step = fdf->head->step + 1;
	else if (keyboard == 78 && (fdf->head->step > 1))
		fdf->head->step = fdf->head->step - 1;
	else if (keyboard == 123 && (fdf->head->max_l >= 1 &&
		fdf->head->max_l - 2 >= 1))
		fdf->head->max_l = fdf->head->max_l - 2;
	else if (keyboard == 124 && (fdf->head->max_l <= 100 &&
		fdf->head->max_l + 2 <= 100))
		fdf->head->max_l = fdf->head->max_l + 2;
	mlx_clear_window(fdf->head->mlx, fdf->head->win);
	mlx_destroy_image(fdf->head->mlx, fdf->head->img);
	init_img(fdf);
	ft_open_window(fdf, fdf->head->step);
	return (0);
}

int		init_img(t_list *fdf)
{
	if (!(fdf->head->img = mlx_new_image(fdf->head->mlx, SCREEN_X, SCREEN_Y)))
		return (-1);
	if (!(fdf->head->data = mlx_get_data_addr(fdf->head->img,
					&(fdf->head->bpp), &(fdf->head->sline)
					, &(fdf->head->endian))))
		return (-1);
	return (0);
}

int		ft_color(int value, int value2)
{
	if ((value == value2) && (value == 0 && value2 == 0))
		return (0x00FFFFFF);
	else if ((value > 0 && value2 > 0) && (value == value2))
		return (0xFFFFFF00);
	else if (value < value2)
		return (0xFFFFFF00);
	else if (value > value2)
		return (0xFFFFFF00);
	return (0x00FFFFFF);
}
