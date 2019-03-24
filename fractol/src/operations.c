/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:30:29 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/07 16:06:59 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		exit_x(t_info *info)
{
	mlx_destroy_image(info->mlx_ptr, info->win_ptr);
	exit(1);
	return (0);
}

int		expose_hook(t_info *info)
{
	ft_display(info);
	return (0);
}

void	ft_operations(t_info *info)
{
	mlx_expose_hook(info->win_ptr, expose_hook, info);
	mlx_hook(info->win_ptr, 17, 1L << 17, exit_x, info);
	mlx_hook(info->win_ptr, 2, 5, ft_key_hook, info);
	mlx_hook(info->win_ptr, 6, 1L << 6, ft_julia_hook, info);
	mlx_mouse_hook(info->win_ptr, ft_julia_hook, info);
	mlx_mouse_hook(info->win_ptr, ft_mouse_hook, info);
	mlx_loop(info->mlx_ptr);
}
