/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_use.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 16:19:23 by odidukh           #+#    #+#             */
/*   Updated: 2018/10/07 20:36:15 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_selector(char *str, t_info *info)
{
	if (ft_strequ("Mandelbrot", str) || ft_strequ("M", str))
		info->type = 'M';
	else if (ft_strequ("Julia", str) || ft_strequ("J", str))
		info->type = 'J';
	else if (ft_strequ("BurnShip", str) || ft_strequ("B", str))
		info->type = 'B';
	else if (ft_strequ("Newton", str) || ft_strequ("N", str))
		info->type = 'N';
	else if (ft_strequ("InfiniteCube", str) || ft_strequ("C", str))
		info->type = 'C';
	else
		info->type = 0;
}

void	ft_usage(void)
{
	ft_putstr("usage: ./fractol (Mandelbrot | Julia | BurningShip | ");
	ft_putstr("Newton | InfiniteCube)\n");
	ft_putstr("or : ./fractol (M | J | B | N | C)\n");
}
