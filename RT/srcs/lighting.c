/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/20 14:48:52 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static int			is_shaded(t_cache *cache, double *ray,
							double max_t, double *refr_factor)
{
	double			t;
	t_objlst		*list;

	list = cache->info->objlst;
	while (list)
	{
		t = list->is_hit(list->obj, ray, cache->hit, cache);
		if (t > PRECISION && t < max_t - PRECISION)
		{
			if (refr_factor && list->transparency > 0.0)
				*refr_factor *= list->transparency * 0.9;
			else
				return (1);
		}
		list = list->next;
	}
	return (0);
}

static double		check_shading(t_ltlst *lsrc, t_cache *cache,
									double cosi, double *lray)
{
	double			tfactor;
	double			max_dist;
	double			l_dot_n;

	tfactor = 1.0;
	max_dist = T_MAX;
	if (lsrc->type == TYPE_PLIGHT)
	{
		vecsub(lsrc->pos, cache->hit, lray, 3);
		max_dist = veclen(lray);
	}
	else
	{
		lray[X] = -lsrc->dir[X];
		lray[Y] = -lsrc->dir[Y];
		lray[Z] = -lsrc->dir[Z];
	}
	vecnorm(lray);
	l_dot_n = vecdot(lray, cache->norm);
	if (max_dist > PRECISION && ((l_dot_n > PRECISION && cosi < PRECISION)
		|| (l_dot_n < PRECISION && cosi > PRECISION)))
		if (!is_shaded(cache, lray, max_dist, &tfactor))
			return (tfactor);
	return (-1.0);
}

double				get_diff_intensity(t_cache *cache, double cosi)
{
	double			l_dot_n;
	double			intensity;
	double			lray[3];
	t_ltlst			*lsrc;
	double			tfactor;

	intensity = AMBIENCE_LIGHT;
	lsrc = cache->info->ltlst;
	while (lsrc)
	{
		if ((tfactor = check_shading(lsrc, cache, cosi, lray)) > PRECISION)
		{
			l_dot_n = fabs(vecdot(lray, cache->norm));
			intensity += tfactor * lsrc->power * l_dot_n;
		}
		lsrc = lsrc->next;
	}
	return (intensity);
}

double				get_spec_intensity(t_cache *cache, double cosi)
{
	double			dot;
	double			k[2];
	double			intensity;
	double			lray[3];
	t_ltlst			*lsrc;

	intensity = 0.0;
	k[0] = cache->closest->reflection + cache->closest->transparency;
	if (k[0] < PRECISION)
		return (intensity);
	lsrc = cache->info->ltlst;
	while (lsrc)
	{
		if ((k[1] = check_shading(lsrc, cache, cosi, lray)) > PRECISION)
		{
			dot = fabs(vecdot(lray, cache->norm));
			lray[X] -= 2.0 * cache->norm[X] * dot;
			lray[Y] -= 2.0 * cache->norm[Y] * dot;
			lray[Z] -= 2.0 * cache->norm[Z] * dot;
			if ((dot = vecdot(lray, cache->ray)) > PRECISION)
				intensity += k[1] * lsrc->power * pow(dot, 100.0 * k[0]);
		}
		lsrc = lsrc->next;
	}
	return (intensity);
}
