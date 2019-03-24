/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:34:41 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 16:35:03 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strcpy() function copy the string src to dst (including the terminating
** `\0' character.
** The strcpy() function return dst.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	char	*tmp_src;
	char	*tmp_dst;

	tmp_src = (char *)src;
	tmp_dst = dst;
	while ((*tmp_dst++ = *tmp_src++))
		continue;
	return (dst);
}
