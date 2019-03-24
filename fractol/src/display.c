/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 13:55:28 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/07 18:51:29 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_menu_init(t_info *w)
{
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 40, 0xFF0000, "[ esc ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 100, 85, 0x00FF00, "[ ^ ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 85, 0x00FFFF, "[ + ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 110, 0x00FF00, "[ < ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 100, 110, 0x00FF00, "[ V ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 150, 85, 0x00FFFF, "[ - ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 150, 110, 0x00FF00, "[ > ]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 155, 0xF76AFF,
			"[ B ] - Burning Ship");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 180, 0xF76AFF,
			"[ N ] - Newton");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 205, 0xF76AFF,
			"[ M ] - Mandelbrot");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 230, 0xF76AFF,
			"[ J ] - Julia");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50, 255, 0xF76AFF,
			"[ C ] - Infinite Cube");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50,
			290, 0xFFFFFF, "COLOR SET: [1] [2] [3]");
	mlx_string_put(w->mlx_ptr, w->win_ptr, 50,
			320, 0xFFE025, "[ I ] - initial state");
}

void	ft_fract_to_dispay(t_info *info)
{
	if (info->type == 'M')
		ft_thread(info, ft_mandelbrot);
	else if (info->type == 'J')
		ft_thread(info, ft_julia);
	else if (info->type == 'B')
		ft_thread(info, ft_burning_ship);
	else if (info->type == 'C')
		ft_thread(info, ft_infinite_cube);
	else if (info->type == 'N')
		ft_thread(info, ft_newton);
}

void	ft_display(t_info *info)
{
	info->image = mlx_new_image(info->mlx_ptr, WIN_X, WIN_Y);
	info->pixels = mlx_get_data_addr(info->image, &(info->bpp),
			&(info->s_line), &(info->endian));
	mlx_clear_window(info->mlx_ptr, info->win_ptr);
	ft_fract_to_dispay(info);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->image, 0, 0);
	ft_menu_init(info);
}
