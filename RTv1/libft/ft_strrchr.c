/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:52:15 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 16:37:00 by odidukh          ###   ########.fr       */
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

char	*ft_strrchr(const char *s, int c)
{
	char	symbl;
	char	*temp_res;

	symbl = (char)c;
	temp_res = NULL;
	while (*(s) != '\0' && symbl != '\0')
	{
		if (*s == symbl)
			temp_res = (char *)s;
		s++;
	}
	if (symbl == '\0')
	{
		while (*s != '\0')
			s++;
		temp_res = (char *)s;
	}
	return (temp_res);
}
