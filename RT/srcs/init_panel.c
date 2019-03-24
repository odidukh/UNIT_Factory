/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:19:20 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/22 12:50:07 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		init_scene_manager(t_ui_panel *p)
{
	kiss_label_new(&p->lbl_scene_manager, &p->panel,
					"Scene manager", 100, 15);
	kiss_array_append(&p->objects, ARRAY_TYPE, &p->entries);
	update_dirent("scenes/", &p->entries, ".json_like");
	kiss_combobox_new(&p->cmb_scenes, &p->panel,
					"none", &p->entries, UI_STEP_X, 40, 290, 22 * 5);
	kiss_label_new(&p->state_label[0], &p->panel,
					"Invalid scene file", UI_STEP_X, 75);
	kiss_label_new(&p->state_label[1], &p->panel,
					"Valid scene file", UI_STEP_X, 75);
	kiss_label_new(&p->lbl_object_editor, &p->panel,
					"Object editor", 100, 100);
}

static void		init_preview_area(SDL_Rect *dmap_area, SDL_Rect *nmap_area)
{
	dmap_area->x = 135;
	dmap_area->y = 545;
	dmap_area->w = 170;
	dmap_area->h = 170;
	nmap_area->x = 135;
	nmap_area->y = 755;
	nmap_area->w = 170;
	nmap_area->h = 170;
}

static void		init_texturing_panel(t_ui_panel *p)
{
	init_preview_area(&p->clip_dmap, &p->clip_nmap);
	kiss_label_new(&p->lbl_texturing, &p->panel, "Texturing", 120, 485);
	kiss_array_append(&p->objects, ARRAY_TYPE, &p->textures);
	update_dirent("textures/", &p->textures, ".png");
	kiss_label_new(&p->lbl_diff_map, &p->panel,
					"Diffusal map:", UI_STEP_X, 515);
	kiss_combobox_new(&p->cmb_diff_map, &p->panel,
					"none", &p->textures, 135, 510, 170, 22 * 5);
	kiss_label_new(&p->lbl_norm_map, &p->panel, "Normal map:", UI_STEP_X, 725);
	kiss_combobox_new(&p->cmb_norm_map, &p->panel,
					"none", &p->textures, 135, 720, 170, 22 * 5);
	kiss_label_new(&p->lbl_tex_delta[X], &p->panel, "dX:", UI_STEP_X, 940);
	kiss_label_new(&p->lbl_tex_delta[Y], &p->panel, "dY:", UI_STEP_X, 972);
	kiss_label_new(&p->lbl_tex_angle, &p->panel,
					"Angle:", UI_STEP_X + 135, 940);
	kiss_label_new(&p->lbl_tex_scale, &p->panel,
					"Scale:", UI_STEP_X + 135, 972);
	kiss_entry_new(&p->ent_tex_delta[X], &p->panel, 0,
					"0.00", UI_STEP_X + 27, 935, 95);
	kiss_entry_new(&p->ent_tex_delta[Y], &p->panel, 0,
					"0.00", UI_STEP_X + 27, 967, 95);
	kiss_entry_new(&p->ent_tex_angle, &p->panel, 0,
					"0.00", UI_STEP_X + 190, 935, 95);
	kiss_entry_new(&p->ent_tex_scale, &p->panel, 0,
					"1.00", UI_STEP_X + 190, 967, 95);
}

void			init_color_filters(t_ui_panel *p)
{
	kiss_label_new(&p->lbl_filter_title, &p->panel,
					"Color filter: ", UI_STEP_X, 1015);
	kiss_label_new(&p->lbl_color_filter[0], &p->panel,
					"none", UI_STEP_X + 125, 1015);
	kiss_label_new(&p->lbl_color_filter[1], &p->panel,
					"Grayscale", UI_STEP_X + 125, 1015);
	kiss_label_new(&p->lbl_color_filter[2], &p->panel,
					"Sepia", UI_STEP_X + 125, 1015);
	kiss_label_new(&p->lbl_color_filter[3], &p->panel,
					"Negative", UI_STEP_X + 125, 1015);
	kiss_label_new(&p->lbl_color_filter[4], &p->panel,
					"Grayscale Sketch", UI_STEP_X + 125, 1015);
	kiss_label_new(&p->lbl_color_filter[5], &p->panel,
					"Colored Sketch", UI_STEP_X + 125, 1015);
	kiss_button_new(&p->btn_filter_prev, &p->panel,
					"Previous", UI_STEP_X + 35, 1040);
	kiss_button_new(&p->btn_filter_next, &p->panel,
					"Next", UI_STEP_X + 35 + 80, 1040);
	kiss_button_new(&p->btn_filter_reset, &p->panel,
					"Reset", UI_STEP_X + 35 + 160, 1040);
}

void			init_panel(t_ui_panel *panel, SDL_Renderer *renderer)
{
	kiss_array_new(&panel->entries);
	kiss_array_new(&panel->textures);
	kiss_window_new(&panel->panel, NULL, 1, 0, 0, PANEL_W, PANEL_H);
	init_scene_manager(panel);
	init_texturing_panel(panel);
	init_color_filters(panel);
	panel->renderer = renderer;
	panel->dmap_preview = NULL;
	panel->nmap_preview = NULL;
	panel->is_changed = 1;
	panel->is_valid_file = 0;
	panel->panel.visible = 1;
}
