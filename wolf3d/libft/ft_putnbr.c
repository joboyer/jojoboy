/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:02:46 by joboyer           #+#    #+#             */
/*   Updated: 2015/12/04 12:15:14 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int		neg;

	neg = 0;
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			neg = 1;
			n++;
		}
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	if (neg == 1)
		ft_putchar(n % 10 + '1');
	else
		ft_putchar(n % 10 + '0');
}
