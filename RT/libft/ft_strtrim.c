/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:23:29 by oponomar          #+#    #+#             */
/*   Updated: 2018/11/07 14:34:43 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s, int free_src)
{
	size_t	start;
	size_t	end;
	char	*new;

	new = NULL;
	if (s)
	{
		start = 0;
		end = ft_strlen(s);
		if (end == 0)
			return ((char *)ft_memalloc(1));
		while (is_whitespace(s[start]))
			start++;
		if (start == end)
			return ((char *)ft_memalloc(1));
		while (s[end] == 0 || is_whitespace(s[end]))
			end--;
		new = ft_strsub(s, start, end - start + 1);
		if (free_src)
			free(s);
	}
	return (new);
}
