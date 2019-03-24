/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_sketch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:19:20 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 15:38:10 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static unsigned int	get_new_color(unsigned int clr1, unsigned int clr2)
{
	t_color			color1;
	t_color			color2;
	unsigned int	average;
	unsigned int	sum[3];

	color1.value = clr1;
	color2.value = clr2;
	sum[0] = color1.channel[0] * 255 / (256 - color2.channel[0]);
	sum[1] = color1.channel[1] * 255 / (256 - color2.channel[1]);
	sum[2] = color1.channel[2] * 255 / (256 - color2.channel[2]);
	average = (sum[0] + sum[1] + sum[2]) / 3;
	if (average > 255)
		average = 255;
	color1.channel[0] = average;
	color1.channel[1] = average;
	color1.channel[2] = average;
	return (color1.value);
}

void				filter_sketch(SDL_Surface *surface, t_objlst **screen_buff)
{
	SDL_Surface		*another_surface;
	unsigned int	*pixel1;
	unsigned int	*pixel2;
	unsigned int	counter;

	another_surface = SDL_CreateRGBSurface(0, surface->w, surface->h,
											32, 0, 0, 0, 0);
	filter_grayscale(surface);
	SDL_BlitSurface(surface, NULL, another_surface, NULL);
	filter_negative(another_surface);
	filter_cartoon(another_surface, screen_buff);
	counter = surface->w * surface->h;
	pixel1 = surface->pixels;
	pixel2 = another_surface->pixels;
	while (counter--)
	{
		*pixel1 = get_new_color(*pixel1, *pixel2);
		pixel1++;
		pixel2++;
	}
	SDL_FreeSurface(another_surface);
}
