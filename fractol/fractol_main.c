/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 10:38:11 by joboyer           #+#    #+#             */
/*   Updated: 2016/02/17 10:38:13 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ft_mouse_move(int x, int y, t_list *fract)
{
	if (fract->val->cho == 1 && (x >= 0 && x <= SCREEN_X)
		&& (y >= 0 && y <= SCREEN_Y))
	{
		fract->val->x = 0;
		fract->val->y = 0;
		fract->val->c_r = -1.0 + x * 2.0 / SCREEN_X;
		fract->val->c_i = -1.0 + y * 2.0 / SCREEN_Y;
		ft_draw_in_window(fract);
	}
	return (0);
}

void	ft_error(int i)
{
	if (i == 0)
	{
		ft_putstr("vous ne pouvez entrer qu'un parametre\n");
		ft_putstr("1 = mandelbrot\n2 = julia\n");
		ft_putstr("3 = X\nune fois le programe lancé\n");
		ft_putstr("c = changé de couleur\nr = reset image\n");
	}
	else if (i == 1)
		ft_putstr("error malloc\n");
	else if (i == 2)
		ft_putstr("1 = mandelbrot\n2 = julia\n3 = X\n");
	else if (i == 3)
		ft_putstr("error mlx init\n");
	exit(EXIT_FAILURE);
}

t_list	*ft_init_fractol(void)
{
	t_list	*fract;
	t_val	*value;

	if (!(fract = (t_list*)malloc(sizeof(t_list))))
		ft_error(1);
	fract->head = NULL;
	if (!(value = (t_val*)malloc(sizeof(t_val))))
		ft_error(1);
	fract->val = NULL;
	return (fract);
}

void	check_parametre(char *av, t_list *fract)
{
	if (1 == (ft_strequ("1", av)))
	{
		ft_init_jojo(fract);
		ft_init_value(fract);
		ft_init_mandelbrot(fract);
	}
	else if (1 == (ft_strequ("2", av)))
	{
		ft_init_jojo(fract);
		ft_init_value(fract);
		ft_init_julia(fract);
	}
	else if (1 == (ft_strequ("3", av)))
	{
		ft_init_jojo(fract);
		ft_init_value(fract);
		ft_init_x(fract);
	}
	else
		ft_error(2);
}

int		main(int ac, char **av)
{
	t_list *fract;

	fract = NULL;
	if (ac != 2)
		ft_error(0);
	else
	{
		fract = ft_init_fractol();
		check_parametre(av[1], fract);
		ft_draw_in_window(fract);
	}
	return (0);
}
