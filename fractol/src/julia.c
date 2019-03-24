/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 20:32:36 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/04 18:48:58 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_calculation_j(t_info_fr *fr)
{
	fr->n = 0;
	while (fr->n < fr->iterations && (fr->c_re * fr->c_re +
	fr->c_im * fr->c_im) < 4)
	{
		fr->re_factor = fr->c_re * fr->c_re - fr->c_im * fr->c_im;
		fr->im_factor = 2 * fr->c_re * fr->c_im;
		fr->c_re = fr->re_factor + fr->info->c_re_tmp;
		fr->c_im = fr->im_factor + fr->info->c_im_tmp;
		fr->n++;
	}
}

void	*ft_julia(void *args)
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
			ft_calculation_j(fr);
			fr->z = (int)(fr->c_re * fr->c_re + fr->c_im * fr->c_im);
			if (fr->n < fr->iterations)
				ft_fill_color(fr);
			fr->x++;
		}
		fr->y_start++;
	}
	pthread_exit(0);
}
