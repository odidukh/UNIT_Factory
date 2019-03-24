/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:25:58 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 19:26:07 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	normal_plane(t_ray *ray, t_object obj)
{
	if (vector_dot(ray->direction, obj.rotation) < 0)
		return (obj.rotation);
	return (vector_scal_mult(obj.rotation, -1));
}

double		intersect_plane(t_ray *ray, t_object obj)
{
	double		a;
	double		b;
	t_vector	v;

	obj.rotation = vector_norm(obj.rotation);
	v = vector_subtraction(ray->origin, obj.position);
	a = vector_dot(v, obj.rotation);
	b = vector_dot(ray->direction, obj.rotation);
	return (-a / b);
}
