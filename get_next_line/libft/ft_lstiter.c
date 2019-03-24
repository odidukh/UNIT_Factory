/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:18:02 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/12 21:05:06 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Iterates the list lst and applies the function f to each link.
** Param. #1
**	A pointer to the first link of a list.
** Param. #2
**	The address of a function to apply to each link of a list.
** Return value
**	None.
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst && f)
	{
		while (lst)
		{
			(*f)(lst);
			lst = lst->next;
		}
	}
}
