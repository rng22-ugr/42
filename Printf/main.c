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

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_itoa.c"

int	printstr(char *str)
{
	int	i;
	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	printpercent(void)
{
	char	target;

	target = '%';
	write(1, &target, 1);
	return (1);
}

int	printc(char c)
{
	write(1, &c, 1);
	return (1);
}

int	printunsigned(int i)
{
	if (i < 0)
		i = i * -1;
    return ( printstr(mitoa(i)));
}

int turntable(char	c, va_list args)
{
	if (c == 'c')
		return (printc(va_arg(args, int)));
	if (c == 's')
		return (printstr(va_arg(args, char *)));
	if (c == 'i')
		return (printstr(mitoa(va_arg(args, int))));
	if (c == 'u')
	   return (printunsigned(va_arg(args, unsigned int)));
	return (-1);
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
			j = j + turntable(str[i], args);
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
	char	c= 'H';

	ft_printf("probando meter cadenas directamente\n");
	ft_printf("probando introducir caracteres: %c \n", c);
	ft_printf("probando introducir cadenas: %s \n", "me muero");
	ft_printf("probando introducir números positivos: %i \n", 139);
	ft_printf("probando introducir números lenativos: %i \n", -139);
	ft_printf("probando introducir caracteres: %c y luego cadenas %s \n", c, "no se cuanto mas aguantare");
	ft_printf("probando introducir números sin signo: %u  \n",29);

	printf("probando intlen: \n", intlen(1));
	printf("%i \n", intlen(1));
	printf("%i \n", intlen(12));
	printf("%i \n", intlen(123));
	printf("%i \n", intlen(12345));
	printf("%i \n", intlen(1234567890));
	printf("%i \n", intlen(132));
	printf("%i \n", intlen(3141));
	printf("%i \n", intlen(1349));
	printf("probando mitoa \n", intlen(1));
	printf("%s \n", ft_itoa(2));
	printf("%s \n", mitoa(92));
	printf("%s \n", mitoa(-5392));
	printf("%s \n", mitoa(432432));
	return (0);
}
