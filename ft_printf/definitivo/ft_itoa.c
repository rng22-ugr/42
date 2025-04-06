/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:44:11 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/22 16:44:12 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		len++;
		str[0] = '-';
		i = i * -1;
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
