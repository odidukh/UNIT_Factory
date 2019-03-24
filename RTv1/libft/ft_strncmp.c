/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 19:04:23 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/10 18:01:14 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	The strcmp() and strncmp() functions lexicographically compare the
**	null-terminated strings s1 and s2.
** RETURN VALUES
**	The strcmp() and strncmp() functions return an integer greater than,
**	equal to, or less than 0, according as the string s1 is greater than,
**	equal to, or less than the string s2. The comparison is done using
**	unsigned characters, so that `\200' is greater than `\0'.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n--)
	{
		if (((unsigned char)(*s1) - (unsigned char)(*s2)))
			return (((unsigned char)(*s1) - (unsigned char)(*s2)));
		s1++;
		s2++;
	}
	return (0);
}
