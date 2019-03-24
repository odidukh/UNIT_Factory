/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:49:53 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/12 19:55:44 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Applies the function f to each character of the string passed as argument.
**	Each character is passed by address to f to be modified if necessary.
** Param. #1
**	The string to iterate.
** Param. #2
**	The function to apply to each character of s.
** Return value
**	None.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
	{
		while (*s)
			(*f)(s++);
	}
}
