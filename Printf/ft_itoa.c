	//#include "libft.h"
//#include <stdlib.h>

static int int_len(long nbr);
static char *pre_conv(int len);

char *ft_itoa(int n)
{
	char *tmp;
    int len;
    int i;
    char *result;
    long nbr;

    nbr = n;
    len = int_len(nbr);
    result = pre_conv(len);
    if (!result)
        return (NULL);
    while (nbr != 0)
    {
        result[i] = ((nbr % 10) + 48);
        nbr = nbr / 10;
        i--;
    }
    tmp = malloc((len + 1) * sizeof(char));
    if (!tmp)
        return (NULL);
    tmp[0] = '0';
    return (tmp);
}

static int_len(long nbr)
{
    int count;

    count = 0;
    if (nbr < 0)
    {
        count++;
        nbr = -nbr;
    }
    if (nbr == 0)
        count++;
    while (nbr != 0)
    {
        nbr /= 10;
        count++;
    }
    return (count);
}
