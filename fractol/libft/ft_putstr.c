/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:29:55 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/13 13:01:29 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Outputs the string s to the standard output.
** Param. #1
**	The string to output.
** Return value
**	None.
*/

void	ft_putstr(char const *s)
{
	if (s)
	{
		while (*s)
			ft_putchar(*s++);
	}
}
