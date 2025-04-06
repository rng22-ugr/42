/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:39:55 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/26 15:44:02 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	selector(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == '%')
		len = ft_print_percent();
	else if (c == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (c == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len = ft_print_int(va_arg(args, int));
	else if (c == 'x')
		len = ft_print_hex(va_arg(args, int), "0123456789abcdef");
	else if (c == 'X')
		len = ft_print_hex(va_arg(args, int), "0123456789ABCDEF");
	else if (c == 'p')
		len = ft_print_ptr((va_arg(args, uintptr_t)));
	else if (c == 'u')
		len = ft_print_unsigned(va_arg(args, int));
	return (len);
}

int	ft_printf(char *str, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += selector(str[++i], args);
		else
			ft_putchar(str[i]);
		len++;
		i++;
	}
	len += i;
	va_end(args);
	return (len);
}
