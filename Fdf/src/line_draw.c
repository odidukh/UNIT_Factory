/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:29:38 by odidukh           #+#    #+#             */
/*   Updated: 2018/09/24 20:32:19 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_line_data	*ft_line_data_init(t_line_coord *line_coord)
{
	t_line_data	*line_data;

	line_data = malloc(sizeof(t_line_data));
	line_data->i = 1;
	line_data->dx = fabs(line_coord->x1 - line_coord->x0);
	line_data->dy = fabs(line_coord->y1 - line_coord->y0);
	if (line_coord->x1 >= line_coord->x0)
		line_data->sx = 1;
	else
		line_data->sx = -1;
	if (line_coord->y1 >= line_coord->y0)
		line_data->sy = 1;
	else
		line_data->sy = -1;
	line_data->d = (line_data->dy * 2) - line_data->dx;
	line_data->d1 = line_data->dy * 2;
	line_data->d2 = (line_data->dy - line_data->dx) * 2;
	line_data->y = line_coord->y0;
	line_data->x = line_coord->x0 + line_data->sx;
	return (line_data);
}

void		ft_function_1(t_line_data *line_data, t_line_coord *line_coord,
		t_win *window1, int color)
{
	line_data->d = (line_data->dx * 2) - line_data->dy;
	line_data->d1 = line_data->dx * 2;
	line_data->d2 = (line_data->dx - line_data->dy) * 2;
	line_data->y = line_coord->y0 + line_data->sy;
	line_data->x = line_coord->x0;
	line_data->i = 1;
	mlx_pixel_put(window1->mlx_ptr, window1->win_ptr,
			line_coord->x0, line_coord->y0, color);
	while (line_data->i++ <= line_data->dy)
	{
		if (line_data->d > 0)
		{
			line_data->d += line_data->d2;
			line_data->x += line_data->sx;
		}
		else
			line_data->d += line_data->d1;
		mlx_pixel_put(window1->mlx_ptr, window1->win_ptr,
				line_data->x, line_data->y, color);
		line_data->y += line_data->sy;
	}
}

void		line_draw(t_line_coord *line_coord, t_win *window1, int color)
{
	t_line_data	*line_data;

	line_data = ft_line_data_init(line_coord);
	if (line_data->dy <= line_data->dx)
	{
		mlx_pixel_put(window1->mlx_ptr, window1->win_ptr,
				line_coord->x0, line_coord->y0, color);
		while (line_data->i++ <= line_data->dx)
		{
			if (line_data->d > 0)
			{
				line_data->d += line_data->d2;
				line_data->y += line_data->sy;
			}
			else
				line_data->d += line_data->d1;
			mlx_pixel_put(window1->mlx_ptr, window1->win_ptr,
					line_data->x, line_data->y, color);
			line_data->x += line_data->sx;
		}
	}
	else
		ft_function_1(line_data, line_coord, window1, color);
	free(line_data);
}
