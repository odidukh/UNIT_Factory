/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsed_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <odidukh@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:30:14 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/18 20:31:03 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

char	*selector(char *splited, char *text, char *formated_str)
{
	if (!(ft_strcmp(splited, "\"camera\"")))
		return (camera_parser(text, formated_str));
	else if (!(ft_strcmp(splited, "\"point_light\"")))
		return (light_point_parser(text, formated_str));
	else if (!(ft_strcmp(splited, "\"direct_light\"")))
		return (light_direct_parser(text, formated_str));
	else if (!(ft_strcmp(splited, "\"cone\"")))
		return (cone_parser(text, formated_str));
	else if (!(ft_strcmp(splited, "\"cylinder\"")))
		return (cylinder_parser(text, formated_str));
	else if (!(ft_strcmp(splited, "\"disk\"")))
		return (disk_parser(text, formated_str));
	else if (!(ft_strcmp(splited, "\"hemisphere\"")))
		return (hemisphere_parser(text, formated_str));
	else if (!(ft_strcmp(splited, "\"limit_cone\"")))
		return (limit_cone_parser(text, formated_str));
	else if (!(ft_strcmp(splited, "\"limit_cylinder\"")))
		return (limit_cylinder_parser(text, formated_str));
	else if (!(ft_strcmp(splited, "\"plane\"")))
		return (plane_parser(text, formated_str));
	else if (!(ft_strcmp(splited, "\"sphere\"")))
		return (sphere_parser(text, formated_str));
	else if (!(ft_strcmp(splited, "\"triangle\"")))
		return (triangle_parser(text, formated_str));
	return (NULL);
}

char	*parser_selector(char *text, char *formated_str)
{
	int		i;
	char	**splited_str;

	splited_str = ft_strsplit_by_delim(text, ';');
	i = 0;
	while (splited_str[i])
	{
		if (!(ft_strncmp(splited_str[i], "\"type\":", ft_strlen("\"type\":"))))
		{
			formated_str = selector(splited_str[i]
				+ ft_strlen("\"type\":"), text, formated_str);
			if (formated_str == NULL)
				break ;
		}
		i++;
	}
	ft_del_split_arr(splited_str);
	return (formated_str);
}

char	*splited_in_types(char **splited_str, char *formated_str)
{
	while (*splited_str)
	{
		if (!ft_strstr(*splited_str, "\"type\":\""))
			return (NULL);
		if (!ft_strncmp(*splited_str, "{\"", 2))
			formated_str = parser_selector((*splited_str) + 1, formated_str);
		else if (!ft_strncmp(*splited_str, ",{\"", 3))
			formated_str = parser_selector((*splited_str) + 2, formated_str);
		if (formated_str == NULL)
			return (NULL);
		splited_str++;
	}
	return (formated_str);
}

char	*init_formated_str(char *formated_str, char *text)
{
	int		i;
	char	**splited_str;

	splited_str = ft_strsplit_by_delim(text, '}');
	i = 0;
	while (splited_str[i])
	{
		if ((i == 0 && ft_strncmp(splited_str[i], "{\"", 2))
			|| ((i != 0 && ft_strncmp(splited_str[i], ",{\"", 3))))
		{
			ft_del_split_arr(splited_str);
			return (NULL);
		}
		i++;
	}
	formated_str = splited_in_types(splited_str, formated_str);
	ft_del_split_arr(splited_str);
	return (formated_str);
}

char	*get_formated_string(char *text)
{
	char	*formated_str;
	char	*copy;

	if (!text || text[0] != '{' || text[ft_strlen(text) - 1] != '}'
		|| text[1] != '[' || text[ft_strlen(text) - 2] != ']')
		return (NULL);
	text += 2;
	text[ft_strlen(text) - 2] = '\0';
	formated_str = ft_strnew(ft_strlen(text));
	ft_bzero(formated_str, ft_strlen(text));
	copy = formated_str;
	copy = init_formated_str(copy, text);
	if (copy == NULL)
	{
		free(formated_str);
		formated_str = NULL;
	}
	return (formated_str);
}
