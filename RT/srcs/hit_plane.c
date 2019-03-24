/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 15:59:06 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

double			hit_plane(void *obj, double *ray, double *start, t_cache *cache)
{
	double		dirc[3];
	double		k;
	double		nbr;
	t_plane		*tmp;

	tmp = (t_plane *)obj;
	nbr = vecdot(tmp->dir, ray);
	if (!nbr)
		return (-1.0);
	if (start && cache)
	{
		dirc[X] = tmp->pos[X] - start[X];
		dirc[Y] = tmp->pos[Y] - start[Y];
		dirc[Z] = tmp->pos[Z] - start[Z];
		k = vecdot(tmp->dir, dirc);
	}
	else
		k = vecdot(tmp->dir, tmp->dirc);
	return (k / nbr);
}
