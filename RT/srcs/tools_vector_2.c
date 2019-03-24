/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_vector_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 16:07:30 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double			veclen(double *vec)
{
	return (sqrt(vec[X] * vec[X] + vec[Y] * vec[Y] + vec[Z] * vec[Z]));
}

void			vecnorm(double *vec)
{
	double		len;

	len = veclen(vec);
	if (len > PRECISION)
	{
		len = 1.0 / (len + PRECISION);
		vec[X] *= len;
		vec[Y] *= len;
		vec[Z] *= len;
	}
}

void			vecrot_ox(double *vec, double ox_angle, double *point)
{
	double		new_vec[3];
	double		p[3];

	p[X] = 0.0;
	p[Y] = 0.0;
	p[Z] = 0.0;
	if (point)
	{
		p[X] = point[X];
		p[Y] = point[Y];
		p[Z] = point[Z];
	}
	new_vec[Y] = p[Y] + (vec[Y] - p[Y]) * cos(ox_angle)
				- (vec[Z] - p[Z]) * sin(ox_angle);
	new_vec[Z] = p[Z] + (vec[Y] - p[Y]) * sin(ox_angle)
				+ (vec[Z] - p[Z]) * cos(ox_angle);
	vec[Y] = new_vec[Y];
	vec[Z] = new_vec[Z];
}

void			vecrot_oy(double *vec, double oy_angle, double *point)
{
	double		new_vec[3];
	double		p[3];

	p[X] = 0.0;
	p[Y] = 0.0;
	p[Z] = 0.0;
	if (point)
	{
		p[X] = point[X];
		p[Y] = point[Y];
		p[Z] = point[Z];
	}
	new_vec[X] = p[X] + (vec[X] - p[X]) * cos(oy_angle)
				- (vec[Z] - p[Z]) * sin(oy_angle);
	new_vec[Z] = p[Z] + (vec[X] - p[X]) * sin(oy_angle)
				+ (vec[Z] - p[Z]) * cos(oy_angle);
	vec[X] = new_vec[X];
	vec[Z] = new_vec[Z];
}

void			vecrot_oz(double *vec, double oz_angle, double *point)
{
	double		new_vec[3];
	double		p[3];

	p[X] = 0.0;
	p[Y] = 0.0;
	p[Z] = 0.0;
	if (point)
	{
		p[X] = point[X];
		p[Y] = point[Y];
		p[Z] = point[Z];
	}
	new_vec[X] = p[X] + (vec[X] - p[X]) * cos(oz_angle)
				- (vec[Y] - p[Y]) * sin(oz_angle);
	new_vec[Y] = p[Y] + (vec[X] - p[X]) * sin(oz_angle)
				+ (vec[Y] - p[Y]) * cos(oz_angle);
	vec[X] = new_vec[X];
	vec[Y] = new_vec[Y];
}
