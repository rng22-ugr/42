/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:52:03 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/26 15:57:41 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}
/*
int	main(void)
{
	ft_print_str("123456890 34343\042\n");
	return (0);
}
*/
