/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joboyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:10:44 by joboyer           #+#    #+#             */
/*   Updated: 2016/02/05 13:31:13 by joboyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx_macos/mlx.h"
# include "./libft/get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>
# define SCREEN_X 2100
# define SCREEN_Y 1100

typedef struct		s_jojo
{
	char			*read;
	char			*data;
	int				value;
	int				index;
	int				max_index;
	int				y;
	int				x;
	int				endian;
	int				*img;
	int				bpp;
	int				sline;
	int				y_max;
	int				sign;
	int				max_line;
	int				screen_x;
	int				screen_y;
	int				step;
	int				max_l;
	void			*mlx;
	void			*win;
	struct s_jojo	*next;
	struct s_jojo	*right;
	struct s_jojo	*down;
}					t_jojo;

typedef struct		s_list
{
	t_jojo			*head;
}					t_list;

void				ft_error(void);
t_list				*ft_creat_list(void);
t_list				*ft_transformation(t_list *fdf);
void				ft_add_link(t_list *fdf, int *xy, int nb_line, char *line);
void				ft_add_down_link(t_list *fdf);
void				ft_read_fdf(int fd, t_list *fdf);
void				add_elem(t_list *fdf, int i, char *line);
void				ft_open_window(t_list *fdf, int step);
void				ft_error(void);
void				dessin(t_list *fdf);
void				trace(t_list *fdf, t_jojo *list, t_jojo *list2, int limit);
void				ft_pixel_in_win(t_list *fdf, int step);
void				ft_value_plu(t_list *fdf);
void				ft_free_all(t_list *fdf);
int					check_nb_line(char **line);
int					ft_test(t_list *fdf);
int					ft_matoi(const char *str);
int					ft_stop(int keyboard, t_list *fdf);
char				*ft_strdu(const char *s1);
void				ft_right(t_list *fdf, int nb_line);
int					init_img(t_list *fdf);
void				ft_put_pix_img(t_list *fdf, int x, int y, int color);
int					ft_color(int value, int value2);
void				ft_put_null(t_jojo *elem);

#endif
