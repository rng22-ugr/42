/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:20:15 by ranavarr          #+#    #+#             */
/*   Updated: 2025/04/11 20:29:27 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"


size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;

	i = 0;
	while ((i + 1 < size) && (src[i]))
	{
		dst[i] = src[i];
		i++;
	}
	if (size > 0)
		dst[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i] != '\0' && s1)
		res[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0' && s2)
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

/*
 * function: _get_line
 * reads from file until a '\n' character is found
 * or ther is no more data to read from
 * fd: file descriptor to read from
 * returns:	char *arrray with the full line that has been read
 *			without removing what goes after the '\n'
*/
/*
char	*_get_line(int fd)
{
	char	*line;
	char	*dump;
	char	*tmp;
	int		bytes;

	dump = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	line = ft_calloc(sizeof(char), 1);
	if (fd < 0 || !dump || !line)
		return (free(line), free(dump), NULL);
	bytes = read(fd, dump, BUFFER_SIZE);
	while (bytes > 0)
	{
		if (bytes <= 0 || bytes > BUFFER_SIZE)
			return (free (line), free(dump), NULL);
		dump[bytes] = '\0';
		tmp = ft_strjoin(line, dump);
		free(line);
		line = tmp;
		if (ft_strchr(line, '\n'))
			break ;
		bytes = read(fd, dump, BUFFER_SIZE);
	}
		if (bytes < 0)
			return(free(line), NULL);
	return (free(dump), line);
}
*/
size_t	get_line(int fd, char **line)
{
	size_t	len;
	char	*tmp;
	int		bytes;
	char	*nlpos;
	char	*dump;

	nlpos = NULL;
	bytes = BUFFER_SIZE;
	*line = ft_calloc(sizeof(char), 1);
	dump = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!dump || !line)
		return (free(*line),free(dump), 0);
	while(!nlpos && bytes == BUFFER_SIZE)
	{
		bytes = read(fd, dump, BUFFER_SIZE);
		tmp = ft_strjoin(*line, dump);
		if	(*line)
			free(*line);
		*line = tmp;
		nlpos = ft_strchr(*line, '\n');
	}
	if (bytes < BUFFER_SIZE)
		len = ft_strchr(*line, '\0') - *line;
	else

		len = nlpos - *line;
	return (free(dump),len);
}

void	save_buffer(size_t len, char **line, char buffer[])
{
	char *tmp;

	if (len == 0)
		return ;
	ft_memmove(buffer, &(*line)[len + 1], (ft_strlen(*line) - len));
	tmp = ft_calloc(sizeof(char), len + 2);
	if (!tmp)
		return ;
	ft_memmove(tmp, *line, len + 1);
	free(*line);
	*line = tmp;
}

void	extract_line(char **line, char buffer[])
{
	char	*nlpos;
	size_t	len;

	nlpos = ft_strchr(buffer, '\n');
	if (nlpos)
	{
		len = nlpos - buffer;
		*line = ft_calloc(sizeof(char), len + 2);
		if (!line)
			return ;
		//ft_memmove(*line, buffer, len + 1);
		ft_memmove(*line, buffer, len);
		if (buffer[len] == '\n')
			(*line)[len++] = '\n';
		(*line)[len] = '\0';
		//(*line)[len] = '\n';
		ft_memmove(buffer, &buffer[len], BUFFER_SIZE - len);
	}
	else
		*line = NULL;
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*tmp;
	char		*tmp1;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	tmp1 = NULL;
	extract_line(&line, buffer);
	if (!line)
	{
		len = get_line(fd, &line);
		tmp = ft_strjoin(buffer, "\0");
		ft_memset(buffer, 0, BUFFER_SIZE + 1);
		save_buffer(len, &line, buffer);
		tmp1 = ft_strjoin(tmp, line);
		free(line);
		line = tmp1;
		free(tmp);
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

void	_save_buffer(char **str, char buffer[])
{
	char	*nlpos;	
	char	*line;
	int		len;

	nlpos = ft_strchr(*str, '\n');
	if (!nlpos)
		return ;
	len = nlpos - *str + 1;
	ft_memmove(buffer, &nlpos[1], ft_strlen(&nlpos[1]) + 1);
	line = ft_calloc(sizeof(char), (len + 1));
	if (!line)
		return ;
	ft_memmove(line, *str, (len));
	line[len] = 0;
	free(*str);
	*str = line;
}
 */
/*
 * function: extract_line
 * searches for a '\n' character in the given buffer and extracts it, removing
 * the line it returns.
 * buffer: buffer to be inspected.

 * returns:	NULL if there is no newline
 * 			char * containing the (NULL terminated) line

void	extract_line(char **line, char buffer[])
{
	char	*nlpos;
	size_t	len;

	nlpos = ft_strchr(buffer, '\n');
	if (nlpos)
	{
		len = nlpos - *line;
		*line = malloc(sizeof(char) * (len + 2));
		ft_memmove(line, buffer, len + 1);
		line[len + 1] = 0;
		ft_memmove(buffer, &buffer[len + 1], ft_strlen(&buffer[len]));
	}
	else
		*line = NULL;

}
*/
/*
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
		ft_memmove(line, buffer, (new_size + 1));
		ft_memmove(buffer, &buffer[new_size + 1],
			ft_strlen(&buffer[new_size + 1]) + 1);
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
	extract_line(&line, buffer);
	if (!line)

	{
		tmp = _get_line(fd);
		if (!tmp)
			return (NULL);
		line = ft_strjoin(buffer, tmp);
		_save_buffer(&line, buffer);
		ft_memset(buffer, 0, BUFFER_SIZE);
		free(tmp);
	}
	return (line);
}
*/
/*
int	main()
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open("get_next_line.c", O_RDONLY);
	while (i < 600)
	{
		str = get_next_line(fd);
		printf("%s", str);
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
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		len;
	int			fd;

	fd = open("41_with_nl", O_RDONLY);
	printf("prueba de get_line \n");
	len = get_line(fd, &line);
	printf("la linea es %s y acaba en la posicion %lu", line, len);
	printf("prueba de save_buffer \n");
	save_buffer(len, &line, buffer);
	printf("la linea es %s y buffer es %s", line, buffer);
	printf("prueba de extract_line \n");
	extract_line(&line, buffer);
	printf("la linea es %s y buffer es %s", line, buffer);
	free(line);
	line = NULL;
	close(fd);
	return (0);
}
*/
