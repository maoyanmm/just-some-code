#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int Search(int arr[][4], int x)
{
	int i = 0;
	int j = 3;
	while (i != 4 && j != -1 )
	{
		if (x == arr[i][j])
		{
			return 1;
		}
		else if (x < arr[i][j])
		{
			j--;
		}
		else if (x > arr[i][j])
		{
			i++;
		}
	}
	return 0;
}
int main()
{
	int arr[4][4] = { 1, 2, 8, 9,
		             2, 4, 9, 12,
		             4, 7, 10, 13,
		             6, 8, 11, 15 };
	int a = 6;
	int ret = Search(arr, a);
	if (ret == 1)
	{
		printf("有该整数\n");
	}
	else if (ret == 0)
	{
		printf("无该整数\n");
	}
	system("pause");
	return 0;
}