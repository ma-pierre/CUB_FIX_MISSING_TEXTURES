/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:07:22 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/06 14:39:19 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	error_exit(t_config *config, char *message)
{
	ft_putendl_fd_cub(message, 2);
	free_config(config);
	exit(EXIT_FAILURE);
}

void	free_strs(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map_data(t_map *map_data)
{
	int	i;

	if (map_data)
	{
		if (map_data->map)
		{
			i = 0;
			while (map_data->map[i])
			{
				free(map_data->map[i]);
				i++;
			}
			free(map_data->map);
		}
		free(map_data);
		map_data = NULL;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_config(t_config *config)
{
	if (!config)
		return ;
	if (config->north_texture)
		free(config->north_texture);
	if (config->south_texture)
		free(config->south_texture);
	if (config->west_texture)
		free(config->west_texture);
	if (config->east_texture)
		free(config->east_texture);
	if (config->map_data)
	{
		free_map_data(config->map_data);
	}
	free(config);
}
