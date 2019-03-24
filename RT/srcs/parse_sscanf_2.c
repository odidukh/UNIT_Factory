/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sscanf_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <odidukh@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:26:48 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/18 20:29:21 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_objlst	*disk_sscanf(char *line, t_objlst *node, t_disk *tmp)
{
	unsigned int	color;
	double			reflection;
	double			transparency;
	double			ior;

	sscanf(line, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %x",
		&tmp->pos[X], &tmp->pos[Y], &tmp->pos[Z], &tmp->pos[OX],
		&tmp->pos[OY], &tmp->pos[OZ], &tmp->radius, &reflection,
		&transparency, &ior, &color);
	node = objlst_new(create_disk(tmp->pos, tmp->radius));
	node->color = color;
	node->ior = ior;
	node->reflection = reflection;
	node->transparency = transparency;
	clamp_obj_data(node);
	return (node);
}

t_objlst	*hemisphere_sscanf(char *line, t_objlst *node, t_hemisphere *tmp)
{
	unsigned int	color;
	double			reflection;
	double			transparency;
	double			ior;

	sscanf(line, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %x",
		&tmp->pos[X], &tmp->pos[Y], &tmp->pos[Z], &tmp->pos[OX],
		&tmp->pos[OY], &tmp->pos[OZ], &tmp->radius,
		&reflection, &transparency, &ior, &color);
	node = objlst_new(create_hemisphere(tmp->pos, tmp->radius));
	node->color = color;
	node->ior = ior;
	node->reflection = reflection;
	node->transparency = transparency;
	clamp_obj_data(node);
	return (node);
}

t_objlst	*sphere_sscanf(char *line, t_objlst *node, t_sphere *tmp)
{
	unsigned int	color;
	double			reflection;
	double			transparency;
	double			ior;

	sscanf(line, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %x",
		&tmp->pos[X], &tmp->pos[Y], &tmp->pos[Z], &tmp->pos[OX],
		&tmp->pos[OY], &tmp->pos[OZ], &tmp->radius,
		&reflection, &transparency, &ior, &color);
	node = objlst_new(create_sphere(tmp->pos, tmp->radius));
	node->color = color;
	node->ior = ior;
	node->reflection = reflection;
	node->transparency = transparency;
	node->obj_type = TYPE_SPHERE;
	clamp_obj_data(node);
	return (node);
}

t_objlst	*triangle_sscanf(char *line, t_objlst *node, t_triangle *tmp)
{
	unsigned int	color;
	double			reflection;
	double			transparency;
	double			ior;

	sscanf(line, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %x",
		&tmp->p0[X], &tmp->p0[Y], &tmp->p0[Z],
		&tmp->p1[X], &tmp->p1[Y], &tmp->p1[Z],
		&tmp->p2[X], &tmp->p2[Y], &tmp->p2[Z],
		&reflection, &transparency, &ior, &color);
	node = objlst_new(create_triangle(tmp->p0, tmp->p1, tmp->p2));
	node->color = color;
	node->ior = ior;
	node->reflection = reflection;
	node->transparency = transparency;
	node->obj_type = TYPE_TRIANGLE;
	clamp_obj_data(node);
	return (node);
}
