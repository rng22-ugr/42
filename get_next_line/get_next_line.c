/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:42:05 by ranavarr          #+#    #+#             */
/*   Updated: 2025/02/21 10:22:19 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			i;

	i = 0;
	line = (char *) malloc(BUFFER_SIZE);
	while (i < BUFFER_SIZE)
	{
		if (*buffer == '\n' || *buffer == '\0' )
		{

		}
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*p;

	fd = open("get_next_line.c", O_RDONLY);
	p = "a";
	while (p != NULL)
	{
		p = get_next_line(fd);
		printf("%s", p);
		free(p);
	}
	p = get_next_line(fd);
	return (0);
}
