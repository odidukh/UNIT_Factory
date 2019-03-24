/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_hemisphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <odidukh@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:08:10 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/18 20:08:24 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static	double	hit_hemisphere_disk(t_hemisphere *hemi,
	double *ray, double *start, t_cache *cache)
{
	t_disk			disk;
	double			t_dis;

	ft_memcpy(disk.dir, hemi->dir, sizeof(double) * 3);
	disk.dirc[X] = -hemi->dirc[X];
	disk.dirc[Y] = -hemi->dirc[Y];
	disk.dirc[Z] = -hemi->dirc[Z];
	ft_memcpy(disk.pos, hemi->pos, sizeof(double) * 6);
	disk.radius = hemi->radius;
	t_dis = hit_disk((void *)&disk, ray, start, cache);
	return (t_dis);
}

static	double	hit_hemisphere_sphere(t_hemisphere *hemi,
	double *ray, double *start, t_cache *cache)
{
	t_sphere		sphere;
	double			t_sph;

	ft_memcpy(sphere.dirc, hemi->dirc, sizeof(double) * 3);
	ft_memcpy(sphere.pos, hemi->pos, sizeof(double) * 6);
	sphere.radius = hemi->radius;
	sphere.prm = hemi->prm;
	t_sph = hit_sphere((void *)&sphere, ray, start, cache);
	return (t_sph);
}

double			hit_hemisphere(void *obj, double *ray,
						double *start, t_cache *cache)
{
	t_hemisphere	*hemi;
	double			t_sph;
	double			t_dis;
	double			vec[3];
	double			dirc[3];

	hemi = (t_hemisphere *)obj;
	t_dis = hit_hemisphere_disk(hemi, ray, start, cache);
	t_sph = hit_hemisphere_sphere(hemi, ray, start, cache);
	if (!start)
		start = cache->info->cam->pos;
	vec[X] = start[X] + t_sph * ray[X];
	vec[Y] = start[Y] + t_sph * ray[Y];
	vec[Z] = start[Z] + t_sph * ray[Z];
	vecsub(start, hemi->pos, dirc, 3);
	vecsub(hemi->pos, vec, vec, 3);
	if ((veclen(dirc) < hemi->radius && vecdot(hemi->dir, dirc) > PRECISION)
		|| vecdot(hemi->dir, vec) < PRECISION)
	{
		cache->norm_type[hemi->index] = 2;
		return (t_dis);
	}
	cache->norm_type[hemi->index] = 1;
	return (t_sph);
}
