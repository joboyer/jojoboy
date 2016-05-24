/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brillance.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:48:23 by joboyer           #+#    #+#             */
/*   Updated: 2016/05/10 14:48:34 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_bri_sphr(t_jojo *rtv1, int o)
{
	double	bri[3];
	double	br[3];
	double	b;

	ft_vec_sous(bri, rtv1->cam.ori, rtv1->obj[o].xyzpos);
	ft_normalise(&bri[0], &bri[1], &bri[2]);
	b = ft_dot_product(bri, rtv1->cam.dirxyz);
	br[0] = -rtv1->cam.dirxyz[0] + 2 * bri[0] * b;
	br[1] = -rtv1->cam.dirxyz[1] + 2 * bri[1] * b;
	br[1] = -rtv1->cam.dirxyz[2] + 2 * bri[2] * b;
	ft_normalise(&br[0], &br[1], &br[2]);
	return (ft_dot_product(br, rtv1->cam.oeil));
}

double	ft_bri_plan(t_jojo *rtv1, int o)
{
	double	b;
	double	bri[3];

	b = ft_dot_product(rtv1->obj[o].xyz, rtv1->cam.dirxyz);
	bri[0] = -rtv1->cam.dirxyz[0] + 2 * rtv1->obj[o].xyz[0] * b;
	bri[1] = -rtv1->cam.dirxyz[1] + 2 * rtv1->obj[o].xyz[1] * b;
	bri[2] = -rtv1->cam.dirxyz[2] + 2 * rtv1->obj[o].xyz[2] * b;
	ft_normalise(&bri[0], &bri[1], &bri[2]);
	return (ft_dot_product(bri, rtv1->cam.oeil));
}

double	ft_bri_cyl(t_jojo *rtv1, int o)
{
	double	a[2];
	double	n[3];
	double	z[3];

	a[0] = rtv1->obj[o].xyz[0] * (rtv1->cam.ori[0] - rtv1->obj[o].xyzpos[0])
	+ rtv1->obj[o].xyz[1] * (rtv1->cam.ori[1] - rtv1->obj[o].xyzpos[1]) +
	rtv1->obj[o].xyz[2] * (rtv1->cam.ori[2] - rtv1->obj[o].xyzpos[2]);
	n[0] = rtv1->cam.ori[0] - rtv1->obj[o].xyzpos[0] - rtv1->obj[o].xyz[0]
	* a[0];
	n[1] = rtv1->cam.ori[1] - rtv1->obj[o].xyzpos[1] - rtv1->obj[o].xyz[1]
	* a[0];
	n[2] = rtv1->cam.ori[2] - rtv1->obj[o].xyzpos[2] - rtv1->obj[o].xyz[2]
	* a[0];
	ft_normalise(&n[0], &n[1], &n[2]);
	a[1] = ft_dot_product(n, rtv1->cam.dirxyz);
	z[0] = -rtv1->cam.dirxyz[0] + 2 * n[0] * a[1];
	z[1] = -rtv1->cam.dirxyz[1] + 2 * n[1] * a[1];
	z[2] = -rtv1->cam.dirxyz[2] + 2 * n[2] * a[1];
	ft_normalise(&z[0], &z[1], &z[2]);
	return (ft_dot_product(z, rtv1->cam.oeil));
}

double	ft_bri_cone(t_jojo *r, int o)
{
	double	b[3];
	double	a[3];
	double	c[3];

	b[0] = r->obj[o].xyz[0] * (r->cam.ori[0] - r->obj[o].xyzpos[0])
	+ r->obj[o].xyz[1] * (r->cam.ori[1] - r->obj[o].xyzpos[1])
	+ r->obj[o].xyz[2] * (r->cam.ori[2] - r->obj[o].xyzpos[2]);
	a[0] = r->cam.ori[0] - r->obj[o].xyzpos[0] - r->obj[o].xyz[0] * b[0];
	a[1] = r->cam.ori[1] - r->obj[o].xyzpos[1] - r->obj[o].xyz[1] * b[0];
	a[2] = r->cam.ori[2] - r->obj[o].xyzpos[2] - r->obj[o].xyz[2] * b[0];
	b[1] = ft_check_long(a[0], a[1], a[2]);
	a[0] *= cos(r->obj[o].rayon) - b[1] * r->obj[o].xyz[0]
	* sin(r->obj[o].rayon) * b[0] / fabs(b[0]);
	a[1] *= cos(r->obj[o].rayon) - b[1] * r->obj[o].xyz[1]
	* sin(r->obj[o].rayon) * b[0] / fabs(b[0]);
	a[2] *= cos(r->obj[o].rayon) - b[1] * r->obj[o].xyz[2]
	* sin(r->obj[o].rayon) * b[0] / fabs(b[0]);
	ft_normalise(&a[0], &a[1], &a[2]);
	b[2] = ft_dot_product(a, r->cam.dirxyz);
	c[0] = -r->cam.dirxyz[0] + 2 * a[0] * b[2];
	c[1] = -r->cam.dirxyz[1] + 2 * a[1] * b[2];
	c[2] = -r->cam.dirxyz[2] + 2 * a[2] * b[2];
	ft_normalise(&c[0], &c[1], &c[2]);
	return (ft_dot_product(c, r->cam.oeil));
}

double	ft_brillance(t_jojo *rtv1, int o)
{
	double bri;

	bri = 0;
	if (rtv1->obj[o].obj == 1)
		bri = ft_bri_sphr(rtv1, o);
	else if (rtv1->obj[o].obj == 2)
		bri = ft_bri_plan(rtv1, o);
	else if (rtv1->obj[o].obj == 3)
		bri = ft_bri_cyl(rtv1, o);
	else
		bri = ft_bri_cone(rtv1, o);
	if (bri <= 0.0)
		return (0.0);
	else
		return (bri);
}
