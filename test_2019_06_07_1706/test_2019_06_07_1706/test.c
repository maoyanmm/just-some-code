#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void front_odd(int arr[],int sz)
{
	int count = 0;
	int i = 0;
	int arr1[] = { 0 };
	int arr2[] = { 0 };
	for (i = 0; i < sz; i++)
	{
		if (1 == arr[i] % 2)
		{
			arr1[i] = arr[i];
		}
		else if (0 == arr[i] % 2)
		{
			arr2[i] = arr[i];
		}
	}
	for (i = 0; i < sz; i++)
	{
		if ('\0' == arr1[i])
		{
			break;
		}
		arr[i] = arr1[i];
		count++;
	}
	for (i = count; i < sz; i++)
	{
		if ('\0' == arr2[i])
		{
			break;
		}
		arr[i] = arr2[i];
	}

}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	front_odd(arr, len);
	printf("%s", arr);
	system("pause");
	return 0;
}