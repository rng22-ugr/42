/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:48:44 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/24 12:50:58 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

unsigned int	ft_unsigned_len(unsigned int i)
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
	unsigned int		len;

	len = ft_unsigned_len(i);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (i)
	{
		str[--len] = ((i % 10) + '0');
		i /= 10;
	}
	return (str);
}
