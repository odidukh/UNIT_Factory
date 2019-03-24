/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:02:41 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/07 16:48:04 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_part_init(t_info *info)
{
	info->zoom = 0.0025;
	info->x_move = 0;
	info->y_move = 0;
	info->iterations = 50;
	info->c_re_tmp = 0;
	info->c_im_tmp = 0.8;
}

t_info	*ft_fractol(void)
{
	t_info	*info;

	info = ft_memalloc(sizeof(t_info));
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, WIN_X, WIN_Y, "fractol");
	ft_part_init(info);
	return (info);
}
