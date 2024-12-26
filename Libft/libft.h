/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <ranavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 19:32:52 by ranavarr          #+#    #+#             */
/*   Updated: 2024/12/27 00:55:40 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int		ft_isalpha(int v);
int		ft_isdigit(int v);
int		ft_isalnum(int v);
int		ft_isascii(unsigned int c);
int		ft_isprint(int c);

int		ft_strlen(const char *s);

void	*ft_memset(void *s, int c, unsigned int n);
void	ft_bzero(void *s, size_t n);
#endif
