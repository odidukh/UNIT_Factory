/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:34:18 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/13 13:04:02 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Outputs the integer n to the file descriptor fd.
** Param. #1
**	The integer to print.
** Param. #2
**	The file descriptor.
** Return value
**	None.
*/

void	ft_putnbr_fd(int n, int fd)
{
	int res_n;
	int ten;

	ten = 1;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	res_n = n;
	while (n / 10)
	{
		n = n / 10;
		ten *= 10;
	}
	while (ten != 1)
	{
		ft_putchar_fd((res_n / ten) + 48, fd);
		res_n = res_n - (res_n / ten) * ten;
		ten /= 10;
	}
	ft_putchar_fd(res_n + 48, fd);
}
