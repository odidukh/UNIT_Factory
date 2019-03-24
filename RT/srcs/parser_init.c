/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <odidukh@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:31:26 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/19 22:12:22 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static void			select_obj_to_parse(char *line, t_info *info)
{
	if (!(ft_strncmp(line, "point_light", 11)))
		parse_point_light(line + 12, &info->ltlst);
	else if (!(ft_strncmp(line, "direct_light", 12)))
		parse_direct_light(line + 13, &info->ltlst);
	else if (!(ft_strncmp(line, "limit_cone", 10)))
		parse_lcone(line + 11, &info->objlst);
	else if (!(ft_strncmp(line, "cone", 4)))
		parse_cone(line + 5, &info->objlst);
	else if (!(ft_strncmp(line, "plane", 5)))
		parse_plane(line + 6, &info->objlst);
	else if (!(ft_strncmp(line, "sphere", 6)))
		parse_sphere(line + 7, &info->objlst);
	else if (!(ft_strncmp(line, "triangle", 8)))
		parse_triangle(line + 9, &info->objlst);
	else if (!(ft_strncmp(line, "limit_cylinder", 14)))
		parse_lim_cyl(line + 15, &info->objlst);
	else if (!(ft_strncmp(line, "cylinder", 8)))
		parse_cyl(line + 9, &info->objlst);
	else if (!(ft_strncmp(line, "disk", 4)))
		parse_disk(line + 5, &info->objlst);
	else if (!(ft_strncmp(line, "hemisphere", 10)))
		parse_hemisphere(line + 11, &info->objlst);
	else if (!(ft_strncmp(line, "camera", 6)) && !(info->cam))
		parse_cam(line + 7, &info->cam);
}

static void			parse_line(char *line, t_info *info)
{
	if (ft_strlen(line))
		select_obj_to_parse(line, info);
}

static char			*text_after_prev_checks(char *file)
{
	char	*text;

	if ((ft_strlen(file) <= ft_strlen(".json_like")) ||
		(ft_strcmp(ft_strstr(file, ".json_like"), ".json_like")))
		return (NULL);
	text = get_whole_file_text(file);
	if (!(text))
		return (NULL);
	if (!(check_file_text(text)))
	{
		free(text);
		return (NULL);
	}
	return (text);
}

int					parse_file(char *file, t_info *info)
{
	int				i;
	int				obj_counter;
	char			*formated_str;
	char			**splited;
	char			*text;

	obj_counter = 0;
	text = text_after_prev_checks(file);
	formated_str = get_formated_string(text);
	if (formated_str)
	{
		i = 0;
		splited = ft_strsplit_by_delim(formated_str, '\n');
		while (splited[i] && (obj_counter++ < MAX_OBJ_AMOUNT))
			parse_line(splited[i++], info);
		ft_del_split_arr(splited);
		free(formated_str);
	}
	free(text);
	if (info->cam && info->objlst)
		return (1);
	return (0);
}
