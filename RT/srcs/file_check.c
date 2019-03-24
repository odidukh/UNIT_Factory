/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <odidukh@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:42:11 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/18 20:42:16 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static int		match_check(char left, char right)
{
	if ((left == '[' && right == ']') || (left == '{' && right == '}'))
		return (1);
	return (0);
}

int				check_brackets(char *text)
{
	int		last;
	char	*brackets_array;

	last = 0;
	brackets_array = ft_strnew(ft_strlen(text));
	while (*text)
	{
		if (*text == '[' || *text == '{')
			brackets_array[last++] = *text;
		if (*text == ']' || *text == '}')
		{
			if (!match_check(brackets_array[--last], *text))
			{
				free(brackets_array);
				return (0);
			}
		}
		text++;
	}
	free(brackets_array);
	return (1);
}

int				ft_jsonsym(char a)
{
	if (a == ',' || a == '.' || a == '-' || a == '\"' ||
		a == ':' || a == '[' || a == '{' || a == '}' ||
		a == ']' || a == ';' || a == '_')
		return (1);
	return (0);
}

int				check_symbols(char *text)
{
	while (*text)
	{
		if (!ft_isalnum(*text) && !is_whitespace(*text) && !ft_jsonsym(*text))
			return (0);
		text++;
	}
	return (1);
}

int				check_file_text(char *text)
{
	if ((check_brackets(text)) && (check_symbols(text)))
		return (1);
	return (0);
}
