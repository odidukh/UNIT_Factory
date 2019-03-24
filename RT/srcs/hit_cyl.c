/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cyl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 15:38:28 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double			hit_cyl(void *obj, double *ray, double *start, t_cache *cache)
{
	double		dirc[3];
	double		k;
	double		param[3];
	double		rd;
	t_cyl		*tmp;

	tmp = (t_cyl *)obj;
	rd = vecdot(ray, tmp->dir);
	param[A] = vecdot(ray, ray) - rd * rd;
	if (start && cache)
	{
		dirc[X] = start[X] - tmp->pos[X];
		dirc[Y] = start[Y] - tmp->pos[Y];
		dirc[Z] = start[Z] - tmp->pos[Z];
		k = vecdot(tmp->dir, dirc);
		param[B] = 2.0 * (vecdot(ray, dirc) - rd * k);
		param[C] = vecdot(dirc, dirc) - k * k - tmp->radius * tmp->radius;
	}
	else
	{
		param[B] = 2.0 * (vecdot(ray, tmp->dirc) - rd * tmp->prm[0]);
		param[C] = tmp->prm[1];
	}
	return (get_min_positive_root(param[A], param[B], param[C], NULL));
}
