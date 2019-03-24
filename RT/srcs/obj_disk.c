/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_disk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 11:34:58 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/21 16:29:21 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_disk			*create_disk(double *pos, double radius)
{
	t_disk		*obj;

	obj = (t_disk *)malloc(sizeof(t_disk));
	obj->dir[X] = 0;
	obj->dir[Y] = 0;
	obj->dir[Z] = 1;
	obj->pos[X] = pos[X];
	obj->pos[Y] = pos[Y];
	obj->pos[Z] = pos[Z];
	obj->pos[OX] = pos[OX] * M_PI / 180.0;
	obj->pos[OY] = pos[OY] * M_PI / 180.0;
	obj->pos[OZ] = pos[OZ] * M_PI / 180.0;
	obj->radius = radius <= PRECISION ? PRECISION : radius;
	vecrot_ox(obj->dir, obj->pos[OX], NULL);
	vecrot_oy(obj->dir, obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
	vecnorm(obj->dir);
	return (obj);
}

double			hit_disk(void *obj, double *ray, double *start, t_cache *cache)
{
	t_disk		*tmp_d;
	double		t;
	double		p_c[3];
	double		dir[3];

	tmp_d = (t_disk *)obj;
	if ((t = hit_plane(obj, ray, start, cache)) > PRECISION)
	{
		vecmult(ray, t, dir, 3);
		if (!start)
			start = cache->info->cam->pos;
		vecadd(start, dir, p_c, 3);
		vecsub(tmp_d->pos, p_c, p_c, 3);
		if (vecdot(p_c, p_c) <= tmp_d->radius * tmp_d->radius)
			return (t);
	}
	return (-1);
}

void			edit_disk(t_objlst *this)
{
	t_disk		*obj;

	obj = (t_disk *)this->obj;
	obj->dir[X] = 0;
	obj->dir[Y] = 0;
	obj->dir[Z] = 1;
	obj->pos[OX] *= M_PI / 180.0;
	obj->pos[OY] *= M_PI / 180.0;
	obj->pos[OZ] *= M_PI / 180.0;
	obj->radius = obj->radius <= PRECISION ? PRECISION : obj->radius;
	vecrot_ox(obj->dir, obj->pos[OX], NULL);
	vecrot_oy(obj->dir, obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
	clamp_obj_data(this);
}
