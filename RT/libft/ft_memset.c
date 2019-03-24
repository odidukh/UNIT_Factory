/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:12:14 by oponomar          #+#    #+#             */
/*   Updated: 2018/08/13 15:06:58 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memset(void *b, int c, size_t len)
{
	size_t					i;
	void					*temp;

	i = 0;
	temp = b;
	while (i < len)
	{
		*(unsigned char *)b = (unsigned char)c;
		b++;
		i++;
	}
	return (temp);
}
