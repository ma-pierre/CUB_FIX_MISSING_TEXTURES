/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 00:20:23 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/06 14:37:11 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	is_valid(int i, int j, t_config *config)
{
	char	c;

	c = config->map_data->map[i][j];
	if (!c || (c != WALL && c != FREE_WAY && c != PLAYER_NORTH
			&& c != PLAYER_SOUTH && c != PLAYER_EAST && c != PLAYER_WEST))
	{
		printf(MAP_NOT_CLOSED, i, j);
		free_config(config);
		exit(EXIT_FAILURE);
	}
}

int	map_empty(t_map *map_data, t_config *config)
{
	(void)config;
	if (map_data->y == 0 || map_data->x == 0)
	{
		ft_putendl_fd_cub(ERROR_FILE_EMPTY, 2);
		free_config(config);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	is_map_border_closed(t_map *map_data, t_config *config, char **map)
{
	check_first_line(map_data, config, map);
	map_data->i_end_of_tc += 1;
	while (map[map_data->i_end_of_tc])
	{
		while (map[map_data->i_end_of_tc][map_data->j_end_of_tc])
		{
			if (check_player(map[map_data->i_end_of_tc][map_data->j_end_of_tc]))
			{
				check_particular_cases(config, map_data, map);
				is_valid(map_data->i_end_of_tc, map_data->j_end_of_tc + 1,
					config);
				is_valid(map_data->i_end_of_tc, map_data->j_end_of_tc - 1,
					config);
				is_valid(map_data->i_end_of_tc - 1, map_data->j_end_of_tc,
					config);
				is_valid(map_data->i_end_of_tc + 1, map_data->j_end_of_tc,
					config);
			}
			map_data->j_end_of_tc++;
		}
		map_data->j_end_of_tc = 0;
		map_data->i_end_of_tc++;
	}
	return (EXIT_SUCCESS);
}
