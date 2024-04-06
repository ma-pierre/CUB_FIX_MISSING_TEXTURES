/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:45:06 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/06 19:23:18 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_first_line(t_map *map_data, t_config *config, char **map)
{
	int	j;
	int flag;
	
	flag = 0;
	j = 0;
	while (map[map_data->i_end_of_tc][j])
	{
		while ((map[map_data->i_end_of_tc][j]) 
			&& (map[map_data->i_end_of_tc][j] == ' '))
			j++;
		while ((map[map_data->i_end_of_tc][j]) 
		&& (map[map_data->i_end_of_tc][j] == '1'))
		{
			flag = 1;
			j++;
		}
		while ((map[map_data->i_end_of_tc][j]) 
			&& (map[map_data->i_end_of_tc][j] == ' '))
			j++;
		if (map[map_data->i_end_of_tc][j] != '\0' || flag != 1)
		{
			printf(MAP_NOT_CLOSED, map_data->i_end_of_tc, j - 1);
			free_config(config);
			exit(EXIT_FAILURE);
		}
	}
}

int	check_player(char c)
{
	return ((c == FREE_WAY || c == PLAYER_NORTH || c == PLAYER_SOUTH
			|| c == PLAYER_EAST || c == PLAYER_WEST));
}

void	check_particular_cases(t_config *config, t_map *map_data, char **map)
{
	if ((map_data->j_end_of_tc >= ft_strlen_cub(map[map_data->i_end_of_tc + 1]))
		|| (map_data->j_end_of_tc
			>= ft_strlen_cub(map[map_data->i_end_of_tc - 1])))
	{
		printf(MAP_NOT_CLOSED, map_data->i_end_of_tc,
			map_data->j_end_of_tc - 1);
		free_config(config);
		exit(EXIT_FAILURE);
	}
	else if (map_data->j_end_of_tc == 0)
	{
		printf(MAP_NOT_CLOSED, map_data->i_end_of_tc,
			map_data->j_end_of_tc - 1);
		free_config(config);
		exit(EXIT_FAILURE);
	}
}

void	parsing_part(t_config *config, char *argv)
{
	config->map_data = init_the_map_data(argv);
	if (!config->map_data)
	{
		ft_putendl_fd_cub(FAIL_INIT_STRUCT, 2);
		exit(EXIT_FAILURE);
	}
	if (check_if_dotcub(argv))
	{
		ft_putendl_fd_cub(INV_EXT, 2);
		free_config(config);
		exit(EXIT_FAILURE);
	}
	if (count_and_read(config->map_data))
	{
		free_config(config);
		exit(EXIT_FAILURE);
	}
	if (parsing(config->map_data, config))
	{
		free_config(config);
		exit(EXIT_FAILURE);
	}
	retrieve_the_final_map(config->map_data, config);
	print_the_map(config->map_data->map);
	close(config->map_data->fd);
}

int	main(int argc, char *argv[])
{
	t_config	*config;
	t_data		data;
	int			i;
	int			j;

	config = ft_calloc(1, sizeof(t_config));
	if (!config)
		return (1);
	if (argc != 2)
	{
		printf("Error\nWrong number of arguments.");
		return (EXIT_FAILURE);
	}
	parsing_part(config, argv[1]);
	////////////////////////////////
	data.config = config;
	data.player_start_dir = config->map_data->player_start_dir;
	data.game_map = config->map_data->map;
	i = 0;
	while (data.game_map[i])
	{
		j = 0;
		while (data.game_map[i][j])
		{
			if (data.game_map[i][j] == data.player_start_dir)
			{
				data.pos_y = (double)j + 0.5;
				data.pos_x = (double)i + 0.5;
				data.game_map[i][j] = '0';
				printf(" i = %d j = %d \n", i, j);
			}
			j++;
		}
		i++;
	}
	//print_the_map(config->map_data->map);
	data.mlx = mlx_init();
	if (!data.mlx)
	{
		return (1);
	}
	init_player_direction(&data);
	data.move_speed = 0.01;
	data.rot_speed = 0.01;
	data.map_witdh = 0;
	data.map_height = 0;
	readtab(&data);
	init_keys(&data);
	data.win = mlx_new_window(data.mlx, SCREEN_W, SCREEN_H, "eya et marine");
	mlx_hook(data.win, KEYPRESS, (1L << 0), key_press, &data);
	mlx_hook(data.win, KEYRELEASE, (1L << 1), key_release, &data);
	mlx_loop_hook(data.mlx, &do_frame, &data);
	mlx_hook(data.win, 17, 0, &clean_game, &data);
	mlx_loop(data.mlx);
	close(config->map_data->fd);
	//free_config(config);
	return (0);
}
