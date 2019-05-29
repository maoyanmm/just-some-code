#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{	
	int i = 0;
	int j = 0;
	int x = 0;
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <=5 ; j++)
		{
			if (i == 3)
				continue;
			x = i*j;
			printf("%-4d", x);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}