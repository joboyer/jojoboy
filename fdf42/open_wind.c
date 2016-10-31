/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 15:18:24 by joboyer           #+#    #+#             */
/*   Updated: 2016/02/02 14:53:55 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_open_window(t_list *fdf, int step)
{
	if (!(fdf->head->mlx))
	{
		fdf->head->mlx = mlx_init();
		if (init_img(fdf) == -1)
			ft_error();
		if (fdf->head->max_l > 1)
			fdf->head->max_l = 5;
		if (fdf->head->max_line > 1)
			fdf->head->max_line = 150;
	}
	ft_pixel_in_win(fdf, step);
	dessin(fdf);
	if (!(fdf->head->win))
		fdf->head->win = mlx_new_window(fdf->head->mlx, 2200, 1100, "fdf");
	mlx_put_image_to_window(fdf->head->mlx, fdf->head->win,
		fdf->head->img, 0, 0);
	mlx_key_hook(fdf->head->win, ft_stop, fdf);
	mlx_loop(fdf->head->mlx);
}

void	ft_put_pix_img(t_list *fdf, int x, int y, int color)
{
	int i;

	i = ((fdf->head->bpp / 8) * x) + ((fdf->head->sline) * y);
	if (i >= 0 && i < SCREEN_Y * fdf->head->sline && i >
		y * fdf->head->sline && i <
			(y * fdf->head->sline) + ((fdf->head->bpp / 8) * SCREEN_X))
	{
		fdf->head->data[i] = color;
		fdf->head->data[i + 1] = color >> 8;
		fdf->head->data[i + 2] = color >> 16;
	}
}

void	ft_pixel_in_win(t_list *fdf, int step)
{
	t_jojo	*window;

	window = fdf->head;
	while (window != NULL)
	{
		window->screen_x = step * 2 * window->x - step * 2 * window->y;
		window->screen_x += (fdf->head->max_line * fdf->head->max_l);
		window->screen_y = step * window->x + step * window->y - window->value;
		window->screen_y += (fdf->head->max_line * fdf->head->max_l);
		window = window->next;
	}
}

void	dessin(t_list *fdf)
{
	t_jojo	*list;

	list = fdf->head;
	while (list)
	{
		if (list->right != NULL)
		{
			if (list->screen_x < list->right->screen_x)
				list->sign = 1;
			else
				list->sign = -1;
			trace(fdf, list, list->right,
				list->right->screen_x - list->screen_x);
		}
		if (list->down != NULL)
		{
			if (list->screen_y < list->down->screen_y)
				list->sign = -1;
			else
				list->sign = -1;
			trace(fdf, list, list->down, list->screen_x - list->down->screen_x);
		}
		list = list->next;
	}
}

void	trace(t_list *fdf, t_jojo *list, t_jojo *list2, int limit)
{
	int		i;
	float	flo;
	float	y;
	float	x;

	y = (float)(list->screen_y - list2->screen_y);
	x = (float)(list->screen_x - list2->screen_x);
	flo = y / x;
	i = 0;
	while (i <= limit)
	{
		ft_put_pix_img(fdf, list->screen_x + (i * list->sign),
			list->screen_y + (list->sign * (int)(i * flo)),
			ft_color(list->value, list2->value));
		i++;
	}
}
