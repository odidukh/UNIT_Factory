/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:08:36 by oponomar          #+#    #+#             */
/*   Updated: 2018/03/29 14:17:38 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	size_t			needle_len;
	size_t			haystack_len;
	char			*temp;

	i = 0;
	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	if (!needle_len)
		return ((char *)haystack);
	while (i < haystack_len && i + needle_len <= len)
	{
		temp = ft_strsub(haystack, i, needle_len);
		if (ft_strnequ(temp, needle, len))
			return ((char *)haystack + i);
		i++;
		free(temp);
	}
	return (NULL);
}
