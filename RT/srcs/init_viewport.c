/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_viewport.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:19:20 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 15:59:37 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		set_color_filters(t_info *info)
{
	info->apply_filter[0] = NULL;
	info->apply_filter[1] = filter_grayscale;
	info->apply_filter[2] = filter_sepia;
	info->apply_filter[3] = filter_negative;
	info->apply_filter[4] = filter_sketch;
	info->apply_filter[5] = filter_cartoon;
}

void			init_viewport(t_info *info, kiss_array *objects,
								SDL_Renderer *renderer)
{
	kiss_window_new(&info->viewport, NULL, 0, PANEL_W, 0, VPORT_W, VPORT_H);
	info->surface = SDL_CreateRGBSurface(0, VPORT_W, VPORT_H, 32, 0, 0, 0, 0);
	clear_surface(info->surface, BCOLOR);
	info->screen_buff = (t_objlst **)ft_memalloc(sizeof(t_objlst *)
												* info->surface->w
												* info->surface->h);
	info->cam = NULL;
	info->ltlst = NULL;
	info->objlst = NULL;
	info->selected = NULL;
	info->canvas.image = NULL;
	info->karray = objects;
	kiss_update_surface(info->surface, &info->canvas, objects, renderer);
	info->keystate = SDL_GetKeyboardState(NULL);
	ft_memset(info->delta, 0, sizeof(double) * 6);
	info->renderer = renderer;
	info->is_changed = 1;
	info->is_prerendered = 0;
	info->is_at_viewport = 1;
	info->viewport.visible = 1;
	info->selected_filter = 0;
	set_color_filters(info);
}
