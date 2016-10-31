/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_wind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 18:20:11 by joboyer           #+#    #+#             */
/*   Updated: 2016/03/15 11:10:53 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_open_window(t_pos *wolf)
{
	if (!(wolf->head->mlx))
	{
		wolf->head->mlx = mlx_init();
		if (init_img(wolf) == -1)
			ft_error(10);
		ft_init_val(wolf, 0);
		ft_init_val2(wolf, 0);
		ft_init_pos(wolf);
	}
	else
	{
		ft_init_val2(wolf, 1);
		ft_init_val(wolf, 2);
	}
	ft_raycasting(wolf);
	if (!(wolf->head->win))
		wolf->head->win = mlx_new_window(wolf->head->mlx, SCREEN_X
			+ 1, SCREEN_Y + 1, "Wolf3D");
	mlx_put_image_to_window(wolf->head->mlx,
		wolf->head->win, wolf->head->img, 0, 0);
	mlx_key_hook(wolf->head->win, ft_stop, wolf);
	mlx_hook(wolf->head->win, 2, (1L << 0), move, wolf);
	mlx_loop(wolf->head->mlx);
}

void	ft_raycasting(t_pos *wolf)
{
	while (wolf->val2->x < wolf->val->w)
	{
		wolf->val->camerax = 2 * wolf->val2->x / wolf->val->w - 1;
		wolf->val->rayposx = wolf->val->posx;
		wolf->val->rayposy = wolf->val->posy;
		wolf->val->raydirx = wolf->val->dirx +
		wolf->val->planex * wolf->val->camerax;
		wolf->val->raydiry = wolf->val->diry +
		wolf->val->planey * wolf->val->camerax;
		wolf->val->mapx = (int)wolf->val->rayposx;
		wolf->val->mapy = (int)wolf->val->rayposy;
		wolf->val->deltadistx = sqrt(1 + (wolf->val->raydiry *
			wolf->val->raydiry) / (wolf->val->raydirx * wolf->val->raydirx));
		wolf->val->deltadisty = sqrt(1 + (wolf->val->raydirx *
			wolf->val->raydirx) / (wolf->val->raydiry * wolf->val->raydiry));
		wolf->val2->hit = 0;
		ft_calcul_step(wolf);
		ft_check_square(wolf);
		ft_project(wolf);
		wolf->val2->h = SCREEN_Y;
		wolf->val2->lineheight = (int)(wolf->val2->h / wolf->val2->perpdist);
		ft_calcul(wolf);
		ft_put_pix(wolf);
		wolf->val2->x++;
	}
}

int		move(int keyboard, t_pos *wolf)
{
	if (keyboard == 126)
		move_front(wolf);
	else if (keyboard == 125)
		move_back(wolf);
	else if (keyboard == 124)
		move_right(wolf);
	else if (keyboard == 123)
		move_left(wolf);
	return (0);
}

void	ft_calcul(t_pos *wolf)
{
	wolf->val2->drawstart = -wolf->val2->lineheight / 2 + wolf->val2->h / 2;
	if (wolf->val2->drawstart < 0)
		wolf->val2->drawstart = 0;
	wolf->val2->drawend = wolf->val2->lineheight / 2 + wolf->val2->h / 2;
	if (wolf->val2->drawend >= wolf->val2->h)
		wolf->val2->drawend = wolf->val2->h - 1;
}

void	ft_project(t_pos *wolf)
{
	if (wolf->val2->side == 0)
		wolf->val2->perpdist = (wolf->val->mapx - wolf->val->rayposx
			+ (1 - wolf->val2->stepx) / 2) / wolf->val->raydirx;
	else
		wolf->val2->perpdist = (wolf->val->mapy - wolf->val->rayposy
			+ (1 - wolf->val2->stepy) / 2) / wolf->val->raydiry;
}
