/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 16:05:34 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_plane			*create_plane(double *pos)
{
	t_plane		*obj;

	obj = (t_plane *)malloc(sizeof(t_plane));
	obj->dir[X] = 0;
	obj->dir[Y] = 0;
	obj->dir[Z] = 1;
	obj->pos[X] = pos[X];
	obj->pos[Y] = pos[Y];
	obj->pos[Z] = pos[Z];
	obj->pos[OX] = pos[OX] * M_PI / 180.0;
	obj->pos[OY] = pos[OY] * M_PI / 180.0;
	obj->pos[OZ] = pos[OZ] * M_PI / 180.0;
	vecrot_ox(obj->dir, obj->pos[OX], NULL);
	vecrot_oy(obj->dir, obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
	vecnorm(obj->dir);
	return (obj);
}

void			define_plane_constants(void *obj, double *viewpos)
{
	t_plane		*tmp;

	tmp = (t_plane *)obj;
	tmp->dirc[X] = tmp->pos[X] - viewpos[X];
	tmp->dirc[Y] = tmp->pos[Y] - viewpos[Y];
	tmp->dirc[Z] = tmp->pos[Z] - viewpos[Z];
}

void			set_plane_normvec(t_cache *cache)
{
	cache->norm[X] = ((t_plane *)cache->closest->obj)->dir[X];
	cache->norm[Y] = ((t_plane *)cache->closest->obj)->dir[Y];
	cache->norm[Z] = ((t_plane *)cache->closest->obj)->dir[Z];
	if (vecdot(cache->ray, cache->norm) > PRECISION)
	{
		cache->norm[X] = -cache->norm[X];
		cache->norm[Y] = -cache->norm[Y];
		cache->norm[Z] = -cache->norm[Z];
	}
}

void			edit_plane_live(t_objlst *this, double *delta)
{
	t_plane		*obj;

	obj = (t_plane *)this->obj;
	vecadd(obj->pos, delta, obj->pos, 6);
	obj->dir[X] = 0.0;
	obj->dir[Y] = 0.0;
	obj->dir[Z] = 1.0;
	vecrot_ox(obj->dir, obj->pos[OX], NULL);
	vecrot_oy(obj->dir, obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
}

void			edit_plane(t_objlst *this)
{
	t_plane		*obj;

	obj = (t_plane *)this->obj;
	obj->dir[X] = 0;
	obj->dir[Y] = 0;
	obj->dir[Z] = 1;
	obj->pos[OX] *= M_PI / 180.0;
	obj->pos[OY] *= M_PI / 180.0;
	obj->pos[OZ] *= M_PI / 180.0;
	vecrot_ox(obj->dir, obj->pos[OX], NULL);
	vecrot_oy(obj->dir, obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
	clamp_obj_data(this);
}
