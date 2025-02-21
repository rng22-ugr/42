/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:42:05 by ranavarr          #+#    #+#             */
/*   Updated: 2025/02/21 13:53:11 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* POSIBLE BASURA char	*get_next_line(int fd)
 *
 *
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
*/

char	*reader(int fd, char *buffer)
{
	char		*temp;
	ssize_t		size;


		
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	size = read(fd, temp, BUFFER_SIZE);
	printf("esto es temp %s \n", temp);
	return (buffer);
}

int main(void)
{
	int	fd;
	static char *buffer;
//	printf("esto ha ido mal despues de declarar el buffer \n");

	fd = open("text", O_RDONLY);
	if (fd < 0)
	{
		printf("esto ha ido mal  \n");
		return (1);
	}
//	printf("esto ha ido mal despues de abrir\n");

	if (!buffer)
	{
		buffer = malloc(1 * sizeof(char));
		if (!buffer)
		{
			printf("esto ha ido mal  \n");
			return (1);
		}
		buffer[0] = '\0';
	}


//	printf("esto ha ido mal antes de leer\n");
	buffer = reader(fd, buffer);
//	printf("esto ha ido mal despues  de leer\n");
//
	return (0);
}
