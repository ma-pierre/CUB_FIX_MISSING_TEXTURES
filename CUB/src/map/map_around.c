/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_around.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:51:20 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/06 14:37:02 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**find_the_end_of_the_map(t_config *config, char **map)
{
	char	c;
	int		j;

	c = 'a';
	config->map_data->beg_index = config->map_data->i_begin_the_map + 1;
	while (map[config->map_data->beg_index + 1])
	{
		j = 0;
		while (map[config->map_data->beg_index + 1][j])
		{
			if ((map[config->map_data->beg_index + 1][j] == '\n'
				|| map[config->map_data->beg_index + 1][j] == '\0')
				&& c == '\n')
				config->map_data->j_end_of_map = j;
			c = map[config->map_data->beg_index + 1][j];
			j++;
		}
		if (config->map_data->j_end_of_map == j)
			break ;
		config->map_data->beg_index++;
	}
	return (map);
}

int	under_the_map(t_config *config)
{
	char	**map;
	int		j;

	j = 0;
	map = config->map_data->map;
	map = find_the_end_of_the_map(config, map);
	config->map_data->end_i = config->map_data->beg_index;
	config->map_data->end_j = config->map_data->j_end_of_map;
	while (map[config->map_data->beg_index + 1])
	{
		j = 0;
		while (map[config->map_data->beg_index + 1][j] != '\0')
		{
			if (map[config->map_data->beg_index + 1][j] != SPACES)
			{
				printf(INV_UNDER_THE_MAP);
				free_config(config);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		config->map_data->beg_index++;
	}
	return (0);
}
