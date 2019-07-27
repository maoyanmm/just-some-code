#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
int Min_num(int arr[],int k)
{
	int i = 0;
	int tmp = 0;
	for (i = 0; i < k-1; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
		}
	}
	return arr[k-1];
}
int main()
{
	int k = 0;
	int a[100] = { 7, 8, 6, 3, 4, 5, 1, 8, 92, 8, 8, 7, 1, 4, 2, 1, 8, 8, 2, 1, 89, 78, 2, 6, 7, 5, 8, 9, 2, -10, 85, 87, 11, 41, 3, 8 };
	printf("输入K的大小：\n");
	scanf("%d", &k);
	int ret = Min_num(a, k);
	printf("最小是：%d", ret);
	system("pause");
	return 0;
}