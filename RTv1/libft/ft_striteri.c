/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:59:54 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/12 19:56:31 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Applies the function f to each character of the string passed as argument,
**	and passing its index as first argument. Each character is passed by
**	address to f to be modified if necessary.
** Param. #1
**	The string to iterate.
** Param. #2
**	The function to apply to each character of s and its index.
** Return value
**	None.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int		i;

	i = 0;
	if (s && f)
	{
		while (*s)
			(*f)(i++, s++);
	}
}
