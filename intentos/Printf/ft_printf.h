/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:02:29 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/25 18:26:24 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

//	printers
int				ft_putchar(char c);
int				ft_print_str(char *str);
int				ft_print_int(int i);
int				ft_print_percent(void);
int				ft_print_hex(int n, char *chars);
int				ft_print_hex_long(uintptr_t num, char *chars);
int				ft_print_unsigned(unsigned int n);
int				ft_print_ptr(uintptr_t ptr);
int				ft_printf(char const *str, ...);

//	utils
int			ft_int_len(int i);
char	*ft_itoa(int i, char *str);
int		ft_unsigned_len(unsigned int i);
char	*ft_uitoa(unsigned int i, char *str);
int		ft_hex_len(int n);

#endif
