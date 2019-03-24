/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 16:34:20 by odidukh           #+#    #+#             */
/*   Updated: 2018/09/24 23:06:09 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include "libft/libft.h"
# include <unistd.h>
# include <math.h>
# define WIN_X 1920
# define WIN_Y 1080
# define AIR(angle) (angle * M_PI) / 180

typedef struct		s_point
{
	double				x;
	double				y;
	double				z;
}					t_point;

typedef struct		s_matr
{
	double			x11;
	double			x12;
	double			x13;
	double			y21;
	double			y22;
	double			y23;
	double			z31;
	double			z32;
	double			z33;
}					t_matrix;

typedef struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;

}					t_win;

typedef struct		s_line_coord
{
	double			x0;
	double			y0;
	double			x1;
	double			y1;
}					t_line_coord;

typedef struct		s_line_data
{
	double			dx;
	double			dy;
	double			sx;
	double			sy;
	int				i;
	double			x;
	double			y;
	double			d;
	double			d1;
	double			d2;
}					t_line_data;

typedef struct		s_info
{
	char			*file_name;
	int				max_altitude;
	int				color;
	double			gap;
	int				line;
	int				column;
	int				fd;
	t_point			**init_map;
	t_point			**map_with_oper;
	t_win			*window;
}					t_info;

void				operation(t_info *info);
void				line_draw(t_line_coord *line_coord,
		t_win *window1, int color);
void				ft_rotate(t_point *point, char axis, int angle);
void				ft_display(t_info *info);
int					exit_x(void);
int					key_hook(int key_code, t_info *info);
t_matrix			*ft_matr_el_x(double angle);
t_matrix			*ft_matr_el_y(double angle);
t_matrix			*ft_matr_el_z(double angle);
t_matrix			*ft_matr_el_s(double k);
void				ft_matr_mult(t_point *point, t_matrix *matr);
void				ft_map_scalling(t_info *info, t_point **map, double coeff);
int					line_counter(char *file_name);
int					column_counter(char *file_name);
void				ft_map_rotation(t_info *info, t_point **map,
		char axis, int angle);
void				ft_isometric(t_info *info, t_point **map);
t_info				*ft_information(char *file_name);
void				ft_map_moving(t_info *info, t_point **map,
		double coeff, char axis);
void				ft_copy_map(t_info *info);
int					expose_hook(t_info *info);
void				map(t_info *info);
void				find_max_abs_altitude(t_info *info, t_point **input_map,
		int l, int c);
#endif
