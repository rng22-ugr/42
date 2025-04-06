/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranavarr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:02:29 by ranavarr          #+#    #+#             */
/*   Updated: 2025/03/26 16:44:21 by ranavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int			ft_printf(char *str, ...);

int		ft_putchar(char c);
int		ft_put_percent(void);
int		ft_print_str(char *str);
char	*ft_itoa(int n, char *str, int base);
char	*ft_uitoa(unsigned long long int num, char *str, int base);
void	reverse(char str[], int lenght);

#endif
