/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:58:36 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/26 16:55:00 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_len(int n)
{
	int	len;	
	int	tmp;

	printf("intlen\n");
	if (n == 0)
		return (1);
	tmp = n;
	len = 0;
	while (tmp >= 10)
	{
		tmp = tmp / 10;
		len++;
	}
	len++;
	return (len);
}

int	last_digit(int n)
{
	int	digit;
	int	rest;

	printf("lastdigit\n");
	if (n < 10)
		return (n);
	rest = n / 10;
	digit = n - (rest * 10);
	return (digit);
}

char	minitoa(int n)
{
	printf("minitoa\n");
	if (n < 10)
		return (n + '0');
	else
		return (0);
}

int	ft_itoa(int n, char *buffer)
{
	int	len;	
	int	tmp;
	int	i;	

	i = 1;
	printf("itoa\n");
	len = int_len(n) - 1;
	buffer[len] = '\0';
	tmp = n;
	while (buffer[len - i])
	{
		buffer[len - i] = minitoa(last_digit(tmp));
		tmp /= 10;
		i++;
	}
	return (0);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*buffer;

	printf("putnbr\n");
	len = int_len(n);
	buffer = malloc(sizeof(char) * len + 1);
	if (!buffer)
	{
		free(buffer);
		buffer = NULL;
		return (0);
	}
	ft_itoa(n, buffer);
	ft_print_str(buffer);
	return (len);
}

int	main(void)
{
	/*
	ft_putchar(int_len(0) + '0');
	ft_putchar(int_len(01) + '0');
	ft_putchar(int_len(10) + '0');
	ft_putchar(int_len(110) + '0');
	ft_putchar(int_len(13420) + '0');
	ft_putchar('\n');
	ft_putchar(last_digit(13420) + '0');
	ft_putchar(last_digit(13427) + '0');
	ft_putchar(last_digit(13424) + '0');
	ft_putchar(last_digit(13429) + '0');
	ft_putchar(last_digit(13424) + '0');
	ft_putchar(last_digit(13426) + '0');
	ft_putchar('\n');
	*/
	ft_putnbr(1);
	ft_putnbr(2341);
	ft_putnbr(12048);
	ft_putnbr(9);
	ft_putnbr(0);
	return (0);
}
