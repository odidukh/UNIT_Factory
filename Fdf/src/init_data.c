/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 13:37:40 by odidukh           #+#    #+#             */
/*   Updated: 2018/09/24 22:39:54 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_isometric(t_info *info, t_point **map)
{
	ft_map_rotation(info, map, 'X', -50);
	ft_map_rotation(info, map, 'Y', 30);
	ft_map_rotation(info, map, 'Z', -15);
}

void	ft_copy_map(t_info *info)
{
	int		l;
	int		c;

	l = 0;
	while (l < info->line)
	{
		c = 0;
		while (c < info->column)
		{
			info->map_with_oper[l][c].x = info->init_map[l][c].x;
			info->map_with_oper[l][c].y = info->init_map[l][c].y;
			info->map_with_oper[l][c].z = info->init_map[l][c].z;
			c++;
		}
		l++;
	}
}

void	map_malloc(t_info *info, int line, int column)
{
	int			i;

	info->map_with_oper = (t_point **)malloc(line * sizeof(t_point *));
	i = -1;
	while (++i < line)
		info->map_with_oper[i] = (t_point *)malloc(column * sizeof(t_point));
}

t_info	*ft_information(char *file_name)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	info->fd = open(file_name, O_RDONLY);
	if (info->fd < 0)
	{
		write(1, "Error: wrong file\n", 18);
		exit(0);
	}
	info->file_name = file_name;
	info->window = malloc(sizeof(t_win));
	info->window->mlx_ptr = mlx_init();
	info->window->win_ptr = mlx_new_window(info->window->mlx_ptr,
			WIN_X, WIN_Y, "fdf");
	info->line = line_counter(info->file_name);
	info->column = column_counter(info->file_name);
	info->gap = WIN_X / 2 / info->column;
	info->color = 0xffffff;
	map(info);
	ft_isometric(info, info->init_map);
	map_malloc(info, info->line, info->column);
	ft_copy_map(info);
	return (info);
}
