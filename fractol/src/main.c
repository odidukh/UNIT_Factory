/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 19:37:02 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/07 15:52:08 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		main(int argc, char *argv[])
{
	t_info	*info;

	if (argc == 2)
	{
		info = ft_fractol();
		ft_selector(argv[1], info);
		if (info->type == 0)
		{
			ft_usage();
			free(info);
			return (0);
		}
		ft_operations(info);
	}
	else
		ft_usage();
	return (0);
}
