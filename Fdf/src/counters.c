/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counters.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 22:22:18 by odidukh           #+#    #+#             */
/*   Updated: 2018/09/24 22:34:20 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		line_counter(char *file_name)
{
	int		num;
	char	*line;
	int		fd;

	line = NULL;
	fd = open(file_name, O_RDONLY);
	num = 0;
	if (fd < 0)
		exit(1);
	while (get_next_line(fd, &line) > 0)
	{
		num++;
		free(line);
	}
	return (num);
}

int		column_counter(char *file_name)
{
	int		fd;
	int		num;
	char	*line;
	char	**str_array;
	char	**tmp;

	line = NULL;
	fd = open(file_name, O_RDONLY);
	num = 0;
	get_next_line(fd, &line);
	str_array = ft_strsplit(line, ' ');
	tmp = str_array;
	while (*str_array)
	{
		free(*str_array);
		str_array++;
		num++;
	}
	free(tmp);
	free(line);
	return (num);
}

void	find_max_abs_altitude(t_info *info, t_point **input_map, int l, int c)
{
	if (abs((int)input_map[l][c].z) > info->max_altitude)
		info->max_altitude = abs((int)input_map[l][c].z);
}
