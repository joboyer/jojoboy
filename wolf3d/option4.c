/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 09:37:32 by joboyer           #+#    #+#             */
/*   Updated: 2016/03/14 09:37:43 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_len_str(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j])
		{
			if (0 == (ft_isdigit(str[i][j])))
				ft_error(1);
			j++;
		}
		free(str[i]);
		i++;
	}
	free(str);
	return (i);
}

void	test_read(char *line, t_pos *wolf)
{
	t_jojo *test;
	t_jojo *ptr;

	ptr = wolf->head;
	test = (t_jojo*)malloc(sizeof(t_jojo));
	ft_init_jojo(test);
	test->read = ft_strdup(line);
	test->len_rd = ft_len_str(ft_strsplit(test->read, ' '));
	if (wolf->head == NULL)
		wolf->head = test;
	else
	{
		if (wolf->head->len_rd != test->len_rd || test->len_rd < 3)
			ft_error(2);
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = test;
	}
}

void	ft_check_map(int fd, t_pos *wolf)
{
	char	*line;
	int		stop;
	int		i;

	i = 0;
	stop = 1;
	while (stop != 0)
	{
		stop = get_next_line(fd, &line);
		if (stop == -1)
			ft_error(1);
		if (stop == 1)
		{
			test_read(line, wolf);
			free(line);
			i++;
		}
	}
	if (i < 3)
		ft_error(2);
	wolf->head->max_y = i;
	ft_put_map(wolf, i);
}

void	ft_calcul_step(t_pos *wolf)
{
	if (wolf->val->raydirx < 0)
	{
		wolf->val2->stepx = -1;
		wolf->val->sidedistx = (wolf->val->rayposx -
			wolf->val->mapx) * wolf->val->deltadistx;
	}
	else
	{
		wolf->val2->stepx = 1;
		wolf->val->sidedistx = (wolf->val->mapx + 1.0 -
			wolf->val->rayposx) * wolf->val->deltadistx;
	}
	if (wolf->val->raydiry < 0)
	{
		wolf->val2->stepy = -1;
		wolf->val->sidedisty = (wolf->val->rayposy -
			wolf->val->mapy) * wolf->val->deltadisty;
	}
	else
	{
		wolf->val2->stepy = 1;
		wolf->val->sidedisty = (wolf->val->mapy + 1.0 -
			wolf->val->rayposy) * wolf->val->deltadisty;
	}
}

void	ft_check_square(t_pos *wolf)
{
	while (wolf->val2->hit == 0)
	{
		if (wolf->val->sidedistx < wolf->val->sidedisty)
		{
			wolf->val->sidedistx += wolf->val->deltadistx;
			wolf->val->mapx += wolf->val2->stepx;
			wolf->val2->side = 0;
		}
		else
		{
			wolf->val->sidedisty += wolf->val->deltadisty;
			wolf->val->mapy += wolf->val2->stepy;
			wolf->val2->side = 1;
		}
		if (wolf->map[wolf->val->mapx][wolf->val->mapy] > 0)
			wolf->val2->hit = 1;
	}
}
