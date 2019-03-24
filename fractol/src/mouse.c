/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 16:39:36 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/07 18:13:02 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_mouse_hook(int key_code, int x, int y, t_info *info)
{
	int	temp_1;
	int	temp_2;

	temp_1 = x;
	temp_2 = y;
	if (key_code == 5)
	{
		info->zoom *= 0.9;
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		expose_hook(info);
	}
	if (key_code == 4)
	{
		info->zoom *= 1.1;
		mlx_clear_window(info->mlx_ptr, info->win_ptr);
		expose_hook(info);
	}
	return (0);
}

int	ft_julia_hook(int x, int y, t_info *info)
{
	if (info->type == 'J')
	{
		info->c_re_tmp = (1 / (double)WIN_X * (double)x * 4) - 2;
		info->c_im_tmp = (1 / (double)WIN_Y * (double)y * 4) - 2;
		expose_hook(info);
	}
	return (0);
}
