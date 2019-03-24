/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:08:38 by odidukh           #+#    #+#             */
/*   Updated: 2018/09/24 22:16:46 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	menu_init(t_win *w)
{
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 60, 0xFF0000, "[ esc ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 100, 85, 0x00FF00, "[ ^ ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 85, 0x00FFFF, "[ + ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 110, 0x00FF00, "[ < ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 100, 110, 0x00FF00, "[ V ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 150, 85, 0x00FFFF, "[ - ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 150, 110, 0x00FF00, "[ > ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 145, 0xF76A40,
			"[ 5 ] - to center");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 180, 0xFFFF00, "[ 7 ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 100, 180, 0x008000, "[ 8 ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 150, 180, 0xFFFF00, "[ 9 ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 205, 0x0000FF, "[ 4 ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 150, 205, 0x0000FF, "[ 6 ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 230, 0xFFFF00, "[ 1 ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 100, 230, 0x008000, "[ 2 ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 150, 230, 0xFFFF00, "[ 3 ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 260, 0x00FFFF, "ZOOM");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 285, 0x00FF00, "MOVE");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 310, 0xFFFF00, "Z ROTATION");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 335, 0x008000, "Y ROTATION");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 360, 0x0000FF, "X ROTATION");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50,
			385, 0xFFFFFF, "COLOR: [R] [G] [B] [W]");
}

int		exit_x(void)
{
	exit(1);
	return (0);
}

int		expose_hook(t_info *info)
{
	mlx_clear_window(info->window->mlx_ptr, info->window->win_ptr);
	ft_display(info);
	menu_init(info->window);
	return (0);
}

void	operation(t_info *info)
{
	mlx_expose_hook(info->window->win_ptr, expose_hook, info);
	mlx_hook(info->window->win_ptr, 17, 1L << 17, exit_x, info->window);
	mlx_hook(info->window->win_ptr, 2, 5, key_hook, info);
	mlx_loop(info->window->mlx_ptr);
}
