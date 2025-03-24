/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:01:10 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/24 12:39:50 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	char	*buffer;
	int		len;

	buffer = malloc(sizeof(char) * (ft_int_len(n) + 1));
	if (!buffer)
		return (0);
	len = ft_print_str(ft_uitoa(n, buffer));
	free(buffer);
	buffer = NULL;
	return (len);
}
