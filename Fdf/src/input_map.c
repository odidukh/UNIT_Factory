/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:14:44 by odidukh           #+#    #+#             */
/*   Updated: 2018/09/24 23:04:41 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	fill_x_y_coord(t_info *info, t_point **input_map)
{
	int		c;
	int		l;

	l = 0;
	while (l < info->line)
	{
		c = 0;
		while (c < info->column)
		{
			input_map[l][c].x = -info->column * info->gap / 2 +
					c * info->gap;
			input_map[l][c].y = -info->line * info->gap / 2 +
					info->gap * l;
			if (info->max_altitude <= 20)
				input_map[l][c].z = input_map[l][c].z * info->gap;
			c++;
		}
		l++;
	}
}

int		ft_check_digit(char *str)
{
	while (*str)
	{
		if ((*str == '-') && (*(str + 1) >= '0' && *(str + 1) <= '9'))
			str++;
		if (!((*str >= '0') && (*str <= '9')))
		{
			write(1, "Error: invalid map\n", 19);
			exit(1);
		}
		str++;
	}
	return (1);
}

void	fill_map_array(t_point **input_map, t_info *info)
{
	char	*string;
	char	**line_array;
	int		c;
	int		l;
	char	**tmp;

	l = 0;
	string = NULL;
	while (get_next_line(info->fd, &string) > 0)
	{
		c = 0;
		line_array = ft_strsplit(string, ' ');
		tmp = line_array;
		free(string);
		while (*line_array && ft_check_digit(*line_array) == 1)
		{
			input_map[l][c].z = ft_atoi(*line_array);
			find_max_abs_altitude(info, input_map, l, c);
			free(*line_array);
			line_array++;
			c++;
		}
		free(tmp);
		l++;
	}
}

void	map(t_info *info)
{
	int		i;
	int		line;
	int		column;

	line = line_counter(info->file_name);
	column = column_counter(info->file_name);
	info->init_map = (t_point **)malloc(line * sizeof(t_point *));
	i = -1;
	while (++i < line)
		info->init_map[i] = (t_point *)malloc(column * sizeof(t_point));
	fill_map_array(info->init_map, info);
	fill_x_y_coord(info, info->init_map);
}
