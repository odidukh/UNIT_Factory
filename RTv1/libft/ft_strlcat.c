/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:04:52 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/10 16:08:50 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strlcpy() and strlcat() functions copy and concatenate strings
** with the same input parameters and output result as snprintf(3).i
** They are designed to be safer, more consistent, and less error prone
** replacements for the easily misused functions strncpy(3) and
** strncat(3). strlcat() appends string src to the end of dst.
** It will append at most dstsize strlen(dst) - 1 characters.
** It will then NUL-terminate, unless dstsize is 0 or the original dst string
** was longer than dstsize (in practice this should not happen as it means
** that either dstsize is incorrect or that dst is not a proper string).
**
** If the src and dst strings overlap, the behavior is undefined.
*/

size_t		ft_strlcat(char *dst, const	char *src, size_t dstsize)
{
	char		*temp_dst;
	const char	*temp_src;
	size_t		n;
	size_t		dlen;

	temp_dst = dst;
	temp_src = src;
	n = dstsize;
	while (n-- && *temp_dst)
		temp_dst++;
	dlen = temp_dst - dst;
	n = dstsize - dlen;
	if (n == 0)
		return (dlen + ft_strlen(temp_src));
	temp_dst = ft_strncat(temp_dst, temp_src, n - 1);
	return (dlen + ft_strlen(src));
}
