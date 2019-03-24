/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parsers_0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <odidukh@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:19:28 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/18 20:19:32 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

char	*camera_parser(char *text, char *formated_str)
{
	formated_str = ft_strcat(formated_str, "camera(");
	if (!(position(text, formated_str) && rotation(text, formated_str)))
		return (NULL);
	formated_str = ft_strcat(formated_str, ")\n");
	return (formated_str);
}

char	*light_direct_parser(char *text, char *formated_str)
{
	formated_str = ft_strcat(formated_str, "direct_light(");
	if (!(rotation(text, formated_str)) || !(intensivity(text, formated_str)))
		return (NULL);
	formated_str = ft_strcat(formated_str, ")\n");
	return (formated_str);
}

char	*light_point_parser(char *text, char *formated_str)
{
	formated_str = ft_strcat(formated_str, "point_light(");
	if (!(position(text, formated_str) && intensivity(text, formated_str)))
		return (NULL);
	formated_str = ft_strcat(formated_str, ")\n");
	return (formated_str);
}
