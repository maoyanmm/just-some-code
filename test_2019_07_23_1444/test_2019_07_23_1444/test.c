#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int Fibonacci(int n)
{
	int a = 1;
	int b = 1;
	int x = 0;   // 1 1 2 3 5 8 13
	if (n <=  0)
	{
		printf("��������");
	}
	else if (n <= 2 && n >= 1)
	{
		return 1;
	}
	else if ( n > 2 )
	{
		while (n != 2)
		{
			x = a + b;
			a = b;
			b = x;
			n--;
		}
		return x;
	}
}
int main()
{
	int n = 0;
	printf("������:\n");
	scanf("%d", &n);
	int ret = Fibonacci(n);
	printf("��%d��쳲��������ǣ�%d\n", n, ret);
	system("pause");
	return 0;
}