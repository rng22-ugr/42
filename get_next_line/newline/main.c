//#include "get_next_line.c"
#include "get_next_line.h"
//#include "get_next_line_utils.c"

int	main(void)
{
	char src[] = "crotolamodgj";
	char dst[] = "destructor de mundos";
	printf("TEST DE SEEK_DESTROY \n");
	printf("TEST DE %i \n", seek_destroy(src, dst, 'd' ));
	printf("TEST DE %s \n",src);
	printf("TEST DE %s \n",dst);
	return (0);
}
