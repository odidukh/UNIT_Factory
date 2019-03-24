/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:26:44 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 19:27:49 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	normal_cylinder(t_ray *ray, t_object obj)
{
	double		m;
	t_vector	shape_norm;
	t_vector	point_on_shape;

	m = obj.t * vector_dot(ray->direction, obj.rotation)
		+ vector_dot(vector_subtraction(ray->origin, obj.position),
				obj.rotation);
	point_on_shape = vector_addition(ray->origin,
			vector_scal_mult(ray->direction, obj.t));
	shape_norm = vector_scal_mult(obj.rotation, m);
	shape_norm =
		vector_subtraction(vector_subtraction(point_on_shape, obj.position),
				shape_norm);
	shape_norm = vector_norm(shape_norm);
	if (vector_dot(ray->direction, shape_norm) > 0.000001)
		shape_norm = vector_scal_mult(shape_norm, -1);
	return (shape_norm);
}

double		intersect_cylinder(t_ray *ray, t_object obj)
{
	double		a;
	double		b;
	double		c;
	t_vector	v;

	v = vector_subtraction(ray->origin, obj.position);
	a = vector_dot(ray->direction, ray->direction)
		- pow(vector_dot(ray->direction, obj.rotation), 2);
	b = 2 * (vector_dot(ray->direction, v)
			- (vector_dot(ray->direction, obj.rotation)
				* vector_dot(v, obj.rotation)));
	c = vector_dot(v, v) - pow(vector_dot(v, obj.rotation), 2)
		- pow(obj.r, 2);
	obj.rotation = vector_norm(obj.rotation);
	return (quadratic_eq(a, b, c));
}
