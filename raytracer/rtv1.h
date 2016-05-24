/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 17:17:24 by joboyer           #+#    #+#             */
/*   Updated: 2016/04/25 17:17:28 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "./minilibx_macos/mlx.h"
# include "./libft/get_next_line.h"
# include "./libft/libft.h"
# include "fcntl.h"
# define SCREEN_X 1000
# define SCREEN_Y 600

typedef	struct		s_light
{
	double			xyz[3];
	double			rgb[3];
}					t_light;

typedef	struct		s_objet
{
	int				obj;
	double			xyz[3];
	double			xyzpos[3];
	double			rayon;
	double			rgb[3];
	double			bri;
}					t_objet;

typedef	struct		s_camera
{
	double			rayxyz[3];
	double			ori[3];
	double			vecdirxyz[3];
	double			vpldist;
	double			vplheight;
	double			vplwidth;
	double			xyz[3];
	double			dirxyz[3];
	double			indentx;
	double			indenty;
	double			upvecxyz[3];
	double			rightvecxyz[3];
	double			oeil[3];
	double			tray;
	int				obj;
}					t_camera;

typedef	struct		s_wind
{
	int				in;
	void			*mlx;
	void			*win;
	int				endian;
	int				*img;
	int				bpp;
	int				sline;
	char			*data;
}					t_wind;

typedef	struct		s_jojo
{
	int				nb_obj;
	int				nb_light;
	t_wind			win;
	t_objet			*obj;
	t_light			*light;
	t_camera		cam;
}					t_jojo;

void				ft_error(int i);
void				ft_img_para(char **av, t_jojo *rtv1);
void				ft_init_env(t_jojo *rtv1);
void				ft_read_obj(int fd, t_jojo *rtv1);
void				ft_init_cam(t_jojo *rtv1);
void				ft_vec_para(double *tmp, double x, double y, double z);
void				ft_init_sphr(t_jojo *rtv1, int i, double obj[2][3]);
void				ft_print_vec(double *str);
int					ft_init_img(t_jojo *rtv1);
void				ft_open_wind(t_jojo *rtv1);
int					ft_stop(int keyboard, t_jojo *rtv1);
void				ft_check_img(t_jojo *rtv1);
void				ft_put_pixel(int x, int y, int color, t_jojo *rtv1);
unsigned int		ft_check_obj(int x, int y, t_jojo *rtv1);
double				ft_check_det(double a, double b, double c);
double				ft_dist_spher(t_jojo *rtv1, int i);
double				ft_dist_obj(t_jojo *rtv1, int i);
void				ft_check_ray(int x, int y, t_jojo *rtv1);
double				ft_carre(double i);
double				ft_check_long(double x, double y, double z);
void				ft_normalise(double *x, double *y, double *z);
void				ft_vec_sous(double *target, double *tab1, double *tab2);
void				ft_vec_addi(double *target, double *tab1, double *tab2);
double				ft_dist_plan(t_jojo *rtv1, int i);
void				ft_init_plan(t_jojo *rtv1, int i, double obj[2][3]);
void				ft_init_scene1(t_jojo *rtv1, int i);
double				ft_dist_cyl(t_jojo *rtv1, int i);
void				ft_init_cyl(t_jojo *rtv1, int i, double obj[2][3]);
void				ft_init_cone(t_jojo *rtv1, int i, double obj[2][3]);
double				ft_dist_cone(t_jojo *rtv1, int i);
void				ft_init_light(t_jojo *rtv1, int i);
unsigned int		ft_dark(t_jojo *rtv1, int ob);
void				ft_light(double **collight,
	double *finalcol, int i, t_jojo *rtv1);
int					ft_shadow(double *couleur, t_jojo *rtv1,
	int obj, int light);
void				ft_init_light(t_jojo *rtv1, int i);
void				ft_light_para(t_jojo *rtv1, int i, double par[2][3]);
void				ft_read_light(int fd, t_jojo *rtv1);
void				ft_calc_pos(t_jojo *rtv1);
double				ft_dot_product(double *tab1, double *tab2);
double				ft_angle_spher(t_jojo *rtv1, int i);
double				ft_angle_obj(t_jojo *rtv1, int i);
void				ft_free(t_jojo *rtv1, double **light);
double				ft_angle_plan(t_jojo *rtv1, int i);
double				ft_angle_cyl(t_jojo *rtv1, int i);
double				ft_brillance(t_jojo *rtv1, int o);
double				ft_bri_plan(t_jojo *rtv1, int o);
double				ft_bri_sphr(t_jojo *rtv1, int o);
double				ft_puissance(double i, int p);
void				ft_check_bri(double *couleur);
double				ft_angle_cone(t_jojo *rtv1, int i);
double				ft_bri_cyl(t_jojo *rtv1, int o);
double				ft_bri_cone(t_jojo *rtv1, int o);
void				ft_init_scene2(t_jojo *rtv1, int i);
void				ft_init_scene3(t_jojo *rtv1, int i);
void				ft_init_scene4(t_jojo *rtv1, int i);
int					move(int keyboard, t_jojo *rtv1);
void				ft_free_all(t_jojo *rtv1);

#endif
