 unsigned int	ft_unsigned_len(unsigned i)
{
	int	len;

	if (i == 0)
		return (1);
	len = 0;
	while (i)
	{
		len++;
		i /= 10;
	}
	return (len);
}

char *ft_uitoa(unsigned i, char *str)
{
	unsigned int		len;

	len = ft_unsigned_len(i);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str(len) = '\0';
	while(mod2)
	{
		str[--len] = ((i % 10) + '0');
		i /= 10;
	}
	return (str);
}
