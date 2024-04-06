/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 09:49:21 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/06 14:36:55 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**malloc_the_map(t_config *config, int i)
{
	int		j;
	char	**map_cpy;

	i = config->map_data->end_i - config->map_data->i_begin_the_map;
	map_cpy = ft_calloc((i + 2), sizeof(char *));
	if (map_cpy == NULL)
	{
		ft_putendl_fd_cub("Error\nMemory allocation failed.\n", 2);
		free_config(config);
		exit(EXIT_FAILURE);
	}
	j = 0;
	while (j <= config->map_data->end_i - config->map_data->i_begin_the_map)
	{
		map_cpy[j] = ft_calloc((config->map_data->x + 1), sizeof(char));
		if (map_cpy[j] == NULL)
		{
			ft_putendl_fd_cub("Error\nMemory allocation failed.\n", 2);
			free_tab(map_cpy);
			free_config(config);
			exit(EXIT_FAILURE);
		}
		j++;
	}
	return (map_cpy);
}

void	retrieve_the_final_map(t_map *map_data, t_config *config)
{
	int		i;
	int		j;
	char	**map_final;
	int		i_final;

	i = 0;
	i_final = 0;
	map_final = malloc_the_map(config, i);
	i = map_data->i_begin_the_map;
	while (i <= map_data->end_i)
	{
		j = 0;
		while (map_data->map[i][j])
		{
			if (map_data->map[i][j] == ' ')
				map_final[i_final][j] = '0';
			else
				map_final[i_final][j] = map_data->map[i][j];
			j++;
		}
		i++;
		i_final++;
	}
	free_tab(map_data->map);
	map_data->map = map_final;
}
