/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_key_words_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <odidukh@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:33:15 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/18 20:35:27 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void		single_value_parse(char **line, char *formated_str,
				char *word, int *check)
{
	char	tmp[256];

	while (*line)
	{
		if (!(ft_strncmp(*line, word, ft_strlen(word))))
		{
			sprintf(tmp, "%f ", atof((*line) + ft_strlen(word)));
			formated_str = ft_strcat(formated_str, tmp);
			*check = 0;
			break ;
		}
		line++;
	}
}

char		*split_2_with_coma(char *line, char *formated_str)
{
	char	**split_2;
	char	tmp[256];
	int		counter;
	int		iterator;

	counter = 0;
	iterator = 0;
	split_2 = ft_strsplit_by_delim(line, ',');
	while (split_2[iterator])
	{
		sprintf(tmp, "%f ", atof(split_2[iterator]));
		formated_str = ft_strcat(formated_str, tmp);
		counter++;
		iterator++;
	}
	ft_del_split_arr(split_2);
	if (counter != 3)
		return (NULL);
	return (formated_str);
}

char		*point_1(char *text, char *formated_str)
{
	char	**split;
	int		iterator;
	int		point_found;

	point_found = 0;
	iterator = 0;
	split = ft_strsplit_by_delim(text, ';');
	while (split[iterator])
	{
		if (!(ft_strncmp(split[iterator], "\"point_1\":[",
			ft_strlen("\"point_1\":["))))
		{
			formated_str = split_2_with_coma(split[iterator]
				+ ft_strlen("\"point_1\":["), formated_str);
			point_found = 1;
			break ;
		}
		iterator++;
	}
	ft_del_split_arr(split);
	if (point_found)
		return (formated_str);
	return (NULL);
}

char		*point_2(char *text, char *formated_str)
{
	char	**split;
	int		iterator;
	int		point_found;

	point_found = 0;
	iterator = 0;
	split = ft_strsplit_by_delim(text, ';');
	while (split[iterator])
	{
		if (!(ft_strncmp(split[iterator], "\"point_2\":[",
			ft_strlen("\"point_2\":["))))
		{
			formated_str = split_2_with_coma(split[iterator]
				+ ft_strlen("\"point_2\":["), formated_str);
			point_found = 1;
			break ;
		}
		iterator++;
	}
	ft_del_split_arr(split);
	if (point_found)
		return (formated_str);
	return (NULL);
}

char		*point_3(char *text, char *formated_str)
{
	char	**split;
	int		iterator;
	int		point_found;

	point_found = 0;
	iterator = 0;
	split = ft_strsplit_by_delim(text, ';');
	while (split[iterator])
	{
		if (!(ft_strncmp(split[iterator], "\"point_3\":[",
			ft_strlen("\"point_3\":["))))
		{
			formated_str = split_2_with_coma(split[iterator]
				+ ft_strlen("\"point_3\":["), formated_str);
			point_found = 1;
			break ;
		}
		iterator++;
	}
	ft_del_split_arr(split);
	if (point_found)
		return (formated_str);
	return (NULL);
}
