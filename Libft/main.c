int ft_isdigit(int c)
{
    int output = 0;
   
    if (c >= '0' && c <= '9')
    {
        output = 1;
    }
    return output;
}

int ft_islower(int c)
{
    if ((c >= 'a') && (c <= 'z'))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
int ft_isupper(int c)
{
    if ((c >= 'A') && (c <= 'Z'))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int ft_isalpha(int c)
{
    if (ft_isupper(c) == 1 || ft_islower(c) == 1)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int ft_isalnum(int c)
{
    if ((ft_isalpha(c) != 0) || (ft_isdigit(c) != 0))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int ft_ispositive(int c)
{
    if (c >= 0)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int ft_is7bit(int c)
{
    if (c < 128) //128, porque el 0 tambien cuenta!!!!!!
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int ft_isascii(int c)
{
    if ((ft_ispositive(c) != 0) && (ft_is7bit(c) != 0))
    {
        return (1);
    }
    else
    {
        return(0);
    }
}
int ft_isstrlen(const char* s)
{
    int len;

    len = 0;
    while (s[len] != '\0')
    {
        len = len + 1;

    }
    return (len);
}

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *ptr = s;
    size_t i;
    i = 0;
    while (i < n)
    {
        if (ptr[i] == '\0')
        {
            break;
        }
        else
        {
            ptr[i] = (unsigned char)c;
            i = i + 1;
        }
    }
    return (ptr);
}

void ft_bzero(void *s, size_t n)
{
    char *ptr = s;
    size_t i;

    i = 0;
    while (i < n)
    {
        ptr[i] = '\0';
        i = i + 1;
    }
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    int i;
    
    i = 0;
    while (i < n)
    {
        dest[i] = src[i];
        i = i + 1;
    }
}
void *ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;
	

	

}

