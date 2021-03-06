/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:55:32 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/12 17:40:27 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Description
**	Allocates (with malloc(3)) and returns a “fresh” link. The variables content
**	and content_size of the new link are ini- tialized by copy of the parameters
**	of the function. If the parameter content is nul, the variable content is
**	initialized to NULL and the variable content_size is initialized to 0 even
**	if the parameter content_size isn’t. The variable next is initialized
**	to NULL. If the allocation fails, the function returns NULL.
** Param. #1
**	The content to put in the new link.
** Param. #2
**	The size of the content of the new link.
** Return value
**	The new link.
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;

	if (!(new_elem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new_elem->content = NULL;
		new_elem->content_size = 0;
		new_elem->next = NULL;
		return (new_elem);
	}
	if (!(new_elem->content = (void *)malloc(content_size)))
		return (NULL);
	ft_memcpy(new_elem->content, content, content_size);
	new_elem->content_size = content_size;
	new_elem->next = NULL;
	return (new_elem);
}
