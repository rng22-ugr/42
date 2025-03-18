#include "ft_printf.h"

/*
int	ft_print_int(int i)
{
			char	*str;
			int		len;

			str = malloc(sizeof(char) * (intlen(i, 0) + 1));
			ft_itoa(i, str);
			len = ft_print_str(str);
			free(str);
			str = NULL;
			return (len);
}
*/
int	ft_print_int(int i)
{
	char	*str;
	int		len;

	str = malloc(sizeof(char) * (ft_int_len(i) + 1));
	if (!str)
		return (0);
	ft_itoa(i, str);
	len = ft_print_str(str);
	free(str);
	str = NULL;
	return (len);
}
