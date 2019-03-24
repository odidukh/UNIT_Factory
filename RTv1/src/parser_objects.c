/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:11:07 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/31 13:47:39 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		num_of_elem(char **s)
{
	int		num;

	num = 0;
	while (*s++)
		num++;
	return (num);
}

void	cylinder_data(t_sdl *sdl, char **s)
{
	if (num_of_elem(s) < 12
		|| ((double)ft_atoi(s[4]) / 10) < 0.1 ||
		atoi(s[8]) < 0 || atoi(s[9]) < 0 || atoi(s[10]) < 0)
	{
		free_objects(sdl);
		free_str_array(sdl, s, 1);
	}
	OBJECT->position.x = (double)ft_atoi(s[1]);
	OBJECT->position.y = (double)ft_atoi(s[2]);
	OBJECT->position.z = (double)ft_atoi(s[3]);
	OBJECT->r = (double)ft_atoi(s[4]) / 10;
	OBJECT->rotation.x = (double)ft_atoi(s[5]);
	OBJECT->rotation.y = (double)ft_atoi(s[6]);
	OBJECT->rotation.z = (double)ft_atoi(s[7]);
	OBJECT->color.red = (unsigned char)ft_atoi(s[8]);
	OBJECT->color.green = (unsigned char)ft_atoi(s[9]);
	OBJECT->color.blue = (unsigned char)ft_atoi(s[10]);
	OBJECT->specular = (double)ft_atoi(s[11]);
	OBJECT->name = CYLINDER;
	sdl->object_counter++;
}

void	sphere_data(t_sdl *sdl, char **s)
{
	if (num_of_elem(s) < 9
		|| ((double)ft_atoi(s[4]) / 10) < 0.1 ||
		atoi(s[5]) < 0 || atoi(s[6]) < 0 || atoi(s[7]) < 0)
	{
		free_objects(sdl);
		free_str_array(sdl, s, 1);
	}
	OBJECT->position.x = (double)ft_atoi(s[1]);
	OBJECT->position.y = (double)ft_atoi(s[2]);
	OBJECT->position.z = (double)ft_atoi(s[3]);
	OBJECT->r = (double)ft_atoi(s[4]) / 10;
	OBJECT->color.red = (unsigned char)ft_atoi(s[5]);
	OBJECT->color.green = (unsigned char)ft_atoi(s[6]);
	OBJECT->color.blue = (unsigned char)ft_atoi(s[7]);
	OBJECT->specular = (double)ft_atoi(s[8]);
	OBJECT->name = SPHERE;
	sdl->object_counter++;
}

void	conus_data(t_sdl *sdl, char **s)
{
	if (num_of_elem(s) < 12
		|| ((double)ft_atoi(s[4]) / 10) < 0.1 ||
		atoi(s[8]) < 0 || atoi(s[9]) < 0 || atoi(s[10]) < 0)
	{
		free_objects(sdl);
		free_str_array(sdl, s, 1);
	}
	OBJECT->position.x = (double)ft_atoi(s[1]);
	OBJECT->position.y = (double)ft_atoi(s[2]);
	OBJECT->position.z = (double)ft_atoi(s[3]);
	OBJECT->r = (double)ft_atoi(s[4]) / 10;
	OBJECT->rotation.x = (double)ft_atoi(s[5]);
	OBJECT->rotation.y = (double)ft_atoi(s[6]);
	OBJECT->rotation.z = (double)ft_atoi(s[7]);
	OBJECT->color.red = (unsigned char)ft_atoi(s[8]);
	OBJECT->color.green = (unsigned char)ft_atoi(s[9]);
	OBJECT->color.blue = (unsigned char)ft_atoi(s[10]);
	OBJECT->specular = (double)ft_atoi(s[11]);
	OBJECT->name = CONUS;
	sdl->object_counter++;
}

void	plane_data(t_sdl *sdl, char **s)
{
	if (num_of_elem(s) < 11 || atoi(s[7]) < 0
			|| atoi(s[8]) < 0 || atoi(s[9]) < 0)
	{
		free_objects(sdl);
		free_str_array(sdl, s, 1);
	}
	OBJECT->position.x = (double)ft_atoi(s[1]);
	OBJECT->position.y = (double)ft_atoi(s[2]);
	OBJECT->position.z = (double)ft_atoi(s[3]);
	OBJECT->rotation.x = (double)ft_atoi(s[4]);
	OBJECT->rotation.y = (double)ft_atoi(s[5]);
	OBJECT->rotation.z = (double)ft_atoi(s[6]);
	OBJECT->color.red = (unsigned char)ft_atoi(s[7]);
	OBJECT->color.green = (unsigned char)ft_atoi(s[8]);
	OBJECT->color.blue = (unsigned char)ft_atoi(s[9]);
	OBJECT->specular = (double)ft_atoi(s[10]);
	OBJECT->name = PLANE;
	sdl->object_counter++;
}
