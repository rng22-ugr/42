/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:39:28 by ranavarr          #+#    #+#             */
/*   Updated: 2025/04/02 01:52:20 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *) dest;
	s = (const char *) src;
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (d);
}

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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*ft_realloc(char *ptr, size_t size)
{
	char		*newarray;
	size_t		old_size;

	if (size == 0)
	{
		free(ptr);
		return(NULL);
	}
	if (!ptr)
		return (malloc(size));
	old_size = strlen(ptr);
	if (old_size > size)
		old_size = size;
	newarray = malloc(size);
	if (!newarray)
		return (NULL);
	while (ptr[i] && i < size)
	{
		newarray[i] = ptr[i];
		i++;
	}
	while (i <= size)
	{
		newarray[i] = 0;
		i++;
	}
	free(ptr);
	return (newarray);
}

ssize_t	nlpos(char *buffer)
{
	ssize_t	pos;

	pos = 0;
	while (buffer[pos] != '\0' && buffer[pos] != '\n')
		pos++;
	if (buffer[pos] == '\n')
		return (pos);
	else
		return (-1);
}

char	*extracted_line(char **dst, const char *src, ssize_t nlpos)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	if (nlpos < 0)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(*dst);
	tmp = malloc(sizeof(char) * (len + BUFFER_SIZE + 1));
	while (dst[i])
	{
		tmp[i] = *dst[i];
		i++;
	}
	while (src[j] && i <= nlpos)
	{
		tmp[i] = src[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	free(*dst);
	*dst = NULL;
	return (tmp);
}
/*
// get_next_line
// takes: file descriptor
// returns: char array containing the next line to be read
char	*get_next_line(int fd)
{
	static char	*buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*nlpos;
	int			bytes;
	int			laps;

	// check that file descriptor is valid, if it isnt't exit
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	printf("fd valido y buffer size valido \n");
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	printf("line ya existe \n");
	line[BUFFER_SIZE] = 0;
	printf("line[BUFFER_SIZE] = 0 \n");
	laps = 0;
	printf("laps = %i \n", laps);
	// esta buffer vacio?
	if (buffer[0] == 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		printf("bytes = %i \n", bytes);
		printf("laps = %i \n", laps);
		if (bytes == 0)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		buffer[BUFFER_SIZE] = '\0';
	}
	nlpos = ft_strchr((char *)buffer, '\n');
	while (nlpos == 0)
	{
		ft_realloc(line, (sizeof(char) * ((laps * BUFFER_SIZE) + 2)));
		ft_memmove(ft_strchr(line, '\0'), buffer, BUFFER_SIZE);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		nlpos = ft_strchr((char *)buffer, '\n');
		laps ++;
	}
	ft_realloc(line, (sizeof(char) * ((laps * BUFFER_SIZE) + 1)));
	ft_memmove(ft_strchr(line, '\0'), buffer, nlpos - buffer[0]);
	ft_memmove(buffer, buffer[&nlpos - &buffer[0]], BUFFER_SIZE - (nlpos - buffer[0]));
	// test that the read worked
	// extract line from what is read
	// loop on the buffer to find a newline, if there is none, read again
	// store what's left from itc
	// resize the buffer
	// move buffer content
	return (line);
	}
*/
// main meant for testing purposes
int	main(void)
{
	char	*str;
	char	*chars;

	str = malloc(sizeof(char) * (11));
	chars = malloc(sizeof(char) * (11));
	printf("%li\n", nlpos("neeeewline"));
	printf("%li\n", nlpos("ne\newline"));
	printf("%li\n", nlpos("neeeewline"));
	printf("%li\n", nlpos("ne\neeewline"));
	printf("%li\n", nlpos("neeeew\nline"));
	printf("%li\n", nlpos("neeeewline"));
	printf("%li\n", nlpos("neeee\nwline"));
	printf("%li\n", nlpos("neeeewline"));
	printf("%li\n", nlpos("neeee\nwline"));
	printf("%li\n", nlpos("neeeewline"));
	printf("%li\n", nlpos("n\neeeewline"));
	printf("%li\n", nlpos("\nneeeewline"));

	return (0);
}
