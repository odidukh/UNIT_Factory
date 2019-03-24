/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/21 16:24:01 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				edit_mapping(double *tmap, double *raw_point)
{
	vecrot_oz(raw_point, tmap[OZ], NULL);
	raw_point[X] = fmod((raw_point[X] + tmap[X]) / tmap[SCALE], 1.0);
	raw_point[Y] = fmod((raw_point[Y] + tmap[Y]) / tmap[SCALE], 1.0);
	raw_point[X] += raw_point[X] < 0.0 ? 1.0 : 0.0;
	raw_point[Y] += raw_point[Y] < 0.0 ? 1.0 : 0.0;
}

void				get_cone_uv(t_cache *cache, double *u, double *v)
{
	t_cone			*cone;
	double			raw_point[3];

	cone = (t_cone *)cache->closest->obj;
	raw_point[X] = cache->hit[X] - cone->pos[X];
	raw_point[Y] = cache->hit[Y] - cone->pos[Y];
	raw_point[Z] = cache->hit[Z] - cone->pos[Z];
	vecrot_oz(raw_point, -cone->pos[OZ], NULL);
	vecrot_oy(raw_point, -cone->pos[OY], NULL);
	vecrot_ox(raw_point, -cone->pos[OX], NULL);
	raw_point[X] = (0.5 + atan2(raw_point[Y], raw_point[X]) / (2.0 * M_PI));
	raw_point[Y] = raw_point[Z] / 20.0;
	edit_mapping(cache->closest->tmapping, raw_point);
	*u = raw_point[X];
	*v = raw_point[Y];
}

void				get_lcone_uv(t_cache *cache, double *u, double *v)
{
	t_lcone			*cone;
	double			raw_point[3];

	cone = (t_lcone *)cache->closest->obj;
	raw_point[X] = cache->hit[X] - cone->pos[X];
	raw_point[Y] = cache->hit[Y] - cone->pos[Y];
	raw_point[Z] = cache->hit[Z] - cone->pos[Z];
	vecrot_oz(raw_point, -cone->pos[OZ], NULL);
	vecrot_oy(raw_point, -cone->pos[OY], NULL);
	vecrot_ox(raw_point, -cone->pos[OX], NULL);
	if (cache->norm_type[cone->index] == 2)
	{
		raw_point[X] *= 0.1;
		raw_point[Y] *= 0.1;
	}
	else
	{
		raw_point[X] = (0.5 + atan2(raw_point[Y], raw_point[X]) / (2.0 * M_PI));
		raw_point[Y] = raw_point[Z] / 20.0;
	}
	edit_mapping(cache->closest->tmapping, raw_point);
	*u = raw_point[X];
	*v = raw_point[Y];
}

void				get_cyl_uv(t_cache *cache, double *u, double *v)
{
	t_cyl			*cyl;
	double			raw_point[3];

	cyl = (t_cyl *)cache->closest->obj;
	raw_point[X] = cache->hit[X] - cyl->pos[X];
	raw_point[Y] = cache->hit[Y] - cyl->pos[Y];
	raw_point[Z] = cache->hit[Z] - cyl->pos[Z];
	vecrot_oz(raw_point, -cyl->pos[OZ], NULL);
	vecrot_oy(raw_point, -cyl->pos[OY], NULL);
	vecrot_ox(raw_point, -cyl->pos[OX], NULL);
	raw_point[X] = 1.0 + 2.0 * atan2(raw_point[Y], raw_point[X]) / M_PI;
	raw_point[Y] = raw_point[Z] / 10.0;
	edit_mapping(cache->closest->tmapping, raw_point);
	*u = raw_point[X];
	*v = raw_point[Y];
}

void				get_lcyl_uv(t_cache *cache, double *u, double *v)
{
	t_lcyl			*lcyl;
	double			raw_point[3];

	lcyl = (t_lcyl *)cache->closest->obj;
	raw_point[X] = cache->hit[X] - lcyl->pos[X];
	raw_point[Y] = cache->hit[Y] - lcyl->pos[Y];
	raw_point[Z] = cache->hit[Z] - lcyl->pos[Z];
	vecrot_oz(raw_point, -lcyl->pos[OZ], NULL);
	vecrot_oy(raw_point, lcyl->pos[OY], NULL);
	vecrot_ox(raw_point, lcyl->pos[OX], NULL);
	if (cache->norm_type[lcyl->index] == 2
		|| cache->norm_type[lcyl->index] == 3)
	{
		raw_point[X] *= 0.1;
		raw_point[Y] *= 0.1;
	}
	else
	{
		raw_point[X] = 1.0 + 2.0 * atan2(raw_point[Y], raw_point[X]) / M_PI;
		raw_point[Y] = raw_point[Z] / 10.0;
	}
	edit_mapping(cache->closest->tmapping, raw_point);
	*u = raw_point[X];
	*v = raw_point[Y];
}
