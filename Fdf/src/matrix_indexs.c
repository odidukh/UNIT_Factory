/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_indexs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 19:52:40 by odidukh           #+#    #+#             */
/*   Updated: 2018/09/24 22:21:28 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_matrix	*ft_matr_el_x(double angle)
{
	t_matrix *matr_x;

	matr_x = malloc(sizeof(*matr_x));
	matr_x->x11 = 1;
	matr_x->x12 = 0;
	matr_x->x13 = 0;
	matr_x->y21 = 0;
	matr_x->y22 = cos(angle);
	matr_x->y23 = sin(angle);
	matr_x->z31 = 0;
	matr_x->z32 = -sin(angle);
	matr_x->z33 = cos(angle);
	return (matr_x);
}

t_matrix	*ft_matr_el_y(double angle)
{
	t_matrix *matr_y;

	matr_y = malloc(sizeof(*matr_y));
	matr_y->x11 = cos(angle);
	matr_y->x12 = 0;
	matr_y->x13 = -sin(angle);
	matr_y->y21 = 0;
	matr_y->y22 = 1;
	matr_y->y23 = 0;
	matr_y->z31 = sin(angle);
	matr_y->z32 = 0;
	matr_y->z33 = cos(angle);
	return (matr_y);
}

t_matrix	*ft_matr_el_z(double angle)
{
	t_matrix *matr_z;

	matr_z = malloc(sizeof(*matr_z));
	matr_z->x11 = cos(angle);
	matr_z->x12 = sin(angle);
	matr_z->x13 = 0;
	matr_z->y21 = -sin(angle);
	matr_z->y22 = cos(angle);
	matr_z->y23 = 0;
	matr_z->z31 = 0;
	matr_z->z32 = 0;
	matr_z->z33 = 1;
	return (matr_z);
}

t_matrix	*ft_matr_el_s(double k)
{
	t_matrix *matr_s;

	matr_s = malloc(sizeof(*matr_s));
	matr_s->x11 = k;
	matr_s->x12 = 0;
	matr_s->x13 = 0;
	matr_s->y21 = 0;
	matr_s->y22 = k;
	matr_s->y23 = 0;
	matr_s->z31 = 0;
	matr_s->z32 = 0;
	matr_s->z33 = k;
	return (matr_s);
}

void		ft_matr_mult(t_point *point, t_matrix *matr)
{
	double x;
	double y;
	double z;

	x = point->x;
	y = point->y;
	z = point->z;
	point->x = x * matr->x11 + y * matr->x12 +
			z * matr->x13;
	point->y = x * matr->y21 + y * matr->y22 +
			z * matr->y23;
	point->z = x * matr->z31 + y * matr->z32 +
			z * matr->z33;
}
