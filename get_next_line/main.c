/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 00:49:39 by ranavarr          #+#    #+#             */
/*   Updated: 2025/02/28 00:49:41 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

* ************************************************************************* */

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
	printf("hola 1\n");
	if (!res)
		return (NULL);
	while (s1[i])
		res[j++] = s1[i++];
	printf("hola 2\n");
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	printf("hola 3\n");
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

int mymalloc(void **ptr, int size)
{
	*ptr = malloc(size);
	if (!(*ptr))
		return (1);
	else
		return (0);
}

int	get_next_line(int fd)
{
	int			bytes;	
	char		*chr;
	char		*aux;
	static char	*buf;

	chr = NULL;			// at least initialize it for hygiene
	aux = NULL;	// at least initialize it for hygiene
	buf = NULL;
	// Alocate memory size for buffer
	if ( mymalloc((void *)&buf, (sizeof(char) * (BUFFER_SIZE) + 1)) == 1)
	{
		printf("me cago en dios que eso no va (en el malloc de buf)\n");
		return (1);
	}
	if ( mymalloc((void *)&aux, (sizeof(char) * (BUFFER_SIZE) + 1)) == 1)
	{
		printf("me cago en dios que eso no va (en el malloc de aux)\n");
		return (1);
	}
	// Check that malloc worked
	if (buf)
	{
		printf("malloc ha ido bien");
	}
	else
	{
		printf("malloc ha fallado\n");
		return (1);
	}
	// open file before reading it


	// read BUFFER_SIZE bytes from the fdit
	while (chr == 0)
	{
		bytes = read(fd, aux, BUFFER_SIZE);
		if (bytes == -1)
		{
			printf("read ha salido mal\n");
		}
		else
		{
			printf("read ha salido bien, aqui lo tengo: %i y se han leido  %i bytes\n", fd, bytes);
		}

	// Check wether there is a newline character and if there is, locate 
		chr = ft_strchr(buf, '\n');
		printf("No newline found in buffer \n");
		buf = ft_strjoin(buf, aux);
		printf("Esto es aux %s y esto es buf %s,antes del switcherido\n",aux, buf);
	}
	// do the thing where we add another buffer and read again?
	printf("Newline en el carácter número %li del buffer\n", (buf - chr));
	return (0);
}

int main(void)
{
	int fd = open("text", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
}
