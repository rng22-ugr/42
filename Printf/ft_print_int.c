/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:45:03 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/22 16:45:05 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int	ft_print_int(int i)
{
			char	*str;
			int		len;

			str = malloc(sizeof(char) * (intlen(i, 0) + 1));
			ft_itoa(i, str);
			len = ft_print_str(str);
			free(str);
			str = NULL;
			return (len);
}
*/
int	ft_print_int(int i)
{
	char	*str;
	int		len;

	str = malloc(sizeof(char) * (ft_int_len(i) + 1));
	if (!str)
		return (0);
	ft_itoa(i, str);
	len = ft_print_str(str);
	free(str);
	str = NULL;
	return (len);
}
