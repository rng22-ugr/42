/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 06:54:46 by ranavarr          #+#    #+#             */
/*   Updated: 2024/12/27 07:19:31 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  dst_len;
    size_t  src_len;
    size_t  i;
    size_t  j;

    dst_len = 0;
    src_len = 0;
    while (dst[dst_len] && (dst_len < size))
        dst_len++;
    src_len = 0;
    while (src[src_len])
        src_len++;

    if (dst_len == size)
        return (size + src_len);

    i = dst_len;
    j = 0;
    while ((i + 1 < size) && (src[j] != '\0'))
    {
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[i] = '\0';

    return (dst_len + src_len);
}

