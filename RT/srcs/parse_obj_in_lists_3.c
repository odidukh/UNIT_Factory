/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_in_lists_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:23:50 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/20 14:52:52 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				parse_disk(char *line, t_objlst **objlst)
{
	t_objlst		*node;
	t_disk			tmp;

	node = NULL;
	node = disk_sscanf(line, node, &tmp);
	node->apply_live_changes = edit_plane_live;
	node->apply_changes = edit_disk;
	node->get_uv = get_plane_uv;
	node->init_values = define_plane_constants;
	node->is_hit = hit_disk;
	node->set_normvec = set_plane_normvec;
	node->init_ui = init_disk_ui;
	node->update_values = update_disk_values;
	node->update_entries = update_disk_entries;
	objlst_add(objlst, node);
}

void				parse_hemisphere(char *line, t_objlst **objlst)
{
	t_objlst		*node;
	t_hemisphere	tmp;

	node = NULL;
	node = hemisphere_sscanf(line, node, &tmp);
	node->apply_live_changes = edit_hemisphere_live;
	node->apply_changes = edit_hemisphere;
	node->get_uv = get_hemisphere_uv;
	node->init_values = define_hemisphere_constants;
	node->is_hit = hit_hemisphere;
	node->set_normvec = set_hemisphere_normvec;
	node->init_ui = init_hemisphere_ui;
	node->update_values = update_hemisphere_values;
	node->update_entries = update_hemisphere_entries;
	objlst_add(objlst, node);
}

void				parse_sphere(char *line, t_objlst **objlst)
{
	t_objlst		*node;
	t_sphere		tmp;

	node = NULL;
	node = sphere_sscanf(line, node, &tmp);
	node->apply_live_changes = edit_sphere_live;
	node->apply_changes = edit_sphere;
	node->get_uv = get_sphere_uv;
	node->init_values = define_sphere_constants;
	node->is_hit = hit_sphere;
	node->set_normvec = set_sphere_normvec;
	node->init_ui = init_sphere_ui;
	node->update_values = update_sphere_values;
	node->update_entries = update_sphere_entries;
	objlst_add(objlst, node);
}

void				parse_triangle(char *line, t_objlst **objlst)
{
	t_objlst		*node;
	t_triangle		tmp;

	node = NULL;
	node = triangle_sscanf(line, node, &tmp);
	node->apply_live_changes = edit_triangle_live;
	node->apply_changes = edit_triangle;
	node->get_uv = get_triangle_uv;
	node->init_values = define_triangle_constants;
	node->is_hit = hit_triangle;
	node->set_normvec = set_triangle_normvec;
	node->init_ui = init_triangle_ui;
	node->update_values = update_triangle_values;
	node->update_entries = update_triangle_entries;
	objlst_add(objlst, node);
}
