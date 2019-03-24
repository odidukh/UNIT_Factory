/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:20:55 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/20 18:47:46 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				clear_info(t_info *info, int free_surface)
{
	if (info->cam)
	{
		free(info->cam);
		info->cam = NULL;
	}
	if (info->screen_buff)
	{
		if (free_surface)
		{
			free(info->screen_buff);
			info->screen_buff = NULL;
		}
		else
			ft_memset(info->screen_buff, 0, info->surface->w
						* info->surface->h * sizeof(t_objlst *));
	}
	if (info->surface && free_surface)
	{
		SDL_FreeSurface(info->surface);
		info->surface = NULL;
	}
	ltlst_delete(&info->ltlst);
	objlst_delete(&info->objlst);
}
