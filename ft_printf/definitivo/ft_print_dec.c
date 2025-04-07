/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:36:32 by ranavarr          #+#    #+#             */
/*   Updated: 2025/04/07 18:35:04 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dec(int n)
{
	int		len;
	char	*str;

	len = ft_int_len(n);
	if (n < 0)
		len++;
	str = ft_calloc(sizeof(char), (len + 1));
	if (!str)
		return (0);
	ft_itoa(n, str);
	ft_print_str(str);
	free(str);
	str = NULL;
	return (len);
}
/*
int main(void)
{
	int	i;

	i = 0;
	ft_print_dec(i);
	return (0);
}
*/
