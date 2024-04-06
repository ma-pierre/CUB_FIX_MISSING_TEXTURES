/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:55:09 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/06 14:39:32 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_strlen_cub(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (0);
	}
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_cub(const char *s1)
{
	size_t	i_cub;
	size_t	i;
	char	*dest;

	i_cub = ft_strlen(s1);
	while (i_cub > 0 && s1[i_cub - 1] == ' ')
		i_cub--;
	dest = malloc(sizeof(char) * (i_cub + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < i_cub)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_putendl_fd_cub(char *s, int fd)
{
	if (!s)
		return (EXIT_FAILURE);
	if (write(fd, s, ft_strlen(s)) == -1)
		return (EXIT_FAILURE);
	if (write(fd, "\n", 1) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f');
}
