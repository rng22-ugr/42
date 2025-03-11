/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafa <rafa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:55:25 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/11 21:14:12 by rafa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			bytes;	
	char		*aux;
	static char	*buf;
	char		*line;

	line = NULL;
	aux = NULL;
	bytes = 1;
	if (fd < 0)
		return (NULL);
	if (!buf)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	aux = malloc(sizeof(char) * (BUFFER_SIZE) + 1);
	if (!aux)
		return (NULL);
	while (bytes > 0 && !ft_strchr(buf,'\n'))
	{
		bytes = read(fd, aux, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(aux);
			free(buf);
			return (NULL);
		}
		if (bytes == 0)
			break;
		aux[bytes] = '\0';
		char *temp = ft_strjoin(buf, aux);
		if (!temp)
		{
		free(aux);
		free(buf);
		return (NULL);
		}
		buf = temp;
	}
	line = extract(buf);
	if (!line)
	{
	free(buf);
	free(aux);
	return (NULL);
	}
	buf = cropper(buf, '\n');
	free(aux);
	if (!line)
	{
		free(buf);
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

