/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:40:50 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/11 20:25:16 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Allocates (with malloc(3)) and returns an array of “fresh” strings (all
**	ending with ’\0’, including the array itself) ob- tained by spliting s using
**	the character c as a delimiter. If the allocation fails the function returns
**	NULL. Example : ft_strsplit("*hello*fellow***students*", ’*’) returns the
**	array ["hello", "fellow", "students"].
** Param. #1
**	The string to split.
** Param. #2
**	The delimiter character.
** Return value
**	The array of “fresh” strings result of the split.
*/

static int			ft_word_counter(char const *s, char c)
{
	int		counter;

	counter = 0;
	while (*s)
	{
		while ((*s == c) && (*s))
			s++;
		if (*s)
			counter++;
		while ((*s != c) && (*s))
			s++;
	}
	return (counter);
}

static int			ft_letter_counter(char const *str_bgn, char c)
{
	int		counter;

	counter = 0;
	while ((*str_bgn != c) && (*str_bgn))
	{
		counter++;
		str_bgn++;
	}
	return (counter);
}

static const char	*ft_word_begin(char const *s, char c)
{
	while (*s)
	{
		if ((*s != c) && (*s))
			return (s);
		s++;
	}
	return (NULL);
}

char				**ft_strsplit(char const *s, char c)
{
	int		w_count;
	int		l_count;
	char	*wrd_bgn;
	char	**new_str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	w_count = ft_word_counter(s, c);
	if (!(new_str = malloc((w_count + 1) * sizeof(char *))))
		return (NULL);
	while (i < w_count)
	{
		wrd_bgn = (char *)ft_word_begin(s, c);
		l_count = ft_letter_counter(wrd_bgn, c);
		if (!(new_str[i] = ft_strnew(l_count)))
			return (NULL);
		new_str[i] = ft_strncpy(new_str[i], wrd_bgn, l_count);
		new_str[i][l_count + 1] = '\0';
		s = wrd_bgn + l_count;
		i++;
	}
	new_str[i] = NULL;
	return (new_str);
}
