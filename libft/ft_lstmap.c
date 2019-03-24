/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:36:54 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/12 19:01:13 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Iterates a list lst and applies the function f to each link to create
**	a “fresh” list (using malloc(3)) resulting from the successive applications
**	of f. If the allocation fails, the function returns NULL.
** Param. #1
**	A pointer’s to the first link of a list.
** Param. #2
**	The address of a function to apply to each link of a list.
** Return value
**	The new list.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*temp;

	if (!(lst) || !(f))
		return (NULL);
	head = f(lst);
	temp = head;
	lst = lst->next;
	while (lst)
	{
		if (!(temp->next = f(lst)))
			return (NULL);
		temp = temp->next;
		lst = lst->next;
	}
	return (head);
}
