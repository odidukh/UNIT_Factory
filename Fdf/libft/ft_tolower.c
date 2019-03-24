/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:47:19 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 19:56:39 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	The tolower() function converts an upper-case letter to the corresponding
**	lower-case letter.  The argument must be representable as an unsigned
**	char or the value of EOF.
** RETURN VALUES
**	If the argument is an upper-case letter, the tolower() function returns
**	the corresponding lower-case letter if there is one; otherwise,
**	the argument is returned unchanged.
*/

int		ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		return (c + 32);
	return (c);
}
