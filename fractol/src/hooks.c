/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 21:13:31 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/07 20:17:05 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_color_hook(int key_code, t_info *info)
{
	if (key_code == 18)
		info->scheme = 1;
	if (key_code == 19)
		info->scheme = 2;
	if (key_code == 20)
		info->scheme = 3;
}

void	ft_move_zoom_hook(int key_code, t_info *info)
{
	if (key_code == 123)
		info->x_move += 0.5 * info->zoom * 100;
	if (key_code == 124)
		info->x_move -= 0.5 * info->zoom * 100;
	if (key_code == 126)
		info->y_move += 0.5 * info->zoom * 100;
	if (key_code == 125)
		info->y_move -= 0.5 * info->zoom * 100;
	if (key_code == 69)
		info->zoom *= 0.9;
	if (key_code == 78)
		info->zoom *= 1.1;
}

void	ft_zoom_iteration_hook(int key_code, t_info *info)
{
	if (key_code == 116)
		info->iterations += 5;
	if (key_code == 121)
		info->iterations -= 5;
}

void	ft_fr_type_hook(int key_code, t_info *info)
{
	if (key_code == 46)
		info->type = 'M';
	else if (key_code == 38)
		info->type = 'J';
	else if (key_code == 11)
		info->type = 'B';
	else if (key_code == 45)
		info->type = 'N';
	else if (key_code == 8)
		info->type = 'C';
	else if (key_code == 34)
	{
		info->zoom = 0.0025;
		info->x_move = 0;
		info->y_move = 0;
		info->iterations = 50;
		info->c_re_tmp = 0;
		info->c_im_tmp = 0.8;
	}
}

int		ft_key_hook(int key_code, t_info *info)
{
	if (key_code == 53)
		exit_x(info);
	ft_move_zoom_hook(key_code, info);
	ft_zoom_iteration_hook(key_code, info);
	ft_fr_type_hook(key_code, info);
	ft_color_hook(key_code, info);
	expose_hook(info);
	return (0);
}
