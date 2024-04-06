/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_and_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:55:51 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/06 14:39:06 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_floor_color(char *line, t_config *config)
{
	config->floor_color = rgbstr_to_int(line);
	if (config->floor_color == -1)
	{
		free_config(config);
		ft_putendl_fd_cub(INVALID_TEXT_COL, 2);
		exit(EXIT_FAILURE);
	}
}

void	init_ceiling_color(char *line, t_config *config)
{
	config->ceiling_color = rgbstr_to_int(line);
	if (config->ceiling_color == -1)
	{
		free_config(config);
		ft_putendl_fd_cub(INVALID_TEXT_COL, 2);
		exit(EXIT_FAILURE);
	}
}

void	handle_floor_color(char *line, t_config *config)
{
	if (config->floor_color == -1)
		config->flag += 1;
	line += 2;
	while (*line == ' ')
		line++;
	init_floor_color(line, config);
	if (config->flag == 6)
		config->map_data->j_end_of_tc = ft_strlen(line);
}

void	handle_ceiling_color(char *line, t_config *config)
{
	if (config->ceiling_color == -1)
		config->flag += 1;
	line += 2;
	while (*line == ' ')
		line++;
	init_ceiling_color(line, config);
	if (config->flag == 6)
		config->map_data->j_end_of_tc = ft_strlen(line);
}

int	check_texture_and_color(char *line, t_config *config)
{
	int	i;

	i = 0;
	while (*line == ' ')
		line++;
	if (ft_strncmp(line, "NO ", 3) == 0)
		handle_north_texture(line, config);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		handle_south_texture(line, config);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		handle_west_texture(line, config);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		handle_east_texture(line, config);
	else if (ft_strncmp(line, "F ", 2) == 0)
		handle_floor_color(line, config);
	else if (ft_strncmp(line, "C ", 2) == 0)
		handle_ceiling_color(line, config);
	else if ((*line != '\0') && (*line != '\n') && (config->flag != 6))
		return (0);
	return (1);
}
