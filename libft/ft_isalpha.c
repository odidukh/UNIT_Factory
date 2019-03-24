/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:16:36 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 19:50:58 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	The isalpha() function tests for any character for which isupper(3) or
**	islower(3) is true.  The value of the argument must be representable as
**	an unsigned char or the value of EOF.
** RETURN VALUES
**	The isalpha() function returns zero if the character tests false and
**	returns non-zero if the character tests true.
*/

int		ft_isalpha(int c)
{
	int		ch;

	ch = c;
	if ((ch >= 65 && (ch <= 90)) || ((ch >= 97) && ((ch <= 122))))
		return (1);
	return (0);
}
