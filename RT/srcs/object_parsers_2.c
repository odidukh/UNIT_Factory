/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_parsers_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odidukh <odidukh@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 20:15:46 by odidukh           #+#    #+#             */
/*   Updated: 2019/03/18 20:15:49 by odidukh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

char	*limit_cylinder_parser(char *text, char *formated_str)
{
	formated_str = ft_strcat(formated_str, "limit_cylinder(");
	if (!(position(text, formated_str)) || !(rotation(text, formated_str))
	|| !(radius(text, formated_str)) || !(height(text, formated_str)))
		return (NULL);
	if (!(reflection(text, formated_str)) || !(transparency(text, formated_str))
	|| !(ior(text, formated_str)) || !(color(text, formated_str)))
		return (NULL);
	formated_str = ft_strcat(formated_str, ")\n");
	return (formated_str);
}

char	*plane_parser(char *text, char *formated_str)
{
	formated_str = ft_strcat(formated_str, "plane(");
	if (!(position(text, formated_str)) || !(rotation(text, formated_str)))
		return (NULL);
	if (!(reflection(text, formated_str)) || !(transparency(text, formated_str))
	|| !(ior(text, formated_str)) || !(color(text, formated_str)))
		return (NULL);
	formated_str = ft_strcat(formated_str, ")\n");
	return (formated_str);
}

char	*sphere_parser(char *text, char *formated_str)
{
	formated_str = ft_strcat(formated_str, "sphere(");
	if (!(position(text, formated_str)) || !(rotation(text, formated_str))
	|| !(radius(text, formated_str)))
		return (NULL);
	if (!(reflection(text, formated_str)) || !(transparency(text, formated_str))
	|| !(ior(text, formated_str)) || !(color(text, formated_str)))
		return (NULL);
	formated_str = ft_strcat(formated_str, ")\n");
	return (formated_str);
}

char	*triangle_parser(char *text, char *formated_str)
{
	formated_str = ft_strcat(formated_str, "triangle(");
	if (!(point_1(text, formated_str)) || !(point_2(text, formated_str))
	|| !(point_3(text, formated_str)))
		return (NULL);
	if (!(reflection(text, formated_str)) || !(transparency(text, formated_str))
	|| !(ior(text, formated_str)) || !(color(text, formated_str)))
		return (NULL);
	formated_str = ft_strcat(formated_str, ")\n");
	return (formated_str);
}
