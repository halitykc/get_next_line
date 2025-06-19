#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h>
int	main(void)
{
	int a = open("test.txt", O_RDONLY | O_RDWR);
	char *sa = get_next_line(a);
	printf("-%s",sa);
	free(sa);
	sa = get_next_line(a);
	printf("-%s",sa);
	free(sa);
	sa = get_next_line(a);
	printf("-%s",sa);
	free(sa);
	sa = get_next_line(a);
	printf("-%s",sa);
	free(sa);
	sa = get_next_line(a);
	printf("-%s",sa);
	free(sa);
	sa = get_next_line(a);
	printf("-%s",sa);
	free(sa);
	sa = get_next_line(a);
	printf("-%s",sa);
	free(sa);


}//git@github.com:keyiflerolsun/get_next_line.git