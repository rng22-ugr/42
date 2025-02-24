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

ssize_t hasnewline(char *buffer)
{
	int	i;
	
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*reader(int fd, char *buffer)
{
	char		*temp;
	ssize_t		size;

		
	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (hasnewline(buffer) == -1 )
	{
	size = read(fd, temp, BUFFER_SIZE);
	printf("esto es temp %s \n", temp);
	return (buffer);
	}
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
