#include <stdio.h>
#include "main.c" 



void test(int value)

{
	if (value == 0)
	{
	    printf("\033[0;31mKO\033[0m\n");
	}
	else
	{
		printf("\033[0;32mOK\033[0m\n");
	}
}


//isalpha
int test_isdigit()
{
	unsigned char i = 0;

	while (i < '0')         //Debe ser menor que '0' para que no de error en '0'!!!!!
	{
		if (isdigit(i) != 0)
		{
			return (0);
		}
        i = i+1;
	}
	while (i <= '9')
	{
		if (isdigit(i) != 0)
		{
            i = i+1;
		}
        else
        {
			return (0);
        }
	}

    return (1);
}

int test_isalpha()
{
    char i = 0;
    
    while (i < 'A')
    {
        if (isalpha(i) != 0)
        {
            return (0);
        }
        i++;
    }
    while (i <='Z')
    {
        if (isalpha(i) == 0)
        {
            return (0);
        }
        i++;
    }
 
    while (i < 'a')
    {
        if (isalpha(i) != 0)
        {
            return (0);
        }
        i++;
    }
 
    while (i <='z')
    {
        if (isalpha(i) == 0)
        {
            return (0);
        }
        i++;
    }
    return (1);
}
int test_isalnum(int c)
{
    if (test_isdigit(c) != 0 || test_isalpha(c) != 0)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int test_isascii()
{
    int c;

    c = -10;

    //Números negativos
    while (c < 0)
    {
        if (isascii(c) != 0)
        {
            return (0);
        }
        c = c+1;
    }
    // Hasta 128
    while (c < 128)
    {
         if (isascii(c) == 0)
        {
            return (0);
        }
        c = c+1;
    }

    return (1);
}
int test_strlen()
{
    char str[101]; 
    int i;

    i = 0;
    str[0] = '\0';
    while (i < 100)
    {
        if (isstrlen(str) != i)
        {
            return (0);
        }
        str[i] = 'A';
        str[i+1] = '\0';
        i = i + 1;
    }
    return (1);
}

int main()
{

    // Isdigit
    printf("isdigit ");
	test(test_isdigit());

    // Isalpha
    printf("isalpha ");
	test(test_isalpha());

    // Isalnum
    printf("isalnum ");
	test(test_isalpha());

    // Isascii
    printf("isascii ");
	test(test_isascii());

    //  strlen 
    printf("strlen ");
	test(test_strlen());


	return (0);
}
