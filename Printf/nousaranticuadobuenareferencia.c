/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:21:28 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/11 17:26:24 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>


int	ft_print_char(char c)
{
	write(1, &c, 1);
	return(1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i += ft_print_char(str[i]);
	return (i);
}

int	ft_int_len(int i)
{
	int	len;

	if (i == 0)
		return (1);
	len = 0;
	if (i < 0)
		len++;
	while (i)
	{
		len++;
		i /= 10;

	}
	return (len);
}

int	ft_print_int(int i)
{
			char	*str;
			int		len;

			str = malloc(sizeof(char) * (ft_int_len(i) + 1));
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

int ft_puthex_long(long unsigned int num)
{
	const char	hex_digits[] = "0123456789abcdef";
	int			shift = (sizeof(num) * 8) - 4;  // Start from the most significant nibble
	int			started = 0;  // Flag to skip leading zeros
	int			i;

	i = 1;
    if (num == 0) {
        ft_print_char('0');
        return (0);
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
	}
	while(i)
	{
		str[--len] = ((i % 10) + 48);
		i /= 10;
	}
	return (str);
}

char *ft_uitoa(unsigned int i, char *str)
{
	unsigned int		len;

	len = ft_unsigned_len(i);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while(i)
	{
		str[--len] = ((i % 10) + '0');
		i /= 10;
	}
	return (str);
}
/*
int ft_puthex_long(long unsigned int n)
{
	if (n = 0)
	{
		return ('0');
	}
		return ('0');
}
*/

/*
int ft_ftoa(float n, char *s)
{
	int	whole;
	int	fractional;

	whole = n;
}
*/

/*
int	ft_print_p(uintptr_t ptr)
{
	if(ptr == 0)
		return (ft_print_str("0x0"));


	return(ft_puthex_long(ptr));
}
*/
int	selector(char	c, va_list args)
{
	if (c == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (c == 'i' || c == 'd')
		return (ft_print_int(va_arg(args, int)));
	else if (c == '%')
		return (ft_print_percent());
/*
	else if (c == 'u')
		return (ft_print_u(va_arg(args, unsigned)));

	else if (c == 'x')
		return (ft_puthex(va_arg(args, int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_puthex(va_arg(args, int), "0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_print_ptr(va_arg(args, uintptr_t)));
		else
*/
	return(0);
}

int	ft_printf(char const *str, ...)

{
	va_list	args;
	int		i;
	int		j;

	va_start (args, str);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			j = j + selector(str[i], args);
			i++;
		}
		write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (i + j);
}


int	main (void)
{
	char	c[]= "esto es una cadena, no se si lo has visto.";

	ft_printf("probando meter cadenas directamente\n");
	ft_printf("probando introducir caracteres: %c \n", c);
	ft_printf("probando introducir cadenas: %s \n", "me muero");
	ft_printf("probando introducir números positivos: %i \n", 139);
	ft_printf("probando introducir números lenativos: %i \n", -139);
	ft_printf("probando introducir caracteres: %c y luego cadenas %s \n", c, "no se cuanto mas aguantare");
	ft_printf("probando introducir números sin signo: %u  \n", 29);
	ft_printf("probando introducir hexadecimales positivos: %x  \n", 29);
	ft_printf("probando introducir hexadecimales negativos: %x  \n", -29);
	ft_printf("probando introducir hexadecimales negativos: %x  \n", -2000);
	ft_printf("probando introducir hexadecimales positivos: %x  \n", 29);
	ft_printf("probando introducir hexadecimales negativos: %x  \n", -29);
	ft_printf("probando introducir hexadecimales negativos: %x  \n", -223452);
	ft_printf("probando introducir punteros: %p  \n", c);


	return (0);
}
/*
//	printf("probando ft_itoa \n", ft_int_len(1));
	printf("itoa %i \n", ft_itoa(2234535, c));
	printf("%s \n", c);

	printf("uitoa %u \n", ft_uitoa(2734365472, c));
	printf("%s \n", c);

	printf("%i \n", ft_print_int(2348));
	printf("%s \n", c);

	printf("%i \n", ft_print_int(-2492));
	printf("%s \n", c);

	printf(" no se como funcionan los hex en printf... :%x \n", 255);
	printf("%s \n", c);

	printf("  tampoco  se como funciona imprimir punteros hex en printf... :%p \n", &c);
*/
