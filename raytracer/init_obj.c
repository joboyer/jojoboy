/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:19:29 by joboyer           #+#    #+#             */
/*   Updated: 2016/04/25 17:19:32 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

void	ft_init_cyl(t_jojo *rtv1, int i, double obj[2][3])
{
	ft_vec_para(rtv1->obj[i].xyz, obj[0][0], obj[0][1], obj[0][2]);
	ft_normalise(&rtv1->obj[i].xyz[0], &rtv1->obj[i].xyz[1],
		&rtv1->obj[i].xyz[2]);
	ft_vec_para(rtv1->obj[i].xyzpos, obj[1][0], obj[1][1], obj[1][2]);
	if (obj[2][0] != 0.0 && obj[2][1] != 0.0 && obj[2][2] != 0.0)
		ft_vec_para(rtv1->obj[i].rgb, obj[2][0], obj[2][1], obj[2][1]);
	else
		ft_vec_para(rtv1->obj[i].rgb, 0.99, 0.15, 0.15);
	ft_normalise(&rtv1->obj[i].xyz[0], &rtv1->obj[i].xyz[1],
		&rtv1->obj[i].xyz[2]);
	rtv1->obj[i].rayon = 1.0;
	rtv1->obj[i].bri = 0.02;
	rtv1->obj[i].obj = 3;
}

void	ft_init_plan(t_jojo *rtv1, int i, double obj[2][3])
{
	ft_vec_para(rtv1->obj[i].xyz, obj[0][0], obj[0][1], obj[0][2]);
	ft_vec_para(rtv1->obj[i].xyzpos, obj[1][0], obj[1][1], obj[1][2]);
	ft_vec_para(rtv1->obj[i].rgb, 0.90, 0.90, 0.90);
	ft_normalise(&rtv1->obj[i].xyz[0], &rtv1->obj[i].xyz[1],
		&rtv1->obj[i].xyz[2]);
	rtv1->obj[i].rayon = 0.0;
	rtv1->obj[i].bri = 0.02;
	rtv1->obj[i].obj = 2;
}

void	ft_init_sphr(t_jojo *rtv1, int i, double obj[2][3])
{
	ft_vec_para(rtv1->obj[i].xyz, obj[0][0], obj[0][1], obj[0][2]);
	ft_vec_para(rtv1->obj[i].xyzpos, obj[1][0], obj[1][1], obj[1][2]);
	ft_vec_para(rtv1->obj[i].rgb, 0.01, 0.01, 0.99);
	rtv1->obj[i].rayon = 1.70;
	rtv1->obj[i].bri = 0.02;
	rtv1->obj[i].obj = 1;
}

void	ft_init_cone(t_jojo *rtv1, int i, double obj[2][3])
{
	ft_vec_para(rtv1->obj[i].xyz, obj[0][0], obj[0][1], obj[0][2]);
	ft_vec_para(rtv1->obj[i].xyzpos, obj[1][0], obj[1][1], obj[1][2]);
	ft_vec_para(rtv1->obj[i].rgb, 0.8, 0.1, 0.9);
	ft_normalise(&rtv1->obj[i].xyz[0], &rtv1->obj[i].xyz[1],
		&rtv1->obj[i].xyz[2]);
	rtv1->obj[i].rayon = 4.0;
	rtv1->obj[i].bri = 0.90;
	rtv1->obj[i].obj = 4;
}

void	ft_init_cam(t_jojo *rtv1)
{
	ft_vec_para(rtv1->cam.rayxyz, 0.0, 0.0, 0.0);
	ft_vec_para(rtv1->cam.vecdirxyz, 0.0, 0.0, 1.0);
	ft_vec_para(rtv1->cam.xyz, 0.0, 0.0, -1.0);
	ft_vec_para(rtv1->cam.dirxyz, 0.0, 0.0, 0.0);
	ft_vec_para(rtv1->cam.upvecxyz, 0.0, 1.0, 0.0);
	ft_vec_para(rtv1->cam.rightvecxyz, 1.0, 0.0, 0.0);
	ft_vec_para(rtv1->cam.ori, 0.0, 0.0, 0.0);
	ft_vec_para(rtv1->cam.oeil, 0.0, 0.0, 0.0);
	ft_normalise(&rtv1->cam.vecdirxyz[0], &rtv1->cam.vecdirxyz[1],
		&rtv1->cam.vecdirxyz[2]);
	ft_normalise(&rtv1->cam.upvecxyz[0], &rtv1->cam.upvecxyz[1],
		&rtv1->cam.upvecxyz[2]);
	ft_normalise(&rtv1->cam.rightvecxyz[0], &rtv1->cam.rightvecxyz[1],
		&rtv1->cam.rightvecxyz[2]);
	rtv1->cam.vpldist = 200.0;
	rtv1->cam.tray = 0.0;
	rtv1->cam.obj = 3;
	rtv1->cam.vplheight = 0.58;
	rtv1->cam.vplwidth = 100.0;
}
