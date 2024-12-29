/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:32:34 by ranavarr          #+#    #+#             */
/*   Updated: 2024/12/27 18:43:22 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
    size_t	total_size;
    void	*ptr;

    // Check for overflow
    if (nmemb != 0 && size > SIZE_MAX / nmemb)
        return (0);

    total_size = nmemb * size;

    // Allocate memory
    ptr = malloc(total_size);
    if (!ptr)
        return (0);

    // Initialize memory to zero
    ft_memset(ptr, 0, total_size);
    return (ptr);
}
