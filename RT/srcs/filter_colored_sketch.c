/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_colored_sketch.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 17:38:24 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static unsigned int	aline_channels(unsigned int *channel, double factor)
{
	t_color			color;

	color.channel[0] = factor * channel[0];
	color.channel[1] = factor * channel[1];
	color.channel[2] = factor * channel[2];
	color.channel[3] = factor * channel[3];
	return (color.value);
}

static void			add_channels(unsigned int *dst, unsigned int color)
{
	t_color			tmp;

	tmp.value = color;
	dst[0] += (unsigned int)tmp.channel[0];
	dst[1] += (unsigned int)tmp.channel[1];
	dst[2] += (unsigned int)tmp.channel[2];
	dst[3] += (unsigned int)tmp.channel[3];
}

static unsigned int	get_average_color(SDL_Surface *surface, t_objlst **buff,
					int x, int y)
{
	t_objlst		*selected;
	unsigned int	sum[4];

	if (!(selected = buff[y * surface->w + x]))
		return (BCOLOR);
	ft_memset(sum, 0, sizeof(unsigned int) * 4);
	if (selected == buff[(y - 1) * surface->w + x - 1])
		add_channels(sum, get_pixel_color(surface, x - 1, y - 1));
	if (selected == buff[(y - 1) * surface->w + x + 1])
		add_channels(sum, get_pixel_color(surface, x + 1, y - 1));
	if (selected == buff[(y + 1) * surface->w + x + 1])
		add_channels(sum, get_pixel_color(surface, x + 1, y + 1));
	if (selected == buff[(y + 1) * surface->w + x - 1])
		add_channels(sum, get_pixel_color(surface, x - 1, y + 1));
	if (selected == buff[(y - 1) * surface->w + x])
		add_channels(sum, get_pixel_color(surface, x, y - 1));
	if (selected == buff[(y + 1) * surface->w + x])
		add_channels(sum, get_pixel_color(surface, x, y + 1));
	if (selected == buff[y * surface->w + x - 1])
		add_channels(sum, get_pixel_color(surface, x - 1, y));
	if (selected == buff[y * surface->w + x + 1])
		add_channels(sum, get_pixel_color(surface, x + 1, y));
	return (aline_channels(sum, 0.125));
}

void				filter_cartoon(SDL_Surface *surface, t_objlst **screen_buff)
{
	SDL_Surface		*modified;
	int				y;
	int				x;
	unsigned int	steps;

	modified = SDL_CreateRGBSurface(0, surface->w, surface->h, 32, 0, 0, 0, 0);
	steps = 6;
	while (steps--)
	{
		clear_surface(modified, BCOLOR);
		y = -1;
		while (++y < surface->h)
		{
			x = -1;
			while (++x < surface->w)
				draw_point(modified, x, y, get_average_color(surface,
							screen_buff, x, y));
		}
		SDL_BlitSurface(modified, NULL, surface, NULL);
	}
	SDL_FreeSurface(modified);
}
