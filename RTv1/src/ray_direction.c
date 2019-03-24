/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:20:40 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/30 19:20:53 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ray_direction(t_ray *ray, double x, double y)
{
	ray->direction.x = x * ((double)50 / (double)W_WIDTH);
	ray->direction.y = y * ((double)50 / (double)W_HEIGHT);
	ray->direction.z = 1.0;
}
