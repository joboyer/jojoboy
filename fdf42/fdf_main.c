/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:09:31 by joboyer           #+#    #+#             */
/*   Updated: 2016/07/19 10:58:15 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_test(t_list *fdf)
{
	int		i;
	int		limit;
	int		j;
	t_jojo	*control;

	control = fdf->head;
	i = 0;
	j = 0;
	limit = check_nb_line(ft_strsplit((char const*)fdf->head->read, ' '));
	while (control)
	{
		if (limit != check_nb_line(ft_strsplit(
			(char const*)control->read, ' ')))
			return (-1);
		j++;
		control = control->next;
	}
	return (0);
}

void	add_elem(t_list *fdf, int i, char *line)
{
	t_jojo *new_elem;
	t_jojo *ptr;

	ptr = fdf->head;
	new_elem = (t_jojo*)malloc(sizeof(t_jojo));
	ft_put_null(new_elem);
	new_elem->next = NULL;
	new_elem->read = ft_strdu(line);
	new_elem->index = i;
	if (fdf->head == NULL)
		fdf->head = new_elem;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new_elem;
	}
}

void	ft_read_fdf(int fd, t_list *fdf)
{
	int		stop;
	int		i;
	char	*line;

	i = 0;
	while ((stop = get_next_line(fd, &line)) > 0)
	{
		add_elem(fdf, i, line);
		free(line);
		i++;
	}
	if (ft_test(fdf) == -1 || stop == -1)
		ft_error();
}

t_list	*ft_creat_list(void)
{
	t_list	*fdf;

	fdf = (t_list*)malloc(sizeof(t_list));
	if (fdf)
	{
		fdf->head = NULL;
	}
	return (fdf);
}

int		main(int ac, char **av)
{
	int		fd;
	t_list	*fdf;
	t_list	*fdf_new;

	fdf = ft_creat_list();
	if (ac != 2)
		ft_error();
	if (-1 == (fd = open(av[1], O_RDONLY)))
		ft_error();
	ft_read_fdf(fd, fdf);
	fdf_new = ft_transformation(fdf);
	ft_free_all(fdf);
	fdf = NULL;
	ft_add_down_link(fdf_new);
	fdf_new->head->step = 10;
	ft_open_window(fdf_new, fdf_new->head->step);
	return (0);
}
