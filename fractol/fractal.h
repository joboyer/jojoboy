/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 18:33:15 by joboyer           #+#    #+#             */
/*   Updated: 2016/02/12 18:33:17 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "./minilibx_macos/mlx.h"
# include "./libft/get_next_line.h"
# include "./libft/libft.h"
# define SCREEN_X 730
# define SCREEN_Y 500
# define ECRT_X (fract->head->x2 - fract->head->x1)
# define ECRT_Y (fract->head->y2 - fract->head->y1)

typedef struct		s_jojo
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			zoom_x;
	double			zoom_y;
	double			image_x;
	double			image_y;
	int				x;
	int				y;
	int				z;
	int				c;
	int				bpp;
	int				sline;
	int				endian;
	int				*img;
	void			*mlx;
	void			*win;
	char			*data;
}					t_jojo;

typedef struct		s_val
{
	int			x;
	int			y;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	int			i;
	int			coul;
	double		tmp;
	int			cho;
	int			*couleur;
	int			zoom;
	int			iteration_max;
}					t_val;

typedef struct		s_list
{
	t_val			*val;
	t_jojo			*head;
}					t_list;

void				ft_init_mandelbrot(t_list *fract);
void				check_parametre(char *av, t_list *fract);
t_list				*ft_init_fractol(void);
void				ft_error(int i);
void				ft_init_jojo(t_list *fract);
void				ft_draw_in_window(t_list *fract);
void				ft_calcul(t_list *fractol);
void				ft_put_pix_img(t_list *fractol, int x, int y, int color);
int					init_img(t_list *fract);
int					ft_stop(int keyboard, t_list *fract);
void				ft_free_all(t_list *fract);
void				ft_couleur(t_list *fract);
void				ft_init_value(t_list *fract);
void				ft_special_value(t_list *fract);
void				ft_init_julia(t_list *fract);
int					ft_mouse(int mouse, int x, int y, t_list *fract);
void				zoom(int mouse, int x, int y, t_list *fract);
void				ft_couleur2(t_list *fract);
void				change_coul(t_list *fract);
void				ft_couleur3(t_list *fract);
int					ft_mouse_move(int x, int y, t_list *fract);
void				ft_init_x(t_list *fract);

#endif
