/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:44:01 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/22 16:48:20 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len_long(uintptr_t value)
{
	int	len;

	len = 0;
	while (value)
	{
		value /= 16;
		len++;
	}
	return (len);
}

int ft_puthex_long(long unsigned int num)
{
	const char	hex_digits[] = "0123456789abcdef";
	int			shift = (sizeof(num) * 8) - 4;
	int			started = 0;
	int			i;

	i = 1;
	if (num == 0) {
		ft_putchar('0');
		return (1);
	}

	while (shift >= 0)
	{
		char digit = hex_digits[(num >> shift) & 0xF];  // Extract 4-bit chunk
		if (digit != '0' || started) {
			ft_putchar(digit);
			started = 1;
		}
		shift -= 4;
		i++;
	}
	return (i);
}	

int	ft_print_ptr(uintptr_t ptr)
{
	char	*buffer;
	int		len;

	buffer = malloc(sizeof(char) * ((ft_hex_len_long(ptr)) + 1));
	if (!buffer)
		return (0);
	ft_print_str("0x");
	len = ft_puthex_long(ptr);
	return (len + 2);
}
