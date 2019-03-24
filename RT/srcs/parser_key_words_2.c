/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_key_words_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <odidukh@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:33:12 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/18 20:34:24 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

char	*height(char *text, char *formated_str)
{
	char	**split;
	int		check;

	check = 1;
	split = ft_strsplit_by_delim(text, ';');
	single_value_parse(split, formated_str, "\"height\":", &check);
	ft_del_split_arr(split);
	if (check)
		formated_str = NULL;
	return (formated_str);
}

char	*reflection(char *text, char *formated_str)
{
	char	**split;
	int		check;

	check = 1;
	split = ft_strsplit_by_delim(text, ';');
	single_value_parse(split, formated_str, "\"reflection\":", &check);
	ft_del_split_arr(split);
	if (check)
		formated_str = NULL;
	return (formated_str);
}

char	*transparency(char *text, char *formated_str)
{
	char	**split;
	int		check;

	check = 1;
	split = ft_strsplit_by_delim(text, ';');
	single_value_parse(split, formated_str, "\"transparency\":", &check);
	ft_del_split_arr(split);
	if (check)
		formated_str = NULL;
	return (formated_str);
}

char	*ior(char *text, char *formated_str)
{
	char	**split;
	int		check;

	check = 1;
	split = ft_strsplit_by_delim(text, ';');
	single_value_parse(split, formated_str, "\"ior\":", &check);
	ft_del_split_arr(split);
	if (check)
		formated_str = NULL;
	return (formated_str);
}

char	*color(char *text, char *formated_str)
{
	unsigned int	num;
	char			tmp[256];
	char			**split;
	char			**spl_begin;
	int				check;

	check = 1;
	split = ft_strsplit_by_delim(text, ';');
	spl_begin = split;
	while (*split)
	{
		if (!(ft_strncmp(*split, "\"color\":", ft_strlen("\"color\":"))))
		{
			sscanf((*split) + ft_strlen("\"color\":"), "%x", &num);
			sprintf(tmp, "0x%x", num);
			formated_str = ft_strcat(formated_str, tmp);
			check = 0;
			break ;
		}
		split++;
	}
	ft_del_split_arr(spl_begin);
	if (check)
		formated_str = NULL;
	return (formated_str);
}
