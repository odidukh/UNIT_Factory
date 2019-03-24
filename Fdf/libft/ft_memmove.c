/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:02:08 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/10 13:20:30 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memmove() function copies len bytes from string src to string dst.
** The two strings may overlap;
** the copy is always done in a non-destructive manner.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp_dst;
	char	*tmp_src;

	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	if (src > dst)
		ft_memcpy(dst, src, len);
	else
		while (len--)
		{
			tmp_dst[len] = tmp_src[len];
		}
	return (dst);
}
