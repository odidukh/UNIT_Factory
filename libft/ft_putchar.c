/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:32:03 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/11 19:55:21 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Outputs the character c to the standard output.
** Param. #1
**	The character to output.
** Return value
**	None.
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
