int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i += ft_put_char(str[i]);
	return (i);
}
