/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 16:04:41 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_cone			*create_cone(double *pos, double angle)
{
	t_cone		*obj;

	obj = (t_cone *)malloc(sizeof(t_cone));
	obj->dir[X] = 0.0;
	obj->dir[Y] = 0.0;
	obj->dir[Z] = -1.0;
	obj->pos[X] = pos[X];
	obj->pos[Y] = pos[Y];
	obj->pos[Z] = pos[Z];
	obj->pos[OX] = pos[OX] * M_PI / 180.0;
	obj->pos[OY] = pos[OY] * M_PI / 180.0;
	obj->pos[OZ] = pos[OZ] * M_PI / 180.0;
	vecrot_ox(obj->dir, obj->pos[OX], NULL);
	vecrot_oy(obj->dir, obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
	obj->angle = angle < 5.0 ? 5.0 : angle;
	obj->angle = angle > 179.0 ? 179.0 : angle;
	return (obj);
}

void			define_cone_constants(void *obj, double *viewpos)
{
	t_cone		*tmp;

	tmp = (t_cone *)obj;
	tmp->dirc[X] = viewpos[X] - tmp->pos[X];
	tmp->dirc[Y] = viewpos[Y] - tmp->pos[Y];
	tmp->dirc[Z] = viewpos[Z] - tmp->pos[Z];
	tmp->prm[0] = 1.0 + pow(tan(tmp->angle * M_PI / 360.0), 2);
	tmp->prm[1] = vecdot(tmp->dir, tmp->dirc);
	tmp->prm[2] = vecdot(tmp->dirc, tmp->dirc)
				- tmp->prm[0] * tmp->prm[1] * tmp->prm[1];
}

void			set_cone_normvec(t_cache *cache)
{
	t_cone		*cone;
	double		m;
	double		p[3];

	cone = (t_cone *)cache->closest->obj;
	vecsub(cache->hit, cone->pos, p, 3);
	m = vecdot(p, p) / vecdot(p, cone->dir);
	cache->norm[X] = cache->hit[X] - (cone->pos[X] + cone->dir[X] * m);
	cache->norm[Y] = cache->hit[Y] - (cone->pos[Y] + cone->dir[Y] * m);
	cache->norm[Z] = cache->hit[Z] - (cone->pos[Z] + cone->dir[Z] * m);
	vecnorm(cache->norm);
	if (vecdot(cache->norm, cache->ray) > PRECISION)
	{
		cache->norm[X] = -cache->norm[X];
		cache->norm[Y] = -cache->norm[Y];
		cache->norm[Z] = -cache->norm[Z];
	}
}

void			edit_cone_live(t_objlst *this, double *delta)
{
	t_cone		*obj;

	obj = (t_cone *)this->obj;
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

void			edit_cone(t_objlst *this)
{
	t_cone		*obj;

	obj = (t_cone *)this->obj;
	obj->dir[X] = 0.0;
	obj->dir[Y] = 0.0;
	obj->dir[Z] = -1.0;
	obj->pos[OX] *= M_PI / 180.0;
	obj->pos[OY] *= M_PI / 180.0;
	obj->pos[OZ] *= M_PI / 180.0;
	vecrot_ox(obj->dir, obj->pos[OX], NULL);
	vecrot_oy(obj->dir, obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
	obj->angle = obj->angle < 5.0 ? 5.0 : obj->angle;
	obj->angle = obj->angle > 179.0 ? 179.0 : obj->angle;
	clamp_obj_data(this);
}
