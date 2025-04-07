/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:44:11 by ranavarr          #+#    #+#             */
/*   Updated: 2025/04/07 21:17:03 by ranavarr         ###   ########.fr       */
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

int	limit_fix(long int n, int len, char *str)
{
	int	last_digit;
	int	return_nbr;

	last_digit = (n % -10);
	str[len - 1] = last_digit + '0';
	return_nbr = (n / -10);
	return (return_nbr);
}

*/
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
	int			len;
	long int	tmp;	

	tmp = (long int)i;
	len = ft_int_len(i);
	if (!str)
		return (NULL);
	if (tmp == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (tmp < 0)
	{
		len++;
		tmp *= -1;
		str[0] = '-';
	}
	while (tmp)
	{
		str[--len] = ((tmp % 10) + 48);
		tmp /= 10;
	}
	return (str);
}
/*
int	main(void)
{
	return (0);
}
*/
