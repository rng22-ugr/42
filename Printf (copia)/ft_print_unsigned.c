#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	char	*buffer;
	int		len;

	buffer = malloc(sizeof(char) * (ft_int_len(n) + 1));
	len = ft_print_str(ft_uitoa(n, buffer));	
	free(buffer);
	buffer = NULL;
	return(len);
}

