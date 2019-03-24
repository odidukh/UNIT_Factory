/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_lcone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 16:11:22 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_lcone			*create_lcone(double *pos, double radius, double height)
{
	t_lcone		*obj;

	obj = (t_lcone *)malloc(sizeof(t_lcone));
	obj->dir[X] = 0.0;
	obj->dir[Y] = 0.0;
	obj->dir[Z] = -1.0;
	obj->pos[OX] = pos[OX] * M_PI / 180.0;
	obj->pos[OY] = pos[OY] * M_PI / 180.0;
	obj->pos[OZ] = pos[OZ] * M_PI / 180.0;
	vecrot_ox(obj->dir, obj->pos[OX], NULL);
	vecrot_oy(obj->dir, obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
	obj->radius = radius < PRECISION ? PRECISION : radius;
	obj->height = height < PRECISION ? PRECISION : height;
	obj->pos[X] = pos[X] - obj->dir[X] * obj->height;
	obj->pos[Y] = pos[Y] - obj->dir[Y] * obj->height;
	obj->pos[Z] = pos[Z] - obj->dir[Z] * obj->height;
	return (obj);
}

void			define_lcone_constants(void *obj, double *viewpos)
{
	t_lcone		*lcone;

	lcone = (t_lcone *)obj;
	lcone->dirc[X] = viewpos[X] - lcone->pos[X];
	lcone->dirc[Y] = viewpos[Y] - lcone->pos[Y];
	lcone->dirc[Z] = viewpos[Z] - lcone->pos[Z];
	lcone->prm[0] = 1.0 + pow(lcone->radius / lcone->height, 2);
	lcone->prm[1] = vecdot(lcone->dir, lcone->dirc);
	lcone->prm[2] = vecdot(lcone->dirc, lcone->dirc)
				- lcone->prm[0] * lcone->prm[1] * lcone->prm[1];
}

void			set_lcone_normvec(t_cache *cache)
{
	double		p[3];
	double		m;
	t_lcone		*lcone;

	lcone = (t_lcone *)cache->closest->obj;
	if (cache->norm_type[lcone->index] == 2)
	{
		ft_memcpy(cache->norm, lcone->dir, sizeof(double) * 3);
	}
	else
	{
		vecsub(cache->hit, lcone->pos, p, 3);
		m = vecdot(p, p) / vecdot(p, lcone->dir);
		cache->norm[X] = cache->hit[X] - (lcone->pos[X] + lcone->dir[X] * m);
		cache->norm[Y] = cache->hit[Y] - (lcone->pos[Y] + lcone->dir[Y] * m);
		cache->norm[Z] = cache->hit[Z] - (lcone->pos[Z] + lcone->dir[Z] * m);
	}
	if (vecdot(cache->norm, cache->ray) > PRECISION)
	{
		cache->norm[X] = -cache->norm[X];
		cache->norm[Y] = -cache->norm[Y];
		cache->norm[Z] = -cache->norm[Z];
	}
	vecnorm(cache->norm);
}

void			edit_lcone_live(t_objlst *this, double *delta)
{
	t_lcone		*obj;

	obj = (t_lcone *)this->obj;
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

void			edit_lcone(t_objlst *this)
{
	t_lcone		*obj;

	obj = (t_lcone *)this->obj;
	obj->dir[X] = 0.0;
	obj->dir[Y] = 0.0;
	obj->dir[Z] = -1.0;
	obj->pos[OX] *= M_PI / 180.0;
	obj->pos[OY] *= M_PI / 180.0;
	obj->pos[OZ] *= M_PI / 180.0;
	vecrot_ox(obj->dir, obj->pos[OX], NULL);
	vecrot_oy(obj->dir, obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
	obj->radius = obj->radius < PRECISION ? PRECISION : obj->radius;
	obj->height = obj->height < PRECISION ? PRECISION : obj->height;
	obj->pos[X] -= obj->dir[X] * obj->height;
	obj->pos[Y] -= obj->dir[Y] * obj->height;
	obj->pos[Z] -= obj->dir[Z] * obj->height;
	clamp_obj_data(this);
}
