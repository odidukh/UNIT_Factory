/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:47:10 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/11 19:57:33 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 	Description
**	Applies the function f to each character of the string passed as argument
**	by giving its index as first argument to create a “fresh” new string
**	(with malloc(3)) resulting from the successive applications of f.
** 	Param. #1
**	The string to map.
** 	Param. #2
**	The function to apply to each character of s and its index.
** 	Return value
**	The “fresh” string created from the successive applications of f.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_bgn;
	char	*str;
	size_t	i;

	if (s && f && (str = ft_strnew(ft_strlen(s))))
	{
		i = 0;
		str_bgn = str;
		while (*s)
			*str++ = (*f)(i++, (char)*s++);
		*str = '\0';
		return (str_bgn);
	}
	return (NULL);
}
