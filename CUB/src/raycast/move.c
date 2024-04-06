/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:55:35 by mapierre          #+#    #+#             */
/*   Updated: 2024/04/06 19:08:23 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_data *data)
{
	if (data->game_map[(int)(data->pos_x + data->dir_x * data->move_speed)]
			[(int)(data->pos_y)] == '0')
			data->pos_x += data->dir_x * data->move_speed;
	if (data->game_map[(int)(data->pos_x)]
			[(int)(data->pos_y + data->dir_y * data->move_speed)] == '0')
			data->pos_y += data->dir_y * data->move_speed;
}

void	move_back(t_data *data)
{
	if (data->game_map[(int)(data->pos_x - data->dir_x * data->move_speed)]
			[(int)(data->pos_y)] == '0')
			data->pos_x -= data->dir_x * data->move_speed;
	if (data->game_map[(int)(data->pos_x)]
			[(int)(data->pos_y - data->dir_y * data->move_speed)] == '0')
			data->pos_y -= data->dir_y * data->move_speed;
}

void	move_right(t_data *data)
{
	double  perp_dir_x;
	double  perp_dir_y;

	perp_dir_x = data->dir_y;
	perp_dir_y = -data->dir_x;   
	if (data->game_map[(int)(data->pos_x + perp_dir_x * data->move_speed)]
			[(int)(data->pos_y)] == '0')
		data->pos_x += perp_dir_x * data->move_speed;
	if (data->game_map[(int)(data->pos_x)]
			[(int)(data->pos_y + perp_dir_y * data->move_speed)] == '0')
		data->pos_y += perp_dir_y * data->move_speed;
}

void	move_left(t_data *data)
{
	double  perp_dir_x;
	double  perp_dir_y;
	
	perp_dir_x = -data->dir_y;
	perp_dir_y = data->dir_x;
	if (data->game_map[(int)(data->pos_x + perp_dir_x * data->move_speed)]
			[(int)(data->pos_y)] == '0')
		data->pos_x += perp_dir_x * data->move_speed;
	if (data->game_map[(int)(data->pos_x)]
			[(int)(data->pos_y + perp_dir_y * data->move_speed)] == '0')
		data->pos_y += perp_dir_y * data->move_speed;
}