/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:15:45 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 18:10:22 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strncpy() function copy at most len characters
** from src into dst. If src is less than len characters long,
** the remainder of dst is filled with `\0' characters.
** Otherwise, dst is not terminated.
** strncpy() functions return dst.
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*tmp_dst;
	char	*tmp_src;
	int		i;

	tmp_dst = dst;
	tmp_src = (char *)src;
	i = 0;
	while (((size_t)i++ < len) && (*tmp_dst++ = *tmp_src++))
		continue;
	while ((size_t)i++ < len)
		*tmp_dst++ = '\0';
	return (dst);
}
