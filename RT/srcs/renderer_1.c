/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:19:20 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 16:06:21 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void			init_unit_vec(double unit_vec[3][3])
{
	unit_vec[X][X] = 1.0;
	unit_vec[X][Y] = 0.0;
	unit_vec[X][Z] = 0.0;
	unit_vec[Y][X] = 0.0;
	unit_vec[Y][Y] = 1.0;
	unit_vec[Y][Z] = 0.0;
	unit_vec[Z][X] = 0.0;
	unit_vec[Z][Y] = 0.0;
	unit_vec[Z][Z] = 1.0;
}

void				render_scene(t_info *info, int is_prerender)
{
	t_cache			cache[THREAD_AMOUNT];
	size_t			i;
	size_t			step;

	set_obj_constants(info, info->cam->pos);
	i = -1;
	step = ceil((double)info->surface->w / THREAD_AMOUNT);
	while (++i < THREAD_AMOUNT)
	{
		init_unit_vec(cache[i].unit_vec);
		ft_memset(cache[i].norm_type, 0, sizeof(int) * MAX_OBJ_AMOUNT);
		cache[i].is_prerender = is_prerender;
		cache[i].start_x = i * step;
		cache[i].end_x = cache[i].start_x + step;
		if (cache[i].end_x >= info->surface->w)
			cache[i].end_x = info->surface->w;
		cache[i].info = info;
		pthread_create(&cache[i].thread, NULL, render_part, &cache[i]);
	}
	i = -1;
	while (++i < THREAD_AMOUNT)
		pthread_join(cache[i].thread, NULL);
	apply_color_filter(info, is_prerender);
	kiss_update_surface(info->surface, &info->canvas,
						info->karray, info->renderer);
}
