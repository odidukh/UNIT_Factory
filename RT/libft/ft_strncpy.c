/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 18:42:21 by oponomar          #+#    #+#             */
/*   Updated: 2018/03/29 15:09:30 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char	*start;

	start = dest;
	while (*src)
	{
		if (len--)
			*dest++ = *src++;
		else
			return (start);
	}
	while (len--)
		*dest++ = '\0';
	return (start);
}
