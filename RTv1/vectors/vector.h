/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:47:45 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 18:47:51 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>
# define RAD(d) ((double)d * (M_PI/180))

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

t_vector		vector_addition(t_vector v_1, t_vector v_2);
t_vector		vector_scal_mult(t_vector v_1, double a);
t_vector		vector_subtraction(t_vector v_1, t_vector v_2);
t_vector		vector_norm(t_vector v_1);
double			vector_dot(t_vector v_1, t_vector v_2);
double			vector_length(t_vector v_1);
t_vector		vector_rotation(t_vector v, t_vector ray);
t_vector		vector_rotation_x(t_vector v, double d);
t_vector		vector_rotation_y(t_vector v, double d);
t_vector		vector_rotation_z(t_vector v, double d);
#endif
