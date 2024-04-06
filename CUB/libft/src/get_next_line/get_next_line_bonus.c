/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:45:04 by eghaffar          #+#    #+#             */
/*   Updated: 2024/03/31 18:45:39 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line_bonus.h"
int	ft_check(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_extract(char *stash)
{
	char	*ltoreturn;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	ltoreturn = (char *)malloc((i + 2) * sizeof(char));
	if (!ltoreturn)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		ltoreturn[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		ltoreturn[i++] = '\n';
	ltoreturn[i] = '\0';
	return (ltoreturn);
}

char	*ft_remaining(char *stash)
{
	char	*stock;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen_GNL(stash);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	stock = (char *)malloc((len - i + 1) * sizeof(char));
	if (!stock)
		return (NULL);
	while (stash[j] && stash[j] != '\n')
		j++;
	i = 0;
	while (stash[j] != '\0')
		stock[i++] = stash[j++ + 1];
	free(stash);
	stock[i] = '\0';
	return (stock);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*stash[1024];
	char			*line;
	int				i;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	i = 1;
	while (i > 0 && ft_check(stash[fd]) == 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (free(buffer), NULL);
		buffer[i] = '\0';
		stash[fd] = ft_strjoin(stash[fd], buffer);
	}
	free(buffer);
	line = ft_extract(stash[fd]);
	stash[fd] = ft_remaining(stash[fd]);
	return (line);
}
