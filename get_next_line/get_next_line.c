/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:55:25 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/11 16:22:25 by ranavarr         ###   ########.fr       */
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
	if (!buf)
	{
		if (mymalloc((void *)&buf, (sizeof (char))) == 1)
			return (NULL);
		buf[0] = '\0';
	}
	if (mymalloc((void *)&aux, (sizeof(char) * (BUFFER_SIZE) + 1)) == 1)
		return (NULL);
	while ((!buf) || (bytes != 0 && !ft_strchr(buf, '\n')))
	{
		bytes = read(fd, aux, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(aux);
			return (NULL);
		}
		aux[bytes] = '\0';
		buf = ft_strjoin(buf, aux);
		if (!buf)
			return (NULL);
	}
	line = extract(buf);
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
	int	fd = open("text", O_RDONLY);
	int	i;
	char *line = NULL;
	i = 0;
	for (i = 0; i < 200; i++)
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
