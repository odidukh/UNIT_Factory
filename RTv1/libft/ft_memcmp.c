/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:54:43 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/10 17:57:32 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memcmp() function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
** The memcmp() function returns zero if the two strings are identical,
** otherwise returns the difference between the first two differing bytes
** (treated as unsigned char values, so that `\200' is greater than `\0',
** for example).  Zero-length strings are always identical.
** This behavior is not required by C and
** portable code should only depend on the sign of the returned value.
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*tmp_s1;
	char	*tmp_s2;
	int		i;

	tmp_s1 = (char *)s1;
	tmp_s2 = (char *)s2;
	i = 0;
	while ((size_t)i++ < n)
	{
		if ((unsigned char)(*tmp_s1) != (unsigned char)(*tmp_s2))
			return ((unsigned char)(*tmp_s1) - (unsigned char)(*tmp_s2));
		tmp_s1++;
		tmp_s2++;
	}
	return (0);
}
