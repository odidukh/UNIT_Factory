/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:55:47 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 19:13:31 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <SDL2/SDL.h>
# include <math.h>
# include "../vectors/vector.h"
# define OBJECT	sdl->object[sdl->object_counter]
# define W_WIDTH 1000
# define W_HEIGHT 1000
# define SPHERE 1
# define CYLINDER 2
# define PLANE 3
# define CONUS 4

typedef struct		s_converted
{
	double			x;
	double			y;
}					t_converted;

typedef	struct		s_light
{
	t_vector		position;
	t_vector		point_on_object;
	t_vector		normal;
	double			intensivity;
	double			res_intensivity;
}					t_light;

typedef struct		s_rgb
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}					t_rgb;

typedef struct		s_object
{
	t_vector		position;
	t_rgb			color;
	t_vector		rotation;
	double			r;
	double			t;
	int				name;
	double			specular;
}					t_object;

typedef	struct		s_cam
{
	t_vector		position;
	t_vector		rotation;
}					t_cam;

typedef	struct		s_ray
{
	t_vector		origin;
	t_vector		direction;
}					t_ray;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	t_cam			camera;
	t_object		**object;
	int				object_counter;
	int				light_counter;
	int				closest_object;
	int				object_number;
	int				light_number;
	int				running;
	double			minimal;
	double			ambient;
	t_light			**light;
}					t_sdl;

int					test_argv(int argc, char **argv);
int					num_of_elem(char **s);
void				free_objects(t_sdl *sdl);
void				free_str_array(t_sdl *sdl, char **str_array, int alert);
void				computing_intensivity(t_sdl *sdl, t_ray *ray);
void				ft_init_sdl(t_sdl *sdl);
void				event_catch(void);
void				exit_x(t_sdl *sdl);
void				parser(t_sdl *sdl, char *file_name);
void				ray_tracer(t_sdl *sdl);
void				ray_direction(t_ray *ray, double x, double y);
void				scene_data(t_sdl *sdl);
void				cylinder_data(t_sdl *sdl, char **str_array);
void				sphere_data(t_sdl *sdl, char **str_array);
void				conus_data(t_sdl *sdl, char **str_array);
void				plane_data(t_sdl *sdl, char **str_array);
void				put_color(t_sdl *sdl, int i, int x, int y);
void				light_data(t_sdl *sdl, char **str_array);
void				camera_data(t_sdl *sdl, char **str_array);
double				compute_light(t_sdl *sdl, double t);
double				convert_x(int x);
double				convert_y(int y);
double				intersect_conus(t_ray *ray, t_object obj);
double				intersect_cylinder(t_ray *ray, t_object obj);
double				intersect_plane(t_ray *ray, t_object obj);
double				intersect_sphere(t_ray *ray, t_object obj);
double				quadratic_eq(double a, double b, double c);
t_vector			normal_plane(t_ray *ray, t_object obj);
t_vector			normal_sphere(t_ray *ray, t_object obj);
t_vector			normal_conus(t_ray *ray, t_object obj);
t_vector			normal_cylinder(t_ray *ray, t_object obj);

#endif
