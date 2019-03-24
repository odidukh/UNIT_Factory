/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:23:09 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/10 16:12:09 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memccpy() function copies bytes from string src to string dst.
** If the character c (as converted to an unsigned char) occurs in the string
** src, the copy stops an a pointer to the byte after the copy of c in
** the string dst is returned.  Otherwise, n bytes are copied,
** and a NULL pointer is returned.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	int				i;

	i = 0;
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	while ((size_t)i++ < n)
	{
		*tmp_dst++ = *tmp_src;
		if (*tmp_src++ == (unsigned char)c)
			return ((unsigned char *)dst + i);
	}
	return (NULL);
}
