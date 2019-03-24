/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/20 14:56:17 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_objlst		*get_closest_obj(t_cache *cache, double *start,
									double *ray, double *t)
{
	double			min_t;
	double			tmp_t;
	t_objlst		*closest;
	t_objlst		*tmplst;

	min_t = -1.0;
	tmp_t = -1.0;
	closest = NULL;
	tmplst = cache->info->objlst;
	while (tmplst)
	{
		tmp_t = tmplst->is_hit(tmplst->obj, ray, start, cache);
		if ((tmp_t > PRECISION && min_t - tmp_t > PRECISION)
			|| (min_t < PRECISION && tmp_t > PRECISION))
		{
			min_t = tmp_t;
			closest = tmplst;
		}
		tmplst = tmplst->next;
	}
	if (closest)
		*t = min_t;
	return (closest);
}

static void			modify_normvec(t_cache *cache, double u, double v)
{
	t_plane			*obj;
	double			raw_n[3];
	double			t[3];
	double			b[3];
	double			n[3];

	obj = (t_plane *)cache->closest->obj;
	get_norm_from_map(raw_n, get_texture_color(cache->closest->norm_map, u, v));
	ft_memcpy(n, cache->norm, sizeof(double) * 3);
	veccross(n, obj->dir, t);
	if (veclen(t) < PRECISION)
	{
		ft_memcpy(t, cache->unit_vec[Y], sizeof(double) * 3);
		vecrot_ox(t, obj->pos[OX], NULL);
		vecrot_oy(t, obj->pos[OY], NULL);
		vecrot_oz(t, obj->pos[OZ], NULL);
		veccross(n, t, t);
	}
	vecnorm(t);
	veccross(t, n, b);
	vecnorm(b);
	cache->norm[X] = t[X] * raw_n[X] + b[X] * raw_n[Y] + n[X] * raw_n[Z];
	cache->norm[Y] = t[Y] * raw_n[X] + b[Y] * raw_n[Y] + n[Y] * raw_n[Z];
	cache->norm[Z] = t[Z] * raw_n[X] + b[Z] * raw_n[Y] + n[Z] * raw_n[Z];
	vecnorm(cache->norm);
}

static void			get_obj_color(t_cache *cache, double *cosi,
							unsigned int *color, unsigned int *shine)
{
	double			u;
	double			v;
	double			diff_intensity;
	double			spec_intensity;

	if (cache->closest->diff_map || cache->closest->norm_map)
		cache->closest->get_uv(cache, &u, &v);
	if (cache->closest->diff_map)
		*color = get_texture_color(cache->closest->diff_map, u, v);
	else
		*color = cache->closest->color;
	cache->closest->set_normvec(cache);
	if (cache->closest->norm_map)
		modify_normvec(cache, u, v);
	*cosi = vecdot(cache->ray, cache->norm);
	diff_intensity = get_diff_intensity(cache, *cosi);
	spec_intensity = get_spec_intensity(cache, *cosi);
	*color = apply_intensity(*color, diff_intensity);
	*shine = apply_intensity(0x888888, spec_intensity);
}

unsigned int		trace_ray(t_cache *cache, double *start,
								unsigned int depth, int *is_hit)
{
	unsigned int	local_color;
	unsigned int	shine;
	double			cosi;

	if ((cache->closest = get_closest_obj(cache, start, cache->ray, &cache->t)))
	{
		if (is_hit)
			*is_hit = 1;
		if (!start)
			start = cache->info->cam->pos;
		cache->hit[X] = start[X] + cache->t * cache->ray[X];
		cache->hit[Y] = start[Y] + cache->t * cache->ray[Y];
		cache->hit[Z] = start[Z] + cache->t * cache->ray[Z];
		get_obj_color(cache, &cosi, &local_color, &shine);
		handle_ray_deflection(cache, cosi, &local_color, depth);
		return (add_colors(local_color, shine));
	}
	return (BCOLOR);
}
