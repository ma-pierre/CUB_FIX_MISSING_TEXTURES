#include "cub3D.h"

void    init_raycast_main(t_data *data)
{
    int i;
    int j;

    data->player_start_dir = data->config->map_data->player_start_dir;
	data->game_map = data->config->map_data->map;

	i = 0;
	while (data->game_map[i])
	{
		j = 0;
		while (data->game_map[i][j])
		{
			if (data->game_map[i][j] == data->player_start_dir)
			{
				data->pos_y = (double)j + 0.5;
				data->pos_x = (double)i + 0.5;
				data->game_map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void    init_raycast_all(t_data *data)
{
    init_player_direction(data);
	init_texture(data);
	data->move_speed = 0.03;
	data->rot_speed = 0.03;
	data->map_witdh = 0;
	data->map_height = 0;
	readtab(data);
	init_keys(data);
	data->win = mlx_new_window(data->mlx, SCREEN_W, SCREEN_H, "eya et marine");
}

t_texture    *define_texture(t_data *d, int side)
{
    	if (side == 0)
		{
			if (d->raycast_var.step_x > 0)
				// sud
				return(&d->textures_info[1]);				
			else
				//nord
				return(&d->textures_info[0]);	
				
		} 
		else
		{ // Mur horizontal
		if (d->raycast_var.step_y > 0)
			//est
			return(&d->textures_info[2]);	
		else
			//ouest
			return(&d->textures_info[3]);	
		}
    return(NULL);
}