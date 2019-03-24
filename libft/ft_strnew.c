/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:36:28 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 16:42:54 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’.
**	Each character of the string is initialized at ’\0’. If the allocation
**	fails the function returns NULL.
** Param. #1
**	The size of the string to be allocated.
** Return value
**	The string allocated and initialized to 0.
*/

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)ft_memalloc(size + 1);
	return (str);
}
