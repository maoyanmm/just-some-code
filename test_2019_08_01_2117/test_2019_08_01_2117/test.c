#include<stdio.h>
#include<stdlib.h>
void Only_once_for_two(int arr[], int k, int *x, int *y)
{
	int q = 0;
	int i = 0;
	for (i = 0; i < k; i++)
	{
		q ^= arr[i];
	}
	int tmp = 31;
	int count = 0;
	while (tmp--)
	{
		if ((1 & q) == 1)
		{
			break;
		}
		q = q >> 1;
		count++;
	}
	int x1 = 0;
	int x2 = 0;
	for (i = 0; i < k; i++)
	{
		if (((arr[i] >> count) & 1) == 1)
		{
			x1 ^= arr[i];
		}
		else if (((arr[i] >> count) & 1) == 0)
		{
			x2 ^= arr[i];
		}
	}
	*x = x1;
	*y = x2;
}
int main()
{
	int a[] = { 1, 3, 5, 7, 1, 3, 5, 9 };
	int len = sizeof(a) / sizeof(a[0]);
	int x = 0;
	int y = 0;
	Only_once_for_two(a, len, &x, &y);
	printf("%d,%d", x,y);
	system("pause");
	return 0;
}