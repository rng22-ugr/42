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
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	i = 0;
	j = 0;
	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	res = (char *) malloc((len1 + len2 + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1 && s1[i] != '\0')
		res[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i] != '\0')
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

char	*buffer_line(char buffer[])
{
	char	*nlpos;
	char	*line;
	size_t	len;

	nlpos = ft_strchr(buffer, '\n');
	if (buffer[0] == 0)
		return (NULL);
	if (nlpos)
		len = nlpos - buffer;
	else
	{
		len =ft_strlen(buffer);
		if (len == 0)
			return (NULL);
	}
	line = ft_calloc(sizeof(char), len + 2);
	if (!line)
		return (NULL);
	ft_memmove(line, buffer, len + 1);
	ft_memmove(buffer, &buffer[len + 1], ft_strlen(buffer) - len + 1);
	return (line);
}
/*
 *	function: _get_line
 *	Reads from file descriptor until it finds a '\n' or file ends.
 *	fd:		File descriptor to read from.
 *	buffer:	Auxiliary array to store read characters.
 *	return:	The line that has been read INCLUDING leftover
 *			characters that must be removed later.
 */
char	*_get_line(int fd, char buffer[])
{
	char	*line;
	char	*tmp;
	char	*nlpos;
	int		bytes;

	line = NULL;
	nlpos = NULL;
	bytes = BUFFER_SIZE;
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	while (!nlpos && bytes == BUFFER_SIZE)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			return (ft_memset(buffer, 0, BUFFER_SIZE + 1), line);
		buffer[bytes] = 0;
		nlpos = ft_strchr(buffer, '\n');
		tmp = ft_strjoin(line, buffer);
		if (line)
			free(line);
		line = tmp;
	}
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	return (line);
}

/*
 * function: clean_line
 * searches for the first '\n' character in the given line, shortens it
 * and stores the remainder in buffer.
 * line:	array to shorten.
 * buffer:	static array where the leftover characters will be stored.
 */
void	clean_line(char **line, char buffer[])
{
	char	*nlpos;
	char	*new_line;
	int		len;
	int		new_len;

	if (!(*line))
		return ;
	len = ft_strlen(*line);
	nlpos = ft_strchr(*line, '\n');
	if (!nlpos)
		return ;
	new_len = nlpos - *line;
	new_line = ft_calloc(sizeof(char), new_len + 2);
	if (!new_line)
		return ;
	ft_memmove(new_line, *line, new_len + 1);
	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	ft_memmove(buffer, &(*line)[new_len + 1], len - new_len);
	ft_memset(&buffer[len - new_len + 1], 0, BUFFER_SIZE - (len - new_len));
	free(*line);
	*line = new_line;
}

/*
	function: get_next_line
	when given a file descriptor, it will read a line and return it, line 
	after line until the end of file.
	fd: file decriptor to read from.
	return: char array with content of the line that has been read.
*/
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*nlpos;
	char		*line1;
	char		*tmp;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	line = buffer_line(buffer);
	if (line)
		nlpos = ft_strchr(line, '\n');
	else
		nlpos = NULL;
	if (!nlpos)
	{
		line1 = _get_line(fd, buffer);
		if (!line && !line1)
			return (NULL);
		clean_line(&line1, buffer);
		tmp = ft_strjoin(line, line1);
		free(line1);
		free(line);
		line = tmp;
	}
	return (line);
}
/*

int main(void)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open("read_error.txt", O_RDONLY);
	// _get_line(fd, buffer)
	printf("probando get_next_line\n\n");
	while (i < 2)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}

	str = get_next_line(-1);
	printf("%s", str);
	free(str);

	while (i < 6)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	fd = open("read_error.txt", O_RDONLY);
	close(fd);
	// _get_line(fd, buffer)
	return (0);
}




	// clean_line(line, buffer)
	printf("probando clean_line\n\n");
	str = ft_strjoin("esta es una linea \n esta otra\n y esta otra", NULL);
	clean_line(&str, buffer);
	printf("str = %s||buffer = %s||", str, buffer);
	free(str);
	close(fd);
	printf("probando todo junto\n\n");
*/
