/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 13:55:12 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/29 13:59:33 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
char *get_next_line(int fd)
{
	static char	*buf;
	char 		*tmp;
	int			bytes;
	char		*newline;

	newline = NULL;
	if (fd < 0)
		return (NULL);
	tmp = malloc(sizeof(char) * (BUFFER_SIZE));
	if (!tmp)
		return (NULL);
	if (!buf)
	{
		printf("buf no existe todavia \n");
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		printf("buf ya si  existe  \n");
	}
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes < 0)
		return (NULL);
//	printf("%s \n", buf);
	while (!newline)
	{
		printf("no se encontro un newline \n");
		bytes = read(fd, tmp, BUFFER_SIZE);
		buf = ft_strjoin(buf, tmp);
		printf("%s \n", buf);
		newline = ft_strchr(buf, '\n');
 	}
	free(tmp);
	tmp = NULL;
	tmp = malloc(sizeof(char) * (newline + 1));
	strlcpy(tmp, buf, newline);
	printf("%s \n", buf);
	return (newline);
}
*/

char	*get_next_line(int fd)
{
	int			bytes;
	char		*aux;
	static char	*buf;
	char		*line;

	// FD CORRECTO?
	if (fd < 0)
		return (NULL);
	if (!buf)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		bytes = read(fd, buf, BUFFER_SIZE);
		
		//buf[0] = '\0';
	}
	aux = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!aux)
		return (NULL);
	while (bytes > 0 && (ft_strchr(buf,'\n') != 0))
	{
		bytes = read(fd, aux, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(aux);
			return (NULL);
		}
		if (bytes == 0)
			break;
		aux[bytes] = '\0';
		aux = ft_strjoin(buf, aux);
		buf = aux;
	}
	line = extract(buf);
	if (!line)
	{
		free(aux);
		aux = NULL;
		return (NULL);
	}
	buf = cropper(buf, '\n');
	free(aux);
	aux = NULL;
	if (!line)
	{
		buf = NULL;
	}
	return (line);
}

int	main(void)
{
	int	fd = open("get_next_line.c", O_RDONLY);
	int	i;
	char *line = NULL;
	i = 0;
	for (i = 0; i < 100 ; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if (!line)
			break;
		free(line);
		line = NULL;
	}

	free(line);
	line = NULL;
	close(fd);
}
