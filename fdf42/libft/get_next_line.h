/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:51:31 by joboyer           #+#    #+#             */
/*   Updated: 2016/02/12 14:20:13 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 8

int					get_next_line(int const fd, char **line);

typedef	struct		s_get
{
	int				nb_read;
	int				fd;
	int				i;
	char			*read;
	struct s_get	*next;
}					t_get;

#endif
