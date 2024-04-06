/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:26:59 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/06 14:36:33 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "struct.h"

t_map	*init_the_map_data(char *filename)
{
	t_map	*map_data;

	map_data = ft_calloc(1, sizeof(t_map));
	if (!map_data)
		return (NULL);
	map_data->map_name = filename;
	return (map_data);
}

int	count_and_read(t_map *map_data)
{
	if (nb_lines_and_col(map_data))
		return (EXIT_FAILURE);
	if (!read_file_lines(map_data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
