/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 11:08:42 by oponomar          #+#    #+#             */
/*   Updated: 2018/08/13 15:08:05 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*dup;

	i = 0;
	dup = NULL;
	if (s1)
	{
		if (ft_strlen(s1) < n)
			n = ft_strlen(s1);
		if ((dup = (char *)malloc(n + 1)))
		{
			while (i < n)
			{
				dup[i] = s1[i];
				i++;
			}
			dup[i] = 0;
		}
	}
	return (dup);
}
