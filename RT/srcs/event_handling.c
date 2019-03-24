/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:17:46 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/20 17:12:51 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		handle_panel_events(t_ui_panel *p, t_info *info, SDL_Event *event)
{
	kiss_window_event(&p->panel, event, &p->is_changed);
	scene_selection_event(p, info, event);
	if (info->selected)
	{
		handle_ui(info->selected, event, &p->is_changed);
		dmap_selection_event(p, info, event);
		nmap_selection_event(p, info, event);
	}
	kiss_entry_event(&p->ent_tex_delta[X], event, &p->is_changed);
	kiss_entry_event(&p->ent_tex_delta[Y], event, &p->is_changed);
	kiss_entry_event(&p->ent_tex_angle, event, &p->is_changed);
	kiss_entry_event(&p->ent_tex_scale, event, &p->is_changed);
	if (p->is_changed && info->selected)
	{
		sscanf(p->ent_tex_delta[X].text, "%lf", &info->selected->tmapping[X]);
		sscanf(p->ent_tex_delta[Y].text, "%lf", &info->selected->tmapping[Y]);
		sscanf(p->ent_tex_angle.text, "%lf", &info->selected->tmapping[OZ]);
		sscanf(p->ent_tex_scale.text, "%lf", &info->selected->tmapping[SCALE]);
		info->selected->tmapping[OZ] *= M_PI / 180;
		if (info->selected->tmapping[SCALE] < PRECISION)
			info->selected->tmapping[SCALE] = PRECISION;
	}
	prev_button_event(p, info, event);
	next_button_event(p, info, event);
	reset_button_event(p, info, event);
}

void		handle_mouse_events(t_info *info, SDL_Event *e, int *is_at_viewport)
{
	int		pos;

	if (e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT)
	{
		if (e->button.x > PANEL_W)
		{
			pos = e->button.x + e->button.y * VPORT_W - PANEL_W;
			info->selected = info->screen_buff[pos];
			*is_at_viewport = 1;
		}
		else
			*is_at_viewport = 0;
	}
}

void		handle_live_movement(t_info *info)
{
	if ((info->delta[X] != 0 || info->delta[Y] != 0 || info->delta[Z] != 0
		|| info->delta[OX] != 0 || info->delta[OZ] != 0))
	{
		if (info->selected)
			info->selected->apply_live_changes(info->selected, info->delta);
		else
			edit_camera_live(info->cam, info->delta);
		info->is_changed = 1;
	}
}

void		handle_keyboard(t_info *info)
{
	Uint8	*s;
	double	rads;

	s = (Uint8 *)info->keystate;
	rads = M_PI / 180;
	info->delta[X] = (s[SDL_SCANCODE_D] - s[SDL_SCANCODE_A]) * MOVEMENT_SPEED;
	info->delta[Y] = (s[SDL_SCANCODE_W] - s[SDL_SCANCODE_S]) * MOVEMENT_SPEED;
	info->delta[Z] = (s[SDL_SCANCODE_SPACE] - s[SDL_SCANCODE_C])
					* MOVEMENT_SPEED;
	info->delta[OX] = (s[SDL_SCANCODE_UP] - s[SDL_SCANCODE_DOWN])
					* ROTATION_SPEED;
	info->delta[OZ] = (s[SDL_SCANCODE_LEFT] - s[SDL_SCANCODE_RIGHT])
					* ROTATION_SPEED;
	info->delta[OX] *= rads;
	info->delta[OZ] *= rads;
	if (s[SDL_SCANCODE_ESCAPE])
		info->selected = NULL;
	if (s[SDL_SCANCODE_RETURN] && info->selected)
	{
		info->selected->update_values(info->selected);
		info->is_changed = 1;
		info->is_at_viewport = 1;
	}
}
