/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 18:03:58 by odidukh           #+#    #+#             */
/*   Updated: 2018/09/17 21:57:07 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 2 || !ft_strstr(argv[1], ".fdf"))
	{
		write(1, "Error: program takes only one file name\n", 40);
		return (0);
	}
	info = ft_information(argv[1]);
	operation(info);
	return (0);
}
