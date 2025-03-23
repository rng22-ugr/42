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

int	ft_hex_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_print_hex(int n, char *chars)
{
	int		len;
	char	*buffer;
	int		i;

	len = ft_hex_len(n);
	i = len - 1;
	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (0);
	buffer[len] = 0;
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
/*
int	main(void)
{
	int		i = 0;

	// hex_len test
	while (i <= 300)
	{
		printf("value = %i || len = %i\n", i, ft_hex_len(i));
		i += 10;
	}
	i = 0;
	while (i <= 300)
	{
		ft_print_hex(i, "0123456789abcdef");
		ft_putchar('\n');
		i += 1;
	}
	return (i);
}
*/
