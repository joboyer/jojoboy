/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 18:20:11 by joboyer           #+#    #+#             */
/*   Updated: 2016/02/29 18:22:13 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include "./minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# define SCREEN_X 1000
# define SCREEN_Y 600

typedef struct		s_jojo
{
	char			*read;
	size_t			len_rd;
	int				max_y;
	void			*mlx;
	void			*win;
	int				endian;
	int				*img;
	int				bpp;
	int				sline;
	char			*data;
	struct s_jojo	*next;
}					t_jojo;

typedef struct		s_val
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			old_time;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			camerax;
	double			w;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
}					t_val;

typedef struct		s_val2
{
	int				x;
	double			perpdist;
	int				stepx;
	int				stepy;
	int				side;
	int				hit;
	double			h;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
	double			olddiry;
	double			olddirx;
	double			oldplanex;
}					t_val2;

typedef struct		s_pos
{
	int				i;
	int				j;
	int				**map;
	t_jojo			*head;
	t_val			*val;
	t_val2			*val2;
}					t_pos;

void				ft_error(int i);
t_pos				*ft_init_wolf(void);
void				ft_init_jojo(t_jojo *wolf);
int					ft_len_str(char **str);
void				test_read(char *line, t_pos *wolf);
void				ft_check_map(int fd, t_pos *wolf);
int					ft_take_map(char *av);
int					init_img(t_pos *wolf);
void				ft_open_window(t_pos *wolf);
void				ft_init_val(t_pos *wolf, int i);
void				ft_init_pos(t_pos *wolf);
void				ft_init_val2(t_pos *wolf, int i);
void				ft_raycasting(t_pos *wolf);
int					init_img(t_pos *wolf);
void				ft_put_pix_img(t_pos *wolf, int y, int color);
void				ft_put_pix(t_pos *wolf);
void				check_color(t_pos *wolf);
void				ft_calcul(t_pos *wolf);
void				ft_calcul_step(t_pos *wolf);
void				ft_check_square(t_pos *wolf);
void				ft_project(t_pos *wolf);
void				ft_put_map(t_pos *wolf, int y);
void				put_map(t_pos *wolf, char **tab);
int					ft_stop(int keyboard, t_pos *wolf);
void				move_front(t_pos *wolf);
void				move_back(t_pos *wolf);
void				move_right(t_pos *wolf);
void				move_left(t_pos *wolf);
void				ft_free_all(t_pos *wolf);
void				ft_free_map(t_pos *wolf);
int					move(int keyboard, t_pos *wolf);
int					ft_put_pix2(t_pos *wolf, int i);

#endif
