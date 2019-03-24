/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_key_words_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <odidukh@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:33:06 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/18 20:33:55 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

char	*position(char *text, char *formated_str)
{
	char	**split;
	int		iterator;
	int		position_found;

	position_found = 0;
	iterator = 0;
	split = ft_strsplit_by_delim(text, ';');
	while (split[iterator])
	{
		if (!(ft_strncmp(split[iterator],
			"\"position\":[", ft_strlen("\"position\":["))))
		{
			formated_str = split_2_with_coma(split[iterator]
				+ ft_strlen("\"position\":["), formated_str);
			position_found = 1;
			break ;
		}
		iterator++;
	}
	ft_del_split_arr(split);
	if (position_found)
		return (formated_str);
	return (NULL);
}

char	*rotation(char *text, char *formated_str)
{
	char	**split;
	int		iterator;
	int		rotation_found;

	rotation_found = 0;
	iterator = 0;
	split = ft_strsplit_by_delim(text, ';');
	while (split[iterator])
	{
		if (!(ft_strncmp(split[iterator],
			"\"rotation\":[", ft_strlen("\"rotation\":["))))
		{
			formated_str = split_2_with_coma(split[iterator]
				+ ft_strlen("\"rotation\":["), formated_str);
			rotation_found = 1;
			break ;
		}
		iterator++;
	}
	ft_del_split_arr(split);
	if (rotation_found)
		return (formated_str);
	return (NULL);
}

char	*intensivity(char *text, char *formated_str)
{
	char	**split;
	int		check;

	check = 1;
	split = ft_strsplit_by_delim(text, ';');
	single_value_parse(split, formated_str, "\"intensivity\":", &check);
	ft_del_split_arr(split);
	if (check)
		formated_str = NULL;
	return (formated_str);
}

char	*angle(char *text, char *formated_str)
{
	char	**split;
	int		check;

	check = 1;
	split = ft_strsplit_by_delim(text, ';');
	single_value_parse(split, formated_str, "\"angle\":", &check);
	ft_del_split_arr(split);
	if (check)
		formated_str = NULL;
	return (formated_str);
}

char	*radius(char *text, char *formated_str)
{
	char	**split;
	int		check;

	check = 1;
	split = ft_strsplit_by_delim(text, ';');
	single_value_parse(split, formated_str, "\"radius\":", &check);
	ft_del_split_arr(split);
	if (check)
		formated_str = NULL;
	return (formated_str);
}
