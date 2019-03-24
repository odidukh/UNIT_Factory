/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:43:46 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/11 19:58:39 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Allocates (with malloc(3)) and returns a copy of the string given as
**	argument without whitespaces at the beginning or at the end of the string.
**	Will be considered as whitespaces the following characters ’ ’, ’\n’
**	and ’\t’. If s has no whitespaces at the beginning or at the end,
**	the function returns a copy of s. If the allocation fails the function
**	returns NULL.
** Param. #1
**	The string to be trimed.
** Return value
**	The “fresh” trimmed string or a copy of s.
*/

char	*ft_strtrim(char const *s)
{
	char	*s_begin;
	char	*s_end;
	char	*res_str;
	int		s_len;

	if (!(s))
		return (NULL);
	while ((*s == ' ') || (*s == '\n') || (*s == '\t'))
		s++;
	s_begin = (char *)s;
	s_len = ft_strlen(s_begin);
	s_end = (char *)(s_begin + s_len);
	while (s_len-- > 0)
	{
		if ((*(s_begin + s_len) != ' ') && (*(s_begin + s_len) != '\n')
				&& *(s_begin + s_len) != '\t')
			break ;
		s_end = (char *)(s_begin + s_len);
	}
	res_str = malloc(s_end - s_begin + 1);
	if (!(res_str))
		return (NULL);
	res_str = ft_strncpy(res_str, s_begin, s_end - s_begin);
	*(res_str + (s_end - s_begin)) = '\0';
	return (res_str);
}
