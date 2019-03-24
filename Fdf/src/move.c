/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 16:12:26 by odidukh           #+#    #+#             */
/*   Updated: 2018/09/17 20:08:00 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_map_moving(t_info *info, t_point **map, double coeff, char axis)
{
	int		l;
	int		c;

	l = 0;
	while (l < info->line)
	{
		c = 0;
		while (c < info->column)
		{
			if (axis == 'X')
				map[l][c].x += coeff;
			else if (axis == 'Y')
				map[l][c].y += coeff;
			c++;
		}
		l++;
	}
}
