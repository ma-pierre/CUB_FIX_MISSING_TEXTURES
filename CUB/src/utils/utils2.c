/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:48:55 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/06 14:39:38 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*trim_new_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

int	is_valid_scene_character(char c, t_map *map_data)
{
	if (c == PLAYER_NORTH || c == PLAYER_SOUTH || is_whitespace(c)
		|| c == PLAYER_EAST || c == PLAYER_WEST)
	{
		if (c == PLAYER_NORTH || c == PLAYER_SOUTH || c == PLAYER_EAST
			|| c == PLAYER_WEST)
		{
			map_data->flag_pos += 1;
			map_data->player_start_dir = c;
			return (EXIT_SUCCESS);
		}
		return (EXIT_SUCCESS);
	}
	else if (c == FREE_WAY || c == WALL || c == SPACES || c == '\n')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}

void	actualize_nb_of_col(char *line, int *nb_of_cols)
{
	int	actual_col;

	actual_col = ft_strlen(line) - 1;
	if (actual_col >= *nb_of_cols)
		*nb_of_cols = actual_col;
}
