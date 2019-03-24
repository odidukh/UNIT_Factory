/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:41:17 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 16:36:47 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	The strchr() function locates the first occurrence of c
**	(converted to a char) in the
**	string pointed to by s.  The terminating null character is considered to be
**	part of the string; therefore if c is `\0', the functions locate
**	the terminating `\0'.
**
**	The strrchr() function is identical to strchr(), except it locates the
**	last occurrence of c.
** RETURN VALUES
**	The functions strchr() and strrchr() return a pointer to the located
**	character, or NULL if the character does not appear in the string.
*/

char	*ft_strchr(const char *s, int c)
{
	char	symbl;

	symbl = (char)c;
	while (*s != symbl)
		if (*s++ == '\0')
			return (NULL);
	return ((char *)s);
}
