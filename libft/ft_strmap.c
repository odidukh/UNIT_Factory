/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:07:36 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/10 19:41:44 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Applies the function f to each character of the string given as argument
**	to create a “fresh” new string (with malloc(3)) resulting from the
**	successive applications of f.
** Param. #1
**	The string to map.
** Param. #2
**	The function to apply to each character of s.
** Return value
**	The “fresh” string created from the successive applications of f.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str_bgn;
	char	*str;

	if (s && f)
	{
		if (*s && *f && (str = ft_strnew(ft_strlen(s))))
		{
			str_bgn = str;
			while (*s)
				*str++ = (*f)((char)*s++);
			*str = '\0';
			return (str_bgn);
		}
	}
	return (NULL);
}
