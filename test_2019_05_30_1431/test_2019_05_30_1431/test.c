#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int arr[] = { 2, 6, 8, 3, 2, 9, 3, 6 };
	int i = 0;
	int x = 0;
	int j = 0;
	int a = 0;
	int b = 0;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		x = x^arr[i];
	}
	for (i = 0; i < 32; i++)
	{
		if ((x & 1) == 1)
		{
			break;
		}
		x = x >> 1;
	}
	
	for (j = 0; j < sizeof(arr) / sizeof(arr[0]); j++)
	{
		if ((((arr[j])>>i)&1) == 1)
		{
			a = a^arr[j];
		}
		else if ((((arr[j]) >> i) & 1) == 0)
		{
			b = b^arr[j];
		}
	}
	printf("%d,%d", a, b);
	system("pause");
	return 0;
}