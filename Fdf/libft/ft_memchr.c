/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:22:21 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 20:02:18 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memchr() function locates the first occurrence of
** c (converted to an unsigned char) in string s.The memchr() function returns
** a pointer to the byte located, or NULL if no such byteexists within n bytes.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	i = 0;
	while ((size_t)i++ < n)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		tmp++;
	}
	return (NULL);
}
