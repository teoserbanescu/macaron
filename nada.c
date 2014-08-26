#include <stdio.h>

int main()
{
	int (*p)(void);
	p = &main;
	printf("fradf\n");
	p();
	return 0;
}