#include "ft_printf.h"

int	hexlen_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		len++;
	}
	len++;
	return (len);
}

int	ft_putptr(void *ptr)
{
	int		len;
	char	*str;

	len = hexlen_unsigned((unsigned long long int)ptr);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	ft_uitoa((unsigned long long int)ptr, str, 16);
	ft_print_str("0x");
	ft_print_str(str);
	free(str);
	str = NULL;
	return (len);
}
/*
int	main(void)
{
	char c = 'c';
	char	*ptr = &c;

	ft_putptr((void *)ptr);
	printf("\n");
	printf("%p", ptr);
	return (0);
}
*/
