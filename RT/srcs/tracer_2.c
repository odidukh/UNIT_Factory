/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracer_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 16:07:37 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double				get_fresnel_val(t_cache *cache, double cosi)
{
	double			cost;
	double			ior[2];
	double			rs;
	double			rp;
	double			sint;

	ior[0] = cosi < 0.0 ? 1.0 : cache->closest->ior;
	ior[1] = cosi < 0.0 ? cache->closest->ior : 1.0;
	sint = sqrt(1.0 - cosi * cosi) * ior[0] / ior[1];
	if (sint < 1.0)
	{
		cost = sqrt(1.0 - sint * sint);
		cosi = fabs(cosi);
		rs = ((ior[1] * cosi) - (ior[0] * cost))
			/ ((ior[1] * cosi) + (ior[0] * cost));
		rp = ((ior[0] * cosi) - (ior[1] * cost))
			/ ((ior[0] * cosi) + (ior[1] * cost));
		return (0.5 * (rs * rs + rp * rp));
	}
	return (1.0);
}

unsigned int		trace_refracted(t_cache *cache, double cosi,
									unsigned int depth)
{
	double			eta;
	double			k;
	double			sign;
	t_cache			tmp;

	cache_copy(&tmp, cache);
	eta = cosi < 0.0 ? 1.0 / cache->closest->ior : cache->closest->ior;
	sign = cosi < 0.0 ? 1 : -1;
	cosi = fabs(cosi);
	k = 1.0 - eta * eta * (1.0 - cosi * cosi);
	if (k < 0.0)
		return (cache->closest->color);
	tmp.ray[X] = eta * tmp.ray[X] + (eta * cosi - sqrt(k)) * tmp.norm[X] * sign;
	tmp.ray[Y] = eta * tmp.ray[Y] + (eta * cosi - sqrt(k)) * tmp.norm[Y] * sign;
	tmp.ray[Z] = eta * tmp.ray[Z] + (eta * cosi - sqrt(k)) * tmp.norm[Z] * sign;
	vecnorm(tmp.ray);
	return (apply_intensity(trace_ray(&tmp, tmp.hit, depth - 1, NULL), 0.9));
}

unsigned int		trace_reflected(t_cache *cache, double cosi,
									unsigned int depth)
{
	t_cache			tmp;

	cache_copy(&tmp, cache);
	tmp.ray[X] -= 2.0 * tmp.norm[X] * cosi;
	tmp.ray[Y] -= 2.0 * tmp.norm[Y] * cosi;
	tmp.ray[Z] -= 2.0 * tmp.norm[Z] * cosi;
	vecnorm(tmp.ray);
	return (apply_intensity(trace_ray(&tmp, tmp.hit, depth - 1, NULL), 0.8));
}

void				handle_ray_deflection(t_cache *cache, double cosi,
										unsigned int *color, int depth)
{
	double			fresnel;
	unsigned int	refl_color;
	unsigned int	refr_color;

	fresnel = get_fresnel_val(cache, cosi);
	if (cache->closest->transparency > PRECISION && depth > 0)
	{
		refr_color = mix_colors(*color, trace_refracted(cache, cosi, depth),
					cache->closest->transparency);
		refl_color = mix_colors(*color, trace_reflected(cache, cosi, depth),
					1.0 - cache->closest->transparency);
		*color = mix_colors(refr_color, refl_color, fresnel);
	}
	else if (cache->closest->reflection > PRECISION && depth > 0)
	{
		refr_color = *color;
		refl_color = mix_colors(*color, trace_reflected(cache, cosi, depth),
					cache->closest->reflection);
		*color = mix_colors(refr_color, refl_color, 1.0 - fresnel);
	}
}
