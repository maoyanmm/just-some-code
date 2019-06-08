#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int one_search(int arr[][3], int line, int row, int k)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < line; i++)
	{
		if (arr[i][row - 1] > k)
		{
			break;
		}
		else if (arr[i][row - 1] == k)
		{
			return 1;
		}
	}
	for (j = 0; j < row; j++)
	{
		if (arr[i][j] == k)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[3][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
	int line = sizeof(arr) / sizeof(arr[0]);
	int row = sizeof(arr[0]) / sizeof(arr[0][0]);
	int a = 2;
	int ret = one_search(arr, line, row, a);
	if (ret == 1)
	{
		printf("有这个数\n");
	}
	else if (ret == 0)
	{
		printf("没这个数\n");
	}
	system("pause");
	return 0;
}