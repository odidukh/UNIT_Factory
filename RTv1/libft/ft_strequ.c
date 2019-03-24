/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:26:23 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/13 13:26:28 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Lexicographical comparison between s1 and s2. If the 2 strings are
**	identical the function returns 1, or 0 otherwise.
** Param. #1
**	The first string to be compared.
** Param. #2
**	The second string to be compared.
** Return value
**	1 or 0 according to if the 2 strings are identical or not.
*/

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		if (*s1 && *s2 && !(ft_strcmp(s1, s2)))
			return (1);
		if ((*s1 == '\0') && (*s2 == '\0'))
			return (1);
	}
	return (0);
}
