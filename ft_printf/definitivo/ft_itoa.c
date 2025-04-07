/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:44:11 by ranavarr          #+#    #+#             */
/*   Updated: 2025/04/07 18:18:07 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
char	*ft_itoa(int i, char *str);

double	ft_pow(double base, int exponent)
{
	double	result;

	result = 1;
	if (exponent == 0)
		return (1);
	if (exponent < 0)
	{
		base = 1 / base;
		exponent = -exponent;
	}
	while (exponent > 0)
	{
		result *= base;
		exponent--;
	}
	return (result);
}

int	first_digit(int n)
{
	int	value;

	value = n;
	while (value >= 10)
	{
		value /= 10;
	}
	return (n);
}
*/
int	limit_fix(int n, int len, char *str)
{
	int	last_digit;
	int	return_nbr;

	last_digit = (n % 10) * -1;
	str[len - 1] = last_digit + '0';
	return_nbr = (n / 10) / -1;
	return (0);

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
	if (i == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (i < 0)
	{
		if (i == INT_MIN)
			i = limit_fix(i, len, str);
		len++;
		str[0] = '-';
	}
	while (i)
	{
		str[--len] = ((i % 10) + 48);
		i /= 10;
	}
	return (str);
}
/*
int	main(void)
{
	return (0);
}
*/
