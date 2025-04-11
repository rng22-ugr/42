/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:20:15 by ranavarr          #+#    #+#             */
/*   Updated: 2025/04/11 07:03:57 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/*
 * function: _get_line
 * reads from file until a '\n' character is found
 * or ther is no more data to read from
 * fd: file descriptor to read from
 * returns:	char *arrray with the full line that has been read
 *			without removing what goes after the '\n'
*/
char	*_get_line(int fd)
{
	char	*line;
	char	dump[BUFFER_SIZE + 1];
	char	*tmp;
	char	*nlpos;
	int		bytes;

	nlpos = NULL;
	bytes = 1;
	line = ft_calloc(1, sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	while (!nlpos && bytes > 0)
	{
		bytes = read(fd, dump, BUFFER_SIZE);
		if (bytes <= 0)
			return (free (line), NULL);
		dump[bytes] = '\0';
		tmp = ft_strjoin(line, dump);
		free(line);
		line = tmp;
		nlpos = ft_strchr(line, '\n');
	}
	return (line);
}

/*
 * function: _save_buffer
 * searches for a '\n' character in the given array, stores
 * the information after said position and reduces the size
 * of the first array so it contains a single line. #redact
 * line: array it must read from.
 * buffer: array where the leftover characters will be stored.
 */
void	_save_buffer(char **str, char buffer[])
{
	char	*nlpos;	
	char	*line;
	int		len;

	nlpos = ft_strchr(*str, '\n');
	if (!nlpos)
		return ;
	len = nlpos - *str + 1;
	ft_memmove(buffer, &nlpos[1], ft_strlen(*str) - len);
	line = ft_calloc(sizeof(char), (len + 1));
	if (!line)
		return ;
	ft_memmove(line, *str, (len));
	line[len] = 0;
	free(*str);
	*str = line;
}

/*
 * function: extract_line
 * searches for a '\n' character in the given buffer and extracts it, removing
 * the line it returns.
 * buffer: buffer to be inspected.
 * returns:	NULL if there is no newline
 * 			char * containing the (NULL terminated) line
*/
char	*extract_line(char buffer[])
{
	char	*line;
	char	*nlpos;
	int		new_size;

	line = NULL;
	nlpos = ft_strchr(buffer, '\n');
	if (nlpos)
	{
		new_size = nlpos - buffer;
		line = ft_calloc(sizeof(char), (new_size + 2));
		if (!line)
			return (NULL);
		line = ft_memmove(line, buffer, sizeof(char) * (new_size + 1));
		ft_memmove(buffer, &nlpos[1],
			sizeof(char) * (ft_strlen(buffer) - new_size));
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;

	if (fd <= 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	line = extract_line(buffer);
	if (!line)
	{
		tmp = _get_line(fd);
		if (!tmp)
			return (NULL);
		line = ft_strjoin(buffer, tmp);
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		_save_buffer(&line, buffer);
		free(tmp);
		tmp = NULL;
	}
	return (line);
}
/*
int	main(void)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open("test", O_RDONLY);
	while (i < 200)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	close(fd);
	return (0);
}

	str = _get_line(fd);
	buffer = _save_buffer(&str);

	printf("str = %s", str);
	printf("buffer = %s", buffer);

	free(buffer);

	buffer = NULL;


}
*/
