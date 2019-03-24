/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 18:24:17 by odidukh           #+#    #+#             */
/*   Updated: 2018/09/24 23:22:52 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_rotate(t_point *point, char axis, int angle)
{
	t_matrix	*matr_x;
	t_matrix	*matr_y;
	t_matrix	*matr_z;

	matr_x = ft_matr_el_x(AIR(angle));
	matr_y = ft_matr_el_y(AIR(angle));
	matr_z = ft_matr_el_z(AIR(angle));
	if (axis == 'X')
		ft_matr_mult(point, matr_x);
	if (axis == 'Y')
		ft_matr_mult(point, matr_y);
	if (axis == 'Z')
		ft_matr_mult(point, matr_z);
	free(matr_x);
	free(matr_y);
	free(matr_z);
}

void	ft_map_rotation(t_info *info, t_point **map, char axis, int angle)
{
	int		l;
	int		c;
	double	x_c;
	double	y_c;

	l = 0;
	x_c = (map[info->line - 1][info->column - 1].x + map[0][0].x) / 2;
	y_c = (map[info->line - 1][info->column - 1].y + map[0][0].y) / 2;
	while (l < info->line)
	{
		c = 0;
		while (c < info->column)
		{
			map[l][c].x -= x_c;
			map[l][c].y -= y_c;
			ft_rotate(&map[l][c], axis, angle);
			map[l][c].x += x_c;
			map[l][c].y += y_c;
			c++;
		}
		l++;
	}
}

void	ft_scalle(t_point *point, double coeff)
{
	t_matrix	*matr_s;

	matr_s = ft_matr_el_s(coeff);
	ft_matr_mult(point, matr_s);
	free(matr_s);
}

void	ft_map_scalling(t_info *info, t_point **map, double coeff)
{
	int		l;
	int		c;
	double	x_c;
	double	y_c;

	l = 0;
	x_c = (map[info->line - 1][info->column - 1].x + map[0][0].x) / 2;
	y_c = (map[info->line - 1][info->column - 1].y + map[0][0].y) / 2;
	while (l < info->line)
	{
		c = 0;
		while (c < info->column)
		{
			map[l][c].x -= x_c;
			map[l][c].y -= y_c;
			ft_scalle(&map[l][c], coeff);
			map[l][c].x += x_c;
			map[l][c].y += y_c;
			c++;
		}
		l++;
	}
}
