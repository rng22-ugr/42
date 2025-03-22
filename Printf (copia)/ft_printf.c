/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:44:49 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/22 16:46:50 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include "ft_printf.h"

/*
int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i += ft_print_char(str[i]);
	return (i);
}

int	ft_int_len(int i)
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

char	*ft_itoa(int i, char *str)
{
	int		len;

	len = ft_int_len(i);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (i < 0)
	{
		len++;
		str[0] = '-';
		i = i * -1;
	}
	while (i)
	{
		str[--len] = ((i % 10) + 48);
		i /= 10;
	}
	return (str);
}

int	ft_print_int(int i)
{
	char	*str;
	int		len;

	str = malloc(sizeof(char) * (ft_int_len(i) + 1));
	if (!str)
		return (0);
	ft_itoa(i, str);
	len = ft_print_str(str);
	free(str);
	str = NULL;
	return (len);
}

int ft_print_percent(void)
{
	return (ft_print_char('%'));
}

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

void ft_puthex_recursive(int n, char *chars)
{
	if (n >= 16)
		ft_puthex_recursive(n / 16, chars);
	ft_print_char(chars[n % 16]);
}

int ft_puthex(int n, char *chars)
{
	int		i;
	int		temp;

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
	temp = n;
	while (temp > 0)
	{
		temp /= 16;
		i++;
	}
	return i;
}

int ft_puthex_long(long unsigned int num)
{
	const char	hex_digits[] = "0123456789abcdef";
	int			shift = (sizeof(num) * 8) - 4;
	int			started = 0;
	int			i;

	i = 1;
	if (num == 0) {
		ft_print_char('0');
		return (1);
	}

	while (shift >= 0)
	{
		char digit = hex_digits[(num >> shift) & 0xF];  // Extract 4-bit chunk
		if (digit != '0' || started) {
			ft_print_char(digit);
			started = 1;
		}
		shift -= 4;
		i++;
	}
	return (i);
}

char *ft_uitoa(unsigned int i, char *str)
{
	unsigned int	len;

	len = ft_unsigned_len(i);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (i)
	{
		str[--len] = ((i % 10) + '0');
		i /= 10;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int n)
{
	char	*buffer;
	int		len;

	buffer = malloc(sizeof(char) * (ft_int_len(n) + 1));
	len = ft_print_str(ft_uitoa(n, buffer));	
	free(buffer);
	buffer = NULL;
	return(len);
}

int	ft_hex_len(uintptr_t value)
{
	int	len;

	while (value)
	{
		value /= 16;
		len++;
	}
	return len;
}
	
int	ft_print_ptr(uintptr_t ptr)
{
	char	*buffer;
	int		len;

	buffer = malloc(sizeof(char) * ((ft_hex_len(ptr)) + 1));
	if (!buffer)
		return (0);
	ft_print_str("0x");
	len = ft_puthex_long(ptr);
	return (len + 2);
}
*/

int	selector(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_print_int(va_arg(args, int)));
	else if (c == '%')
		return (ft_print_percent());
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned)));
	else if (c == 'x')
		return (ft_puthex(va_arg(args, int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(args, uintptr_t)));
	else
		return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		j;

	va_start(args, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			j += selector(str[i], args);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			j++;
			i++;
		}
	}
	va_end(args);
	return (j);
}

/*
int	main(void)
{
	char	c = 'A';

	ft_printf("probando meter cadenas directamente\n");
	ft_printf("probando introducir caracteres: %c \n", c);
	ft_printf("probando introducir cadenas: %s \n", "me muero");
	ft_printf("probando introducir números positivos: %i \n", 139);
	ft_printf("probando introducir números negativos: %i \n", -139);
	ft_printf(" introducir carares: %c y luego cads %s \n", c, "no se cuan);
	ft_printf("probando introducir números sin signo: %u  \n", 29);
	ft_printf("probando introducir hexadecimales positivos: %x  \n", 29);
	ft_printf("probando introducir hexadecimales negativos: %x  \n", -29);
	ft_printf("probando introducir hexadecimales negativos: %x  \n", -2000);
	ft_printf("probando introducir hexadecimales positivos: %x  \n", 2000);
	ft_printf("probando introducir punteros: %p  \n", &c);
	printf("me come los huevos %p \n", &c);

	return (0);
}
*/
