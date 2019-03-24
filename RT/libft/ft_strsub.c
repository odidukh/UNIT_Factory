/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:49:07 by oponomar          #+#    #+#             */
/*   Updated: 2018/09/04 12:40:01 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	substr = (char *)malloc(len + 1);
	ft_memset(substr, 0, len + 1);
	i = 0;
	if (substr && s)
	{
		while (s[start] && i < len)
		{
			substr[i] = s[start];
			i++;
			start++;
		}
		return (substr);
	}
	return (NULL);
}
