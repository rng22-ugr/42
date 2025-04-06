#include "ft_printf.h"

int	hexlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n)
	{
		n /= 16;
		len++;
	}
	len++;
	return (len);
}

int	ft_puthex_lower(int n)
{
	int		len;
	char	*str;

	len = hexlen(n);
	str = malloc(sizeof(char) * (len + 1));
	ft_itoa(n, str, 16);
	ft_print_str(str);
	return (len);
}

int	ft_puthex_upper(int n)
{
	int		len;
	char	*str;

	len = hexlen(n);
	str = malloc(sizeof(char) * (len + 1));
	ft_itoa(n, str, 16);
	while(str[i])
	{
		ft_putchar(ft_toupper(str[i]));
		i++;
	}
	return (len);
}
/*
int	main(void)
{
	ft_puthex(0);
	ft_putchar('\n');
	ft_puthex(9);
	ft_putchar('\n');
	ft_puthex(134);
	ft_putchar('\n');
	ft_puthex(1944350);
	ft_putchar('\n');
	ft_puthex(-190);
	ft_putchar('\n');
	ft_puthex(-140);
	ft_putchar('\n');
	printf("%x \n", -1);
	return (0);
}
*/
