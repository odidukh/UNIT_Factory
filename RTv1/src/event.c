/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:52:58 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 19:53:10 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	free_str_array(t_sdl *sdl, char **str_array, int alert)
{
	char	**temp;

	temp = str_array;
	while (*str_array)
	{
		free(*str_array++);
	}
	free(temp);
	if (alert)
		exit_x(sdl);
}

void	free_objects(t_sdl *sdl)
{
	int	i;

	i = 0;
	while (i < sdl->light_number)
		free(sdl->light[i++]);
	free(sdl->light);
	i = 0;
	while (i < sdl->object_number)
		free(sdl->object[i++]);
	free(sdl->object);
}

int		test_argv(int argc, char **argv)
{
	int			fd;
	struct stat	sb;

	if (argc != 2)
	{
		ft_putendl("ERROR: wrong number of arguments");
		return (1);
	}
	if (stat(argv[1], &sb) == 0 && S_ISDIR(sb.st_mode))
	{
		ft_putendl("ERROR: file is directory");
		return (1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putendl("ERROR: file does not exist");
		return (1);
	}
	close(fd);
	return (0);
}

void	exit_x(t_sdl *sdl)
{
	SDL_RenderClear(sdl->renderer);
	SDL_DestroyWindow(sdl->window);
	SDL_Quit();
	free(sdl);
	exit(1);
}

void	event_catch(void)
{
	SDL_Event	event;
	int			running;

	running = 1;
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if ((SDL_QUIT == event.type)
				|| (SDL_KEYDOWN == event.type
					&& SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
				running = 0;
		}
	}
}
