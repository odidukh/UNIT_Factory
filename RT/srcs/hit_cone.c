/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 15:38:24 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double			hit_cone(void *obj, double *ray, double *start, t_cache *cache)
{
	double		dirc[3];
	double		k;
	double		param[3];
	double		rd;
	t_cone		*tmp;

	tmp = (t_cone *)obj;
	rd = vecdot(ray, tmp->dir);
	param[A] = vecdot(ray, ray) - tmp->prm[0] * rd * rd;
	if (start && cache)
	{
		dirc[X] = start[X] - tmp->pos[X];
		dirc[Y] = start[Y] - tmp->pos[Y];
		dirc[Z] = start[Z] - tmp->pos[Z];
		k = vecdot(tmp->dir, dirc);
		param[B] = 2.0 * (vecdot(ray, dirc) - tmp->prm[0] * rd * k);
		param[C] = vecdot(dirc, dirc) - tmp->prm[0] * k * k;
	}
	else
	{
		param[B] = 2.0 * (vecdot(ray, tmp->dirc)
				- tmp->prm[0] * rd * tmp->prm[1]);
		param[C] = tmp->prm[2];
	}
	return (get_min_positive_root(param[A], param[B], param[C], NULL));
}
