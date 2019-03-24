/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:15:14 by oponomar          #+#    #+#             */
/*   Updated: 2018/03/24 15:17:24 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] == s2[i] && s1[i] && s2[i] && (size_t)i < n)
			i++;
		if ((size_t)i == n || s1[i] == s2[i])
			return (1);
	}
	return (0);
}
