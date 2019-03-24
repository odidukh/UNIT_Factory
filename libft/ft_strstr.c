/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:37:39 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/11 14:34:44 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	The strstr() function locates the first occurrence of the null-terminated
**	string needle in the null-terminated string haystack.
** RETURN VALUES
**	If needle is an empty string, haystack is returned; if needle occurs
**	nowhere in haystack, NULL is returned; otherwise a pointer to the first
**	character of the first occurrence of needle is returned.
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	ndl_len;
	char	*ptr;

	ndl_len = ft_strlen(needle);
	ptr = NULL;
	if (!ndl_len)
		return ((char *)haystack);
	while (*haystack)
	{
		if (ft_memcmp(haystack, needle, ndl_len) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (ptr);
}
