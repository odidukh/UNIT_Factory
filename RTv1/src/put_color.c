/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:29:57 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 19:30:14 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double	intensivity_coef(t_sdl *sdl)
{
	double	coef;
	int		i;

	i = 0;
	coef = 0;
	while (i < sdl->light_number)
	{
		if (sdl->light[i]->res_intensivity > 1)
			sdl->light[i]->res_intensivity = 1;
		coef += sdl->light[i]->res_intensivity;
		if (coef > 1)
			coef = 1;
		i++;
	}
	return (coef);
}

void	put_color(t_sdl *sdl, int i, int x, int y)
{
	double	c;

	c = intensivity_coef(sdl);
	if (i > -1)
		SDL_SetRenderDrawColor(sdl->renderer, sdl->object[i]->color.red * c,
			sdl->object[i]->color.green * c,
			sdl->object[i]->color.blue * c, 255);
	else
		SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, 255);
	SDL_RenderDrawPoint(sdl->renderer, x, y);
}
