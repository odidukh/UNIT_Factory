/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:07:11 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 18:04:54 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The bzero() function writes n zeroed bytes to the string s.  If n is zero,
** bzero() does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*temp_ptr;

	temp_ptr = (char *)s;
	i = 0;
	while (i++ < n)
		*temp_ptr++ = '\0';
}
