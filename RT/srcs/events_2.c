/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:19:20 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 15:36:53 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			free_surface(SDL_Surface **surface)
{
	if (*surface)
	{
		SDL_FreeSurface(*surface);
		*surface = NULL;
	}
}

void			free_texture(SDL_Texture **texture)
{
	if (*texture)
	{
		SDL_DestroyTexture(*texture);
		*texture = NULL;
	}
}

void			prev_button_event(t_ui_panel *p, t_info *info, SDL_Event *e)
{
	if (kiss_button_event(&p->btn_filter_prev, e, &p->is_changed))
	{
		if (info->selected_filter > 0)
		{
			info->selected_filter -= 1;
			info->is_prerendered = 1;
			info->is_at_viewport = 1;
		}
	}
}

void			next_button_event(t_ui_panel *p, t_info *info, SDL_Event *e)
{
	if (kiss_button_event(&p->btn_filter_next, e, &p->is_changed))
	{
		if (info->selected_filter < COLOR_FILTER_AMOUNT)
		{
			info->selected_filter += 1;
			info->is_prerendered = 1;
			info->is_at_viewport = 1;
		}
	}
}

void			reset_button_event(t_ui_panel *p, t_info *info, SDL_Event *e)
{
	if (kiss_button_event(&p->btn_filter_reset, e, &p->is_changed))
	{
		if (info->selected_filter)
		{
			info->selected_filter = 0;
			info->is_prerendered = 1;
			info->is_at_viewport = 1;
		}
	}
}
