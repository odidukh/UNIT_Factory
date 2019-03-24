/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:31:55 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/12 20:44:22 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
**	representing the integer n given as argument. Negative numbers must be
**	supported. If the allocation fails, the function returns NULL.
** Param. #1
**	The integer to be transformed into a string.
** Return value
**	The string representing the integer passed as argument.
*/

static char	*ft_drive(int n, int i, int ten, int res_n)
{
	char	str[12];

	if (n < 0)
	{
		str[i++] = '-';
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
		str[i++] = (res_n / ten) + 48;
		res_n = res_n - (res_n / ten) * ten;
		ten /= 10;
	}
	str[i++] = res_n + 48;
	str[i] = '\0';
	return (ft_strdup(str));
}

char		*ft_itoa(int n)
{
	int		res_n;
	int		ten;
	int		i;

	i = 0;
	ten = 1;
	res_n = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	return (ft_drive(n, i, ten, res_n));
}
