/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:45:25 by eghaffar          #+#    #+#             */
/*   Updated: 2024/03/31 18:44:50 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen_GNL(const char *s);
char	*ft_remaining(char *buffer);
char	*ft_extract(char *line);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*get_next_line(int fd);
int		ft_check(char *stash);
char	*ft_strdup(const char *s1);

#endif
