/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:41:51 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/07 15:52:08 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_calculation_b_sh(t_info_fr *fr)
{
	fr->n = 0;
	while (fr->n < fr->iterations && (fr->c_re * fr->c_re +
	fr->c_im * fr->c_im) < 4)
	{
		fr->re_factor = fr->c_re * fr->c_re;
		fr->im_factor = fr->c_im * fr->c_im;
		fr->c_im = fabs(fr->c_re * fr->c_im) * 2.0 + fr->c_im_tmp;
		fr->c_re = fr->re_factor - fr->im_factor + fr->c_re_tmp;
		fr->n++;
	}
}

void	*ft_burning_ship(void *args)
{
	t_info_fr	*fr;

	fr = (t_info_fr *)args;
	while (fr->y_start < fr->y_finish)
	{
		fr->x = 0;
		while (fr->x < WIN_X)
		{
			fr->c_re = (fr->x - WIN_X / 2.0) * fr->zoom + fr->x_move;
			fr->c_im = (fr->y_start - WIN_Y / 2.0) * fr->zoom + fr->y_move;
			fr->c_re_tmp = fr->c_re;
			fr->c_im_tmp = fr->c_im;
			ft_calculation_b_sh(fr);
			fr->z = (int)(fr->c_re * fr->c_re + fr->c_im * fr->c_im);
			if (fr->n < fr->iterations)
				ft_fill_color(fr);
			fr->x++;
		}
		fr->y_start++;
	}
	pthread_exit(0);
}
