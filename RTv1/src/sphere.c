/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:21:35 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 19:21:38 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	normal_sphere(t_ray *ray, t_object obj)
{
	t_vector	shape_norm;

	shape_norm = vector_addition(ray->origin,
		vector_scal_mult(ray->direction, obj.t));
	shape_norm = vector_subtraction(shape_norm, obj.position);
	shape_norm = vector_norm(shape_norm);
	if (vector_dot(ray->direction, shape_norm) > 0.000001)
		shape_norm = vector_scal_mult(shape_norm, -1);
	return (shape_norm);
}

double		intersect_sphere(t_ray *ray, t_object obj)
{
	double		a;
	double		b;
	double		c;
	t_vector	oc;

	oc = vector_subtraction(ray->origin, obj.position);
	a = vector_dot(ray->direction, ray->direction);
	b = 2 * vector_dot(oc, ray->direction);
	c = vector_dot(oc, oc) - (obj.r * obj.r);
	return (quadratic_eq(a, b, c));
}
