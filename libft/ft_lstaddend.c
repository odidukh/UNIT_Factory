/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:16:04 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/14 15:29:28 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	ft_lstaddend adds lst2 to the end of lst1.
** Param. #1
**	A pointer to the list to which another lst is adding.
** Param. #2
**	A pointer to the list which is adding.
** Return value
**	A pointer to the lst1.
*/

t_list	*ft_lstaddend(t_list *lst1, t_list *lst2)
{
	t_list	*tmp_lst1;

	if (lst1 && lst2)
	{
		tmp_lst1 = lst1;
		while (tmp_lst1->next)
			tmp_lst1 = tmp_lst1->next;
		tmp_lst1->next = lst2;
		return (lst1);
	}
	return (NULL);
}
