/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:17:10 by joboyer           #+#    #+#             */
/*   Updated: 2016/04/25 17:17:11 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_dist_spher(t_jojo *rtv1, int i)
{
	double	a;
	double	b;
	double	c;

	a = ft_carre(rtv1->cam.dirxyz[0]) + ft_carre(rtv1->cam.dirxyz[1]) +
	ft_carre(rtv1->cam.dirxyz[2]);
	b = 2 * (rtv1->cam.dirxyz[0] * (rtv1->cam.ori[0] - rtv1->obj[i].xyzpos[0])
		+ rtv1->cam.dirxyz[1] * (rtv1->cam.ori[1] - rtv1->obj[i].xyzpos[1])
		+ rtv1->cam.dirxyz[2] * (rtv1->cam.ori[2] - rtv1->obj[i].xyzpos[2]));
	c = (ft_carre((rtv1->cam.ori[0] - rtv1->obj[i].xyzpos[0])) +
		ft_carre((rtv1->cam.ori[1] - rtv1->obj[i].xyzpos[1])) +
		ft_carre((rtv1->cam.ori[2] - rtv1->obj[i].xyzpos[2]))) -
	ft_carre(rtv1->obj[i].rayon);
	return (ft_check_det(a, b, c));
}

double	ft_dist_plan(t_jojo *rtv1, int i)
{
	double	normal;
	double	det;

	normal = ft_dot_product(rtv1->obj[i].xyz, rtv1->cam.dirxyz);
	if (normal == 0)
		return (1000000000);
	det = (rtv1->obj[i].xyz[0] * (rtv1->obj[i].xyzpos[0] - rtv1->cam.ori[0]) +
		rtv1->obj[i].xyz[1] * (rtv1->obj[i].xyzpos[1] - rtv1->cam.ori[1]) +
		rtv1->obj[i].xyz[2] * (rtv1->obj[i].xyzpos[2] - rtv1->cam.ori[2])) /
	normal;
	if (det >= 0.0)
		return (det);
	else
		return (1000000000);
}

double	ft_dist_cyl(t_jojo *r, int i)
{
	double	abc[3];

	abc[0] = ft_carre((r->cam.dirxyz[1] * r->obj[i].xyz[2] - r->cam.dirxyz[2]
		* r->obj[i].xyz[1])) + ft_carre((r->cam.dirxyz[0] * r->obj[i].xyz[2]
		- r->cam.dirxyz[2] * r->obj[i].xyz[0])) + ft_carre((r->cam.dirxyz[0] *
		r->obj[i].xyz[1] - r->cam.dirxyz[1] * r->obj[i].xyz[0]));
	abc[1] = 2 * (((r->cam.ori[1] - r->obj[i].xyzpos[1]) * r->obj[i].xyz[2] -
		(r->cam.ori[2] - r->obj[i].xyzpos[2]) * r->obj[i].xyz[1]) *
	(r->cam.dirxyz[1] * r->obj[i].xyz[2] - r->cam.dirxyz[2] *
		r->obj[i].xyz[1]) + ((r->cam.ori[0] - r->obj[i].xyzpos[0]) *
		r->obj[i].xyz[2] - (r->cam.ori[2] - r->obj[i].xyzpos[2]) *
		r->obj[i].xyz[0]) * (r->cam.dirxyz[0] * r->obj[i].xyz[2] -
		r->cam.dirxyz[2] * r->obj[i].xyz[0]) + ((r->cam.ori[0] -
			r->obj[i].xyzpos[0]) * r->obj[i].xyz[1] - (r->cam.ori[1] -
			r->obj[i].xyzpos[1]) * r->obj[i].xyz[0]) * (r->cam.dirxyz[0] *
		r->obj[i].xyz[1] - r->cam.dirxyz[1] * r->obj[i].xyz[0]));
	abc[2] = ft_carre(((r->cam.ori[1] - r->obj[i].xyzpos[1]) * r->obj[i].xyz[2]
		- (r->cam.ori[2] - r->obj[i].xyzpos[2]) * r->obj[i].xyz[1])) +
	ft_carre(((r->cam.ori[0] - r->obj[i].xyzpos[0]) * r->obj[i].xyz[2] -
		(r->cam.ori[2] - r->obj[i].xyzpos[2]) * r->obj[i].xyz[0])) +
	ft_carre(((r->cam.ori[0] - r->obj[i].xyzpos[0]) * r->obj[i].xyz[1] -
		(r->cam.ori[1] - r->obj[i].xyzpos[1]) * r->obj[i].xyz[0])) -
	ft_carre(r->obj[i].rayon);
	return (ft_check_det(abc[0], abc[1], abc[2]));
}

double	ft_dist_cone(t_jojo *rtv1, int i)
{
	double	a;
	double	b;
	double	c;

	a = ft_carre(cos(rtv1->obj[i].rayon)) * (ft_carre(rtv1->cam.dirxyz[0])
		+ ft_carre(rtv1->cam.dirxyz[1]) + ft_carre(rtv1->cam.dirxyz[2])) -
	ft_carre((rtv1->cam.dirxyz[0] * rtv1->obj[i].xyz[0]) + (rtv1->cam.dirxyz[1]
		* rtv1->obj[i].xyz[1]) + (rtv1->cam.dirxyz[2] * rtv1->obj[i].xyz[2]));
	b = 2 * ft_carre(cos(rtv1->obj[i].rayon)) * ((rtv1->cam.dirxyz[0]
		* (rtv1->cam.ori[0] - rtv1->obj[i].xyzpos[0])) + (rtv1->cam.dirxyz[1]
		* (rtv1->cam.ori[1] - rtv1->obj[i].xyzpos[1])) + (rtv1->cam.dirxyz[2]
		* (rtv1->cam.ori[2] - rtv1->obj[i].xyzpos[2]))) - (2 *
	(rtv1->cam.dirxyz[0] * rtv1->obj[i].xyz[0] + rtv1->cam.dirxyz[1]
		* rtv1->obj[i].xyz[1] + rtv1->cam.dirxyz[2] * rtv1->obj[i].xyz[2]) *
	((rtv1->obj[i].xyz[0] * (rtv1->cam.ori[0] - rtv1->obj[i].xyzpos[0])) +
		(rtv1->obj[i].xyz[1] * (rtv1->cam.ori[1] - rtv1->obj[i].xyzpos[1]))
		+ (rtv1->obj[i].xyz[2] * (rtv1->cam.ori[2] - rtv1->obj[i].xyzpos[2]))));
	c = ft_carre(cos(rtv1->obj[i].rayon))
	* (ft_carre(rtv1->cam.ori[0] - rtv1->obj[i].xyzpos[0])
		+ ft_carre(rtv1->cam.ori[1] - rtv1->obj[i].xyzpos[1])
		+ ft_carre(rtv1->cam.ori[2] - rtv1->obj[i].xyzpos[2])) - ft_carre((
			(rtv1->obj[i].xyz[0] * (rtv1->cam.ori[0] - rtv1->obj[i].xyzpos[0]))
		+ (rtv1->obj[i].xyz[1] * (rtv1->cam.ori[1] - rtv1->obj[i].xyzpos[1])) +
		(rtv1->obj[i].xyz[2] * (rtv1->cam.ori[2] - rtv1->obj[i].xyzpos[2]))));
	return (ft_check_det(a, b, c));
}

double	ft_dist_obj(t_jojo *rtv1, int i)
{
	if (rtv1->obj[i].obj == 1)
		return (ft_dist_spher(rtv1, i));
	else if (rtv1->obj[i].obj == 2)
		return (ft_dist_plan(rtv1, i));
	else if (rtv1->obj[i].obj == 3)
		return (ft_dist_cyl(rtv1, i));
	else
		return (ft_dist_cone(rtv1, i));
	return (0);
}
