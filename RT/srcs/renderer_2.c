/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:19:20 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/20 14:54:33 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void			set_ray_values(t_cache *cache)
{
	cache->ray[X] = cache->offset[X] * cache->info->cam->scr_h[X]
					+ cache->offset[Y] * cache->info->cam->scr_v[X]
					+ cache->info->cam->dir[X];
	cache->ray[Y] = cache->offset[X] * cache->info->cam->scr_h[Y]
					+ cache->offset[Y] * cache->info->cam->scr_v[Y]
					+ cache->info->cam->dir[Y];
	cache->ray[Z] = cache->offset[X] * cache->info->cam->scr_h[Z]
					+ cache->offset[Y] * cache->info->cam->scr_v[Z]
					+ cache->info->cam->dir[Z];
	vecnorm(cache->ray);
}

void				launch_precalc(t_cache *cache, unsigned int x,
									unsigned int y)
{
	unsigned int	color;

	if (x % PRERENDER_RES == 0 && y % PRERENDER_RES == 0)
	{
		set_ray_values(cache);
		color = trace_ray(cache, NULL, REFL_DEPTH, NULL);
		draw_scaled_point(cache->info->surface, x, y, color);
	}
}

void				launch_fullcalc(t_cache *cache, unsigned int x,
									unsigned int y, int *is_hit)
{
	unsigned int	color;
	unsigned int	pos;

	pos = y * cache->info->surface->w + x;
	set_ray_values(cache);
	color = trace_ray(cache, NULL, REFL_DEPTH, is_hit);
	if (*is_hit)
		cache->info->screen_buff[pos] = cache->closest;
	else
		cache->info->screen_buff[pos] = NULL;
	draw_point(cache->info->surface, x, y, color);
}

void				*render_part(void *arg)
{
	int				is_hit;
	t_cache			*cache;
	int				x;
	int				y;

	cache = (t_cache *)arg;
	y = 0;
	while (y < cache->info->surface->h)
	{
		x = cache->start_x;
		cache->offset[Y] = 1.0 - (2.0 * y + cache->info->surface->w
						- cache->info->surface->h) / cache->info->surface->w;
		while (x < cache->end_x)
		{
			is_hit = 0;
			cache->offset[X] = 2.0 * x / cache->info->surface->w - 1.0;
			if (cache->is_prerender)
				launch_precalc(cache, x, y);
			else
				launch_fullcalc(cache, x, y, &is_hit);
			x += cache->is_prerender ? PRERENDER_RES : 1;
		}
		y += cache->is_prerender ? PRERENDER_RES : 1;
	}
	return (NULL);
}
