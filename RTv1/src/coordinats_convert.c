/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinats_convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:28:40 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 19:28:50 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double	convert_x(int x)
{
	double	tmp_x;

	tmp_x = (x + 0.5) / (double)W_WIDTH;
	tmp_x = 2 * tmp_x - 1;
	return (tmp_x);
}

double	convert_y(int y)
{
	double	tmp_y;

	tmp_y = (y + 0.5) / (double)W_HEIGHT;
	tmp_y = 1 - (2 * tmp_y);
	return (tmp_y);
}
