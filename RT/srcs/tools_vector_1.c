/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_vector_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 16:07:41 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			veccross(double *v1, double *v2, double *result)
{
	double		tmp[3];

	tmp[X] = v1[Y] * v2[Z] - v2[Y] * v1[Z];
	tmp[Y] = v1[Z] * v2[X] - v2[Z] * v1[X];
	tmp[Z] = v1[X] * v2[Y] - v2[X] * v1[Y];
	result[X] = tmp[X];
	result[Y] = tmp[Y];
	result[Z] = tmp[Z];
}

double			vecdot(double *v1, double *v2)
{
	return (v1[X] * v2[X] + v1[Y] * v2[Y] + v1[Z] * v2[Z]);
}

void			vecadd(double *v1, double *v2, double *result, size_t size)
{
	size_t		i;

	i = -1;
	while (++i < size)
	{
		result[i] = v1[i] + v2[i];
	}
}

void			vecsub(double *v1, double *v2, double *result, size_t size)
{
	size_t		i;

	i = -1;
	while (++i < size)
	{
		result[i] = v1[i] - v2[i];
	}
}

void			vecmult(double *v1, double coeff, double *res, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		res[i] = v1[i] * coeff;
		i++;
	}
}
