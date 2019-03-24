/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:47:44 by oponomar          #+#    #+#             */
/*   Updated: 2018/04/04 12:49:31 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(const char *str)
{
	if (str)
	{
		while (*str)
			write(1, str++, 1);
		write(1, "\n", 1);
	}
}
