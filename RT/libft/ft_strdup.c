/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:31:22 by oponomar          #+#    #+#             */
/*   Updated: 2018/08/13 15:06:52 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char						*ft_strdup(const char *s1)
{
	char					*dup;
	size_t					i;
	size_t					size;

	dup = NULL;
	i = 0;
	size = ft_strlen(s1);
	if (s1)
	{
		dup = (char *)malloc(size + 1);
		if (dup)
		{
			while (i < size)
			{
				dup[i] = s1[i];
				i++;
			}
			dup[i] = 0;
		}
	}
	return (dup);
}
