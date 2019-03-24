/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_split_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <odidukh@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:41:19 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/18 20:41:23 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_del_split_arr(char **array)
{
	int	i;

	if (!(array))
		return ;
	i = -1;
	while (array[++i])
	{
		free(array[i]);
	}
	free(array);
	array = NULL;
}
