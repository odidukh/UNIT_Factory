/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_camera_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:05:34 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 19:06:07 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	light_data(t_sdl *sdl, char **str_array)
{
	if (num_of_elem(str_array) < 5)
	{
		ft_putendl("ERROR: Wrong num_of_elem");
		free_str_array(sdl, str_array, 1);
	}
	sdl->light[sdl->light_counter]->position.x =
		(double)ft_atoi(str_array[1]);
	sdl->light[sdl->light_counter]->position.y =
		(double)ft_atoi(str_array[2]);
	sdl->light[sdl->light_counter]->position.z =
		(double)ft_atoi(str_array[3]);
	sdl->light[sdl->light_counter]->intensivity =
		(double)ft_atoi(str_array[4]) / 100.0;
	if (sdl->light[sdl->light_counter]->intensivity < 0)
	{
		ft_putendl("Wrong intensivity");
		free_str_array(sdl, str_array, 1);
	}
	sdl->light_counter++;
}

void	camera_data(t_sdl *sdl, char **str_array)
{
	if (num_of_elem(str_array) < 7)
	{
		ft_putendl("ERROR: Wrong num_of_elem");
		free_str_array(sdl, str_array, 1);
	}
	sdl->camera.position.x = (double)ft_atoi(str_array[1]);
	sdl->camera.position.y = (double)ft_atoi(str_array[2]);
	sdl->camera.position.z = (double)ft_atoi(str_array[3]);
	sdl->camera.rotation.x = (double)ft_atoi(str_array[4]);
	sdl->camera.rotation.y = (double)ft_atoi(str_array[5]);
	sdl->camera.rotation.z = (double)ft_atoi(str_array[6]);
}
