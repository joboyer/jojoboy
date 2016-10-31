/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:25:12 by joboyer           #+#    #+#             */
/*   Updated: 2016/03/15 12:54:10 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_free_all(t_pos *wolf)
{
	mlx_destroy_image(wolf->head->mlx, wolf->head->img);
	mlx_destroy_window(wolf->head->mlx, wolf->head->win);
	ft_free_map(wolf);
	ft_init_jojo(wolf->head);
	free(wolf->head);
	ft_init_val(wolf, 1);
	free(wolf->val);
	ft_init_val2(wolf, 1);
	if (wolf->val2 != NULL)
		free(wolf->val2);
	free(wolf);
}

void	ft_error(int i)
{
	ft_putstr("error\n");
	if (i == 0)
		ft_putstr("vous ne pouvez entrer qu'un parametre 1 = map42\n");
	else if (i == 1)
		ft_putstr("erreur lecture map\n");
	else if (i == 2)
		ft_putstr("erreur map\n");
	else if (i == 3)
		ft_putstr("erreur ouverture map\n");
	exit(EXIT_FAILURE);
}

int		init_img(t_pos *wolf)
{
	if (!(wolf->head->img = mlx_new_image(wolf->head->mlx, SCREEN_X, SCREEN_Y)))
		return (-1);
	if (!(wolf->head->data = mlx_get_data_addr(wolf->head->img,
		&(wolf->head->bpp), &(wolf->head->sline), &(wolf->head->endian))))
		return (-1);
	return (0);
}

void	ft_free_map(t_pos *wolf)
{
	int i;

	i = 0;
	while (i <= wolf->head->max_y)
	{
		free(wolf->map[i]);
		i++;
	}
	free(wolf->map);
}

void	ft_put_pix(t_pos *wolf)
{
	int i;

	i = 0;
	while (i < wolf->val2->drawstart)
	{
		ft_put_pix_img(wolf, i, 0xA72BC0);
		i++;
	}
	i = ft_put_pix2(wolf, i);
	while (i < SCREEN_Y)
	{
		ft_put_pix_img(wolf, i, 0x1B1142);
		i++;
	}
}
