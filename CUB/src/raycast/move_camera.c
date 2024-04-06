/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:55:41 by mapierre          #+#    #+#             */
/*   Updated: 2024/04/06 19:12:00 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_player_n_s(t_data *data)
{
	if (data->player_start_dir == 'N')
	{
		data->dir_y = 0.01;
		data->dir_x = -1;
		data->plane_y = 0.66;
		data->plane_x = 0.01;
	}
	else if (data->player_start_dir == 'S')
	{
		data->dir_y = 0.01;
		data->dir_x = 1;
		data->plane_y = -0.66;
		data->plane_x = 0.01;
	}
}

void	init_player_direction(t_data *data)
{
	if (data->player_start_dir == 'N' || data->player_start_dir == 'S')
		init_player_n_s(data);
	else if (data->player_start_dir == 'E')
	{
		data->dir_y = 1;
		data->dir_x = 0.01;
		data->plane_y = 0.01;
		data->plane_x = 0.66;
	}
	else if (data->player_start_dir == 'W')
	{
		data->dir_y = -1;
		data->dir_x = 0.01;
		data->plane_y = 0.01;
		data->plane_x = -0.66;
	}
}

void	camera_left(t_data *d)
{
	double	c_dir_x;
	double	c_plane_x;

	c_dir_x = d->dir_x;
	c_plane_x = d->plane_x;
	d->dir_x = d->dir_x * cos(d->rot_speed) - d->dir_y * sin(d->rot_speed);
	d->dir_y = c_dir_x * sin(d->rot_speed) + d->dir_y * cos(d->rot_speed);
	d->plane_x = d->plane_x * cos(d->rot_speed) - d->plane_y * sin(d->rot_speed);
	d->plane_y = c_plane_x * sin(d->rot_speed) + d->plane_y * cos(d->rot_speed);
}

void	camera_right(t_data *d)
{
	double	c_dir_x;
	double	c_plane_x;

	c_dir_x = d->dir_x;
	c_plane_x = d->plane_x;
	d->dir_x = d->dir_x * cos(-d->rot_speed) - d->dir_y * sin(-d->rot_speed);
	d->dir_y = c_dir_x * sin(-d->rot_speed) + d->dir_y * cos(-d->rot_speed);
	d->plane_x = d->plane_x * cos(-d->rot_speed) - d->plane_y * sin(-d->rot_speed);
	d->plane_y = c_plane_x * sin(-d->rot_speed) + d->plane_y * cos(-d->rot_speed);
}
