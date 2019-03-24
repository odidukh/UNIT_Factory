/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:18:21 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/11 15:34:04 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Allocates (with malloc(3)) and returns a “fresh” string ending with ’\0’,
**	result of the concatenation of s1 and s2. If the allocation fails the
**	function returns NULL.
** Param. #1
**	The prefix string.
** Param. #2
**	The suffix string.
** Return value
**	The “fresh” string result of the concatenation of the 2 strings.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*res_str;

	if (!(s1) || !(s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(res_str = ft_strnew(len)))
		return (NULL);
	res_str = ft_strcpy(res_str, s1);
	res_str = ft_strcat(res_str, s2);
	return (res_str);
}
