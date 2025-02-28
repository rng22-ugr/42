/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 00:49:39 by ranavarr          #+#    #+#             */
/*   Updated: 2025/02/28 13:23:29 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// empecemos de nuev(voidtiremoslo todo a la basura
#include "get_next_line.h"

static void	*myrealloc(char *ptr, size_t size)
{
	char	*out;
	int		i;

	i = 0;
	out = malloc(size);
	if (!out)
		return (NULL);
	while (ptr[i])
	{
		out[i] = ptr[i];
		printf("%s\n", out);
		i++;
	}
	out[i] = '\0';
	return (out);
}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
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
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
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

int	mymalloc(void **ptr, int size)
{
	*ptr = malloc(size);
	if (!(*ptr))
		return (1);
	else
		return (0);
}

char	*extract(char *buf, char c)
{
	char	*line;
	//int		target;
	int		i;

	i = 0;
	//target = ft_strchr(buf, c);
	while (buf[i] != c)
		i++;
	line = malloc(sizeof(char) * i + 1);
	line[i] = c;
	while (i >= 0)
	{
		i--;
		line[i] = buf[i];
	}
	return line;
}
char	*cropper(char *buf, char c)
{
	int 	i;
	int		j;
	char	*newbuf;

	i = 0;
	j = 0;
	while (buf[i] != c)
		i++;
	if (mymalloc((void *)&newbuf, (sizeof(char) * (i + 1))))
		return (NULL);
	while (buf[++i])
	{
		newbuf[j] = buf[i];
		printf("%c",newbuf[j]);
		j++;
	}
	printf("\n");
	newbuf[j] = '\0';
	free(buf);
	return (newbuf);
}

char	*get_next_line(int fd)
{
	int			bytes;	
	char		*aux;
	static char	*buf;
	char		*line;	  
	
	line = NULL;
	aux = NULL;
	bytes = 1;
	if (!buf)
	{
		buf = malloc(sizeof(char) * 1);
		buf[0] = '\0';
	}
	/*if (mymalloc((void *)&buf, (sizeof(char) * (BUFFER_SIZE) + 1)) == 1)
		return (NULL);*/
	if (mymalloc((void *)&aux, (sizeof(char) * (BUFFER_SIZE) + 1)) == 1)
		return (NULL);
	while ((!buf) || (bytes != 0 && !ft_strchr(buf, '\n')))
	{
		bytes = read(fd, aux, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		aux[bytes] = '\0';
		buf = ft_strjoin(buf, aux);
	}
	printf("buf:", buf);
	line = extract(buf,'\n');
	buf = cropper(buf, '\n'); 
	return (line);
}

int	main(void)
{
	int fd = open("text", O_RDONLY);

	printf("Linea %s\n", get_next_line(fd));
	printf("Linea %s\n", get_next_line(fd));
	printf("Linea %s\n", get_next_line(fd));
	close(fd);
}
