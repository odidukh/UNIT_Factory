/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:27:41 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 18:04:23 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*fst_arg;

	i = 0;
	fst_arg = (char *)b;
	while ((size_t)i++ < len)
		*fst_arg++ = (unsigned char)c;
	return (b);
}
