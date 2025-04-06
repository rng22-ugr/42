#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_int_len(n);
	str = malloc(sizeof(char) * (len + 1));
	str[len] = 0;
	str = ft_uitoa(n, str);
	ft_print_str(str);
	free(str);
	str = NULL;
	return (len);
}
/*
int main(void)
{
	unsigned int	i;

	i = 1988481;
	ft_print_unsigned(i);
	return (0);
}
*/
