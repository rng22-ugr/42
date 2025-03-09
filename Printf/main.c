#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int printpercent(void)
{
	char	target;

	target = '%';
	write(1, &target, 1);
	return (1);
}

int printstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1,&str[i],1);
		i++;
	}
	return (i);
}

int	printc(char c)
{
	write(1,&c,1);
	return (1);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		j;

	va_start (args, str);

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				j = j + (printc(va_arg(args, int)));
			}
			if (str[i] == 's')
			{
				j = j + (printstr(va_arg(args, char *)));
			}
			i++;
		}
		write(1,&str[i],1);
		i++;
		}
	va_end(args);
	return(i + j);
}

int	main (void)
{
	char	c= 'H';

	ft_printf("probando meter cadenas directamente\n");
	ft_printf("probando introducir caracteres: %c \n", c);
	ft_printf("probando introducir cadenas: %s \n", "me muero");
	return (0);
}
