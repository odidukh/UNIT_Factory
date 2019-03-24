/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 10:28:36 by oponomar          #+#    #+#             */
/*   Updated: 2018/08/13 15:06:32 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	len;

	if (s)
	{
		len = ft_strlen(s) + 1;
		while (len--)
		{
			if (*(unsigned char *)s == (unsigned char)c)
				return ((char *)s);
			s++;
		}
	}
	return (NULL);
}
