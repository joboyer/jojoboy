/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:15:39 by joboyer           #+#    #+#             */
/*   Updated: 2015/12/04 15:56:29 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*tab;

	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		tab = (char *)malloc(sizeof(char) * i + 1);
		if (!tab)
			return (NULL);
		i = -1;
		j = 0;
		while (s1[++i])
			tab[i] = s1[i];
		while (s2[j] != '\0')
		{
			tab[i] = s2[j];
			i++;
			j++;
		}
		tab[i] = '\0';
		return (tab);
	}
	return (NULL);
}
