/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:38:56 by ranavarr          #+#    #+#             */
/*   Updated: 2024/12/27 18:24:32 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*stallman;
	unsigned char	ca;

	i = 0;
	ca = (unsigned char) c;
	stallman = (unsigned char *)s;
	while (i < n)
	{
		if (stallman[i] == ca)
			return ((void *) &stallman[i]);
		i++;
	}
	return (0);
}
