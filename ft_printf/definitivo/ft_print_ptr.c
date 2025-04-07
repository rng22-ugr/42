/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:44:01 by ranavarr          #+#    #+#             */
/*   Updated: 2025/04/07 22:42:20 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
int	ft_hex_len_long(uintptr_t value)
{
	int			len;
	uintptr_t	tmp;

	len = 0;
	if (value == 0)
		return (1);
	tmp = value;
	while (tmp)
	{
		tmp = tmp / 16;

		printf("%i ", len);
		len++;
	}
	return (len);
}
int	ft_puthex_long(long unsigned int num)
{
	const char	hex_digits[] = "0123456789abcdef";
	int			shift = (sizeof(num) * 8) - 4;
	int			started = 0;
	int			i;

	i = 1;
	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (shift >= 0)
	{
		char digit = hex_digits[(num >> shift) & 0xF];
		if (digit != '0' || started) 
		{
			ft_putchar(digit);
			started = 1;
		}
		shift -= 4;
		i++;
	}
	return (i);
}	
*/

int	ft_print_hex_long(uintptr_t n, char *chars)
{
	int		len;
	char	*buffer;
	int		i;

	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	len = ft_hex_len(n);
	i = len - 1;
	buffer = ft_calloc(sizeof(char), (len + 1));
	if (!buffer)
		return (0);
	while (i >= 0)
	{
		buffer[i] = chars[n % 16];
		n /= 16;
		i--;
	}
	ft_print_str(buffer);
	free(buffer);
	buffer = NULL;
	return (len);
}

int	ft_print_ptr(uintptr_t ptr)
{
	int		len;

	if (!ptr)
		return (write(1, "(nil)", 5), 5);
	ft_print_str("0x");
	len = ft_print_hex_long(ptr, "0123456789abcdef\n");
	return (len + 2);
}
/*
int	main(void)
{
	int	i;

	i = 0;
	while (i <= 600)
	{
		ft_print_str("probando hex_len_long \n");
		printf(" numero = %i ", i);
		printf("longitud = ");
		ft_hex_len_long(i);
		printf("\n");
		i += 10;
	}
	
	return (0);
}
*/
