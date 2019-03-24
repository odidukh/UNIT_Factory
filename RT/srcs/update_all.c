/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:20:55 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 16:07:39 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void			ui_draw_scene_manager(t_ui_panel *p)
{
	kiss_window_draw(&p->panel, p->renderer);
	kiss_label_draw(&p->lbl_scene_manager, p->renderer);
	kiss_label_draw(&p->state_label[p->is_valid_file], p->renderer);
}

static void			ui_draw_object_editor(t_ui_panel *p, t_info *info)
{
	kiss_label_draw(&p->lbl_object_editor, p->renderer);
	if (info->selected)
		draw_ui(p->renderer, info->selected);
	kiss_combobox_draw(&p->cmb_scenes, p->renderer);
}

static void			ui_draw_texturing(t_ui_panel *p)
{
	kiss_label_draw(&p->lbl_texturing, p->renderer);
	kiss_label_draw(&p->lbl_diff_map, p->renderer);
	kiss_label_draw(&p->lbl_norm_map, p->renderer);
	if (p->dmap_preview)
		SDL_RenderCopy(p->renderer, p->dmap_preview, NULL, &p->clip_dmap);
	if (p->nmap_preview)
		SDL_RenderCopy(p->renderer, p->nmap_preview, NULL, &p->clip_nmap);
	kiss_label_draw(&p->lbl_tex_delta[X], p->renderer);
	kiss_label_draw(&p->lbl_tex_delta[Y], p->renderer);
	kiss_label_draw(&p->lbl_tex_angle, p->renderer);
	kiss_label_draw(&p->lbl_tex_scale, p->renderer);
	kiss_entry_draw(&p->ent_tex_delta[X], p->renderer);
	kiss_entry_draw(&p->ent_tex_delta[Y], p->renderer);
	kiss_entry_draw(&p->ent_tex_angle, p->renderer);
	kiss_entry_draw(&p->ent_tex_scale, p->renderer);
}

static void			ui_draw_filters(t_ui_panel *p, t_info *info)
{
	kiss_label_draw(&p->lbl_filter_title, p->renderer);
	kiss_label_draw(&p->lbl_color_filter[info->selected_filter], p->renderer);
	kiss_button_draw(&p->btn_filter_prev, p->renderer);
	kiss_button_draw(&p->btn_filter_next, p->renderer);
	kiss_button_draw(&p->btn_filter_reset, p->renderer);
	kiss_combobox_draw(&p->cmb_norm_map, p->renderer);
	kiss_combobox_draw(&p->cmb_diff_map, p->renderer);
}

void				update_all(t_ui_panel *p, t_info *info)
{
	ui_draw_scene_manager(p);
	ui_draw_object_editor(p, info);
	ui_draw_texturing(p);
	ui_draw_filters(p, info);
	kiss_window_draw(&info->viewport, info->renderer);
	kiss_renderimage(info->renderer, info->canvas, PANEL_W, 0, NULL);
	p->is_changed = 0;
	info->is_changed = 0;
}
