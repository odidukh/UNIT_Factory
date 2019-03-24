/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:59:00 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 18:59:30 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ft_init_sdl(t_sdl *sdl)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		sdl->window = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, W_WIDTH, W_HEIGHT, SDL_WINDOW_SHOWN);
		sdl->renderer = SDL_CreateRenderer(sdl->window,
				-1, SDL_RENDERER_ACCELERATED);
		if (sdl->window == NULL || sdl->renderer == NULL)
		{
			ft_putendl(SDL_GetError());
			exit_x(sdl);
		}
	}
	else
	{
		ft_putendl("ERROR: init_sdl()");
		ft_putendl(SDL_GetError());
		free(sdl);
		exit(1);
	}
}
