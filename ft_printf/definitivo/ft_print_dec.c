#include "ft_printf.h"

int	ft_print_dec(int n)
{
	int		len;
	char	*str;

	len = ft_int_len(n);
	str = malloc(sizeof(char) * (len + 1));
	str[len] = 0;
	str = ft_itoa(n, str);
	ft_print_str(str);
	free(str);
	str = NULL;
	return (len);
}
/*
int main(void)
{
	int	i;

	i = 0;
	ft_print_dec(i);
	return (0);
}
*/
