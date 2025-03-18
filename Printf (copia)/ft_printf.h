
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

//	printers
int				ft_print_char(char c);
int				ft_print_str(char *str);
int 			ft_print_int(int i);
int				ft_print_percent(void);
void			ft_puthex_recursive(int n, char *chars);
int				ft_puthex(int n, char *chars);
int				ft_puthex_long(long unsigned int num);
int				ft_print_unsigned(unsigned int n);
int				ft_print_ptr(uintptr_t ptr);
//	utils
int				ft_int_len(int i);
char			*ft_itoa(int i, char *str);
unsigned int	ft_unsigned_len(unsigned i);
char			*ft_uitoa(unsigned int i, char *str);
int				ft_hex_len(uintptr_t value);

#endif
