#include <stdio.h>
#include <stdlib.h>
int main()
{
	char a = 'a';
	char*p = &a;
	printf("%d  ", *p);
	system("pause");
	return 0;
}