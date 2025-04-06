#include "get_next_line.h"

char *ft_strjoin(const char *s1, const char *s2)
{
    char *res;
    int i;
    int j;

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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*d;
	char			*s;

	d = (char *) dest;
	s = (char *) src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
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

int seek_destroy (char *src, char *dst, int c)
{
	int	pos;
	// seeking 
	pos = ft_strchr(src, c) - src;
	// destroying
	dst = memcpy(src, dst, pos);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*aux;

	// Check whether buffer exists and if it doesn't, create it
	aux = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read(fd, &aux, BUFFER_SIZE);
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		buffer = memcpy(buffer, aux, BUFFER_SIZE); 
	}
		
		return (NULL);
	}

