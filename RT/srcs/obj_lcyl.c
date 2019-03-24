/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_lcyl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:25:39 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/21 16:32:04 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_lcyl				*create_lcyl(double *pos, double radius, double height)
{
	t_lcyl		*obj;

	obj = (t_lcyl *)malloc(sizeof(t_lcyl));
	obj->height = height > PRECISION ? height : PRECISION;
	obj->dir[X] = 0.0;
	obj->dir[Y] = 0.0;
	obj->dir[Z] = -1.0;
	ft_memcpy(obj->pos, pos, sizeof(double) * 3);
	obj->pos[OX] = pos[OX] * M_PI / 180.0;
	obj->pos[OY] = pos[OY] * M_PI / 180.0;
	obj->pos[OZ] = pos[OZ] * M_PI / 180.0;
	obj->radius = radius < PRECISION ? PRECISION : radius;
	vecrot_ox(obj->dir, -obj->pos[OX], NULL);
	vecrot_oy(obj->dir, -obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
	obj->lower_cap.radius = obj->radius;
	ft_memcpy(obj->lower_cap.pos, obj->pos, sizeof(double) * 6);
	ft_memcpy(obj->lower_cap.dir, obj->dir, sizeof(double) * 3);
	obj->upper_cap.radius = obj->radius;
	ft_memcpy(obj->upper_cap.pos, obj->pos, sizeof(double) * 6);
	ft_memcpy(obj->upper_cap.dir, obj->dir, sizeof(double) * 3);
	obj->upper_cap.pos[X] -= obj->upper_cap.dir[X] * obj->height;
	obj->upper_cap.pos[Y] -= obj->upper_cap.dir[Y] * obj->height;
	obj->upper_cap.pos[Z] -= obj->upper_cap.dir[Z] * obj->height;
	return (obj);
}

void				define_lcyl_constants(void *obj, double *viewpos)
{
	t_lcyl		*tmp;

	tmp = (t_lcyl *)obj;
	tmp->dirc[X] = viewpos[X] - tmp->pos[X];
	tmp->dirc[Y] = viewpos[Y] - tmp->pos[Y];
	tmp->dirc[Z] = viewpos[Z] - tmp->pos[Z];
	tmp->prm[0] = vecdot(tmp->dir, tmp->dirc);
	tmp->prm[1] = vecdot(tmp->dirc, tmp->dirc) - tmp->prm[0] * tmp->prm[0]
				- tmp->radius * tmp->radius;
	define_plane_constants(&tmp->upper_cap, viewpos);
	define_plane_constants(&tmp->lower_cap, viewpos);
}

void				set_lcyl_normvec(t_cache *cache)
{
	t_lcyl			*obj;
	double			m;

	obj = (t_lcyl *)cache->closest->obj;
	if (cache->norm_type[obj->index] == 1)
	{
		m = (vecdot(cache->hit, obj->dir) - vecdot(obj->pos, obj->dir))
			/ vecdot(obj->dir, obj->dir);
		cache->norm[X] = cache->hit[X] - obj->pos[X] - obj->dir[X] * m;
		cache->norm[Y] = cache->hit[Y] - obj->pos[Y] - obj->dir[Y] * m;
		cache->norm[Z] = cache->hit[Z] - obj->pos[Z] - obj->dir[Z] * m;
	}
	else
	{
		cache->norm[X] = obj->lower_cap.dir[X];
		cache->norm[Y] = obj->lower_cap.dir[Y];
		cache->norm[Z] = obj->lower_cap.dir[Z];
		if (vecdot(cache->norm, cache->ray) > PRECISION)
		{
			cache->norm[X] = -cache->norm[X];
			cache->norm[Y] = -cache->norm[Y];
			cache->norm[Z] = -cache->norm[Z];
		}
	}
	vecnorm(cache->norm);
}

void				edit_lcyl_live(t_objlst *this, double *delta)
{
	t_lcyl		*obj;

	obj = (t_lcyl *)this->obj;
	obj->pos[X] += delta[X];
	obj->pos[Y] += delta[Y];
	obj->pos[Z] += delta[Z];
	obj->pos[OX] += delta[OX];
	obj->pos[OY] += delta[OY];
	obj->pos[OZ] += delta[OZ];
	obj->dir[X] = 0.0;
	obj->dir[Y] = 0.0;
	obj->dir[Z] = -1.0;
	vecrot_ox(obj->dir, -obj->pos[OX], NULL);
	vecrot_oy(obj->dir, -obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
	ft_memcpy(obj->lower_cap.pos, obj->pos, sizeof(double) * 6);
	ft_memcpy(obj->lower_cap.dir, obj->dir, sizeof(double) * 3);
	ft_memcpy(obj->upper_cap.pos, obj->pos, sizeof(double) * 6);
	ft_memcpy(obj->upper_cap.dir, obj->dir, sizeof(double) * 3);
	obj->upper_cap.pos[X] -= obj->upper_cap.dir[X] * obj->height;
	obj->upper_cap.pos[Y] -= obj->upper_cap.dir[Y] * obj->height;
	obj->upper_cap.pos[Z] -= obj->upper_cap.dir[Z] * obj->height;
}

void				edit_lcyl(t_objlst *this)
{
	t_lcyl		*obj;

	obj = (t_lcyl *)this->obj;
	obj->dir[X] = 0.0;
	obj->dir[Y] = 0.0;
	obj->dir[Z] = -1.0;
	obj->pos[OX] *= M_PI / 180.0;
	obj->pos[OY] *= M_PI / 180.0;
	obj->pos[OZ] *= M_PI / 180.0;
	obj->height = obj->height > PRECISION ? obj->height : PRECISION;
	obj->radius = obj->radius < PRECISION ? PRECISION : obj->radius;
	vecrot_ox(obj->dir, -obj->pos[OX], NULL);
	vecrot_oy(obj->dir, -obj->pos[OY], NULL);
	vecrot_oz(obj->dir, obj->pos[OZ], NULL);
	obj->lower_cap.radius = obj->radius;
	ft_memcpy(obj->lower_cap.pos, obj->pos, sizeof(double) * 6);
	ft_memcpy(obj->lower_cap.dir, obj->dir, sizeof(double) * 3);
	obj->upper_cap.radius = obj->radius;
	ft_memcpy(obj->upper_cap.pos, obj->pos, sizeof(double) * 6);
	ft_memcpy(obj->upper_cap.dir, obj->dir, sizeof(double) * 3);
	obj->upper_cap.pos[X] -= obj->upper_cap.dir[X] * obj->height;
	obj->upper_cap.pos[Y] -= obj->upper_cap.dir[Y] * obj->height;
	obj->upper_cap.pos[Z] -= obj->upper_cap.dir[Z] * obj->height;
	clamp_obj_data(this);
}
