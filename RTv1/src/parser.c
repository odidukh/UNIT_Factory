/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:00:08 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 19:02:28 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	parser_counter(t_sdl *sdl, int fd, char *line)
{
	char	**str_array;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		str_array = ft_strsplit(line, ' ');
		free(line);
		if (!ft_strncmp(str_array[0], "cylinder", 8) ||
				!ft_strncmp(str_array[0], "sphere", 6) ||
			!ft_strncmp(str_array[0], "conus", 5) ||
			!ft_strncmp(str_array[0], "plane", 5))
			sdl->object_number++;
		else if (!ft_strncmp(str_array[0], "light", 5))
			sdl->light_number++;
		else if (ft_strncmp(str_array[0], "ambient", 7) &&
				ft_strncmp(str_array[0], "camera", 6))
		{
			ft_putendl("ERROR: wrong file");
			free_str_array(sdl, str_array, 1);
		}
		free_str_array(sdl, str_array, 0);
	}
}

void	read_data_file(t_sdl *sdl, int fd)
{
	char	*line;
	char	**str_array;

	line = NULL;
	while (get_next_line(fd, &line))
	{
		str_array = ft_strsplit(line, ' ');
		free(line);
		if (!ft_strncmp(str_array[0], "cylinder", 8))
			cylinder_data(sdl, str_array);
		else if (!ft_strncmp(str_array[0], "sphere", 6))
			sphere_data(sdl, str_array);
		else if (!ft_strncmp(str_array[0], "conus", 5))
			conus_data(sdl, str_array);
		else if (!ft_strncmp(str_array[0], "plane", 5))
			plane_data(sdl, str_array);
		else if (!ft_strncmp(str_array[0], "light", 5))
			light_data(sdl, str_array);
		else if (!ft_strncmp(str_array[0], "ambient", 7))
			sdl->ambient = (double)ft_atoi(str_array[1]) / 100;
		else if (!ft_strncmp(str_array[0], "camera", 6))
			camera_data(sdl, str_array);
		free_str_array(sdl, str_array, 0);
	}
}

void	parser(t_sdl *sdl, char *file_name)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		ft_putendl("ERROR: wrong file");
		exit_x(sdl);
	}
	parser_counter(sdl, fd, line);
	sdl->light = ft_memalloc(sizeof(t_light *) * sdl->light_number);
	while (i < sdl->light_number)
		sdl->light[i++] = ft_memalloc(sizeof(t_light));
	i = 0;
	sdl->object = ft_memalloc(sizeof(t_object *) * sdl->object_number);
	while (i < sdl->object_number)
		sdl->object[i++] = ft_memalloc(sizeof(t_object));
	fd = open(file_name, O_RDONLY);
	read_data_file(sdl, fd);
}
