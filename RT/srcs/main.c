/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:26:06 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/22 15:18:21 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void			update_screen(t_ui_panel *panel, t_info *info)
{
	unsigned int	tick[2];

	if (panel->is_valid_file)
	{
		handle_keyboard(info);
		if (info->is_at_viewport)
			handle_live_movement(info);
		if (info->is_changed)
		{
			render_scene(info, 1);
			info->is_prerendered = 1;
			tick[0] = SDL_GetTicks();
		}
		tick[1] = SDL_GetTicks();
		if (tick[1] - tick[0] > RENDER_DELAY && info->is_prerendered)
		{
			render_scene(info, 0);
			info->is_prerendered = 0;
		}
	}
	if (info->selected && info->is_changed)
		info->selected->update_entries(info->selected);
	update_all(panel, info);
	SDL_RenderPresent(info->renderer);
}

static void			loop(t_ui_panel *panel, t_info *info)
{
	int				is_running;
	SDL_Event		event;

	is_running = 1;
	while (is_running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				is_running = 0;
			handle_mouse_events(info, &event, &info->is_at_viewport);
			handle_panel_events(panel, info, &event);
		}
		update_screen(panel, info);
	}
}

static void			launch(void)
{
	SDL_Renderer	*renderer;
	t_ui_panel		panel;
	t_info			info;

	if ((renderer = kiss_init("RT - Simple ray tracer",
						&panel.objects, WIN_W, WIN_H)))
	{
		init_panel(&panel, renderer);
		init_viewport(&info, &panel.objects, renderer);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);
		loop(&panel, &info);
		kiss_clean(&panel.objects);
		kiss_clean(&panel.entries);
		kiss_clean(&panel.textures);
		free_texture(&panel.dmap_preview);
		free_texture(&panel.nmap_preview);
		clear_info(&info, 1);
	}
}

int					main(void)
{
	launch();
	system("leaks RT -quiet");
	return (0);
}
