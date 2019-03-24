/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_lcyl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:25:39 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/21 17:54:45 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static double	get_min_root(t_cache *cache, int index, double *roots)
{
	double			min;

	min = roots[0];
	cache->norm_type[index] = 1;
	if (roots[1] > PRECISION && (min < PRECISION || min - roots[1] > PRECISION))
		min = roots[1];
	if (roots[2] > PRECISION && (min < PRECISION || min - roots[2] > PRECISION))
	{
		min = roots[2];
		cache->norm_type[index] = 2;
	}
	if (roots[3] > PRECISION && (min < PRECISION || min - roots[3] > PRECISION))
	{
		min = roots[3];
		cache->norm_type[index] = 3;
	}
	return (min);
}

static void		get_dirc(t_lcyl *lcyl, double *start, double *dirc)
{
	if (start)
		vecsub(start, lcyl->pos, dirc, 3);
	else
		ft_memcpy(dirc, lcyl->dirc, sizeof(double) * 3);
}

static void		init_values(t_lcyl *lcyl, double *ray,
							double *start, double *param)
{
	double		dirc[3];

	param[3] = vecdot(ray, lcyl->dir);
	param[A] = vecdot(ray, ray) - param[3] * param[3];
	if (start)
	{
		vecsub(start, lcyl->pos, dirc, 3);
		param[4] = vecdot(lcyl->dir, dirc);
		param[B] = 2.0 * (vecdot(ray, dirc) - param[3] * param[4]);
		param[C] = vecdot(dirc, dirc) - param[4] * param[4]
				- lcyl->radius * lcyl->radius;
	}
	else
	{
		ft_memcpy(dirc, lcyl->dirc, sizeof(double) * 3);
		param[B] = 2.0 * (vecdot(ray, dirc) - param[3] * lcyl->prm[0]);
		param[C] = lcyl->prm[1];
	}
}

double			hit_lcyl(void *obj, double *ray, double *start, t_cache *cache)
{
	t_lcyl		*lcyl;
	double		param[8];
	double		roots[4];
	double		m[2];
	double		vec[3];

	lcyl = (t_lcyl *)obj;
	init_values(lcyl, ray, start, param);
	if (get_min_positive_root(param[A], param[B], param[C], roots) > PRECISION)
	{
		get_dirc(lcyl, start, param + 5);
		vecmult(ray, -roots[0], vec, 3);
		vecsub(vec, param + 5, vec, 3);
		m[0] = vecdot(vec, lcyl->dir);
		if (m[0] < PRECISION || m[0] > lcyl->height)
			roots[0] = -1.0;
		vecmult(ray, -roots[1], vec, 3);
		vecsub(vec, param + 5, vec, 3);
		m[1] = vecdot(vec, lcyl->dir);
		if (m[1] < PRECISION || m[1] > lcyl->height)
			roots[1] = -1.0;
	}
	roots[2] = hit_disk(&lcyl->upper_cap, ray, start, cache);
	roots[3] = hit_disk(&lcyl->lower_cap, ray, start, cache);
	return (get_min_root(cache, lcyl->index, roots));
}
