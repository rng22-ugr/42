/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:00:17 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/30 01:47:52 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1

# endif

# include <limits.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char		*get_next_line(int fd);
int			ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
size_t		t_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strjoin(const char *s1, const char *s2);
char		*substr(char *str, int len);

#endif
