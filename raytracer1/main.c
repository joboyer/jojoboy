/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:17:39 by joboyer           #+#    #+#             */
/*   Updated: 2016/04/25 17:17:41 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_img_para(char **av, t_jojo *rtv1)
{
	int		fd;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_error(1);
	ft_read_obj(fd, rtv1);
	ft_read_light(fd, rtv1);
}

void	ft_read_obj(int fd, t_jojo *rtv1)
{
	char	*line;
	int		tmp;
	int		neg;

	tmp = 0;
	neg = 0;
	if ((tmp = get_next_line(fd, &line)) <= 0)
		ft_error(2);
	ft_init_cam(rtv1);
	neg = ft_atoi(line);
	if ((neg == -1 || neg == -2) || (neg == -3 || neg == -4))
	{
		rtv1->nb_obj = 1;
		rtv1->obj = (t_objet*)malloc(sizeof(t_objet) * 1);
		rtv1->win.in = 1;
		ft_init_scene1(rtv1, neg);
	}
	else if (ft_atoi(line) == 1)
		ft_init_scene2(rtv1, 2);
	else if (ft_atoi(line) == 2)
		ft_init_scene3(rtv1, 4);
	else if (ft_atoi(line) == 3)
		ft_init_scene4(rtv1, 3);
	else
		ft_error(3);
}

void	ft_read_light(int fd, t_jojo *rtv1)
{
	char	*line;
	int		tmp;

	tmp = 0;
	if ((tmp = get_next_line(fd, &line)) <= 0)
		ft_error(2);
	if (ft_atoi(line) == 1)
		ft_init_light(rtv1, 1);
	else if (ft_atoi(line) == 2)
		ft_init_light(rtv1, 2);
}

void	ft_vec_para(double *tmp, double x, double y, double z)
{
	tmp[0] = x;
	tmp[1] = y;
	tmp[2] = z;
}

int		main(int ac, char **av)
{
	t_jojo rtv1;

	if (ac != 2)
		ft_error(0);
	ft_img_para(av, &rtv1);
	ft_open_wind(&rtv1);
	return (0);
}
