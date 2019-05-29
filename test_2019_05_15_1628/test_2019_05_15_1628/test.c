#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void inv(int* x,int n)
{
	int tmp = 0;
	int i = 0;
	
	for (i = 0; i < n/2; i++)
	{
		tmp = *(x + i);
		*(x + i) = *(x + n - 1 - i);
		*(x + n - 1 - i) = tmp;
	}
}

int main()
{
	int a[8] = { 3, 7, 9, 10, 0, 6, 7, 5 };
	int sz = sizeof(a) / sizeof(a[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	inv(a, sz);
	printf("\n");
	for (i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}