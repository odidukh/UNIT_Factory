/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:54:36 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/12 17:54:23 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Takes as a parameter the adress of a pointer to a link and frees the memory
**	of this link and every successors of that link using the functions del and
**	free(3). Finally the pointer to the link that was just freed must be set to
**	NULL (quite similar to the function ft_memdel from the mandatory part).
** Param. #1
**	The address of a pointer to the first link of a list that needs to be freed.
** Return value
**	None.
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (alst && *alst && del)
	{
		while (*alst)
		{
			next = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = next;
		}
	}
}
