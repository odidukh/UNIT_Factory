/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 15:59:23 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static int			is_inside_triangle(t_triangle *tr, double *start,
										double t, double *ray)
{
	double			pvec[3][3];
	double			result[3][3];
	double			total;
	double			hit[3];

	hit[X] = start[X] + t * ray[X];
	hit[Y] = start[Y] + t * ray[Y];
	hit[Z] = start[Z] + t * ray[Z];
	vecsub(hit, tr->p0, pvec[0], 3);
	vecsub(hit, tr->p1, pvec[1], 3);
	vecsub(hit, tr->p2, pvec[2], 3);
	veccross(tr->edge[0], pvec[0], result[0]);
	veccross(tr->edge[1], pvec[1], result[1]);
	veccross(tr->edge[2], pvec[2], result[2]);
	total = veclen(result[0]) + veclen(result[1]) + veclen(result[2]);
	if (fabs(total - 2.0 * tr->area) < PRECISION)
		return (1);
	return (0);
}

double				hit_triangle(void *obj, double *ray,
								double *start, t_cache *cache)
{
	double			origin[3];
	t_plane			plane;
	double			t;
	t_triangle		*tr;

	tr = (t_triangle *)obj;
	if (tr->area > PRECISION)
	{
		ft_memcpy(plane.dir, tr->dir, sizeof(double) * 3);
		ft_memcpy(plane.dirc, tr->dirc, sizeof(double) * 3);
		ft_memcpy(plane.pos, tr->p0, sizeof(double) * 3);
		if ((t = hit_plane(&plane, ray, start, cache)) > PRECISION)
		{
			if (start)
				ft_memcpy(origin, start, sizeof(double) * 3);
			else
				vecsub(tr->p0, tr->dirc, origin, 3);
			if (is_inside_triangle(tr, origin, t, ray))
				return (t);
		}
	}
	return (-1.0);
}
