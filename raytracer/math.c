/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:17:01 by joboyer           #+#    #+#             */
/*   Updated: 2016/04/25 17:17:02 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_normalise(double *x, double *y, double *z)
{
	double lg;

	lg = ft_check_long(*x, *y, *z);
	*x = *x / lg;
	*y = *y / lg;
	*z = *z / lg;
}

double	ft_check_long(double x, double y, double z)
{
	return (sqrt(ft_carre(x) + ft_carre(y) + ft_carre(z)));
}

double	ft_carre(double i)
{
	return (i * i);
}

void	ft_vec_addi(double *target, double *tab1, double *tab2)
{
	target[0] = tab1[0] + tab2[0];
	target[1] = tab1[1] + tab2[1];
	target[2] = tab1[2] + tab2[2];
}

void	ft_vec_sous(double *target, double *tab1, double *tab2)
{
	target[0] = tab1[0] - tab2[0];
	target[1] = tab1[1] - tab2[1];
	target[2] = tab1[2] - tab2[2];
}
