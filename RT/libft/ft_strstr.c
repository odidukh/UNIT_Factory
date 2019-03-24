/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:32:08 by oponomar          #+#    #+#             */
/*   Updated: 2018/11/08 14:50:26 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	size_t			needle_len;
	size_t			haystack_len;

	i = 0;
	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	if (!needle_len)
		return ((char *)haystack);
	while (i < haystack_len)
	{
		if (ft_strnequ(haystack + i, needle, needle_len))
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
