/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:13:24 by odidukh           #+#    #+#             */
/*   Updated: 2018/09/24 22:58:33 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_fill_line(t_line_coord *l_c, int l, int c, t_info *info)
{
	t_point **p;

	p = info->map_with_oper;
	if (c + 1 < info->column)
	{
		l_c->x0 = p[l][c].x + WIN_X / 2;
		l_c->y0 = p[l][c].y + WIN_Y / 2;
		l_c->x1 = p[l][c + 1].x + WIN_X / 2;
		l_c->y1 = p[l][c + 1].y + WIN_Y / 2;
		line_draw(l_c, info->window, info->color);
	}
	if (l + 1 < info->line)
	{
		l_c->x0 = p[l][c].x + WIN_X / 2;
		l_c->y0 = p[l][c].y + WIN_Y / 2;
		l_c->x1 = p[l + 1][c].x + WIN_X / 2;
		l_c->y1 = p[l + 1][c].y + WIN_Y / 2;
		line_draw(l_c, info->window, info->color);
	}
}

void	ft_display(t_info *info)
{
	int				l;
	int				c;
	t_line_coord	*l_c;

	l = 0;
	l_c = malloc(sizeof(t_line_coord));
	while (l < info->line)
	{
		c = 0;
		while (c < info->column)
		{
			ft_fill_line(l_c, l, c, info);
			c++;
		}
		l++;
	}
	free(l_c);
}
