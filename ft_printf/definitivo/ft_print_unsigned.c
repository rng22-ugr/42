/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:37:18 by ranavarr          #+#    #+#             */
/*   Updated: 2025/04/07 18:49:32 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_unsigned_len(n);
	str = ft_calloc(sizeof(char), (len + 1));
	str = ft_uitoa(n, str);
	ft_print_str(str);
	free(str);
	str = NULL;
	return (len);
}
/*
int main(void)
{
	unsigned int	i;

	i = 1988481;
	ft_print_unsigned(i);
	return (0);
}
*/
