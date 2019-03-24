/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:20:55 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 16:07:17 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				get_norm_from_map(double *norm, unsigned int normvec_info)
{
	t_color			color;

	color.value = normvec_info;
	norm[X] = (color.channel[2] - 128.0) / 128.0;
	norm[Y] = (color.channel[1] - 128.0) / 128.0;
	norm[Z] = (128.0 - color.channel[0]) / 128.0;
	vecnorm(norm);
}

SDL_Surface			*load_texture(const char *file, SDL_PixelFormat *format)
{
	SDL_Surface		*raw_texture;
	SDL_Surface		*converted_texture;

	raw_texture = NULL;
	converted_texture = NULL;
	if ((raw_texture = IMG_Load(file)))
	{
		if (format)
		{
			converted_texture = SDL_ConvertSurface(raw_texture, format, 0);
			if (raw_texture)
				SDL_FreeSurface(raw_texture);
		}
		else
			converted_texture = raw_texture;
	}
	return (converted_texture);
}
