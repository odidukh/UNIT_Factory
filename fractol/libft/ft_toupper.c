/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:27:26 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 19:56:15 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	The toupper() function converts a lower-case letter to the corresponding
**	upper-case letter.  The argument must be representable as an unsigned
**	char or the value of EOF.
** RETURN VALUES
**	If the argument is a lower-case letter, the toupper() function returns
**	the corresponding upper-case letter if there is one; otherwise,
**	the argument is returned unchanged.
*/

int		ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		return (c - 32);
	return (c);
}
