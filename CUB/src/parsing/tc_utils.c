/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:06:50 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/06 14:38:52 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_north_texture(char *line, t_config *config)
{
	if (config->north_texture == NULL)
		config->flag += 1;
	line += 2;
	while (*line == ' ')
		line++;
	free(config->north_texture);
	config->north_texture = ft_strdup_cub(line);
	if (config->flag == 6)
		config->map_data->j_end_of_tc = ft_strlen(line);
}

void	handle_south_texture(char *line, t_config *config)
{
	if (config->south_texture == NULL)
		config->flag += 1;
	line += 2;
	while (*line == ' ')
		line++;
	free(config->south_texture);
	config->south_texture = ft_strdup_cub(line);
	if (config->flag == 6)
		config->map_data->j_end_of_tc = ft_strlen(line);
}

void	handle_east_texture(char *line, t_config *config)
{
	if (config->east_texture == NULL)
		config->flag += 1;
	line += 2;
	while (*line == ' ')
		line++;
	free(config->east_texture);
	config->east_texture = ft_strdup_cub(line);
	if (config->flag == 6)
		config->map_data->j_end_of_tc = ft_strlen(line);
}

void	handle_west_texture(char *line, t_config *config)
{
	if (config->west_texture == NULL)
		config->flag += 1;
	line += 2;
	while (*line == ' ')
		line++;
	free(config->west_texture);
	config->west_texture = ft_strdup_cub(line);
	if (config->flag == 6)
		config->map_data->j_end_of_tc = ft_strlen(line);
}
