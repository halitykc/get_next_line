#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int a = open("test.txt", O_RDONLY);

	printf("%s", get_next_line(a));
	printf("%s", get_next_line(a));

}