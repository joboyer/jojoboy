/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 12:53:01 by joboyer           #+#    #+#             */
/*   Updated: 2016/05/04 12:53:14 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_angle_spher(t_jojo *rtv1, int i)
{
	double ang[3];

	ft_vec_sous(ang, rtv1->cam.ori, rtv1->obj[i].xyzpos);
	ft_normalise(&ang[0], &ang[1], &ang[2]);
	return (ft_dot_product(ang, rtv1->cam.dirxyz));
}

double	ft_angle_cyl(t_jojo *rtv1, int i)
{
	double	n[3];
	double	a;

	a = rtv1->obj[i].xyz[0] * (rtv1->cam.ori[0] - rtv1->obj[i].xyzpos[0]) +
	rtv1->obj[i].xyz[1] * (rtv1->cam.ori[1] - rtv1->obj[i].xyzpos[1]) +
	rtv1->obj[i].xyz[2] * (rtv1->cam.ori[2] - rtv1->obj[i].xyzpos[2]);
	n[0] = rtv1->cam.ori[0] - rtv1->obj[i].xyzpos[0] - rtv1->obj[i].xyz[0] * a;
	n[1] = rtv1->cam.ori[1] - rtv1->obj[i].xyzpos[1] - rtv1->obj[i].xyz[1] * a;
	n[2] = rtv1->cam.ori[2] - rtv1->obj[i].xyzpos[2] - rtv1->obj[i].xyz[2] * a;
	ft_normalise(&n[0], &n[1], &n[2]);
	return (ft_dot_product(n, rtv1->cam.dirxyz));
}

double	ft_angle_cone(t_jojo *rtv1, int i)
{
	double	a[3];
	double	tmp;
	double	longu;

	tmp = rtv1->obj[i].xyz[0] * (rtv1->cam.ori[0] - rtv1->obj[i].xyzpos[0])
	+ rtv1->obj[i].xyz[1] * (rtv1->cam.ori[1] - rtv1->obj[i].xyzpos[1]) +
	rtv1->obj[i].xyz[2] * (rtv1->cam.ori[2] - rtv1->obj[i].xyzpos[2]);
	a[0] = rtv1->cam.ori[0] - rtv1->obj[i].xyzpos[0] - rtv1->obj[i].xyz[0]
	* tmp;
	a[1] = rtv1->cam.ori[1] - rtv1->obj[i].xyzpos[1] - rtv1->obj[i].xyz[1]
	* tmp;
	a[2] = rtv1->cam.ori[2] - rtv1->obj[i].xyzpos[2] - rtv1->obj[i].xyz[2]
	* tmp;
	longu = ft_check_long(a[0], a[1], a[2]);
	a[0] *= cos(rtv1->obj[i].rayon) - longu * rtv1->obj[i].xyz[0]
	* sin(rtv1->obj[i].rayon) * tmp / fabs(tmp);
	a[1] *= cos(rtv1->obj[i].rayon) - longu * rtv1->obj[i].xyz[1]
	* sin(rtv1->obj[i].rayon) * tmp / fabs(tmp);
	a[2] *= cos(rtv1->obj[i].rayon) - longu * rtv1->obj[i].xyz[2]
	* sin(rtv1->obj[i].rayon) * tmp / fabs(tmp);
	ft_normalise(&a[0], &a[1], &a[2]);
	return (ft_dot_product(a, rtv1->cam.dirxyz));
}

double	ft_angle_plan(t_jojo *rtv1, int i)
{
	return (ft_dot_product(rtv1->cam.dirxyz, rtv1->obj[i].xyz));
}

double	ft_angle_obj(t_jojo *rtv1, int i)
{
	double angle;

	angle = 0;
	if (rtv1->obj[i].obj == 1)
		angle = ft_angle_spher(rtv1, i);
	else if (rtv1->obj[i].obj == 2)
		angle = ft_angle_plan(rtv1, i);
	else if (rtv1->obj[i].obj == 3)
		angle = ft_angle_cyl(rtv1, i);
	else
		angle = ft_angle_cone(rtv1, i);
	if (angle >= 0.0 && angle <= 1.0)
		return (angle);
	else
		return (0);
}
