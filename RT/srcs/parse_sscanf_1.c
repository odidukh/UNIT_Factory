/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sscanf_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:26:40 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/21 16:23:42 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_objlst			*cone_sscanf(char *line, t_objlst *node, t_cone *tmp)
{
	unsigned int	color;
	double			reflection;
	double			transparency;
	double			ior;

	sscanf(line, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %x",
		&tmp->pos[X], &tmp->pos[Y], &tmp->pos[Z], &tmp->pos[OX],
		&tmp->pos[OY], &tmp->pos[OZ], &tmp->angle, &reflection,
		&transparency, &ior, &color);
	node = objlst_new(create_cone(tmp->pos, tmp->angle));
	node->color = color;
	node->ior = ior;
	node->reflection = reflection;
	node->transparency = transparency;
	node->obj_type = TYPE_CONE;
	clamp_obj_data(node);
	return (node);
}

t_objlst			*lcone_sscanf(char *line, t_objlst *node, t_lcone *tmp)
{
	unsigned int	color;
	double			reflection;
	double			transparency;
	double			ior;

	sscanf(line, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %x",
		&tmp->pos[X], &tmp->pos[Y], &tmp->pos[Z], &tmp->pos[OX],
		&tmp->pos[OY], &tmp->pos[OZ], &tmp->radius, &tmp->height,
		&reflection, &transparency, &ior, &color);
	node = objlst_new(create_lcone(tmp->pos, tmp->radius, tmp->height));
	node->color = color;
	node->ior = ior;
	node->reflection = reflection;
	node->transparency = transparency;
	node->obj_type = TYPE_LCONE;
	clamp_obj_data(node);
	return (node);
}

t_objlst			*cyl_sscanf(char *line, t_objlst *node, t_cyl *tmp)
{
	unsigned int	color;
	double			reflection;
	double			transparency;
	double			ior;

	sscanf(line, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %x",
		&tmp->pos[X], &tmp->pos[Y], &tmp->pos[Z], &tmp->pos[OX],
		&tmp->pos[OY], &tmp->pos[OZ], &tmp->radius,
		&reflection, &transparency, &ior, &color);
	node = objlst_new(create_cyl(tmp->pos, tmp->radius));
	node->color = color;
	node->ior = ior;
	node->reflection = reflection;
	node->transparency = transparency;
	node->obj_type = TYPE_CYL;
	clamp_obj_data(node);
	return (node);
}

t_objlst			*lim_cyl_sscanf(char *line, t_objlst *node, t_lcyl *tmp)
{
	unsigned int	color;
	double			reflection;
	double			transparency;
	double			ior;

	sscanf(line, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %x",
		&tmp->pos[X], &tmp->pos[Y], &tmp->pos[Z],
		&tmp->pos[OX], &tmp->pos[OY], &tmp->pos[OZ],
		&tmp->radius, &tmp->height, &reflection, &transparency,
		&ior, &color);
	node = objlst_new(create_lcyl(tmp->pos, tmp->radius, tmp->height));
	node->color = color;
	node->ior = ior;
	node->reflection = reflection;
	node->transparency = transparency;
	node->obj_type = TYPE_LCYL;
	clamp_obj_data(node);
	return (node);
}

t_objlst			*plane_sscanf(char *line, t_objlst *node, t_plane *tmp)
{
	unsigned int	color;
	double			reflection;
	double			transparency;
	double			ior;

	sscanf(line, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %x",
		&tmp->pos[X], &tmp->pos[Y], &tmp->pos[Z], &tmp->pos[OX],
		&tmp->pos[OY], &tmp->pos[OZ], &reflection, &transparency, &ior, &color);
	node = objlst_new(create_plane(tmp->pos));
	node->color = color;
	node->ior = ior;
	node->reflection = reflection;
	node->transparency = transparency;
	node->obj_type = TYPE_PLANE;
	clamp_obj_data(node);
	return (node);
}
