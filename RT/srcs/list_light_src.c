/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_light_src.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:01:35 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/20 16:53:50 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

t_ltlst					*ltlst_new(int type, double *pos, double power)
{
	t_ltlst				*new;

	new = (t_ltlst *)malloc(sizeof(t_ltlst));
	new->type = type;
	new->power = power;
	new->pos[X] = pos[X];
	new->pos[Y] = pos[Y];
	new->pos[Z] = pos[Z];
	if (type == TYPE_DLIGHT)
	{
		new->pos[OX] = pos[OX] * M_PI / 180.0;
		new->pos[OY] = pos[OY] * M_PI / 180.0;
		new->pos[OZ] = pos[OZ] * M_PI / 180.0;
		new->dir[X] = 0;
		new->dir[Y] = 1;
		new->dir[Z] = 0;
		vecrot_ox(new->dir, new->pos[OX], NULL);
		vecrot_oy(new->dir, new->pos[OY], NULL);
		vecrot_oz(new->dir, new->pos[OZ], NULL);
	}
	return (new);
}

void					ltlst_add(t_ltlst **list, t_ltlst *node)
{
	node->next = *list;
	*list = node;
}

void					ltlst_delete(t_ltlst **list)
{
	t_ltlst				*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	*list = NULL;
}
