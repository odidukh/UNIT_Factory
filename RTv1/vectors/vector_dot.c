/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_dot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:48:36 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 18:48:40 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vector_dot(t_vector v_1, t_vector v_2)
{
	return (v_1.x * v_2.x + v_1.y * v_2.y + v_1.z * v_2.z);
}
