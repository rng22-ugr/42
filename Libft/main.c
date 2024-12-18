int isdigit(int c)
{
    int output = 0;
   
    if (c >= '0' && c <= '9')
    {
        output = 1;
    }
    return output;
}

int islower(int c)
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
int isupper(int c)
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

int isalpha(int c)
{
    if (isupper(c) == 1 || islower(c) == 1)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int isalnum(int c)
{
    if ((isalpha(c) != 0) || (isdigit(c) != 0))
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int ispositive(int c)
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

int is7bit(int c)
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

int isascii(int c)
{
    if ((ispositive(c) != 0) && (is7bit(c) != 0))
    {
        return (1);
    }
    else
    {
        return(0);
    }
}

int isstrlen(const char* s)
{
    int len;

    len = 0;
    while (s[len] != '\0')
    {
        len = len + 1;

    }
    return (len);
}

void *memset(void *s, int c, size_t n)
{
    :
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

void bzero(void *s, size_t n)
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


