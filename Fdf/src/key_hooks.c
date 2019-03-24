/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:18:35 by odidukh           #+#    #+#             */
/*   Updated: 2018/09/24 22:38:28 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_key_color(int key_code, t_info *info)
{
	if (key_code == 15)
		info->color = 0xFF0000;
	else if (key_code == 5)
		info->color = 0x00FF00;
	else if (key_code == 11)
		info->color = 0x0000FF;
	else if (key_code == 13)
		info->color = 0xFFFFFF;
}

void	ft_key_scale(int key_code, t_info *info)
{
	if (key_code == 69)
		ft_map_scalling(info, info->map_with_oper, 1.1);
	else if (key_code == 78)
		ft_map_scalling(info, info->map_with_oper, 0.9);
}

void	ft_key_move(int key_code, t_info *info)
{
	if (key_code == 123)
		ft_map_moving(info, info->map_with_oper, -15, 'X');
	else if (key_code == 124)
		ft_map_moving(info, info->map_with_oper, 15, 'X');
	else if (key_code == 126)
		ft_map_moving(info, info->map_with_oper, -15, 'Y');
	else if (key_code == 125)
		ft_map_moving(info, info->map_with_oper, 15, 'Y');
}

void	ft_key_rotate(int key_code, t_info *info)
{
	if (key_code == 91)
		ft_map_rotation(info, info->map_with_oper, 'X', 10);
	else if (key_code == 84)
		ft_map_rotation(info, info->map_with_oper, 'X', -10);
	else if (key_code == 86)
		ft_map_rotation(info, info->map_with_oper, 'Y', 10);
	else if (key_code == 88)
		ft_map_rotation(info, info->map_with_oper, 'Y', -10);
	else if (key_code == 89 || key_code == 83)
		ft_map_rotation(info, info->map_with_oper, 'Z', 10);
	else if (key_code == 92 || key_code == 85)
		ft_map_rotation(info, info->map_with_oper, 'Z', -10);
}

int		key_hook(int key_code, t_info *info)
{
	if (key_code == 53)
		exit_x();
	else if (key_code == 69 || key_code == 78)
		ft_key_scale(key_code, info);
	else if (key_code == 123 || key_code == 124
	|| key_code == 126 || key_code == 125)
		ft_key_move(key_code, info);
	else if (key_code == 91 || key_code == 84 || key_code == 86
	|| key_code == 88 || key_code == 89 || key_code == 83
	|| key_code == 92 || key_code == 85)
		ft_key_rotate(key_code, info);
	else if (key_code == 15 || key_code == 5 ||
		key_code == 11 || key_code == 13)
		ft_key_color(key_code, info);
	else if (key_code == 87)
		ft_copy_map(info);
	expose_hook(info);
	return (0);
}
