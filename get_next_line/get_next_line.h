/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:32:57 by odidukh           #+#    #+#             */
/*   Updated: 2018/02/25 15:03:35 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define TRUE 1
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <string.h>

typedef	struct		s_buff
{
	int				fd;
	char			buff[BUFF_SIZE + 1];
	int				ret;
	struct s_buff	*next;
}					t_list_fd;

int					get_next_line(const int fd, char **line);
#endif
