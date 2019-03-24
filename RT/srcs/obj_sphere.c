/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 16:05:37 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_sphere		*create_sphere(double *pos, double radius)
{
	t_sphere	*obj;

	obj = (t_sphere *)malloc(sizeof(t_sphere));
	obj->pos[X] = pos[X];
	obj->pos[Y] = pos[Y];
	obj->pos[Z] = pos[Z];
	obj->pos[OX] = pos[OX] * M_PI / 180.0;
	obj->pos[OY] = pos[OY] * M_PI / 180.0;
	obj->pos[OZ] = pos[OZ] * M_PI / 180.0;
	obj->dir[X] = 0;
	obj->dir[Y] = 0;
	obj->dir[Z] = 1;
	vecrot_ox(obj->dir, obj->pos[OX], NULL);
	vecrot_oy(obj->dir, obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
	obj->radius = radius < PRECISION ? PRECISION : radius;
	return (obj);
}

void			define_sphere_constants(void *obj, double *viewpos)
{
	t_sphere	*tmp;

	tmp = (t_sphere *)obj;
	tmp->dirc[X] = viewpos[X] - tmp->pos[X];
	tmp->dirc[Y] = viewpos[Y] - tmp->pos[Y];
	tmp->dirc[Z] = viewpos[Z] - tmp->pos[Z];
	tmp->prm = vecdot(tmp->dirc, tmp->dirc) - tmp->radius * tmp->radius;
}

void			set_sphere_normvec(t_cache *cache)
{
	cache->norm[X] = cache->hit[X] - ((t_sphere *)cache->closest->obj)->pos[X];
	cache->norm[Y] = cache->hit[Y] - ((t_sphere *)cache->closest->obj)->pos[Y];
	cache->norm[Z] = cache->hit[Z] - ((t_sphere *)cache->closest->obj)->pos[Z];
	vecnorm(cache->norm);
}

void			edit_sphere_live(t_objlst *this, double *delta)
{
	t_sphere	*obj;

	obj = (t_sphere *)this->obj;
	obj->pos[X] += delta[X];
	obj->pos[Y] += delta[Y];
	obj->pos[Z] += delta[Z];
	obj->pos[OX] += delta[OX];
	obj->pos[OZ] += delta[OZ];
	obj->dir[X] = 0;
	obj->dir[Y] = 0;
	obj->dir[Z] = 1;
	vecrot_ox(obj->dir, obj->pos[OX], NULL);
	vecrot_oy(obj->dir, obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
}

void			edit_sphere(t_objlst *this)
{
	t_sphere	*obj;

	obj = (t_sphere *)this->obj;
	obj->pos[OX] *= M_PI / 180.0;
	obj->pos[OY] *= M_PI / 180.0;
	obj->pos[OZ] *= M_PI / 180.0;
	obj->dir[X] = 0;
	obj->dir[Y] = 0;
	obj->dir[Z] = 1;
	vecrot_ox(obj->dir, obj->pos[OX], NULL);
	vecrot_oy(obj->dir, obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
	obj->radius = obj->radius <= PRECISION ? PRECISION : obj->radius;
	clamp_obj_data(this);
}
