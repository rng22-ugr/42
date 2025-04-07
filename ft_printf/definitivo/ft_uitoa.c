/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:44:11 by ranavarr          #+#    #+#             */
/*   Updated: 2025/04/07 21:21:51 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int i)
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

char	*ft_uitoa(unsigned int i, char *str)
{
	int					len;
	long unsigned int	tmp;

	tmp = (long unsigned int)i;
	len = ft_unsigned_len(i);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (tmp == 0)
	{
		str[0] = '0';
		return (str);
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
