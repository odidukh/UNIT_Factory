/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 15:59:12 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double			hit_sphere(void *obj, double *ray,
						double *start, t_cache *cache)
{
	double		dirc[3];
	double		param[3];
	t_sphere	*tmp;

	tmp = (t_sphere *)obj;
	param[A] = vecdot(ray, ray);
	if (start && cache)
	{
		dirc[X] = start[X] - tmp->pos[X];
		dirc[Y] = start[Y] - tmp->pos[Y];
		dirc[Z] = start[Z] - tmp->pos[Z];
		param[B] = 2.0 * vecdot(dirc, ray);
		param[C] = vecdot(dirc, dirc) - tmp->radius * tmp->radius;
	}
	else
	{
		param[B] = 2.0 * vecdot(tmp->dirc, ray);
		param[C] = tmp->prm;
	}
	return (get_min_positive_root(param[A], param[B], param[C], NULL));
}
