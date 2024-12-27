/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <ranavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:32:52 by ranavarr          #+#    #+#             */
/*   Updated: 2024/12/27 06:42:36 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int		ft_isalpha(int v);
int		ft_isdigit(int v);
int		ft_isalnum(int v);
int		ft_isascii(unsigned int c);
int		ft_isprint(int c);
int		ft_strlen(const char *s);

void	*ft_memset(void *s, int c, unsigned int n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, unsigned int n);
void	*ft_memmove(void *dest, const void *src, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
#endif
