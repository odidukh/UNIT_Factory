/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_subtraction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:51:53 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 18:51:56 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	vector_subtraction(t_vector v_1, t_vector v_2)
{
	v_1.x -= v_2.x;
	v_1.y -= v_2.y;
	v_1.z -= v_2.z;
	return (v_1);
}
