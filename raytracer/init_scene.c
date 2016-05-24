/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:21:39 by joboyer           #+#    #+#             */
/*   Updated: 2016/04/25 17:21:50 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_init_scene1(t_jojo *rtv1, int i)
{
	double obj[3][3];

	ft_vec_para(obj[0], 0.0, 1.0, 0.0);
	ft_vec_para(obj[1], 0.0, 0.0, 30.0);
	if (i == -1)
		ft_init_sphr(rtv1, 0, obj);
	else if (i == -2)
	{
		ft_vec_para(obj[1], 0.0, 0.0, 40.0);
		ft_vec_para(obj[2], 0.0, 0.0, 0.0);
		ft_init_cyl(rtv1, 0, obj);
	}
	else if (i == -3)
	{
		ft_vec_para(obj[0], 0.0, 1.0, 0.0);
		ft_vec_para(obj[1], 0.0, 4.00, 100.0);
		ft_init_cone(rtv1, 0, obj);
	}
	else if (i == -4)
	{
		ft_vec_para(obj[0], 0.0, 1.0, 0.0);
		ft_vec_para(obj[1], 0.0, -1.0, 1.0);
		ft_init_plan(rtv1, 0, obj);
	}
}

void	ft_init_scene2(t_jojo *rtv1, int i)
{
	double	obj[3][3];

	rtv1->nb_obj = i;
	rtv1->obj = (t_objet*)malloc(sizeof(t_objet) * i);
	rtv1->win.in = 1;
	ft_vec_para(obj[0], 0.0, 0.0, 0.0);
	ft_vec_para(obj[1], 1.0, 3.0, 47.5);
	ft_init_sphr(rtv1, 0, obj);
	ft_vec_para(obj[0], 0.5, -3.0, 0.0);
	ft_vec_para(obj[1], 1.0, -1.0, 47.418);
	ft_vec_para(obj[2], 0.0, 0.0, 0.0);
	ft_init_cyl(rtv1, 1, obj);
}

void	ft_init_scene3(t_jojo *rtv1, int i)
{
	double	obj[3][3];

	rtv1->nb_obj = i;
	rtv1->obj = (t_objet*)malloc(sizeof(t_objet) * i);
	rtv1->win.in = 1;
	ft_vec_para(obj[0], 0.0, 1.0, -0.1);
	ft_vec_para(obj[1], 0.0, -2.0, 1.0);
	ft_init_plan(rtv1, 0, obj);
	ft_vec_para(obj[0], 1.0, 0.0, 0.0);
	ft_vec_para(obj[1], 0.0, 5.0, 30.0);
	ft_vec_para(obj[2], 0.9, 0.1, 0.1);
	ft_init_cyl(rtv1, 1, obj);
	ft_vec_para(obj[0], 0.0, 1.0, 0.0);
	ft_vec_para(obj[1], 0.0, 0.0, 30.0);
	ft_vec_para(obj[2], 0.1, 0.4, 0.9);
	ft_init_cyl(rtv1, 2, obj);
	ft_vec_para(obj[0], 0.0, 0.0, 1.0);
	ft_vec_para(obj[1], -4.0, 1.0, 25.0);
	ft_init_sphr(rtv1, 3, obj);
}

void	ft_init_scene4(t_jojo *rtv1, int i)
{
	double obj[2][3];

	rtv1->nb_obj = i;
	rtv1->obj = (t_objet*)malloc(sizeof(t_objet) * i);
	rtv1->win.in = 1;
	ft_vec_para(obj[0], 0.0, 1.0, 0.0);
	ft_vec_para(obj[1], 0.0, -4.0, 0.0);
	ft_init_plan(rtv1, 0, obj);
	ft_vec_para(obj[0], 0.0, 1.0, 0.0);
	ft_vec_para(obj[1], 0.0, 0.0, 50.0);
	ft_init_cone(rtv1, 1, obj);
	ft_vec_para(obj[0], 0.0, 0.0, 0.0);
	ft_vec_para(obj[1], -4.0, -3.0, 50.0);
	ft_init_sphr(rtv1, 2, obj);
}

void	ft_init_light(t_jojo *rtv1, int i)
{
	double litpar[2][3];

	rtv1->nb_light = i;
	rtv1->light = (t_light*)malloc(sizeof(t_light) * i);
	if (i == 1)
	{
		ft_vec_para(litpar[0], 5.5, 14.0, 15.0);
		ft_vec_para(litpar[1], 0.40, 0.40, 0.40);
		ft_light_para(rtv1, 0, litpar);
	}
	else if (i == 2)
	{
		ft_vec_para(litpar[0], 5.5, 4.0, 25.0);
		ft_vec_para(litpar[1], 0.30, 0.30, 0.30);
		ft_light_para(rtv1, 0, litpar);
		ft_vec_para(litpar[0], -5.5, 4.0, 25.0);
		ft_vec_para(litpar[1], 0.30, 0.30, 0.30);
		ft_light_para(rtv1, 1, litpar);
	}
}
