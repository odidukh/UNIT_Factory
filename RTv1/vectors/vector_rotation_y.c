/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rotation_y.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:49:46 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 18:53:45 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_rotation_y(t_vector v, double d)
{
	t_vector	vect;

	vect.x = v.x * cos(d) + v.z * sin(d);
	vect.y = v.y;
	vect.z = v.z * cos(d) - v.x * sin(d);
	return (vect);
}
