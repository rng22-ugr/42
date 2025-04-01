/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:39:28 by ranavarr          #+#    #+#             */
/*   Updated: 2025/04/01 20:02:28 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char	*newarray;
	int		i;

	if (!ptr)
		return (NULL);
	i = 0;
	newarray = malloc(size);
	if (!newarray)
		return (NULL);
	while (ptr[i] && i < size - 1)
	{
		newarray[i] = ptr[i];
		i++;
	}
	newarray[i] = 0;
	free(ptr);
	return (newarray);
}

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
	if (fd > 0 || BUFFER_SIZE <= 0)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	laps = 0;
	// esta buffer vacio?
	if (buffer[0] == 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
	}
	nlpos = ft_strchr((char *)buffer, '\n');
	while (nlpos == 0)
	{
		ft_realloc(line, (sizeof(char) * ((laps * BUFFER_SIZE) + 1)));
		ft_memmove(line, buffer, ((laps - 1) * BUFFER_SIZE));
		bytes = read(fd, buffer, BUFFER_SIZE);
		laps ++;
	}
	
	// test that the read worked
	// extract line from what is read
	// loop on the buffer to find a newline, if there is none, read again
	// store what's left from itc
	// resize the buffer
	// move buffer content
	return (line);
	}

// main meant for testing purposes
int	main(void)
{
	return (0);
}
