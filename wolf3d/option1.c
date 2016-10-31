/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 18:20:11 by joboyer           #+#    #+#             */
/*   Updated: 2016/03/15 11:14:12 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_pos	*ft_init_wolf(void)
{
	t_pos *wo;

	wo = (t_pos*)malloc(sizeof(t_pos));
	wo->head = NULL;
	wo->val = NULL;
	wo->map = NULL;
	wo->i = 0;
	wo->j = 0;
	return (wo);
}

void	ft_init_val2(t_pos *wolf, int i)
{
	if (i < 1)
		wolf->val2 = (t_val2*)malloc(sizeof(t_val));
	wolf->val2->perpdist = 0;
	wolf->val2->stepx = 0;
	wolf->val2->stepy = 0;
	wolf->val2->side = 0;
	wolf->val2->hit = 0;
	wolf->val2->lineheight = 0;
	wolf->val2->h = 0;
	wolf->val2->drawstart = 0;
	wolf->val2->drawend = 0;
	wolf->val2->x = 1;
	wolf->val2->color = 0;
	wolf->val2->olddiry = 0;
	wolf->val2->olddirx = 0;
	wolf->val2->oldplanex = 0;
}

void	ft_init_val(t_pos *wolf, int i)
{
	if (i < 1)
		wolf->val = (t_val*)malloc(sizeof(t_val));
	if (i < 2)
	{
		wolf->val->posx = 0;
		wolf->val->posy = 0;
		wolf->val->dirx = 0;
		wolf->val->diry = 0;
		wolf->val->planex = 0;
		wolf->val->planey = 0;
	}
	wolf->val->rayposx = 0;
	wolf->val->rayposy = 0;
	wolf->val->raydirx = 0;
	wolf->val->raydiry = 0;
	wolf->val->camerax = 0;
	wolf->val->w = SCREEN_X;
	wolf->val->mapx = 0;
	wolf->val->mapy = 0;
	wolf->val->sidedistx = 0;
	wolf->val->sidedisty = 0;
	wolf->val->deltadistx = 0;
	wolf->val->deltadisty = 0;
}

void	ft_init_pos(t_pos *wolf)
{
	wolf->val->posx = 11;
	wolf->val->posy = 2;
	wolf->val->dirx = -1;
	wolf->val->diry = 0;
	wolf->val->planex = 0;
	wolf->val->planey = 0.66;
}

void	ft_init_jojo(t_jojo *wo)
{
	wo->len_rd = 0;
	wo->next = NULL;
	wo->mlx = NULL;
	wo->win = NULL;
	wo->endian = 0;
	wo->img = NULL;
	wo->bpp = 0;
	wo->sline = 0;
	wo->data = NULL;
	wo->max_y = 0;
}
