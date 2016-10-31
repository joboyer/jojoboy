/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 16:32:16 by joboyer           #+#    #+#             */
/*   Updated: 2016/02/09 14:13:01 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_right(t_list *fdf, int nb_line)
{
	t_jojo	*ptr;
	int		i;

	i = 0;
	ptr = fdf->head;
	while (i < nb_line - 1)
	{
		i++;
		ptr = ptr->right;
	}
	ptr->right = NULL;
}

char	*ft_strdu(const char *s1)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (!s1)
		return (NULL);
	len = (int)ft_strlen(s1);
	str = ft_strnew(len);
	if (s1[0] == '\0')
		ft_error();
	while (i < len)
	{
		if ((s1[i] >= '0' && s1[i] <= '9') || s1[i] == ' ' || s1[i] == '-')
			str[i] = s1[i];
		else
			ft_error();
		i++;
	}
	if (!str)
		return (NULL);
	return (str);
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(EXIT_FAILURE);
}

void	ft_free_all(t_list *liste)
{
	t_jojo *to_del;

	to_del = liste->head;
	while (liste->head)
	{
		liste->head = liste->head->next;
		free(liste->head);
	}
	free(to_del);
}

void	ft_put_null(t_jojo *elem)
{
	elem->read = NULL;
	elem->data = NULL;
	elem->value = 0;
	elem->index = 0;
	elem->max_index = 0;
	elem->y = 0;
	elem->x = 0;
	elem->endian = 0;
	elem->img = NULL;
	elem->bpp = 0;
	elem->sline = 0;
	elem->y_max = 0;
	elem->sign = 0;
	elem->max_line = 0;
	elem->screen_x = 0;
	elem->screen_y = 0;
	elem->step = 0;
	elem->max_l = 0;
	elem->mlx = NULL;
	elem->win = NULL;
	elem->next = NULL;
	elem->right = NULL;
	elem->down = NULL;
}
