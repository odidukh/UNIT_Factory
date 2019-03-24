/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_hemisphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <odidukh@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:10:17 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/18 20:11:12 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_hemisphere		*create_hemisphere(double *pos, double radius)
{
	t_hemisphere	*obj;

	obj = (t_hemisphere *)malloc(sizeof(t_hemisphere));
	obj->pos[X] = pos[X];
	obj->pos[Y] = pos[Y];
	obj->pos[Z] = pos[Z];
	obj->dir[X] = 0.0;
	obj->dir[Y] = 0.0;
	obj->dir[Z] = -1.0;
	obj->pos[OX] = pos[OX] * M_PI / 180.0;
	obj->pos[OY] = pos[OY] * M_PI / 180.0;
	obj->pos[OZ] = pos[OZ] * M_PI / 180.0;
	vecrot_ox(obj->dir, obj->pos[OX], NULL);
	vecrot_oy(obj->dir, obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
	obj->radius = radius <= PRECISION ? PRECISION : radius;
	return (obj);
}

void				define_hemisphere_constants(void *obj, double *viewpos)
{
	t_hemisphere	*tmp;

	tmp = (t_hemisphere *)obj;
	tmp->dirc[X] = viewpos[X] - tmp->pos[X];
	tmp->dirc[Y] = viewpos[Y] - tmp->pos[Y];
	tmp->dirc[Z] = viewpos[Z] - tmp->pos[Z];
	tmp->prm = vecdot(tmp->dirc, tmp->dirc) - tmp->radius * tmp->radius;
}

void				set_hemisphere_normvec(t_cache *cache)
{
	t_hemisphere *hsph;

	hsph = (t_hemisphere *)cache->closest->obj;
	if (cache->norm_type[hsph->index] == 1)
	{
		cache->norm[X] = cache->hit[X] - hsph->pos[X];
		cache->norm[Y] = cache->hit[Y] - hsph->pos[Y];
		cache->norm[Z] = cache->hit[Z] - hsph->pos[Z];
	}
	else if (cache->norm_type[hsph->index] == 2)
	{
		cache->norm[X] = ((t_disk *)cache->closest->obj)->dir[X];
		cache->norm[Y] = ((t_disk *)cache->closest->obj)->dir[Y];
		cache->norm[Z] = ((t_disk *)cache->closest->obj)->dir[Z];
	}
	if (vecdot(cache->ray, cache->norm) > PRECISION)
	{
		cache->norm[X] = -cache->norm[X];
		cache->norm[Y] = -cache->norm[Y];
		cache->norm[Z] = -cache->norm[Z];
	}
	vecnorm(cache->norm);
}

void				edit_hemisphere_live(t_objlst *this, double *delta)
{
	t_hemisphere	*obj;

	obj = (t_hemisphere *)this->obj;
	obj->pos[X] += delta[X];
	obj->pos[Y] += delta[Y];
	obj->pos[Z] += delta[Z];
	obj->pos[OX] += delta[OX];
	obj->pos[OZ] += delta[OZ];
	obj->dir[X] = 0.0;
	obj->dir[Y] = 0.0;
	obj->dir[Z] = -1.0;
	vecrot_ox(obj->dir, obj->pos[OX], NULL);
	vecrot_oy(obj->dir, obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
}

void				edit_hemisphere(t_objlst *this)
{
	t_hemisphere	*obj;

	obj = (t_hemisphere *)this->obj;
	obj->dir[X] = 0.0;
	obj->dir[Y] = 0.0;
	obj->dir[Z] = -1.0;
	obj->pos[OX] *= M_PI / 180.0;
	obj->pos[OY] *= M_PI / 180.0;
	obj->pos[OZ] *= M_PI / 180.0;
	vecrot_ox(obj->dir, obj->pos[OX], NULL);
	vecrot_oy(obj->dir, obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
	obj->radius = obj->radius <= PRECISION ? PRECISION : obj->radius;
	clamp_obj_data(this);
}
