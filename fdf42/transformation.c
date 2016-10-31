/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 13:34:13 by joboyer           #+#    #+#             */
/*   Updated: 2016/02/05 13:23:33 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_nb_line(char **line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void	ft_add_link(t_list *fdf, int *xy, int nb_line, char *line)
{
	t_jojo	*new_link;
	t_jojo	*ptr;

	if (line != NULL)
	{
		ptr = fdf->head;
		new_link = (t_jojo*)malloc(sizeof(t_jojo));
		ft_put_null(new_link);
		new_link->value = ft_matoi((const char*)line);
		new_link->x = xy[0];
		new_link->y = xy[1];
		new_link->max_line = nb_line;
		if (fdf->head == NULL)
			fdf->head = new_link;
		else
		{
			while (ptr->next)
				ptr = ptr->next;
			ptr->next = new_link;
			ptr->right = new_link;
		}
	}
	else if (line == NULL)
		ft_right(fdf, nb_line);
}

t_list	*ft_transformation(t_list *fdf)
{
	t_jojo	*new;
	t_list	*fd;
	char	**line;
	int		nb_line;
	int		xy[2];

	xy[0] = -1;
	xy[1] = 0;
	new = fdf->head;
	fd = ft_creat_list();
	while (new)
	{
		line = ft_strsplit((char const*)new->read, ' ');
		free(new->read);
		nb_line = check_nb_line(line);
		while (++xy[0] <= nb_line)
			ft_add_link(fd, xy, nb_line, line[xy[0]]);
		free(line);
		xy[0] = -1;
		xy[1]++;
		new = new->next;
	}
	free(new);
	fd->head->y_max = xy[0] - 1;
	return (fd);
}

int		ft_matoi(const char *str)
{
	int	i;
	int	neg;
	int	numb;

	i = 0;
	neg = 0;
	numb = 0;
	if (str[i] == 45)
		neg = 1;
	if (str[i] == 45)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		numb = numb * 10;
		numb = numb + ((int)str[i] - 48);
		i++;
	}
	if (str[i] == '-')
		ft_error();
	if (neg == 1)
		return (-numb);
	else
		return (numb);
}

void	ft_add_down_link(t_list *fdf)
{
	t_jojo	*tab;
	t_jojo	*tab2;
	int		i;

	i = -1;
	tab = fdf->head;
	tab2 = fdf->head;
	while (++i < tab2->max_line)
		tab2 = tab2->next;
	while (tab)
	{
		if (tab2)
			tab->down = tab2;
		if (tab2 != NULL && tab->next != NULL)
		{
			tab = tab->next;
			tab2 = tab2->next;
		}
		else
		{
			fdf->head->max_l = tab->y + 1;
			tab->down = NULL;
			tab = tab->next;
		}
	}
}
