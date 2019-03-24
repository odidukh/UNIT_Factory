/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:31:03 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 19:31:21 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		shadow_obj(double max_t, t_ray *ray, t_sdl *sdl)
{
	int		i;
	double	t;

	i = 0;
	t = 0;
	while (i < sdl->object_number)
	{
		if (sdl->object[i]->name == SPHERE)
			t = intersect_sphere(ray, *(sdl->object[i]));
		else if (sdl->object[i]->name == CYLINDER)
			t = intersect_cylinder(ray, *(sdl->object[i]));
		else if (sdl->object[i]->name == CONUS)
			t = intersect_conus(ray, *(sdl->object[i]));
		else if (sdl->object[i]->name == PLANE)
			t = intersect_plane(ray, *(sdl->object[i]));
		if (t > 0.00001 && t < max_t)
			return (1);
		i++;
	}
	return (0);
}

int		shadow(t_light *light, t_sdl *sdl)
{
	double	max_t;
	t_ray	ray;

	max_t = vector_length(vector_subtraction(light->position,
				light->point_on_object));
	ray.direction = vector_norm(vector_subtraction(light->position,
		light->point_on_object));
	light->point_on_object = vector_addition(light->point_on_object,
		vector_scal_mult(ray.direction, 0.000001));
	ray.origin = light->point_on_object;
	return (shadow_obj(max_t, &ray, sdl));
}

void	specular(t_sdl *sdl, t_light *light, t_vector v, double spec)
{
	t_vector	ray;
	double		param;
	double		intensivity;
	t_vector	l_o;

	l_o = vector_norm(vector_subtraction(light->position,
		light->point_on_object));
	intensivity = 0.0;
	if (shadow(light, sdl) == 0)
		intensivity = light->intensivity;
	if (spec > 0)
	{
		ray = vector_scal_mult(light->normal, 2);
		ray = vector_scal_mult(ray, vector_dot(light->normal, l_o));
		ray = vector_subtraction(ray, l_o);
		param = vector_dot(ray, v);
		if (param > 0.000001)
			light->res_intensivity += intensivity
		* pow((param / (vector_length(ray) * vector_length(v))), spec);
	}
}

void	intensity(t_sdl *sdl, t_light *light, t_vector v, double spec)
{
	double		param;
	double		intensivity;
	t_vector	l;

	light->res_intensivity = sdl->ambient;
	intensivity = 0.0;
	l = vector_norm(vector_subtraction(light->position,
		light->point_on_object));
	param = vector_dot(light->normal, l);
	if (shadow(light, sdl) == 0)
		intensivity = light->intensivity;
	if (param > 0.000001)
		light->res_intensivity += intensivity
	* (param / vector_length(light->normal) / vector_length(l));
	specular(sdl, light, v, spec);
}

void	computing_intensivity(t_sdl *sdl, t_ray *ray)
{
	int	i;

	i = 0;
	while (i < sdl->light_number)
	{
		sdl->light[i]->point_on_object = vector_addition(ray->origin,
			vector_scal_mult(ray->direction,
				sdl->object[sdl->closest_object]->t));
		if (sdl->object[sdl->closest_object]->name == SPHERE)
			sdl->light[i]->normal = normal_sphere(ray,
				*(sdl->object[sdl->closest_object]));
		else if (sdl->object[sdl->closest_object]->name == PLANE)
			sdl->light[i]->normal = sdl->object[sdl->closest_object]->rotation;
		else if (sdl->object[sdl->closest_object]->name == CYLINDER)
			sdl->light[i]->normal = normal_cylinder(ray,
				*(sdl->object[sdl->closest_object]));
		else if (sdl->object[sdl->closest_object]->name == CONUS)
			sdl->light[i]->normal = normal_conus(ray,
				*(sdl->object[sdl->closest_object]));
		intensity(sdl, sdl->light[i], vector_scal_mult(ray->direction, -1),
			sdl->object[sdl->closest_object]->specular);
		i++;
	}
}
