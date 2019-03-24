/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotation_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:49:29 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 18:53:30 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_rotation_x(t_vector v, double d)
{
	t_vector vect;

	vect.x = v.x;
	vect.y = v.y * cos(d) - v.z * sin(d);
	vect.z = v.y * sin(d) + v.z * cos(d);
	return (vect);
}
