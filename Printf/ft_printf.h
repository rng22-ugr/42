
#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

//	printers

int		ft_print_u(unsigned i);
int		ft_inverted_print(char *str, int size);
int		ft_inverted_print(char *str, int size);

int		ft_print_int(int i);
int		ft_print_ptr(uintptr_t ptr);
int		ft_print_char(char c);

int		ft_puthex_long(long unsigned int num);



int		ft_puthex_long(long unsigned int num);
int		ft_print_percent(void);


//	utils
char	*ft_itoa(int n, char *s);
int		ft_abs(int i);
int		intlen(int i, int len);
void	ft_puthex_recursive(int n, char *chars);
char	*ft_uitoa(unsigned int n, char *s);
void	ft_puthex_recursive(int n, char *chars);
int		ft_puthex(int n, char *chars);
#endif
