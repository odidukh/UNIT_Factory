/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 20:14:51 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/07 20:02:22 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_fr_data_init(t_info_fr *fr, t_info *info, int i)
{
	fr->y_finish = STRIP * (i + 1);
	fr->y_start = fr->y_finish - STRIP;
	fr->zoom = info->zoom;
	fr->x_move = info->x_move;
	fr->y_move = info->y_move;
	fr->iterations = info->iterations;
	fr->scheme = info->scheme;
	fr->info = info;
}

void	ft_thread(t_info *info, void *fractal_func(void *))
{
	pthread_t	pthread[CORES];
	t_info_fr	t_fr[CORES];
	int			th_n;

	th_n = 0;
	while (th_n < CORES)
	{
		ft_fr_data_init(&t_fr[th_n], info, th_n);
		pthread_create(&(pthread[th_n]), NULL,
				fractal_func, (void *)&t_fr[th_n]);
		th_n++;
	}
	th_n = 0;
	while (th_n < CORES)
	{
		pthread_join(pthread[th_n], NULL);
		th_n++;
	}
}
