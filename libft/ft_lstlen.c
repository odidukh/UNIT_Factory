/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:57:54 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/14 15:38:35 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	ft_lstlen calculates number on elements in the list.
** Param. #1
**	The pointer of the first link of a list that needs to calculate length.
*/

int		ft_lstlen(t_list *alst)
{
	t_list	*current;
	int		counter;

	counter = -1;
	if (alst)
	{
		counter = 1;
		current = alst->next;
		while (current)
		{
			counter++;
			alst = current;
			current = alst->next;
		}
	}
	return (counter);
}
