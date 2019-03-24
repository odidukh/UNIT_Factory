/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oponomar <oponomar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 13:40:43 by oponomar          #+#    #+#             */
/*   Updated: 2019/03/19 16:03:41 by oponomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void			edit_camera_live(t_camera *cam, double *delta)
{
	ft_memcpy(cam->dir, cam->dir_backup, sizeof(double) * 3);
	ft_memcpy(cam->scr_h, cam->scr_h_backup, sizeof(double) * 3);
	ft_memcpy(cam->scr_v, cam->scr_v_backup, sizeof(double) * 3);
	cam->pos[OX] += delta[OX];
	cam->pos[OZ] += delta[OZ];
	vecrot_ox(cam->dir, cam->pos[OX], NULL);
	vecrot_oz(cam->dir, cam->pos[OZ], NULL);
	vecrot_ox(cam->scr_h, cam->pos[OX], NULL);
	vecrot_oz(cam->scr_h, cam->pos[OZ], NULL);
	vecrot_ox(cam->scr_v, cam->pos[OX], NULL);
	vecrot_oz(cam->scr_v, cam->pos[OZ], NULL);
	cam->pos[X] += delta[X] * cam->scr_h[X] + delta[Y] * cam->dir[X]
				+ delta[Z] * cam->scr_v[X];
	cam->pos[Y] += delta[X] * cam->scr_h[Y] + delta[Y] * cam->dir[Y]
				+ delta[Z] * cam->scr_v[Y];
	cam->pos[Z] += delta[X] * cam->scr_h[Z] + delta[Y] * cam->dir[Z]
				+ delta[Z] * cam->scr_v[Z];
}

t_camera		*create_camera(double *pos)
{
	t_camera	*cam;
	double		delta[6];

	cam = (t_camera *)malloc(sizeof(t_camera));
	cam->dir_backup[X] = 0.0;
	cam->dir_backup[Y] = 1.0 / tan(M_PI * FOV / 360.0);
	cam->dir_backup[Z] = 0.0;
	cam->scr_h_backup[X] = 1.0;
	cam->scr_h_backup[Y] = 0.0;
	cam->scr_h_backup[Z] = 0.0;
	cam->scr_v_backup[X] = 0.0;
	cam->scr_v_backup[Y] = 0.0;
	cam->scr_v_backup[Z] = 1.0;
	cam->pos[X] = pos[X];
	cam->pos[Y] = pos[Y];
	cam->pos[Z] = pos[Z];
	cam->pos[OX] = 0.0;
	cam->pos[OY] = 0.0;
	cam->pos[OZ] = 0.0;
	ft_memset(delta, 0, sizeof(double) * 3);
	delta[OX] = pos[OX] * M_PI / 180.0;
	delta[OZ] = pos[OZ] * M_PI / 180.0;
	edit_camera_live(cam, delta);
	return (cam);
}
