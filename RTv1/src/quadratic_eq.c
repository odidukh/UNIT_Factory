/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic_eq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:29:15 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 19:29:24 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double	quadratic_eq(double a, double b, double c)
{
	double	d;
	double	t_1;
	double	t_2;

	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	t_1 = (-b - sqrt(d)) / (2 * a);
	t_2 = (-b + sqrt(d)) / (2 * a);
	if ((t_1 <= t_2 && t_1 >= 0) || (t_1 >= 0 && t_2 < 0))
		return (t_1);
	else if ((t_2 <= t_1 && t_2 >= 0) || (t_1 < 0 && t_2 >= 0))
		return (t_2);
	return (-1);
}
