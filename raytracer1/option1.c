/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:25:39 by joboyer           #+#    #+#             */
/*   Updated: 2016/04/25 17:25:48 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_stop(int keyboard, t_jojo *rtv1)
{
	if (keyboard == 53)
	{
		ft_free_all(rtv1);
		ft_error(10);
	}
	return (0);
}

int		ft_init_img(t_jojo *rtv1)
{
	rtv1->win.bpp = 4;
	rtv1->win.endian = 0;
	rtv1->win.sline = 4 * 1000;
	if (!(rtv1->win.img = mlx_new_image(rtv1->win.mlx, 1000, 1000)))
		return (-1);
	if (!(rtv1->win.data = mlx_get_data_addr(rtv1->win.img, &(rtv1->win.bpp),
		&(rtv1->win.sline), &(rtv1->win.endian))))
		return (-1);
	return (0);
}

void	ft_put_pixel(int x, int y, int color, t_jojo *rtv1)
{
	int i;

	i = ((rtv1->win.bpp / 8) * x) + (rtv1->win.sline * y);
	rtv1->win.data[i] = color;
	rtv1->win.data[i + 1] = color >> 8;
	rtv1->win.data[i + 2] = color >> 16;
}

void	ft_error(int i)
{
	if (i == 0)
		ft_putstr("Veuillez entrer un ficher map\n");
	else if (i == 1)
		ft_putstr("erreur ouverture fichier\n");
	else if (i == 2)
		ft_putstr("erreur de lecture fichier\n");
	else if (i == 3)
		ft_putstr("erreur de fichier\n");
	else if (i == 4)
		ft_putstr("erreur init window\n");
	else if (i == 5)
		ft_putstr("erreur malloc\n");
	exit(EXIT_FAILURE);
}

void	ft_light_para(t_jojo *rtv1, int i, double par[2][3])
{
	ft_vec_para(rtv1->light[i].xyz, par[0][0], par[0][1], par[0][2]);
	ft_vec_para(rtv1->light[i].rgb, par[1][0], par[1][1], par[1][2]);
}
