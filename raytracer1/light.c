/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 16:54:32 by joboyer           #+#    #+#             */
/*   Updated: 2016/05/04 16:54:43 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			ft_check_bri(double *couleur)
{
	if (couleur[0] >= 1.0)
		couleur[0] = 1.0;
	if (couleur[1] >= 1.0)
		couleur[1] = 1.0;
	if (couleur[2] >= 1.0)
		couleur[2] = 1.0;
}

void			ft_calc_pos(t_jojo *rtv1)
{
	ft_vec_para(rtv1->cam.oeil, -rtv1->cam.dirxyz[0], -rtv1->cam.dirxyz[1],
		-rtv1->cam.dirxyz[2]);
	ft_normalise(&rtv1->cam.oeil[0], &rtv1->cam.oeil[1], &rtv1->cam.oeil[2]);
	ft_vec_para(rtv1->cam.ori, rtv1->cam.ori[0] + rtv1->cam.tray * 0.9999 *
		rtv1->cam.dirxyz[0], rtv1->cam.ori[1] + rtv1->cam.tray * 0.9999 *
		rtv1->cam.dirxyz[1], rtv1->cam.ori[2] + rtv1->cam.tray * 0.9999 *
		rtv1->cam.dirxyz[2]);
}

void			ft_light(double **collight, double *finalcol,
	int i, t_jojo *rtv1)
{
	int tmp;
	int stop;

	tmp = 0;
	stop = 1;
	if (!(collight[i] = (double*)malloc(sizeof(double) * 3)))
		ft_error(5);
	ft_vec_para(collight[i], 0.0, 0.0, 0.0);
	ft_vec_sous(rtv1->cam.dirxyz, rtv1->light[i].xyz, rtv1->cam.ori);
	ft_normalise(&rtv1->cam.dirxyz[0], &rtv1->cam.dirxyz[1],
		&rtv1->cam.dirxyz[2]);
	while (stop && tmp < rtv1->nb_obj)
	{
		stop = ft_shadow(collight[i], rtv1, tmp, i);
		tmp++;
	}
	if (stop)
	{
		finalcol[0] += collight[i][0];
		finalcol[1] += collight[i][1];
		finalcol[2] += collight[i][2];
	}
}

int				ft_shadow(double *couleur, t_jojo *rtv1, int obj, int lit)
{
	double tmp;

	tmp = ft_dist_obj(rtv1, obj);
	if (tmp < ft_check_long(rtv1->light[lit].xyz[0] - rtv1->cam.ori[0],
		rtv1->light[lit].xyz[1] - rtv1->cam.ori[1], rtv1->light[lit].xyz[2] -
		rtv1->cam.ori[2]) && tmp > 0.0)
		return (0);
	else
	{
		couleur[0] += rtv1->light[lit].rgb[0] * (ft_angle_obj(rtv1, obj) +
			ft_puissance(ft_brillance(rtv1, obj), 2) * rtv1->obj[obj].bri);
		couleur[1] += rtv1->light[lit].rgb[1] * (ft_angle_obj(rtv1, obj) +
			ft_puissance(ft_brillance(rtv1, obj), 2) * rtv1->obj[obj].bri);
		couleur[2] += rtv1->light[lit].rgb[2] * (ft_angle_obj(rtv1, obj) +
			ft_puissance(ft_brillance(rtv1, obj), 2) * rtv1->obj[obj].bri);
		return (1);
	}
}

unsigned int	ft_dark(t_jojo *rtv1, int ob)
{
	double	**collight;
	double	finalcol[3];
	int		i;

	i = 0;
	if (!(collight = (double**)malloc(sizeof(double*) * rtv1->nb_light)))
		ft_error(5);
	ft_vec_para(finalcol, 0.0, 0.0, 0.0);
	ft_calc_pos(rtv1);
	while (i < rtv1->nb_light)
	{
		ft_light(collight, finalcol, i, rtv1);
		i++;
	}
	ft_check_bri(finalcol);
	ft_free(rtv1, collight);
	free(collight);
	return (65536 * (unsigned int)((rtv1->obj[ob].rgb[0] * 255) * finalcol[0]) +
		256 * (unsigned int)((rtv1->obj[ob].rgb[1] * 255) * finalcol[1]) +
		(unsigned int)((rtv1->obj[ob].rgb[2] * 255) * finalcol[2]));
}
