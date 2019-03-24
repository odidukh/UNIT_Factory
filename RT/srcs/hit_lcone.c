/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_lcone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/21 16:34:43 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static double	hit_cap(t_lcone *lcone, double *ray,
						double *start, t_cache *cache)
{
	t_disk		cap;
	double		dirc[3];

	if (start)
		vecsub(start, lcone->pos, dirc, 3);
	else
		ft_memcpy(dirc, lcone->dirc, sizeof(double) * 3);
	cap.dir[X] = lcone->dir[X];
	cap.dir[Y] = lcone->dir[Y];
	cap.dir[Z] = lcone->dir[Z];
	cap.pos[X] = lcone->pos[X] + cap.dir[X] * lcone->height;
	cap.pos[Y] = lcone->pos[Y] + cap.dir[Y] * lcone->height;
	cap.pos[Z] = lcone->pos[Z] + cap.dir[Z] * lcone->height;
	cap.dirc[X] = cap.pos[X] - (lcone->pos[X] + dirc[X]);
	cap.dirc[Y] = cap.pos[Y] - (lcone->pos[Y] + dirc[Y]);
	cap.dirc[Z] = cap.pos[Z] - (lcone->pos[Z] + dirc[Z]);
	cap.radius = lcone->radius;
	return (hit_disk(&cap, ray, start, cache));
}

static double	get_min_root(t_cache *cache, int lcone_index, double *roots)
{
	double			min;

	min = roots[0];
	cache->norm_type[lcone_index] = 1;
	if (roots[1] > PRECISION && (min < PRECISION || min - roots[1] > PRECISION))
		min = roots[1];
	if (roots[2] > PRECISION && (min < PRECISION || min - roots[2] > PRECISION))
	{
		min = roots[2];
		cache->norm_type[lcone_index] = 2;
	}
	return (min);
}

static void		init_values(t_lcone *lcone, double *ray,
							double *start, double *param)
{
	double		dirc[3];

	param[3] = vecdot(ray, lcone->dir);
	param[A] = vecdot(ray, ray) - lcone->prm[0] * param[3] * param[3];
	if (start)
	{
		vecsub(start, lcone->pos, dirc, 3);
		param[4] = vecdot(lcone->dir, dirc);
		param[C] = vecdot(dirc, dirc) - lcone->prm[0] * param[4] * param[4];
	}
	else
	{
		ft_memcpy(dirc, lcone->dirc, sizeof(double) * 3);
		param[4] = lcone->prm[1];
		param[C] = lcone->prm[2];
	}
	param[B] = 2.0 * (vecdot(ray, dirc) - lcone->prm[0] * param[3] * param[4]);
}

double			hit_lcone(void *obj, double *ray, double *start, t_cache *cache)
{
	double		param[5];
	t_lcone		*lcone;
	double		roots[3];
	double		m[2];

	lcone = (t_lcone *)obj;
	init_values(lcone, ray, start, param);
	if (get_min_positive_root(param[A], param[B], param[C], roots) > PRECISION)
	{
		m[0] = param[3] * roots[0] + param[4];
		m[1] = param[3] * roots[1] + param[4];
		if (m[0] < PRECISION || m[0] > lcone->height)
			roots[0] = -1.0;
		if (m[1] < PRECISION || m[1] > lcone->height)
			roots[1] = -1.0;
	}
	roots[2] = hit_cap(lcone, ray, start, cache);
	return (get_min_root(cache, lcone->index, roots));
}
