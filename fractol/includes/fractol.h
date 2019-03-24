/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 19:38:27 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/07 20:19:34 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "../libft/libft.h"
# include "mlx.h"
# define WIN_X 1920
# define WIN_Y 1080
# define CORES 16
# define STRIP (WIN_Y / CORES)

typedef struct	s_info
{
	void		*mlx_ptr;
	void		*win_ptr;
	double		c_re_tmp;
	double		c_im_tmp;
	double		x_move;
	double		y_move;
	double		zoom;
	int			iterations;
	int			scheme;
	int			s_line;
	int			bpp;
	int			endian;
	char		*image;
	char		*pixels;
	char		type;
}				t_info;

typedef struct	s_info_fr
{
	double		re_factor;
	double		im_factor;
	double		c_re_tmp;
	double		c_im_tmp;
	double		c_re;
	double		c_im;
	double		x_move;
	double		y_move;
	double		zoom;
	int			y_start;
	int			y_finish;
	double		z;
	int			iterations;
	int			x;
	int			n;
	int			scheme;
	int			ph;
	int			w;
	int			c;
	t_info		*info;
}				t_info_fr;

t_info			*ft_fractol(void);
void			ft_usage(void);
void			ft_fill_color(t_info_fr *fr);
void			ft_display(t_info *info);
void			ft_operations(t_info *info);
void			ft_part_init(t_info *info);
void			ft_thread(t_info *info, void *(*fractal_func)(void *));
void			*ft_mandelbrot(void *args);
void			*ft_julia(void *args);
void			*ft_burning_ship(void *args);
void			*ft_infinite_cube(void *args);
void			*ft_newton(void *args);
void			ft_selector(char *str, t_info *info);
void			ft_menu_init(t_info *w);
int				ft_mouse_hook(int key_code, int x, int y, t_info *info);
int				ft_julia_hook(int x, int y, t_info *info);
int				ft_key_hook(int key_code, t_info *info);
int				expose_hook(t_info *info);
int				exit_x(t_info *info);

#endif
