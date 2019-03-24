/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:00:14 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/20 16:54:11 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_objlst				*objlst_new(void *obj)
{
	t_objlst			*new;

	new = NULL;
	if (obj)
	{
		new = (t_objlst *)malloc(sizeof(t_objlst));
		new->color = 0;
		new->next = NULL;
		new->obj = obj;
		new->reflection = 0;
		new->diff_map = NULL;
		new->norm_map = NULL;
		new->transparency = 0;
		new->ior = 0;
		ft_memset(new->tmapping, 0, sizeof(double) * 7);
		new->tmapping[SCALE] = 1.0;
	}
	return (new);
}

void					objlst_add(t_objlst **list, t_objlst *node)
{
	int					index;

	index = 0;
	if (*list)
		index = ((t_plane *)(*list)->obj)->index;
	((t_plane *)node->obj)->index = index + 1;
	node->next = *list;
	*list = node;
}

void					objlst_delete(t_objlst **list)
{
	t_objlst			*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->obj);
		if ((*list)->diff_map)
			SDL_FreeSurface((*list)->diff_map);
		if ((*list)->norm_map)
			SDL_FreeSurface((*list)->norm_map);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}
