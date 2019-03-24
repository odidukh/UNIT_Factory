/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_ui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:19:20 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/20 18:06:31 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void				kiss_update_surface(SDL_Surface *surface, kiss_image *image,
										kiss_array *a, SDL_Renderer *renderer)
{
	if (!image->image)
		kiss_array_append(a, TEXTURE_TYPE, image->image);
	else
		SDL_DestroyTexture(image->image);
	image->image = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_QueryTexture(image->image, NULL, NULL, &image->w, &image->h);
	image->magic = KISS_MAGIC;
}

void				update_dirent(char *dir, kiss_array *entries, char *ftype)
{
	kiss_dirent		*entry;
	kiss_dir		*kd;

	if ((kd = kiss_opendir(dir)))
	{
		if (entries->length)
		{
			kiss_array_free(entries);
			kiss_array_new(entries);
		}
		kiss_array_appendstring(entries, 0, "none", NULL);
		while ((entry = kiss_readdir(kd)))
		{
			if (entry->d_type == DT_REG && ft_strstr(entry->d_name, ftype))
			{
				kiss_array_appendstring(entries, 0, entry->d_name, NULL);
			}
		}
		kiss_closedir(kd);
	}
}

void				draw_ui(SDL_Renderer *renderer, t_objlst *selected)
{
	int				i;

	kiss_label_draw(&selected->title, renderer);
	i = -1;
	while (++i < selected->ui_form_amount)
	{
		kiss_label_draw(&selected->labels[i], renderer);
		kiss_entry_draw(&selected->entries[i], renderer);
	}
}

void				handle_ui(t_objlst *selected, SDL_Event *event, int *draw)
{
	int				i;

	i = -1;
	while (++i < selected->ui_form_amount)
	{
		kiss_entry_event(&selected->entries[i], event, draw);
	}
}
