/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:48:57 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/10 14:14:44 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strcat() and strncat() functions append a copy of the null-terminated
** string s2 to the end of the null-terminated string s1, then add
** a terminating `\0'. The string s1 must have sufficient space to
** hold the result. The source and destination strings should not overlap,
** as the behavior is undefined.
** The strcat() and strncat() functions return the pointer s1.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*temp_s1;
	char	*temp_s2;
	int		i;

	temp_s1 = (char *)s1;
	temp_s2 = (char *)s2;
	i = 0;
	while (*temp_s1)
		temp_s1++;
	while (((size_t)i++ < n) && *temp_s2)
		*temp_s1++ = *temp_s2++;
	*temp_s1 = '\0';
	return (s1);
}
