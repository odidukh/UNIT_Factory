/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:46:41 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 16:05:41 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_triangle			*create_triangle(double *p0, double *p1, double *p2)
{
	t_triangle		*obj;

	obj = (t_triangle *)malloc(sizeof(t_triangle));
	ft_memcpy(obj->p0, p0, sizeof(double) * 3);
	ft_memcpy(obj->p1, p1, sizeof(double) * 3);
	ft_memcpy(obj->p2, p2, sizeof(double) * 3);
	ft_memcpy(obj->p0_backup, obj->p0, sizeof(double) * 3);
	ft_memcpy(obj->p1_backup, obj->p1, sizeof(double) * 3);
	ft_memcpy(obj->p2_backup, obj->p2, sizeof(double) * 3);
	vecsub(obj->p1, obj->p0, obj->edge[0], 3);
	vecsub(obj->p2, obj->p1, obj->edge[1], 3);
	vecsub(obj->p0, obj->p2, obj->edge[2], 3);
	veccross(obj->edge[0], obj->edge[1], obj->dir);
	if (veclen(obj->dir) > PRECISION)
	{
		obj->area = 0.5 * veclen(obj->dir);
		vecnorm(obj->dir);
	}
	else
		obj->area = -1.0;
	ft_memset(obj->delta, 0, sizeof(double) * 6);
	return (obj);
}

void				define_triangle_constants(void *obj, double *viewpos)
{
	t_triangle		*tr;

	tr = (t_triangle *)obj;
	tr->dirc[X] = tr->p0[X] - viewpos[X];
	tr->dirc[Y] = tr->p0[Y] - viewpos[Y];
	tr->dirc[Z] = tr->p0[Z] - viewpos[Z];
	vecsub(tr->p1, tr->p0, tr->edge[0], 3);
	vecsub(tr->p2, tr->p1, tr->edge[1], 3);
	vecsub(tr->p0, tr->p2, tr->edge[2], 3);
}

void				set_triangle_normvec(t_cache *cache)
{
	cache->norm[X] = ((t_triangle *)cache->closest->obj)->dir[X];
	cache->norm[Y] = ((t_triangle *)cache->closest->obj)->dir[Y];
	cache->norm[Z] = ((t_triangle *)cache->closest->obj)->dir[Z];
	if (vecdot(cache->ray, cache->norm) > PRECISION)
	{
		cache->norm[X] = -cache->norm[X];
		cache->norm[Y] = -cache->norm[Y];
		cache->norm[Z] = -cache->norm[Z];
	}
}

void				edit_triangle_live(t_objlst *this, double *delta)
{
	double			vec[2][3];
	t_triangle		*obj;

	obj = (t_triangle *)this->obj;
	vecadd(obj->delta, delta, obj->delta, 6);
	ft_memcpy(obj->p0, obj->p0_backup, sizeof(double) * 3);
	ft_memcpy(obj->p1, obj->p1_backup, sizeof(double) * 3);
	ft_memcpy(obj->p2, obj->p2_backup, sizeof(double) * 3);
	vecadd(obj->p0, obj->delta, obj->p0, 3);
	vecadd(obj->p1, obj->delta, obj->p1, 3);
	vecadd(obj->p2, obj->delta, obj->p2, 3);
	vecrot_ox(obj->p1, obj->delta[OX], obj->p0);
	vecrot_oy(obj->p1, obj->delta[OY], obj->p0);
	vecrot_oz(obj->p1, obj->delta[OZ], obj->p0);
	vecrot_ox(obj->p2, obj->delta[OX], obj->p0);
	vecrot_oy(obj->p2, obj->delta[OY], obj->p0);
	vecrot_oz(obj->p2, obj->delta[OZ], obj->p0);
	vecsub(obj->p1, obj->p0, vec[0], 3);
	vecsub(obj->p2, obj->p0, vec[1], 3);
	veccross(vec[0], vec[1], obj->dir);
	vecnorm(obj->dir);
}

void				edit_triangle(t_objlst *this)
{
	t_triangle		*obj;

	obj = (t_triangle *)this->obj;
	ft_memcpy(obj->p0_backup, obj->p0, sizeof(double) * 3);
	ft_memcpy(obj->p1_backup, obj->p1, sizeof(double) * 3);
	ft_memcpy(obj->p2_backup, obj->p2, sizeof(double) * 3);
	vecsub(obj->p1, obj->p0, obj->edge[0], 3);
	vecsub(obj->p2, obj->p1, obj->edge[1], 3);
	vecsub(obj->p0, obj->p2, obj->edge[2], 3);
	veccross(obj->edge[0], obj->edge[1], obj->dir);
	if (veclen(obj->dir) > PRECISION)
	{
		obj->area = 0.5 * veclen(obj->dir);
		vecnorm(obj->dir);
	}
	else
		obj->area = -1.0;
	ft_memset(obj->delta, 0, sizeof(double) * 6);
	clamp_obj_data(this);
}
