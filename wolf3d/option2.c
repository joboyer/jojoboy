/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 10:15:04 by joboyer           #+#    #+#             */
/*   Updated: 2016/03/07 10:15:18 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_stop(int keyboard, t_pos *wolf)
{
	if (keyboard == 53)
	{
		ft_free_all(wolf);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	move_front(t_pos *wolf)
{
	if (wolf->map[(int)fabs(wolf->val->posx +
		wolf->val->dirx * 0.27)][(int)fabs(wolf->val->posy)] == 0)
		wolf->val->posx += (wolf->val->dirx * 0.27);
	if (wolf->map[(int)fabs(wolf->val->posx)][(int)fabs(wolf->val->posy
		+ wolf->val->diry * 0.27)] == 0)
		wolf->val->posy += (wolf->val->diry * 0.27);
	ft_open_window(wolf);
}

void	move_back(t_pos *wolf)
{
	if (wolf->map[(int)fabs((double)(wolf->val->posx -
		wolf->val->dirx * 0.27))][(int)fabs(wolf->val->posy)] == 0)
		wolf->val->posx -= (wolf->val->dirx * 0.27);
	if (wolf->map[(int)fabs(wolf->val->posx)][(int)fabs(wolf->val->posy -
		wolf->val->diry * 0.27)] == 0)
		wolf->val->posy -= (wolf->val->diry * 0.27);
	ft_open_window(wolf);
}

void	move_right(t_pos *wolf)
{
	wolf->val2->olddirx = wolf->val->dirx;
	wolf->val->dirx = wolf->val->dirx * cos(-0.16) -
	wolf->val->diry * sin(-0.16);
	wolf->val->diry = wolf->val2->olddirx * sin(-0.16) +
	wolf->val->diry * cos(-0.16);
	wolf->val2->oldplanex = wolf->val->planex;
	wolf->val->planex = wolf->val->planex * cos(-0.16) -
	wolf->val->planey * sin(-0.16);
	wolf->val->planey = wolf->val2->oldplanex * sin(-0.16) +
	wolf->val->planey * cos(-0.16);
	ft_open_window(wolf);
}

void	move_left(t_pos *wolf)
{
	wolf->val2->olddirx = wolf->val->dirx;
	wolf->val->dirx = wolf->val->dirx * cos(0.16) - wolf->val->diry * sin(0.16);
	wolf->val->diry = wolf->val2->olddirx * sin(0.16) +
	wolf->val->diry * cos(0.16);
	wolf->val2->oldplanex = wolf->val->planex;
	wolf->val->planex = wolf->val->planex * cos(0.16) -
	wolf->val->planey * sin(0.16);
	wolf->val->planey = wolf->val2->oldplanex * sin(0.16) +
	wolf->val->planey * cos(0.16);
	ft_open_window(wolf);
}
