/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_in_lists_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:22:47 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/20 14:52:13 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				parse_cone(char *line, t_objlst **objlst)
{
	t_objlst		*node;
	t_cone			tmp;

	node = NULL;
	node = cone_sscanf(line, node, &tmp);
	node->apply_live_changes = edit_cone_live;
	node->apply_changes = edit_cone;
	node->get_uv = get_cone_uv;
	node->init_values = define_cone_constants;
	node->is_hit = hit_cone;
	node->set_normvec = set_cone_normvec;
	node->init_ui = init_cone_ui;
	node->update_values = update_cone_values;
	node->update_entries = update_cone_entries;
	objlst_add(objlst, node);
}

void				parse_lcone(char *line, t_objlst **objlst)
{
	t_objlst		*node;
	t_lcone			tmp;

	node = NULL;
	node = lcone_sscanf(line, node, &tmp);
	node->apply_live_changes = edit_lcone_live;
	node->apply_changes = edit_lcone;
	node->get_uv = get_lcone_uv;
	node->init_values = define_lcone_constants;
	node->is_hit = hit_lcone;
	node->set_normvec = set_lcone_normvec;
	node->init_ui = init_lcone_ui;
	node->update_values = update_lcone_values;
	node->update_entries = update_lcone_entries;
	objlst_add(objlst, node);
}

void				parse_cyl(char *line, t_objlst **objlst)
{
	t_objlst		*node;
	t_cyl			tmp;

	node = NULL;
	node = cyl_sscanf(line, node, &tmp);
	node->apply_live_changes = edit_cyl_live;
	node->apply_changes = edit_cyl;
	node->get_uv = get_cyl_uv;
	node->init_values = define_cyl_constants;
	node->is_hit = hit_cyl;
	node->set_normvec = set_cyl_normvec;
	node->init_ui = init_cyl_ui;
	node->update_values = update_cyl_values;
	node->update_entries = update_cyl_entries;
	objlst_add(objlst, node);
}

void				parse_lim_cyl(char *line, t_objlst **objlst)
{
	t_objlst		*node;
	t_lcyl			tmp;

	node = NULL;
	node = lim_cyl_sscanf(line, node, &tmp);
	node->apply_live_changes = edit_lcyl_live;
	node->apply_changes = edit_lcyl;
	node->get_uv = get_lcyl_uv;
	node->init_values = define_lcyl_constants;
	node->is_hit = hit_lcyl;
	node->set_normvec = set_lcyl_normvec;
	node->init_ui = init_lcyl_ui;
	node->update_values = update_lcyl_values;
	node->update_entries = update_lcyl_entries;
	objlst_add(objlst, node);
}

void				parse_plane(char *line, t_objlst **objlst)
{
	t_objlst		*node;
	t_plane			tmp;

	node = NULL;
	node = plane_sscanf(line, node, &tmp);
	node->apply_live_changes = edit_plane_live;
	node->apply_changes = edit_plane;
	node->get_uv = get_plane_uv;
	node->init_values = define_plane_constants;
	node->is_hit = hit_plane;
	node->set_normvec = set_plane_normvec;
	node->init_ui = init_plane_ui;
	node->update_values = update_plane_values;
	node->update_entries = update_plane_entries;
	objlst_add(objlst, node);
}
