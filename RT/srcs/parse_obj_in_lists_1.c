/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_in_lists_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <odidukh@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:21:03 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/18 20:21:08 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				parse_cam(char *line, t_camera **cam)
{
	double			pos[6];

	sscanf(line, "%lf %lf %lf %lf %lf %lf",
		&pos[X], &pos[Y], &pos[Z], &pos[OX], &pos[OY], &pos[OZ]);
	*cam = create_camera(pos);
}

void				parse_point_light(char *line, t_ltlst **list)
{
	double			pos[6];
	double			power;

	sscanf(line, "%lf %lf %lf %lf", &pos[X], &pos[Y], &pos[Z], &power);
	ltlst_add(list, ltlst_new(TYPE_PLIGHT, pos, power));
}

void				parse_direct_light(char *line, t_ltlst **list)
{
	double			pos[6];
	double			power;

	sscanf(line, "%lf %lf %lf %lf", &pos[OX], &pos[OY], &pos[OZ], &power);
	ltlst_add(list, ltlst_new(TYPE_DLIGHT, pos, power));
}
