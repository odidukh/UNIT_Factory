/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:59:22 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/11 20:34:18 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Outputs the char c to the file descriptor fd.
** Param. #1
**	The character to output.
** Param. #2
**	The file descriptor.
** Return value
** 	None.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
