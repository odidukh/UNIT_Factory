/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:46:21 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/07 18:52:34 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_color_data(t_info_fr *fr)
{
	fr->ph = 1;
	fr->w = 71;
	fr->c = 184;
	if (fr->scheme == 2)
	{
		fr->ph = 6;
		fr->w = 60;
		fr->c = 120;
	}
	if (fr->scheme == 3)
	{
		fr->ph = 2;
		fr->w = 110;
		fr->c = 135;
	}
}

void	ft_fill_color(t_info_fr *fr)
{
	int		c;
	double	index;
	double	frequency;

	ft_color_data(fr);
	c = (fr->x * (fr->info->bpp / 8)) + (fr->y_start * fr->info->s_line);
	index = (fr->n + 1) - (1 / fr->z);
	frequency = M_PI * 2 / fr->iterations;
	fr->info->pixels[++c] = sin(frequency * index + 4 + fr->ph)
		* fr->w + fr->c;
	fr->info->pixels[++c] = sin(frequency * index + 2 + fr->ph)
		* fr->w + fr->c;
	fr->info->pixels[++c] = sin(frequency * index + 1 + fr->ph)
		* fr->w + fr->c;
}
