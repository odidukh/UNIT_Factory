/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:06:16 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 19:55:40 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	The isprint() function tests for any printing character, including
**	space (' ').  The value of the argument must be representable as an
**	unsigned char or the value of EOF.
*/

int		ft_isprint(int c)
{
	if ((c >= 040) && (c <= 0176))
		return (1);
	return (0);
}
