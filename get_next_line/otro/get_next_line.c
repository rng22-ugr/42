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
	while (s1 && s1[i] != '\0')
		res[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i] != '\0')
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

/*
 *	function: get_line
 *	Reads from file descriptor until it finds a '\n' or file ends.
 *	fd:		File descriptor to read from.
 *	buffer:	Auxiliary array to store read characters.
 *	return:	The line that has been read INCLUDING leftover
 *			characters that must be removed later.
 */
char	*get_line(int fd, char buffer[])
{
	char	*line;
	char	*tmp;
	char	*nlpos;
	char	bytes;

	line = NULL;
	nlpos = NULL;
	bytes = BUFFER_SIZE;
	while (!nlpos && bytes == BUFFER_SIZE)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = 0;
		if (bytes == 0)
			break;
		nlpos = ft_strchr(buffer, '\n');
		tmp = ft_strjoin(line, buffer);
		if (line)
			free(line);
		line = tmp;
	}
	return (line);
}

char	clean_line(char **line, char buffer[])
{
	
}
/*
	function: get_next_line
	when given a file descriptor, it will read a line and return it, line 
	after line until the end of file.
	fd: file decriptor to read from.
	return: char array with content of the line that has been read.

char	*get_next_line(int fd)
{
	static char	buffer[];
	char		*end_buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	end_buffer = extract_line(&line, buffer);
	if(!line)
	{
	
	}
}
*/

int main(void)
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	char	*str;
	int		i;

	ft_memset(buffer, 0, BUFFER_SIZE + 1);
	fd = open("get_next_line.h", O_RDONLY);
	// get_line(fd, buffer)
	printf("probando get_line\n\n");
	while (i < 100)
	{
		str = get_line(fd, buffer);
		printf("%s", str);
		free(str);
		i++;
	}
	close(fd);
}
