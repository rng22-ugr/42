// empecemos de nuevo, tiremoslo todo a la basura
#include "get_next_line.h"

static void	*myrealloc(void *ptr, size_t size)
{
	void	*out;
	int 	i;

	i = 0;
	out = malloc(size);
	if (!out)
		return ;

	while (ptr[i])
	{
		out[i] = ptr[i];
		printf("%s\n",out);
		i++;
	}
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
		res[j++] = s2[i];
	res[j] = 0;
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

int	main(void)
{
	static char	*buf; 	//	Buffer where we store BUFFER_SIZE bytes read
	/// static int	steps;	// 	Multiplyer to know the size of the new buffer // don't need this shi
	int			fd;		//	File descriptor we read from 
	int			bytes;	//	Return value of read()
	char		*chr;	//	Return value of ft_strchr
	char		*replacement;

	chr = 0;			// at least initialize it for hygiene
	replacement = 0;	// at least initialize it for hygiene
	// Alocate memory size for buffer
	buf = malloc((sizeof(char) * (BUFFER_SIZE) + 1));
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
	fd = open("text", O_RDONLY);

	// read BUFFER_SIZE bytes from the fd
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes == -1)
	{
		printf("read ha salido mal\n");
	}
	else
	{
		printf("read ha salido bien, aqui lo tengo: %i y se han leido  %i bytes\n", fd, bytes);
	}

	// Check wether there is a newline character and if there is, locate it
	chr = ft_strchr(buf, '\n');
	if (chr == 0)	//	If ther is no newline in buf
	{
		printf("No newline found in buffer \n");
		replacement = (char *)(myrealloc(buf, (strlen(buf + BUFFER_SIZE))));

		// do the thing where we add another buffer and read again?
	}
	else
	{
		printf("Newline en el carácter número %i del buffer\n", (chr - buf));
	}
	return (0);
}
