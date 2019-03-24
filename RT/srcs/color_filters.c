/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_filters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:36:11 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 15:36:17 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				filter_grayscale(SDL_Surface *surface)
{
	unsigned int	*pixel;
	unsigned int	counter;
	unsigned int	gray;
	t_color			color;

	pixel = surface->pixels;
	counter = surface->w * surface->h;
	while (counter--)
	{
		color.value = *pixel;
		gray = (color.channel[0] + color.channel[1] + color.channel[2]) / 3;
		color.channel[0] = gray;
		color.channel[1] = gray;
		color.channel[2] = gray;
		*pixel++ = color.value;
	}
}

void				filter_sepia(SDL_Surface *surface)
{
	unsigned int	*pixel;
	unsigned int	counter;
	t_color			color;
	unsigned int	tmp[3];

	pixel = surface->pixels;
	counter = surface->w * surface->h;
	while (counter--)
	{
		color.value = *pixel;
		tmp[0] = color.channel[0] * 0.393 + color.channel[1] * 0.769
				+ color.channel[2] * 0.289;
		tmp[1] = color.channel[0] * 0.349 + color.channel[1] * 0.686
				+ color.channel[2] * 0.168;
		tmp[2] = color.channel[0] * 0.272 + color.channel[1] * 0.534
				+ color.channel[2] * 0.131;
		color.channel[0] = tmp[2] > 255 ? 255 : tmp[2];
		color.channel[1] = tmp[1] > 255 ? 255 : tmp[1];
		color.channel[2] = tmp[0] > 255 ? 255 : tmp[0];
		*pixel++ = color.value;
	}
}

void				filter_negative(SDL_Surface *surface)
{
	unsigned int	*pixel;
	unsigned int	counter;
	t_color			color;

	pixel = surface->pixels;
	counter = surface->w * surface->h;
	while (counter--)
	{
		color.value = *pixel;
		color.channel[0] = 255 - color.channel[0];
		color.channel[1] = 255 - color.channel[1];
		color.channel[2] = 255 - color.channel[2];
		*pixel++ = color.value;
	}
}
