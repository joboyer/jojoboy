/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:09:48 by joboyer           #+#    #+#             */
/*   Updated: 2016/03/14 17:12:09 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_put_pix2(t_pos *wolf, int i)
{
	while (i < wolf->val2->drawend)
	{
		if (wolf->val2->side == 0)
		{
			if (wolf->val2->stepx < 0)
				ft_put_pix_img(wolf, i, 0xED5306);
			else
				ft_put_pix_img(wolf, i, 0xB0E321);
		}
		else if (wolf->val2->side == 1 && wolf->val2->hit == 1)
		{
			if (wolf->val2->stepy < 0)
				ft_put_pix_img(wolf, i, 0x1D2083);
			else
				ft_put_pix_img(wolf, i, 0xE5A537);
		}
		i++;
	}
	return (i);
}
