/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:47:12 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 18:37:28 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Allocates (with malloc(3)) and returns a “fresh” memory area. The memory
**	allocated is initialized to 0. If the allocation fails, the function
**	returns NULL.
** Param. #1
**	The size of the memory that needs to be allocated.
** Return value
**	The allocated memory area.
*/

void	*ft_memalloc(size_t size)
{
	char	*ptr;

	ptr = malloc(size);
	if (ptr != NULL)
		ft_bzero(ptr, size);
	return (ptr);
}
