/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:49:09 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 18:49:12 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_rotation(t_vector v, t_vector ray)
{
	v = vector_rotation_x(v, RAD(ray.x));
	v = vector_rotation_y(v, RAD(ray.y));
	v = vector_rotation_z(v, RAD(ray.z));
	return (v);
}
