/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:31:46 by oponomar          #+#    #+#             */
/*   Updated: 2018/08/13 15:07:07 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char *s1, char *s2, char **ptr1, char **ptr2)
{
	char	*new;
	int		i;
	size_t	s1_len;
	size_t	s2_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(s1_len + s2_len + 1);
	if (new)
	{
		while (s1_len--)
			new[i++] = *s1++;
		while (s2_len--)
			new[i++] = *s2++;
		new[i] = 0;
		if (ptr1)
			ft_strdel(ptr1);
		if (ptr2)
			ft_strdel(ptr2);
	}
	return (new);
}
