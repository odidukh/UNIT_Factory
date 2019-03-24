/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:26:38 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/22 12:50:25 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void	init_ui(t_objlst *list, t_ui_panel *panel)
{
	while (list)
	{
		list->init_ui(panel, list);
		list = list->next;
	}
}

void		scene_selection_event(t_ui_panel *p, t_info *info, SDL_Event *e)
{
	char	fpath[128];
	int		pos;

	if (kiss_combobox_event(&p->cmb_scenes, e, &p->is_changed))
	{
		update_dirent("scenes/", &p->entries, ".json_like");
		pos = p->cmb_scenes.textbox.selectedline
			+ p->cmb_scenes.textbox.firstline;
		if (pos > 0 && pos < p->entries.length)
		{
			clear_info(info, 0);
			ft_memset(fpath, 0, 128);
			ft_strncpy(fpath, "scenes/", 7);
			ft_strncpy(fpath + 7, ((char **)p->entries.data)[pos], 121);
			p->is_valid_file = 0;
			if (parse_file(fpath, info))
			{
				init_ui(info->objlst, p);
				info->selected = NULL;
				p->is_valid_file = 1;
			}
			info->is_at_viewport = 1;
			info->is_changed = 1;
		}
	}
}

void		dmap_selection_event(t_ui_panel *p, t_info *info, SDL_Event *e)
{
	char	ftex[128];
	int		pos;

	if (kiss_combobox_event(&p->cmb_diff_map, e, &p->is_changed)
		&& info->selected)
	{
		pos = p->cmb_diff_map.textbox.selectedline
			+ p->cmb_diff_map.textbox.firstline;
		free_surface(&info->selected->diff_map);
		free_texture(&p->dmap_preview);
		if (pos > 0 && pos < p->textures.length)
		{
			ft_memset(ftex, 0, 128);
			ft_strncpy(ftex, "textures/", 9);
			ft_strncpy(ftex + 9, ((char **)p->textures.data)[pos], 119);
			info->selected->diff_map = load_texture(ftex, NULL);
			p->dmap_preview = SDL_CreateTextureFromSurface(p->renderer,
													info->selected->diff_map);
		}
		info->is_at_viewport = 1;
		info->is_changed = 1;
		update_dirent("textures/", &p->textures, ".png");
	}
}

void		nmap_selection_event(t_ui_panel *panel, t_info *info, SDL_Event *e)
{
	char	ftex[128];
	int		pos;

	if (kiss_combobox_event(&panel->cmb_norm_map, e, &panel->is_changed)
		&& info->selected)
	{
		pos = panel->cmb_norm_map.textbox.selectedline
			+ panel->cmb_norm_map.textbox.firstline;
		free_surface(&info->selected->norm_map);
		free_texture(&panel->nmap_preview);
		if (pos > 0 && pos < panel->textures.length)
		{
			ft_memset(ftex, 0, 128);
			ft_strncpy(ftex, "textures/", 9);
			ft_strncpy(ftex + 9, ((char **)panel->textures.data)[pos], 119);
			info->selected->norm_map = load_texture(ftex, NULL);
			panel->nmap_preview = SDL_CreateTextureFromSurface(panel->renderer,
													info->selected->norm_map);
		}
		info->is_at_viewport = 1;
		info->is_changed = 1;
		update_dirent("textures/", &panel->textures, ".png");
	}
}
