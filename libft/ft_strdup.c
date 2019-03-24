/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:04:02 by odidukh           #+#    #+#             */
/*   Updated: 2017/12/09 16:34:46 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strdup() function allocates sufficient memory for a copy of
** the string s1, does the copy, and returns a pointer to it.  The pointer may
** subsequently be used as an argument to the function free(3).
** If insufficient memory is available,
** NULL is returned and errno is set to ENOMEM.
*/

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	s1_size;
	char	*tmp_s1;
	char	*s1_bgn;
	char	*copy_tmp;

	s1_size = 0;
	tmp_s1 = (char *)s1;
	s1_bgn = (char *)s1;
	while (*s1_bgn++)
		s1_size++;
	copy = (char *)malloc((s1_size + 1) * sizeof(*copy));
	if (!copy)
		return (NULL);
	copy_tmp = copy;
	while (s1_size--)
		*copy++ = *tmp_s1++;
	*copy = '\0';
	return (copy_tmp);
}
