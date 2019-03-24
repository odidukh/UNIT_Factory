/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_ui_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:34:58 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 16:06:15 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void		init_labels(t_ui_panel *panel, t_objlst *selected)
{
	kiss_label_new(&selected->labels[4], &panel->panel, "X1:",
					UI_STEP_X, UI_Y + 5 * UI_STEP_Y);
	kiss_label_new(&selected->labels[5], &panel->panel, "Y1:",
					UI_STEP_X, UI_Y + 6 * UI_STEP_Y);
	kiss_label_new(&selected->labels[6], &panel->panel, "Z1:",
					UI_STEP_X, UI_Y + 7 * UI_STEP_Y);
	kiss_label_new(&selected->labels[7], &panel->panel, "X2:",
					UI_STEP_X + 150, UI_Y + 5 * UI_STEP_Y);
	kiss_label_new(&selected->labels[8], &panel->panel, "Y2:",
					UI_STEP_X + 150, UI_Y + 6 * UI_STEP_Y);
	kiss_label_new(&selected->labels[9], &panel->panel, "Z2:",
					UI_STEP_X + 150, UI_Y + 7 * UI_STEP_Y);
	kiss_label_new(&selected->labels[10], &panel->panel, "X3:",
					UI_STEP_X, UI_Y + 8 * UI_STEP_Y);
	kiss_label_new(&selected->labels[11], &panel->panel, "Y3:",
					UI_STEP_X, UI_Y + 9 * UI_STEP_Y);
	kiss_label_new(&selected->labels[12], &panel->panel, "Z3:",
					UI_STEP_X, UI_Y + 10 * UI_STEP_Y);
}

static void		init_entries(t_ui_panel *panel, t_objlst *selected)
{
	kiss_entry_new(&selected->entries[4], &panel->panel, 0, "",
					UI_STEP_X + 20, UI_Y + 5 * UI_STEP_Y - 5, 95);
	kiss_entry_new(&selected->entries[5], &panel->panel, 0, "",
					UI_STEP_X + 20, UI_Y + 6 * UI_STEP_Y - 5, 95);
	kiss_entry_new(&selected->entries[6], &panel->panel, 0, "",
					UI_STEP_X + 20, UI_Y + 7 * UI_STEP_Y - 5, 95);
	kiss_entry_new(&selected->entries[7], &panel->panel, 0, "",
					UI_STEP_X + 180, UI_Y + 5 * UI_STEP_Y - 5, 95);
	kiss_entry_new(&selected->entries[8], &panel->panel, 0, "",
					UI_STEP_X + 180, UI_Y + 6 * UI_STEP_Y - 5, 95);
	kiss_entry_new(&selected->entries[9], &panel->panel, 0, "",
					UI_STEP_X + 180, UI_Y + 7 * UI_STEP_Y - 5, 95);
	kiss_entry_new(&selected->entries[10], &panel->panel, 0, "",
					UI_STEP_X + 20, UI_Y + 8 * UI_STEP_Y - 5, 95);
	kiss_entry_new(&selected->entries[11], &panel->panel, 0, "",
					UI_STEP_X + 20, UI_Y + 9 * UI_STEP_Y - 5, 95);
	kiss_entry_new(&selected->entries[12], &panel->panel, 0, "",
					UI_STEP_X + 20, UI_Y + 10 * UI_STEP_Y - 5, 95);
}

void			init_triangle_ui(t_ui_panel *panel, t_objlst *selected)
{
	selected->ui_form_amount = 13;
	kiss_label_new(&selected->title, &panel->panel, "Triangle",
					UI_STEP_X, UI_Y);
	kiss_label_new(&selected->labels[0], &panel->panel, "Color:",
					UI_STEP_X, UI_Y + 1 * UI_STEP_Y);
	kiss_label_new(&selected->labels[1], &panel->panel, "IOR:",
					UI_STEP_X, UI_Y + 2 * UI_STEP_Y);
	kiss_label_new(&selected->labels[2], &panel->panel, "Reflectivity:",
					UI_STEP_X, UI_Y + 3 * UI_STEP_Y);
	kiss_label_new(&selected->labels[3], &panel->panel, "Transparency:",
					UI_STEP_X, UI_Y + 4 * UI_STEP_Y);
	init_labels(panel, selected);
	kiss_entry_new(&selected->entries[0], &panel->panel, 0, "",
					UI_STEP_X + 180, UI_Y + 1 * UI_STEP_Y - 5, 95);
	kiss_entry_new(&selected->entries[1], &panel->panel, 0, "",
					UI_STEP_X + 180, UI_Y + 2 * UI_STEP_Y - 5, 95);
	kiss_entry_new(&selected->entries[2], &panel->panel, 0, "",
					UI_STEP_X + 180, UI_Y + 3 * UI_STEP_Y - 5, 95);
	kiss_entry_new(&selected->entries[3], &panel->panel, 0, "",
					UI_STEP_X + 180, UI_Y + 4 * UI_STEP_Y - 5, 95);
	init_entries(panel, selected);
	update_triangle_entries(selected);
}

void			update_triangle_values(t_objlst *selected)
{
	t_triangle	*obj;

	obj = (t_triangle *)selected->obj;
	sscanf(selected->entries[0].text, "%x", &selected->color);
	sscanf(selected->entries[1].text, "%lf", &selected->ior);
	sscanf(selected->entries[2].text, "%lf", &selected->reflection);
	sscanf(selected->entries[3].text, "%lf", &selected->transparency);
	sscanf(selected->entries[4].text, "%lf", &obj->p0[X]);
	sscanf(selected->entries[5].text, "%lf", &obj->p0[Y]);
	sscanf(selected->entries[6].text, "%lf", &obj->p0[Z]);
	sscanf(selected->entries[7].text, "%lf", &obj->p1[X]);
	sscanf(selected->entries[8].text, "%lf", &obj->p1[Y]);
	sscanf(selected->entries[9].text, "%lf", &obj->p1[Z]);
	sscanf(selected->entries[10].text, "%lf", &obj->p2[X]);
	sscanf(selected->entries[11].text, "%lf", &obj->p2[Y]);
	sscanf(selected->entries[12].text, "%lf", &obj->p2[Z]);
	edit_triangle(selected);
}

void			update_triangle_entries(t_objlst *selected)
{
	t_triangle	*obj;

	obj = (t_triangle *)selected->obj;
	sprintf(selected->entries[0].text, "%#6x", selected->color);
	sprintf(selected->entries[1].text, "%.2lf", selected->ior);
	sprintf(selected->entries[2].text, "%.2lf", selected->reflection);
	sprintf(selected->entries[3].text, "%.2lf", selected->transparency);
	sprintf(selected->entries[4].text, "%.2lf", obj->p0[X]);
	sprintf(selected->entries[5].text, "%.2lf", obj->p0[Y]);
	sprintf(selected->entries[6].text, "%.2lf", obj->p0[Z]);
	sprintf(selected->entries[7].text, "%.2lf", obj->p1[X]);
	sprintf(selected->entries[8].text, "%.2lf", obj->p1[Y]);
	sprintf(selected->entries[9].text, "%.2lf", obj->p1[Z]);
	sprintf(selected->entries[10].text, "%.2lf", obj->p2[X]);
	sprintf(selected->entries[11].text, "%.2lf", obj->p2[Y]);
	sprintf(selected->entries[12].text, "%.2lf", obj->p2[Z]);
}
