#include "ft_printf.h"

void ft_puthex_recursive(int n, char *chars)
{
    if (n >= 16)
        ft_puthex_recursive(n / 16, chars);
    ft_print_char(chars[n % 16]);
}

int ft_puthex(int n, char *chars)
{
	int		i;

	if (n < 0)
	{
		ft_print_char('-');
		n = n * -1;
		i = 1;
	}
	else
		i = 0;
	if (n == 0)
	{
		ft_print_char('0');
		return 1;
	}
	ft_puthex_recursive(n, chars);
	int temp = n;

	while (temp > 0)
	{
		temp /= 16;
		i = i + 3;
	}
	return i;
}

// Tendre que quitar los shift operators
// #arreglar

int ft_puthex_long(long unsigned int num)
{
	const char	hex_digits[] = "0123456789abcdef";
	int			shift = (sizeof(num) * 8) - 4;
	int			started = 0;
	int			i;

	i = 1;
    if (num == 0) {
        ft_print_char('0');
        return (0);
    }

    while (shift >= 0)
		{
        char digit = hex_digits[(num >> shift) & 0xF];
        if (digit != '0' || started) {
            ft_print_char(digit);
            started = 1;
        }
        shift -= 4;
		i++;
    }
	return (i);
}
