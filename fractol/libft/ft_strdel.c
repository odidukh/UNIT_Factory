/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:20:14 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 18:43:19 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Takes as a parameter the address of a string that need to be freed with
**	free(3), then sets its pointer to NULL.
** Param. #1
**	The string’s address that needs to be freed and its pointer set to NULL.
** Return value
**	None.
*/

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}
