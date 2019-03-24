/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:42:46 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/21 15:07:35 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				cache_copy(t_cache *dst, t_cache *src)
{
	dst->closest = src->closest;
	dst->info = src->info;
	ft_memcpy(dst->hit, src->hit, sizeof(double) * 3);
	ft_memcpy(dst->norm, src->norm, sizeof(double) * 3);
	ft_memcpy(dst->ray, src->ray, sizeof(double) * 3);
	ft_memcpy(dst->norm_type, src->norm_type, sizeof(int) * MAX_OBJ_AMOUNT);
	ft_memcpy(dst->unit_vec[X], src->unit_vec[X], sizeof(double) * 3);
	ft_memcpy(dst->unit_vec[Y], src->unit_vec[Y], sizeof(double) * 3);
	ft_memcpy(dst->unit_vec[Z], src->unit_vec[Z], sizeof(double) * 3);
}

double				get_min_positive_root(double a, double b,
										double c, double *roots)
{
	double			d;
	double			result;
	double			t[2];

	t[0] = -1.0;
	t[1] = -1.0;
	d = b * b - 4.0 * a * c;
	result = -1.0;
	if (d > PRECISION)
	{
		a = 1.0 / (2.0 * a);
		t[0] = (-b - sqrt(d)) * a;
		t[1] = (-b + sqrt(d)) * a;
		if ((t[1] < PRECISION || t[0] < t[1]) && t[0] > PRECISION)
			result = t[0];
		else
			result = t[1];
	}
	if (roots)
	{
		roots[0] = t[0];
		roots[1] = t[1];
	}
	return (result);
}

void				clamp_obj_data(t_objlst *selected)
{
	if (selected->color > 0xffffff)
		selected->color = 0xffffff;
	if (selected->ior < 1.0)
		selected->ior = 1.0;
	if (selected->ior > 42.0)
		selected->ior = 42.0;
	if (selected->reflection < 0.0)
		selected->reflection = 0.0;
	if (selected->reflection > 1.0)
		selected->reflection = 1.0;
	if (selected->transparency < 0.0)
		selected->transparency = 0.0;
	if (selected->transparency > 1.0)
		selected->transparency = 1.0;
}

void				set_obj_constants(t_info *info, double *start)
{
	t_objlst		*tmp;

	tmp = info->objlst;
	while (tmp)
	{
		tmp->init_values(tmp->obj, start);
		tmp = tmp->next;
	}
}
