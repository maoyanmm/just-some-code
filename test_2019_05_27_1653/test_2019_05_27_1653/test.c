#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int n = 3;
	int j = 0;
	int sum = 0;
	int ret = 1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		ret = ret*j;
		sum = sum + ret;
	}
	printf("%d\n", sum);
	return 0;
}
