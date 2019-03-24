/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <odidukh@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:41:37 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/18 20:41:40 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_parts(char *str)
{
	int			parts;

	parts = 0;
	while (*str)
	{
		if (is_whitespace(*str))
			str++;
		else if (!is_whitespace(*str))
		{
			parts++;
			while (!is_whitespace(*str) && *str)
				str++;
		}
	}
	return (parts);
}

static char		**split(char *str, int parts)
{
	char		**arr;
	int			start;
	int			end;
	int			i;

	arr = (char **)malloc(sizeof(char *) * (parts + 1));
	arr[parts] = NULL;
	start = 0;
	i = 0;
	while (parts--)
	{
		while (is_whitespace(str[start]) && str[start])
			start++;
		if (!is_whitespace(str[start]) && str[start])
		{
			end = start;
			while (!is_whitespace(str[end]) && str[end])
				end++;
			arr[i++] = ft_strndup(&str[start], end - start);
			start = end;
		}
	}
	return (arr);
}

char			**ft_strsplit(char *str)
{
	int			parts;
	char		**arr;

	if (!str)
		return (NULL);
	parts = count_parts(str);
	if (!parts)
	{
		parts = 1;
		arr = (char **)malloc(sizeof(char *) * (parts + 1));
		arr[0] = ft_strdup("");
	}
	else
		arr = split(str, parts);
	arr[parts] = NULL;
	return (arr);
}
