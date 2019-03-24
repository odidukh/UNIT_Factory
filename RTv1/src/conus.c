/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:23:13 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 19:25:15 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	normal_conus(t_ray *ray, t_object obj)
{
	double		m;
	t_vector	shape_norm;
	t_vector	point_on_shape;

	m = obj.t * vector_dot(ray->direction, obj.rotation) +
		vector_dot(vector_subtraction(ray->origin, obj.position), obj.rotation);
	point_on_shape = vector_addition(ray->origin,
			vector_scal_mult(ray->direction, obj.t));
	shape_norm = vector_scal_mult(vector_scal_mult(obj.rotation, m),
			(1 + obj.r * obj.r));
	shape_norm =
		vector_subtraction(vector_subtraction(point_on_shape, obj.position),
				shape_norm);
	shape_norm = vector_norm(shape_norm);
	return (shape_norm);
}

double		intersect_conus(t_ray *ray, t_object obj)
{
	double		a;
	double		b;
	double		c;
	t_vector	v;

	v = vector_subtraction(ray->origin, obj.position);
	a = vector_dot(ray->direction, ray->direction) - (1 + obj.r * obj.r)
		* pow(vector_dot(ray->direction, obj.rotation), 2);
	b = 2 * (vector_dot(ray->direction, v) - (1 + obj.r * obj.r)
			* vector_dot(ray->direction, obj.rotation)
			* vector_dot(v, obj.rotation));
	c = vector_dot(v, v) - (1 + obj.r * obj.r)
		* pow(vector_dot(v, obj.rotation), 2);
	obj.rotation = vector_norm(obj.rotation);
	return (quadratic_eq(a, b, c));
}
