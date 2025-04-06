#include "ft_printf.h"

int	intlen(int n)
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
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

int	ft_putint(int n)
{
	int		len;
	char	*str;

	len = intlen(n);
	str = malloc(sizeof(char) * (len + 1));
	ft_itoa(n, str, 10);
	ft_print_str(str);
	return (len);
}
/*
int	main(void)
{
	ft_putint(0);
	ft_putchar('\n');
	ft_putint(9);
	ft_putchar('\n');
	ft_putint(134);
	ft_putchar('\n');
	ft_putint(1944350);
	ft_putchar('\n');
	ft_putint(-190);
	ft_putchar('\n');
	ft_putint(-140);
	ft_putchar('\n');
	return (0);
}
*/
