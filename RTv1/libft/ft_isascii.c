/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:10:21 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 19:55:08 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	The isascii() function tests for an ASCII character, which is any character
**	between 0 and octal 0177 inclusive.
*/

int		ft_isascii(int c)
{
	if ((c >= 0) && (c <= 0177))
		return (1);
	return (0);
}
