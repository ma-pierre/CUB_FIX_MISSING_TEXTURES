/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eghaffar <eghaffar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:49:55 by eghaffar          #+#    #+#             */
/*   Updated: 2024/04/01 18:02:07 by eghaffar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
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
char	*get_next_line(int fd);
int		ft_check(char *stash);

#endif
