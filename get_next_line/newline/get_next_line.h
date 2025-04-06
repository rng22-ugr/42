/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:30:09 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/11 13:35:37 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

# include <limits.h>
# include <stddef.h>
# include <stdio.h> // testing purposes, delete later
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strchr(const char *s, int c);
int		seek_destroy(char *src, char *dst, int c);
char	*get_next_line(int fd);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
#endif
