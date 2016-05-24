/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:17:47 by joboyer           #+#    #+#             */
/*   Updated: 2016/04/25 17:17:50 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			ft_open_wind(t_jojo *rtv1)
{
	if (rtv1->win.in == 1)
	{
		rtv1->win.mlx = mlx_init();
		if (ft_init_img(rtv1) == -1)
			ft_error(4);
		rtv1->win.win = mlx_new_window(rtv1->win.mlx, 1000, 1000, "rtV1");
		rtv1->win.in = 0;
	}
	ft_check_img(rtv1);
	mlx_put_image_to_window(rtv1->win.mlx, rtv1->win.win, rtv1->win.img, 0, 0);
	mlx_key_hook(rtv1->win.win, ft_stop, rtv1);
	mlx_hook(rtv1->win.win, 2, (1L << 0), move, rtv1);
	mlx_loop(rtv1->win.mlx);
}

void			ft_check_img(t_jojo *rtv1)
{
	int				x;
	int				y;
	unsigned int	color;

	x = 0;
	y = 0;
	color = 0;
	while (y < SCREEN_X)
	{
		x = 0;
		while (x < SCREEN_X)
		{
			color = ft_check_obj(x, y, rtv1);
			ft_put_pixel(x, y, color, rtv1);
			x++;
		}
		y++;
	}
}

unsigned int	ft_check_obj(int x, int y, t_jojo *rtv1)
{
	int		i;
	double	tmp;

	tmp = 0.0;
	i = -1;
	rtv1->cam.tray = 1000000000;
	ft_check_ray(x, y, rtv1);
	while (++i < rtv1->nb_obj)
	{
		tmp = ft_dist_obj(rtv1, i);
		if (tmp < rtv1->cam.tray && tmp >= 0.0)
		{
			rtv1->cam.tray = tmp;
			rtv1->cam.obj = i;
		}
	}
	if (rtv1->cam.tray < 1000000000 && rtv1->nb_light > 0)
		return (ft_dark(rtv1, rtv1->cam.obj));
	else if (rtv1->cam.tray < 1000000000 && rtv1->nb_light == 0)
	{
		return (65536 * (unsigned int)(rtv1->obj[rtv1->cam.obj].rgb[0] * 255)
			+ 256 * (unsigned int)(rtv1->obj[rtv1->cam.obj].rgb[1] * 255)
			+ (unsigned int)(rtv1->obj[rtv1->cam.obj].rgb[2] * 255));
	}
	return (0);
}

void			ft_free(t_jojo *rtv1, double **light)
{
	int i;

	i = 0;
	while (i < rtv1->nb_light)
	{
		free(light[i]);
		i++;
	}
}

void			ft_check_ray(int x, int y, t_jojo *rtv1)
{
	rtv1->cam.dirxyz[0] = rtv1->cam.xyz[0] + rtv1->cam.vecdirxyz[0] *
	rtv1->cam.vpldist + (rtv1->cam.vplwidth / 2.0) * (rtv1->cam.upvecxyz[0] -
		rtv1->cam.rightvecxyz[0]) + (rtv1->cam.vplwidth / (double)SCREEN_X *
		(x * rtv1->cam.rightvecxyz[0] - y * rtv1->cam.upvecxyz[0]));
	rtv1->cam.dirxyz[1] = rtv1->cam.xyz[1] + rtv1->cam.vecdirxyz[1] *
	rtv1->cam.vpldist + (rtv1->cam.vplwidth / 2.0) * (rtv1->cam.upvecxyz[1] -
		rtv1->cam.rightvecxyz[1]) + (rtv1->cam.vplwidth / (double)SCREEN_X *
		(x * rtv1->cam.rightvecxyz[1] - y * rtv1->cam.upvecxyz[1]));
	rtv1->cam.dirxyz[2] = rtv1->cam.xyz[2] + rtv1->cam.vecdirxyz[2] *
	rtv1->cam.vpldist + (rtv1->cam.vplwidth / 2.0) * (rtv1->cam.upvecxyz[2] -
		rtv1->cam.rightvecxyz[2]) + (rtv1->cam.vplwidth / (double)SCREEN_X *
		(x * rtv1->cam.rightvecxyz[2] - y * rtv1->cam.upvecxyz[2]));
	ft_normalise(&rtv1->cam.dirxyz[0], &rtv1->cam.dirxyz[1],
		&rtv1->cam.dirxyz[2]);
	ft_vec_para(rtv1->cam.ori, rtv1->cam.xyz[0], rtv1->cam.xyz[1],
		rtv1->cam.xyz[2]);
}
