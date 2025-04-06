#include "ft_printf.h"

void	reverse(char str[], int length)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}

char	*ft_itoa(int num, char *str, int base)
{
	int	i;
	int	isnegative;

	i = 0;
	isnegative = 0;
	if 	(num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return str;
	}
	if (num < 0 && base == 10) {
		isnegative = 1;
		num = -num;
	}
	while (num != 0)
	{
		int rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}
	if (isnegative)
		str[i++] = '-';
	str[i] = '\0';
	reverse(str, i);
	return str;
}
/*
int main()
{
    char str[100];
    printf("Number: %d\nBase: %d\tConverted String: %s\n",
           1567, 10, citoa(1567, str, 10));
    printf("Base: %d\t\tConverted String: %s\n", 2,
           citoa(1567, str, 2));
    printf("Base: %d\t\tConverted String: %s\n", 8,
           citoa(1567, str, 8));
    printf("Base: %d\tConverted String: %s\n", 16,
           citoa(1567, str, 16));
    return 0;
}
*/
