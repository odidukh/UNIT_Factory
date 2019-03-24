/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:14:03 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 18:15:51 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Outputs the string s to the file descriptor fd.
** Param. #1
**	The string to output.
** Param. #2
**	The file descriptor.
** Return value
**	None.
*/

void	ft_putstr_fd(char const *s, int fd)
{
	if (s)
	{
		while (*s)
			ft_putchar_fd(*s++, fd);
	}
}
