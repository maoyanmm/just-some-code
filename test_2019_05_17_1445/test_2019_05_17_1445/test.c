#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("* ");
		}
		while (i < 0)
		{
			i--;
			printf(" ");
		}
	}
	system("pause");
	return 0;

}