/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_color_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:19:20 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/20 14:55:55 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				clear_surface(SDL_Surface *surface, unsigned int color)
{
	unsigned int	*pixel;
	size_t			counter;

	if (surface->pixels)
	{
		pixel = surface->pixels;
		counter = surface->w * surface->h;
		while (counter--)
			*pixel++ = color;
	}
}

void				draw_point(SDL_Surface *surface, int x,
								int y, unsigned int color)
{
	unsigned int	*pixel;

	if (x >= 0 && x < surface->w && y >= 0 && y < surface->h)
	{
		pixel = surface->pixels + surface->pitch * y
					+ x * sizeof(unsigned int);
		*pixel = color;
	}
}

void				draw_scaled_point(SDL_Surface *surface, int x,
									int y, unsigned int color)
{
	unsigned int	*pixel;
	int				pos[2];

	pos[Y] = y;
	while (pos[Y] < y + PRERENDER_RES && pos[Y] >= 0)
	{
		pos[X] = x;
		while (pos[X] < x + PRERENDER_RES && pos[X] >= 0)
		{
			if (pos[X] < surface->w && pos[Y] < surface->h)
			{
				pixel = surface->pixels + surface->pitch * pos[Y]
							+ pos[X] * sizeof(unsigned int);
				*pixel = color;
			}
			pos[X]++;
		}
		pos[Y]++;
	}
}

unsigned int		get_texture_color(SDL_Surface *surface, double u, double v)
{
	unsigned int	*pixel;
	int				x;
	int				y;

	x = (double)(surface->w * u);
	y = (double)(surface->h * v);
	if (x < surface->w && y < surface->h)
	{
		pixel = surface->pixels + surface->pitch * y + x * sizeof(unsigned int);
		return (*pixel);
	}
	return (BCOLOR);
}

unsigned int		get_pixel_color(SDL_Surface *surface, int x, int y)
{
	unsigned int	*pixel;

	if (x >= 0 && x < surface->w && y >= 0 && y < surface->h)
	{
		pixel = surface->pixels + surface->pitch * y + x * sizeof(unsigned int);
		return (*pixel);
	}
	return (BCOLOR);
}
