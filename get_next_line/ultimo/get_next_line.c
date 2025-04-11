/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:20:15 by ranavarr          #+#    #+#             */
/*   Updated: 2025/04/11 20:29:27 by ranavarr         ###   ########.fr       */
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
	char	*dump;
	char	*tmp;
	int		bytes;

	line = NULL;
	dump = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	line = ft_calloc(sizeof(char), 1);
	if (fd <= 0 || !dump || !line)
		return (free(line), free(dump), NULL);
	bytes = read(fd, dump, BUFFER_SIZE);
	while (bytes > 0)
	{
		if (bytes < 0 || bytes > BUFFER_SIZE)
			return (free (line), free(dump), NULL);
		dump[bytes] = '\0';
		tmp = ft_strjoin(line, dump);
		free(line);
		line = tmp;
		if (ft_strchr(line, '\n'))
			break ;
		bytes = read(fd, dump, BUFFER_SIZE);
	}
	return (free(dump), line);
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
		line = ft_memmove(line, buffer, (new_size + 1));
		ft_memmove(buffer, &buffer[new_size + 1],
			ft_strlen(&buffer[new_size]) + 1);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = extract_line(buffer);
	if (!line)
	{
		tmp = _get_line(fd);
		if (!tmp)
			return (NULL);
		line = ft_strjoin(buffer, tmp);
		ft_memset(buffer, 0, BUFFER_SIZE);
		_save_buffer(&line, buffer);
		free(tmp);
		tmp = NULL;
	}
	return (line);
}
/*
int	main()
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open("41_with_nl", O_RDONLY);
	while (i < 19)
	{
		str = get_next_line(fd);
		printf("=%i: %s= ", i, str);
		free(str);
		i++;
	}
	close(fd);
	return (0);
}
*/
/*
int	main(void)
{
	char	buffer [BUFFER_SIZE + 1] = "";	
	char	*line;

	line = extract_line(buffer);
	printf("line = %s", line);
	printf("buffer = %s", buffer);
	line = extract_line(buffer);
	printf("line = %s", line);
	printf("buffer = %s", buffer);


	return (0);
}
*/
