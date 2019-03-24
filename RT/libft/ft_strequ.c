/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:15:20 by oponomar          #+#    #+#             */
/*   Updated: 2018/04/07 12:48:43 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strequ(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] == s2[i] && s1[i] && s2[i])
			i++;
		if (s1[i] - s2[i] == 0)
			return (1);
	}
	return (0);
}
