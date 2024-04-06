/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:56:10 by mapierre          #+#    #+#             */
/*   Updated: 2024/04/06 19:22:11 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	do_frame(t_data *data)
{
	t_image	win_img;

	if (data->keys.esc == 1)
		clean_game(data);
	win_img = image_new(data->mlx, SCREEN_W, SCREEN_H);
	handle_keypress(data);
	main_raycast(data, win_img);
	display_minimap(data, win_img);
	mlx_put_image_to_window(data->mlx, data->win, win_img.img, 0, 0);
	image_delete(data->mlx, win_img);
	return (0);
}

void draw_wall(t_image image, int x, int y1, int y2, int color)
{
	if (x < 0 || x >= SCREEN_W) return;
	y1 = (y1 < 0) ? 0 : y1;
	y2 = (y2 >= SCREEN_H) ? SCREEN_H - 1 : y2;

	while (y1 <= y2)
	{
		image_put_px(image, x, y1, color);
		y1++;
	}
}

void	raycast_init_var(t_data *d, int x)
{
	d->raycast_var.cam_x = 2 * x / (double)SCREEN_W - 1;
	d->raycast_var.ray_dir_x = d->dir_x + d->plane_x * d->raycast_var.cam_x;
	d->raycast_var.ray_dir_y = d->dir_y + d->plane_y * d->raycast_var.cam_x;
	d->raycast_var.map_x = (int)d->pos_x;
	d->raycast_var.map_y = (int)d->pos_y;
	d->raycast_var.side_x = 0;
	d->raycast_var.side_y = 0;
	d->raycast_var.delta_dist_x = fabs(1 / d->raycast_var.ray_dir_x);
	d->raycast_var.delta_dist_y = fabs(1 / d->raycast_var.ray_dir_y);
	d->raycast_var.perp_wall_disst = 0;
	d->raycast_var.step_x = 0;
	d->raycast_var.step_y = 0;
}

void	raycast_init_raydir(t_data *data)
{
	if (data->raycast_var.ray_dir_x < 0)
	{
		data->raycast_var.step_x = -1;
		data->raycast_var.side_x = (data->pos_x
				- data->raycast_var.map_x) * data->raycast_var.delta_dist_x;
	}
	else
	{
		data->raycast_var.step_x = 1;
		data->raycast_var.side_x = (data->raycast_var.map_x
				+ 1.0 - data->pos_x) * data->raycast_var.delta_dist_x;
	}
	if (data->raycast_var.ray_dir_y < 0)
	{
		data->raycast_var.step_y = -1;
		data->raycast_var.side_y = (data->pos_y
				- data->raycast_var.map_y) * data->raycast_var.delta_dist_y;
	}
	else
	{
		data->raycast_var.step_y = 1;
		data->raycast_var.side_y = (data->raycast_var.map_y
				+ 1.0 - data->pos_y) * data->raycast_var.delta_dist_y;
	}
}

int	raycast_dda(t_data *data)
{
	int	i;
	int	side;

	i = 0;
	while (i == 0)
	{
		if (data->raycast_var.side_x < data->raycast_var.side_y)
		{
			data->raycast_var.side_x += data->raycast_var.delta_dist_x;
			data->raycast_var.map_x += data->raycast_var.step_x;
			side = 0;
		}
		else
		{
			data->raycast_var.side_y += data->raycast_var.delta_dist_y;
			data->raycast_var.map_y += data->raycast_var.step_y;
			side = 1;
		}
		if (data->game_map[data->raycast_var.map_x]
			[data->raycast_var.map_y] == '1')
			i = 1;
	}
	return (side);
}

void	main_raycast(t_data *d, t_image win_img)
{
	int	x;
	int	side;
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	color;

	x = 0;
	//d->raycast_var.map_y = 9;
	while (x < SCREEN_W)
	{
		raycast_init_var(d, x);
		raycast_init_raydir(d);
		side = raycast_dda(d);
		if (side == 0)
			d->raycast_var.perp_wall_disst = (d->raycast_var.map_x - d->pos_x
					+ (1 - d->raycast_var.step_x) / 2) / d->raycast_var.ray_dir_x;
		else
			d->raycast_var.perp_wall_disst = (d->raycast_var.map_y - d->pos_y
					+ (1 - d->raycast_var.step_y) / 2) / d->raycast_var.ray_dir_y;
		//printf("PERPWALLDIST = %f \n", d->raycast_var.perp_wall_disst);
		line_height = (int)(SCREEN_H / d->raycast_var.perp_wall_disst);
		draw_start = -line_height / 2 + SCREEN_H / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + SCREEN_H / 2;
		if (draw_end >= SCREEN_H)
			draw_end = SCREEN_H - 1;

		if (side == 0)
		{
			if (d->raycast_var.step_x > 0)
				color = 0xFFC0CB; // sud - Rose
			else
				color = 0x0000FF; // nord - Bleu
		} 
		else
		{ // Mur horizontal
		if (d->raycast_var.step_y > 0)
			color = 0xFF0000; // est - Rouge
		else
			color = 0x000000; // ouest - Noir
		}
		draw_wall(win_img, x, 0, draw_start, 0xffdfdf);
		draw_wall(win_img, x, draw_start, draw_end, color);
		draw_wall(win_img, x, draw_end, SCREEN_H, 0xae84a9);
		x++;
	}
}