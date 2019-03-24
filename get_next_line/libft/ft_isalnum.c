/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 15:49:40 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 19:54:13 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	The isalnum() function tests for any character for which isalpha(3) or
**	isdigit(3) is true.  The value of the argument must be representable as
**	an unsigned char or the value of EOF.
** RETURN VALUES
**	The isalnum() function returns zero if the character tests false and
**	returns non-zero if the character tests true.
*/

int		ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
