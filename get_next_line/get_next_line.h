/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:05:38 by ranavarr          #+#    #+#             */
/*   Updated: 2025/02/21 13:52:53 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

# include <limits.h>
# include <stddef.h>
# include <stdio.h> // testing purposes, delete later
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>


char	*get_next_line(int fd);

#endif
