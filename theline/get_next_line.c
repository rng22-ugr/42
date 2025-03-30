/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 14:30:00 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/30 05:49:54 by ranavarr         ###   ########.fr       */
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
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i];
	res[j] = 0;
	return (res);
}

char	*substr(char *s, int len)
{
	int		i;
	char	*substr;

	i = 0;
	if (!s)
		return (0);
	substr = malloc(sizeof(char) * len + 1);
	if (!substr)
		return (substr = NULL);
	while (i < len && s[i])
	{
		substr[i] = s[i];
		i++;
	}
	substr[i] = 0;
	return (substr);
}

char	*shortbuffer(char **s, int pos)
{
	int		i;
	int		len;
	char	*newbuffer;

	i = 0;
	len = 0;
	if (!s || !*s)
		return (NULL);
	while ((*s)[len])
		len++;
	if (pos > len)
		return (NULL);
	newbuffer = malloc(sizeof(char) * (len - pos + 1));
	if (!newbuffer)
		return (NULL);
	while ((*s)[pos])
		newbuffer[i++] = (*s)[pos++];
	newbuffer[i] = 0;
	free(*s);
	*s = NULL;
	return (newbuffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*output;
	int			bytes;

	bytes = read(fd, buffer, BUFFER_SIZE); 
	if (bytes < 0)
		return (NULL);
	return ()
}	

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("get_next_line.c", O_RDONLY);
	str = substr("0123456789", 5);
	printf("%s \n", str);
	str = shortbuffer(&str, 4);
	printf("%s \n", str);
	free(str);
	str = NULL;
	return (0);
}
