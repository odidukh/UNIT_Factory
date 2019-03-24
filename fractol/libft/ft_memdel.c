/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:19:44 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/10 19:32:17 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Takes as a parameter the address of a memory area that needs to be freed
**	with free(3), then puts the pointer to NULL.
** Param. #1
**	A pointer’s address that needs its memory freed and set to NULL.
** Return value
**	None.
*/

void	ft_memdel(void **ap)
{
	if (ap)
	{
		if (*ap)
			free(*ap);
		*ap = NULL;
	}
}
