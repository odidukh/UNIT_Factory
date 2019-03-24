/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:54:22 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/11 14:58:57 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Allocates (with malloc(3)) and returns a “fresh” substring from the string
**	given as argument. The substring begins at indexstart and is of size len.
**	If start and len aren’t refering to a valid substring, the behavior is
**	undefined. If the allocation fails, the function returns NULL.
** Param. #1
**	The string from which create the substring.
** Param. #2
**	The start index of the substring.
** Param. #3
**	The size of the substring.
** Return value
**	The substring.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;

	if (!s)
		return (NULL);
	if (!(sub_str = ft_strnew(len)))
		return (NULL);
	sub_str = ft_strncpy(sub_str, s + start, len);
	return (sub_str);
}
