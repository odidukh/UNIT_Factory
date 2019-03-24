/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <odidukh@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:36:11 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/18 20:36:44 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

static char		*freeing_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*formated_str;

	if (!(s1) || !(s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(formated_str = ft_strnew(len)))
		return (NULL);
	formated_str = ft_strcpy(formated_str, s1);
	formated_str = ft_strcat(formated_str, s2);
	free(s1);
	free(s2);
	return (formated_str);
}

char			*get_whole_file_text(char *file)
{
	int		fd;
	char	*str;
	char	*line;
	char	*str_copy;
	char	*str_begin;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	str = ft_strnew(0);
	while (ft_get_line(fd, &line) > 0)
		str = freeing_strjoin(str, line);
	str_copy = str;
	str_begin = str;
	while (*str_copy)
	{
		if (!is_whitespace(*str_copy))
			*str++ = *str_copy;
		str_copy++;
	}
	*str = '\0';
	free(line);
	close(fd);
	return (str_begin);
}
