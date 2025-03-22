/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:51:14 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/22 16:59:44 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_recursive(int n, char *chars)
{
	if (n >= 16)
		ft_puthex_recursive(n / 16, chars);
	ft_print_char(chars[n % 16]);
}

int	ft_puthex(int n, char *chars)
{
	int		i;
	int		temp;	

	temp = n;
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
		return (1);
	}
	ft_puthex_recursive(n, chars);
	while (temp > 0)
	{
		temp /= 16;
		i = i + 3;
	}
	return (i);
}

// Tendre que quitar los shift operators
// #arreglar

int	ft_puthex_long(long unsigned int num)
{
	const char	hex_digits[] = "0123456789abcdef";
	int			shift;
	int			started;
	int			i;
	char		digit;

	i = 1;
	started = 0;
	shift = (sizeof(num) * 8) - 4;
	if (num == 0)
	{
		ft_print_char('0');
		return (0);
	}
	while (shift >= 0)
	{
		digit = hex_digits[(num >> shift) & 0xF];
		if (digit != '0' || started)
		{
			ft_print_char(digit);
			started = 1;
		}
		shift -= 4;
		i++;
	}
	return (i);
}
