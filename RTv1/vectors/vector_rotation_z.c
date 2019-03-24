/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotation_z.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:51:16 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 18:54:20 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_rotation_z(t_vector v, double d)
{
	t_vector	vector;

	vector.x = v.x * cos(d) - v.y * sin(d);
	vector.y = v.x * sin(d) + v.y * cos(d);
	vector.z = v.z;
	return (vector);
}
