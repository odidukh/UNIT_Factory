/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:47:12 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/13 12:57:48 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Outputs the integer n to the standard output.
** Param. #1
**	The integer to output.
** Return value
**	None.
*/

void	ft_putnbr(int n)
{
	int res_n;
	int ten;

	ten = 1;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		ft_putchar('-');
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
		ft_putchar((res_n / ten) + 48);
		res_n = res_n - (res_n / ten) * ten;
		ten /= 10;
	}
	ft_putchar(res_n + 48);
}
