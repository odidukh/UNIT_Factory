/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 14:19:12 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/13 18:39:40 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memcpy() function copies n bytes from memory area src to memory area dst.
** If dst and src overlap, behavior is undefined.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*temp_dst;
	char	*temp_src;

	i = 0;
	if (!dst && !src)
		return (NULL);
	temp_dst = (char *)dst;
	temp_src = (char *)src;
	while ((size_t)i++ < n)
		*temp_dst++ = *temp_src++;
	return (dst);
}
