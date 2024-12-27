/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:38:56 by ranavarr          #+#    #+#             */
/*   Updated: 2024/12/27 14:08:21 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*stallman;

	i = 0;
	stallman = (char *)s;
	while (i < n)
	{
		if (stallman[i] == c)
			return ((void *) &stallman[i]);
		i++;
	}
	return (0);
}
