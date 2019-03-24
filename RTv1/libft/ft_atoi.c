/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 20:35:50 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/10 18:25:33 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	The atoi() function converts the initial portion of the string pointed
**	to by str to int representation.
*/

static char	*ft_iswhitespace(char *temp_str)
{
	while (*temp_str == ' ' || (*temp_str >= 9 && *temp_str <= 13))
		temp_str++;
	return (temp_str);
}

int			ft_atoi(const char *str)
{
	char				*temp_str;
	int					sign;
	unsigned long int	number;

	temp_str = (char *)str;
	sign = 1;
	number = 0;
	temp_str = ft_iswhitespace(temp_str);
	if (*temp_str == '+')
		temp_str++;
	else if (*temp_str == '-')
	{
		sign = -1;
		temp_str++;
	}
	while (*temp_str && ft_isdigit(*temp_str))
	{
		number = (number * 10) + (*temp_str - '0');
		if (number >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (number > 9223372036854775807 && sign == -1)
			return (0);
		temp_str++;
	}
	return ((int)(number * sign));
}
