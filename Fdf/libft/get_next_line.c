/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:32:11 by odidukh           #+#    #+#             */
/*   Updated: 2018/09/11 18:54:44 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void			ft_no_bsln(t_list_fd *fd_list, char **line)
{
	char	*temp_line;

	if (*line == NULL)
		*line = ft_strdup(fd_list->buff);
	else
	{
		temp_line = ft_strdup(*line);
		free(*line);
		*line = ft_strjoin(temp_line, fd_list->buff);
		free(temp_line);
	}
	fd_list->ret = 0;
}

static void			ft_is_bsln(t_list_fd *fd_list, char *backsl_n, char **line)
{
	char	*strsub;
	char	*temp_line;

	strsub = ft_strsub(fd_list->buff, 0, backsl_n - fd_list->buff);
	if (*line == NULL)
		*line = ft_strdup(strsub);
	else
	{
		temp_line = ft_strdup(*line);
		free(*line);
		*line = ft_strjoin(temp_line, strsub);
		free(temp_line);
	}
	free(strsub);
	fd_list->ret -= (backsl_n - fd_list->buff) + 1;
	ft_memmove(fd_list->buff, (backsl_n + 1), (fd_list->ret + 1));
}

static int			ft_line(t_list_fd *fd_list, char **line)
{
	char	*backsl_n;

	if (fd_list->ret != 0)
	{
		backsl_n = ft_memchr(fd_list->buff, '\n', fd_list->ret);
		if (backsl_n == NULL)
			ft_no_bsln(fd_list, line);
		else
		{
			ft_is_bsln(fd_list, backsl_n, line);
			return (1);
		}
	}
	return (0);
}

static t_list_fd	*ft_find_or_create(t_list_fd **fd_list_begin, int fd)
{
	t_list_fd	*fd_list;

	fd_list = *fd_list_begin;
	if (fd_list)
	{
		while (fd_list->next)
		{
			if (fd_list->fd == fd)
				return (fd_list);
			fd_list = fd_list->next;
		}
		if (fd_list->fd == fd)
			return (fd_list);
		fd_list->next = (t_list_fd *)ft_memalloc(sizeof(t_list_fd));
		fd_list = fd_list->next;
	}
	else
		fd_list = (t_list_fd *)ft_memalloc(sizeof(t_list_fd));
	fd_list->fd = fd;
	if (*fd_list_begin == NULL)
		*fd_list_begin = fd_list;
	return (fd_list);
}

int					get_next_line(int fd, char **line)
{
	static t_list_fd	*fd_list_begin;
	t_list_fd			*fd_list;

	if (fd < 0 || !(line) || read(fd, NULL, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	fd_list = ft_find_or_create(&fd_list_begin, fd);
	while (TRUE)
	{
		if (ft_line(fd_list, line))
			return (1);
		fd_list->ret = (int)read(fd_list->fd, fd_list->buff, BUFF_SIZE);
		fd_list->buff[fd_list->ret] = '\0';
		if (fd_list->ret == 0)
		{
			if (*line == NULL)
				return (0);
			else
				return (1);
		}
	}
}
