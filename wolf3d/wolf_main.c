/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 18:19:04 by joboyer           #+#    #+#             */
/*   Updated: 2016/02/29 18:19:57 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_put_map(t_pos *wolf, int y)
{
	t_jojo	*first;
	char	**tab;

	first = wolf->head;
	wolf->map = (int**)malloc(sizeof(int*) * y);
	while (wolf->head)
	{
		tab = ft_strsplit(wolf->head->read, ' ');
		free(wolf->head->read);
		wolf->map[wolf->i] = (int*)malloc(sizeof(int) * first->len_rd);
		put_map(wolf, tab);
		wolf->head = wolf->head->next;
	}
	wolf->map[wolf->i] = NULL;
	wolf->head = first;
	wolf->i = 0;
	wolf->j = 0;
}

void	put_map(t_pos *wolf, char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			wolf->map[wolf->i][wolf->j] = (int)ft_atoi(&tab[i][j]);
			wolf->j++;
			j++;
		}
		free(tab[i]);
		i++;
	}
	wolf->i++;
	wolf->j = 0;
	free(tab);
}

void	ft_put_pix_img(t_pos *wolf, int y, int color)
{
	int i;

	i = ((wolf->head->bpp / 8) * wolf->val2->x) + (wolf->head->sline * y);
	wolf->head->data[i] = color;
	wolf->head->data[i + 1] = color >> 8;
	wolf->head->data[i + 2] = color >> 16;
	wolf->head->data[i + 3] = 1;
}

int		ft_take_map(char *av)
{
	int fd;

	fd = -2;
	if (1 == (ft_strequ("1", av)))
		fd = open("./maps/42.wolf", O_RDONLY);
	if (fd == -2 || fd == -1)
		ft_error(3);
	return (fd);
}

int		main(int ac, char **av)
{
	int		fd;
	t_pos	*wolf;

	wolf = ft_init_wolf();
	if (ac != 2)
		ft_error(0);
	else
	{
		fd = ft_take_map(av[1]);
		ft_check_map(fd, wolf);
		close(fd);
		ft_open_window(wolf);
	}
	return (0);
}
