/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 09:45:22 by oponomar          #+#    #+#             */
/*   Updated: 2019/02/25 11:24:54 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct		s_fd
{
	struct s_fd		*next;
	int				fd;
	char			*str;
}					t_fd;

int					ft_atoi(const char *str);
int					ft_get_line(const int fd,
								char **line);
void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dest,
								const void *src,
								size_t n);
void				*ft_memset(void *b,
								int c,
								size_t len);
void				ft_putendl(const char *s);
char				*ft_strchr(const char *s,
								int c);
char				*ft_strcpy(char *dest,
								const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(const char *s1,
								const char *s2);
char				*ft_strjoin(char *s1,
								char *s2,
								char **ptr1,
								char **ptr2);
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dest,
								const char *src,
								size_t len);
char				*ft_strndup(const char *s1,
								size_t n);
char				*ft_strnstr(const char *haystack,
								const char *needle,
								size_t len);
int					ft_strnequ(const char *s1,
								const char *s2,
								size_t n);
char				**ft_strsplit(char *s);
char				*ft_strstr(const char *haystack,
								const char *needle);
char				*ft_strsub(const char *s,
								unsigned int start,
								size_t len);
char				*ft_strtrim(char *s,
								int free_src);
int					is_whitespace(char c);
char				*ft_strnew(size_t size);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				**ft_strsplit_by_delim(char const *s, char c);
char				*ft_strcat(char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
void				ft_del_split_arr(char **arr);
#endif
