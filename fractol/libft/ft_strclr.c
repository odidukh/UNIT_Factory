/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:13:32 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/11 14:33:36 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Sets every character of the string to the value ’\0’.
** Param. #1
**	The string that needs to be cleared.
** Return value
**	None.
*/

void	ft_strclr(char *s)
{
	if (s)
	{
		while (*s)
			*s++ = '\0';
	}
}
