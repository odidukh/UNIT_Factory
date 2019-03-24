/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_color_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:19:20 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 16:07:12 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

unsigned int		mix_colors(unsigned int c1, unsigned int c2, double factor)
{
	t_color			color1;
	t_color			color2;
	double			mix[4];

	color1.value = c1;
	color2.value = c2;
	mix[0] = (double)(color1.channel[0] * (1.0 - factor)
			+ color2.channel[0] * factor);
	mix[1] = (double)(color1.channel[1] * (1.0 - factor)
			+ color2.channel[1] * factor);
	mix[2] = (double)(color1.channel[2] * (1.0 - factor)
			+ color2.channel[2] * factor);
	mix[3] = (double)(color1.channel[3] * (1.0 - factor)
			+ color2.channel[3] * factor);
	color1.channel[0] = mix[0] > 255.0 ? 255 : (unsigned char)mix[0];
	color1.channel[1] = mix[1] > 255.0 ? 255 : (unsigned char)mix[1];
	color1.channel[2] = mix[2] > 255.0 ? 255 : (unsigned char)mix[2];
	color1.channel[3] = mix[3] > 255.0 ? 255 : (unsigned char)mix[3];
	return (color1.value);
}

unsigned int		add_colors(unsigned int c1, unsigned int c2)
{
	t_color			color1;
	t_color			color2;
	int				mix[4];

	color1.value = c1;
	color2.value = c2;
	mix[0] = color1.channel[0] + color2.channel[0];
	mix[1] = color1.channel[1] + color2.channel[1];
	mix[2] = color1.channel[2] + color2.channel[2];
	mix[3] = color1.channel[3] + color2.channel[3];
	color1.channel[0] = mix[0] > 255.0 ? 255 : (unsigned char)mix[0];
	color1.channel[1] = mix[1] > 255.0 ? 255 : (unsigned char)mix[1];
	color1.channel[2] = mix[2] > 255.0 ? 255 : (unsigned char)mix[2];
	color1.channel[3] = mix[3] > 255.0 ? 255 : (unsigned char)mix[3];
	return (color1.value);
}

unsigned int		apply_intensity(unsigned int src_color, double intensity)
{
	t_color			color;
	double			new_color[3];

	color.value = src_color;
	new_color[0] = (double)color.channel[0] * intensity;
	new_color[1] = (double)color.channel[1] * intensity;
	new_color[2] = (double)color.channel[2] * intensity;
	color.channel[0] = new_color[0] > 255 ? 255 : (unsigned char)new_color[0];
	color.channel[1] = new_color[1] > 255 ? 255 : (unsigned char)new_color[1];
	color.channel[2] = new_color[2] > 255 ? 255 : (unsigned char)new_color[2];
	return (color.value);
}

void				apply_color_filter(t_info *info, int is_prerender)
{
	if (info->selected_filter)
	{
		if ((info->selected_filter == 4 || info->selected_filter == 5)
			&& !is_prerender)
			info->apply_filter[info->selected_filter](info->surface,
													info->screen_buff);
		else if (info->selected_filter < 4 && info->selected_filter >= 0)
			info->apply_filter[info->selected_filter](info->surface);
	}
}
