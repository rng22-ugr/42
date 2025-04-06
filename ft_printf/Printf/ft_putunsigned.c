/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:01:10 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/25 18:25:40 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


int	ft_putunsigned(unsigned int n)
{
	char			*str;
	int				len;
	unsigned int	tmp;

}

int	main(void)
{
	unsigned int	i;

	i = 1;
	
	while (i <= 100000)
	{
		printf("longitud de %u =  %u \n", i, ft_unsigned_len(i));
		i *= 10;
	}
	return (0);
}
