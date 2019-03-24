/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 10:55:30 by oponomar          #+#    #+#             */
/*   Updated: 2018/11/09 13:39:14 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Checking if there is an occurance of obtained fd value in the list,
**	if so - return a pointer to node with appropriate fd value,
**	if not - create new node with obtained fd value and return pointer to it.
*/

static t_fd		*ft_check_fd(t_fd **list, int fd)
{
	t_fd	*temp;
	t_fd	*new;

	temp = *list;
	new = NULL;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	new = (t_fd *)malloc(sizeof(t_fd));
	new->fd = fd;
	new->str = NULL;
	new->next = *list;
	*list = new;
	return (*list);
}

/*
**	Modifies str field in the node depending on occurance '\n' in it after
**	writing to line: if so - cut str part till the end of new line, if not
**	- delete & free str.
*/

static int		ft_modify_rem(int flag, int end, char **str)
{
	char	*temp;

	temp = NULL;
	if (flag)
	{
		temp = ft_strsub(*str, end + 1, ft_strlen(*str) - 1);
		ft_strdel(str);
		*str = ft_strdup(temp);
		ft_strdel(&temp);
		return (1);
	}
	else
		ft_strdel(str);
	return (0);
}

/*
**	Fills obtained line by chars from str string until last one ends or
**	'\n' occurs. If there is no '\n' in str string - last ones frees up
**	after copy to line succeds.
*/

static int		ft_fill_line(char **line, char **str)
{
	int		flag;
	size_t	end;
	char	*temp;

	flag = 0;
	end = 0;
	if (*str)
	{
		if (ft_strchr(*str, '\n'))
		{
			flag = 1;
			end = ft_strlen(*str) - ft_strlen(ft_strchr(*str, '\n'));
			temp = ft_strsub(*str, 0, end);
		}
		else
		{
			end = ft_strlen(*str) - 1;
			temp = ft_strsub(*str, 0, end + 1);
		}
		*line = ft_strjoin(*line, temp, line, &temp);
		if (ft_modify_rem(flag, end, str))
			return (1);
	}
	return (0);
}

/*
**	Gets the line without '\n' to *line from file with appropriate fd.
**	Before writing to *line its previous containment is erased.
*/

int				ft_get_line(const int fd, char **line)
{
	static t_fd	*list;
	t_fd		*node;
	char		buff[32];
	int			n;

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	node = ft_check_fd(&list, fd);
	if (ft_fill_line(line, &(node->str)))
		return (1);
	ft_memset(buff, 0, 33);
	while ((n = read(fd, buff, 32)))
	{
		if (n < 0)
			return (-1);
		node->str = ft_strjoin(node->str, buff, &(node->str), NULL);
		ft_memset(buff, 0, 33);
		if (ft_fill_line(line, &(node->str)))
			return (1);
	}
	if (*line && (int)ft_strlen(*line) > n)
		return (1);
	return (0);
}
