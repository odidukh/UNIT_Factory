/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cyl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/20 15:58:06 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_cyl			*create_cyl(double *pos, double radius)
{
	t_cyl		*obj;

	obj = (t_cyl *)malloc(sizeof(t_cyl));
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
	obj->radius = radius <= PRECISION ? PRECISION : radius;
	return (obj);
}

void			define_cyl_constants(void *obj, double *viewpos)
{
	t_cyl		*cyl;

	cyl = (t_cyl *)obj;
	cyl->dirc[X] = viewpos[X] - cyl->pos[X];
	cyl->dirc[Y] = viewpos[Y] - cyl->pos[Y];
	cyl->dirc[Z] = viewpos[Z] - cyl->pos[Z];
	cyl->prm[0] = vecdot(cyl->dir, cyl->dirc);
	cyl->prm[1] = vecdot(cyl->dirc, cyl->dirc) - cyl->prm[0] * cyl->prm[0]
				- cyl->radius * cyl->radius;
}

void			set_cyl_normvec(t_cache *cache)
{
	t_cyl		*cyl;
	double		m;

	cyl = (t_cyl *)cache->closest->obj;
	m = (vecdot(cache->hit, cyl->dir) - vecdot(cyl->pos, cyl->dir))
		/ vecdot(cyl->dir, cyl->dir);
	cache->norm[X] = cache->hit[X] - cyl->pos[X] - cyl->dir[X] * m;
	cache->norm[Y] = cache->hit[Y] - cyl->pos[Y] - cyl->dir[Y] * m;
	cache->norm[Z] = cache->hit[Z] - cyl->pos[Z] - cyl->dir[Z] * m;
	vecnorm(cache->norm);
}

void			edit_cyl_live(t_objlst *this, double *delta)
{
	t_cyl		*obj;

	obj = (t_cyl *)this->obj;
	obj->pos[X] += delta[X];
	obj->pos[Y] += delta[Y];
	obj->pos[Z] += delta[Z];
	obj->pos[OX] += delta[OX];
	obj->pos[OY] += delta[OY];
	obj->pos[OZ] += delta[OZ];
	obj->dir[X] = 0.0;
	obj->dir[Y] = 0.0;
	obj->dir[Z] = -1.0;
	vecrot_ox(obj->dir, obj->pos[OX], NULL);
	vecrot_oy(obj->dir, obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
}

void			edit_cyl(t_objlst *this)
{
	t_cyl		*obj;

	obj = (t_cyl *)this->obj;
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
	clamp_obj_data(this);
}
