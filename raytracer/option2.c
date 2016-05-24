/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 15:34:50 by joboyer           #+#    #+#             */
/*   Updated: 2016/05/20 15:35:00 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_dot_product(double *tab1, double *tab2)
{
	return ((tab1[0] * tab2[0]) + (tab1[1] * tab2[1]) + (tab1[2] * tab2[2]));
}

double	ft_check_det(double a, double b, double c)
{
	double	det;
	double	t1;
	double	t2;

	det = ft_carre(b) - (4 * a * c);
	if (det < 0)
		return (1000000000);
	t1 = (-b - sqrt(det)) / (2 * a);
	t2 = (-b + sqrt(det)) / (2 * a);
	if (det > 0)
	{
		if (t1 < t2)
			return (t1);
		else
			return (t2);
	}
	else
		return (-b / (2 * a));
}

int		move(int keyboard, t_jojo *rtv1)
{
	if (keyboard == 124 || keyboard == 123)
	{
		if (keyboard == 124)
			rtv1->cam.xyz[0] += 0.05;
		else if (keyboard == 123)
			rtv1->cam.xyz[0] -= 0.05;
		ft_open_wind(rtv1);
	}
	else if (keyboard == 86 || keyboard == 88)
	{
		if (keyboard == 86)
			rtv1->cam.vecdirxyz[0] -= 0.02;
		else if (keyboard == 88)
			rtv1->cam.vecdirxyz[0] += 0.02;
		ft_open_wind(rtv1);
	}
	return (0);
}

void	ft_free_all(t_jojo *rtv1)
{
	free(rtv1->light);
	free(rtv1->obj);
}

double	ft_puissance(double i, int p)
{
	double r;

	r = i;
	if (p == 1)
		return (i);
	if (p < 0)
		return (0);
	while (p)
	{
		r = r * i;
		p--;
	}
	return (r);
}
