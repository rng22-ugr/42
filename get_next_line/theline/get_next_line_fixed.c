#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:30:00 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/30 17:42:49 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	 if (nmemb != 0 && size > SIZE_MAX / nmemb)
	 return (0);

	 total_size = nmemb * size;

	 ptr = malloc(total_size);
	 if (!ptr)
		 return (0);

	 ft_memset(ptr, 0, total_size);
	 return (ptr);
}
*/

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
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

char	*ft_strjoin_free(char **s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!(*s1) || !(s2))
		return (NULL);
	i = 0;
	j = 0;
	res = malloc((ft_strlen(*s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while ((*s1)[i])
		res[j++] = (*s1)[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	free (*s1);
	(*s1) = res;
	return (res);
}

char	*substr(char *s, int len)
{
	int		i;
	char	*substr;

	i = 0;
	if (!s || len < 0)
		return (NULL);
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	substr[len] = '\0';
	while (s[i] && i <= len)
	{
		substr[i] = s[i];
		i++;
	}
	return (substr);
}

char	*shortbuffer(char **s, int pos)
{
	int		i;
	int		len;
	char	*newbuffer;

	i = 0;
	if (!(*s))
		return (NULL);
	len = ft_strlen(*s);
	if (pos >= len)
		return (NULL);
	printf("pos = %i \n",pos);
	printf("pos = %i \n",pos);
	printf("len - pos = %i \n", len - pos);
	newbuffer = malloc(sizeof(char) * ((len - pos) + 1));
	if (!newbuffer)
		return (NULL);
	while ((*s)[pos])
		newbuffer[i++] = (*s)[pos++];
	newbuffer[i] = '\0';
	printf("newbuffer = %s \n", newbuffer);
	free(*s);
	*s = NULL;
	return (newbuffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*output;
	char		*tmp;
	char		*nlpos;
	int			bytes;

	if (!buffer)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	else
		bytes = read(fd, tmp, BUFFER_SIZE);
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	if (bytes < 0)
	{
		free(tmp);
		return (NULL);
	}
	buffer[bytes] = '\0';
	nlpos = ft_strchr(buffer, '\n');
	while (nlpos == 0)
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		buffer = ft_strjoin_free(&buffer, tmp);
		if (bytes < 0)
		{
			free(tmp);
			return (NULL);
		}
		printf("se han leido %i bytes del fd \n", bytes);
		printf("buffer =  %s \n", buffer);
		tmp[bytes] = '\0';
		nlpos = ft_strchr(buffer, '\n');
	}
	printf("cortamos en el caracter numero = %li \n", nlpos - buffer);
	output = substr(buffer, (nlpos - buffer));
	printf("output =  %s \n", output);
	buffer = shortbuffer(&buffer, (nlpos - buffer) + 1);
	free(tmp);
	tmp = NULL;
	return (output);
}

int	main(void)
{
	int		fd;
	int		i;
	//char	*buffer = "0123456789";


	i = 0;
	//substr
	//printf("%s \n", substr("0123456", 3));
	//shortbuffer
//	buffer = shortbuffer(&buffer, 4);
//	printf("%s \n", buffer);
	fd = open("./get_next_line.c", O_RDONLY);
	while (i < 3)
	{
		printf("line = %s \n", get_next_line(fd));
		i++;
	}		
	close(fd);
	return (0);
}
