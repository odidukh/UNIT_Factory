/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:57:08 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 18:58:32 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		main(int argc, char **argv)
{
	t_sdl		*sdl;

	if (test_argv(argc, argv))
		return (0);
	sdl = ft_memalloc(sizeof(t_sdl));
	ft_init_sdl(sdl);
	parser(sdl, argv[1]);
	ray_tracer(sdl);
	SDL_RenderPresent(sdl->renderer);
	event_catch();
	exit_x(sdl);
	return (0);
}
