
#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;


	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	if (s1)
		free(s1);
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
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

int	ft_strlcpy(char *dst, char *src, int size)
{
	int		i;

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

/*
int copy_shift(char *dst, char *src, int size)
{
	
	
}
*/

char	*extract(char *buf)
{
	char	*line;
	int		i;

	i = 0;
	if (!buf || buf[0] == '\0')
		return (NULL);
	while (buf[i] != '\n' || buf[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i > 0)
	{
		i--;
		line[i] = buf[i];
	}
	return (line);
}

char	*cropper(char *buf, char c) {
	int		i;
	int		j;
	char	*newbuf;

	i = 0;
	j = 0;
	if (!buf)
		return (NULL);
	while (buf[i] && buf[i] != c)
		i++;
	newbuf = malloc(sizeof(char) * ((ft_strlen(buf) - i) + 0));
	if (!newbuf)
		return NULL;
	while (buf[i])
		newbuf[j++] = buf[i++];
	newbuf[j] = '\0';
	free(buf);
	return (newbuf);
}
