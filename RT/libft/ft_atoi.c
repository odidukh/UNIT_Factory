/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 15:20:01 by oponomar          #+#    #+#             */
/*   Updated: 2018/11/08 11:13:13 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	int				i;
	long			nbr;
	long			sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == 43)
		i++;
	else if (str[i] == 45)
	{
		sign = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
		nbr = nbr * 10 + str[i++] - 48;
	if (nbr < 0 && sign < 0)
		return (0);
	if (nbr < 0 && sign > 0)
		return (-1);
	return (nbr * sign);
}
