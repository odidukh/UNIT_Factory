/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parsers_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <odidukh@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:13:56 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/18 20:14:45 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

char	*cone_parser(char *text, char *formated_str)
{
	formated_str = ft_strcat(formated_str, "cone(");
	if (!(position(text, formated_str)) || !(rotation(text, formated_str))
	|| !(angle(text, formated_str)))
		return (NULL);
	if (!(reflection(text, formated_str)) || !(transparency(text, formated_str))
	|| !(ior(text, formated_str)) || !(color(text, formated_str)))
		return (NULL);
	formated_str = ft_strcat(formated_str, ")\n");
	return (formated_str);
}

char	*cylinder_parser(char *text, char *formated_str)
{
	formated_str = ft_strcat(formated_str, "cylinder(");
	if (!(position(text, formated_str)) || !(rotation(text, formated_str))
	|| !(radius(text, formated_str)))
		return (NULL);
	if (!(reflection(text, formated_str)) || !(transparency(text, formated_str))
	|| !(ior(text, formated_str)) || !(color(text, formated_str)))
		return (NULL);
	formated_str = ft_strcat(formated_str, ")\n");
	return (formated_str);
}

char	*disk_parser(char *text, char *formated_str)
{
	formated_str = ft_strcat(formated_str, "disk(");
	if (!(position(text, formated_str)) || !(rotation(text, formated_str))
	|| !(radius(text, formated_str)))
		return (NULL);
	if (!(reflection(text, formated_str)) || !(transparency(text, formated_str))
	|| !(ior(text, formated_str)) || !(color(text, formated_str)))
		return (NULL);
	formated_str = ft_strcat(formated_str, ")\n");
	return (formated_str);
}

char	*hemisphere_parser(char *text, char *formated_str)
{
	formated_str = ft_strcat(formated_str, "hemisphere(");
	if (!(position(text, formated_str)) || !(rotation(text, formated_str))
	|| !(radius(text, formated_str)))
		return (NULL);
	if (!(reflection(text, formated_str)) || !(transparency(text, formated_str))
	|| !(ior(text, formated_str)) || !(color(text, formated_str)))
		return (NULL);
	formated_str = ft_strcat(formated_str, ")\n");
	return (formated_str);
}

char	*limit_cone_parser(char *text, char *formated_str)
{
	formated_str = ft_strcat(formated_str, "limit_cone(");
	if (!(position(text, formated_str)) || !(rotation(text, formated_str))
	|| !(radius(text, formated_str)) || !(height(text, formated_str)))
		return (NULL);
	if (!(reflection(text, formated_str)) || !(transparency(text, formated_str))
	|| !(ior(text, formated_str)) || !(color(text, formated_str)))
		return (NULL);
	formated_str = ft_strcat(formated_str, ")\n");
	return (formated_str);
}
