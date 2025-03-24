/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:00:35 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/24 13:35:22 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	unsigned int	i;

	if (str == NULL)
		return (ft_print_str("(null)"));
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	ft_print_int(ft_print_str("8"));
	ft_putchar('\n');
	ft_print_int(ft_print_str("12"));
	ft_putchar('\n');
	ft_print_int(ft_print_str("123"));
	ft_putchar('\n');
	ft_print_int(ft_print_str("1234"));
	ft_putchar('\n');
	ft_print_int(ft_print_str("12345"));
	ft_putchar('\n');
	ft_print_int(ft_print_str("123456"));
	ft_putchar('\n');
}
*/
