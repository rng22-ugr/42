/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:05:38 by ranavarr          #+#    #+#             */
/*   Updated: 2025/02/21 12:42:02 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69 
# endif

# include <limits.h>
# include <stddef.h>
# include <stdio.h> // testing purposes, delete later
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


char	*get_next_line(int fd);
void	*realloc(void *memblock, size_t size);

#endif
