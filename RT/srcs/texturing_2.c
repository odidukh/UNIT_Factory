/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturing_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 16:06:40 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				get_hemisphere_uv(t_cache *cache, double *u, double *v)
{
	t_hemisphere	*hsph;
	double			raw_point[3];

	hsph = (t_hemisphere *)cache->closest->obj;
	raw_point[X] = cache->hit[X] - hsph->pos[X];
	raw_point[Y] = cache->hit[Y] - hsph->pos[Y];
	raw_point[Z] = cache->hit[Z] - hsph->pos[Z];
	vecrot_oz(raw_point, -hsph->pos[OZ], NULL);
	vecrot_oy(raw_point, -hsph->pos[OY], NULL);
	vecrot_ox(raw_point, -hsph->pos[OX], NULL);
	if (cache->norm_type[hsph->index] == 2)
	{
		raw_point[X] *= 0.1;
		raw_point[Y] *= 0.1;
	}
	else if (cache->norm_type[hsph->index] == 1)
	{
		vecnorm(raw_point);
		raw_point[X] = 0.5 + atan2(raw_point[Y], raw_point[X]) / (2.0 * M_PI);
		raw_point[Y] = 0.5 - asin(raw_point[Z]) / M_PI;
	}
	edit_mapping(cache->closest->tmapping, raw_point);
	*u = raw_point[X];
	*v = raw_point[Y];
}

void				get_plane_uv(t_cache *cache, double *u, double *v)
{
	t_plane			*plane;
	double			raw_point[3];

	plane = (t_plane *)cache->closest->obj;
	raw_point[X] = cache->hit[X] - plane->pos[X];
	raw_point[Y] = cache->hit[Y] - plane->pos[Y];
	raw_point[Z] = cache->hit[Z] - plane->pos[Z];
	vecrot_oz(raw_point, -plane->pos[OZ], NULL);
	vecrot_oy(raw_point, -plane->pos[OY], NULL);
	vecrot_ox(raw_point, -plane->pos[OX], NULL);
	raw_point[X] *= 0.1;
	raw_point[Y] *= 0.1;
	edit_mapping(cache->closest->tmapping, raw_point);
	*u = raw_point[X];
	*v = raw_point[Y];
}

void				get_sphere_uv(t_cache *cache, double *u, double *v)
{
	double			raw_point[3];
	t_sphere		*sphere;

	sphere = (t_sphere *)cache->closest->obj;
	raw_point[X] = cache->hit[X] - sphere->pos[X];
	raw_point[Y] = cache->hit[Y] - sphere->pos[Y];
	raw_point[Z] = cache->hit[Z] - sphere->pos[Z];
	vecrot_oz(raw_point, -sphere->pos[OZ], NULL);
	vecrot_oy(raw_point, -sphere->pos[OY], NULL);
	vecrot_ox(raw_point, -sphere->pos[OX], NULL);
	vecnorm(raw_point);
	raw_point[X] = 0.5 + atan2(raw_point[Y], raw_point[X]) / (2.0 * M_PI);
	raw_point[Y] = 0.5 - asin(raw_point[Z]) / M_PI;
	edit_mapping(cache->closest->tmapping, raw_point);
	*u = raw_point[X];
	*v = raw_point[Y];
}

void				get_triangle_uv(t_cache *cache, double *u, double *v)
{
	t_triangle		*tr;
	double			raw_point[3];
	double			len;
	double			cosi;

	tr = (t_triangle *)cache->closest->obj;
	raw_point[X] = cache->hit[X] - tr->p0[X];
	raw_point[Y] = cache->hit[Y] - tr->p0[Y];
	raw_point[Z] = cache->hit[Z] - tr->p0[Z];
	len = veclen(raw_point);
	cosi = vecdot(raw_point, tr->edge[0]) / (veclen(tr->edge[0]) * len);
	raw_point[X] = 0.1 * len * cosi;
	raw_point[Y] = 0.1 * len * sqrt(1 - cosi * cosi);
	edit_mapping(cache->closest->tmapping, raw_point);
	*u = raw_point[X];
	*v = raw_point[Y];
}
