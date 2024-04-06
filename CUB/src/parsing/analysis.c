/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:53:27 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/06 14:37:27 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing(t_map *map_data, t_config *config)
{
	if (map_empty(map_data, config))
		return (EXIT_FAILURE);
	else if (is_map_valid(map_data, config))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
