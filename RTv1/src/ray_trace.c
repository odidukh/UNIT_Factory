/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:19:24 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 19:19:27 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ray_intersects_object(t_sdl *sdl, t_ray *ray, int x, int y)
{
	int		i;

	i = 0;
	sdl->closest_object = -1;
	sdl->minimal = INFINITY;
	while (i < sdl->object_number)
	{
		if (sdl->object[i]->name == SPHERE)
			sdl->object[i]->t = intersect_sphere(ray, *(sdl->object[i]));
		else if (sdl->object[i]->name == CYLINDER)
			sdl->object[i]->t = intersect_cylinder(ray, *(sdl->object[i]));
		else if (sdl->object[i]->name == CONUS)
			sdl->object[i]->t = intersect_conus(ray, *(sdl->object[i]));
		else
			sdl->object[i]->t = intersect_plane(ray, *(sdl->object[i]));
		if (sdl->object[i]->t > -1 && sdl->object[i]->t < sdl->minimal)
		{
			sdl->minimal = sdl->object[i]->t;
			sdl->closest_object = i;
		}
		i++;
	}
	if (sdl->closest_object > -1)
		computing_intensivity(sdl, ray);
	put_color(sdl, sdl->closest_object, x, y);
}

void	ray_tracer(t_sdl *sdl)
{
	int			x;
	int			y;
	t_ray		*ray;

	ray = ft_memalloc(sizeof(t_ray));
	ray->origin = sdl->camera.position;
	y = 0;
	while (y <= W_HEIGHT)
	{
		x = 0;
		while (x <= W_WIDTH)
		{
			ray_direction(ray, convert_x(x), convert_y(y));
			ray->direction = vector_rotation(ray->direction,
				sdl->camera.rotation);
			ray_intersects_object(sdl, ray, x, y);
			x++;
		}
		y++;
	}
	free(ray);
	free_objects(sdl);
}
