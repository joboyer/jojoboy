/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:30:36 by joboyer           #+#    #+#             */
/*   Updated: 2016/02/26 18:20:50 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_couleur2(t_list *fract)
{
	int i;
	int red;

	i = 0;
	red = 0x7F1744;
	while (i < fract->val->iteration_max)
	{
		fract->val->couleur[i] = red;
		red++;
		i++;
	}
}

void	ft_init_x(t_list *ft)
{
	ft->val->iteration_max = 250;
	if (!ft->val->couleur)
		ft->val->couleur = (int*)malloc(sizeof(int) * 250);
	ft->head->x1 = -1.034958;
	ft->head->x2 = -1.030210;
	ft->head->y1 = -1.002199;
	ft->head->y2 = -0.994945;
	ft->head->image_x = SCREEN_X;
	ft->head->image_y = SCREEN_Y;
	ft->head->zoom_x = ft->head->image_x / (ft->head->x2 - ft->head->x1);
	ft->head->zoom_y = ft->head->image_y / (ft->head->y2 - ft->head->y1);
	ft->val->cho = 2;
	ft->val->coul = 0x262520;
}
