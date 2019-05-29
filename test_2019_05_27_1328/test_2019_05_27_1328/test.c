#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void reverse_arr(char arr[],int sz)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char arr1[] = { 0 };
	char arr2[] = { 0 };
	int count = 0;
	int n = 0;
	for (i = sz-1,k = 0; i >= 0,k<sz ; i--,k++)
	{
		count = 0;
		if (arr[i] != ' ')
		{
			arr1[k] = arr[i];
			count++;
		}
		else
		{
			for (j = 0;j < count; j++)
			{
				arr2[sz - 1 - j - n] = arr1[count-j];
			}
			k = 0;
			n += count;
		}
	}
	for (i = 0; i < sz; i++)
	{
		arr[i] = arr2[i];
	}
}
int main()
{
	char arr[] = "student a am I";
	int sz = sizeof(arr) / sizeof(arr[0]);
	reverse_arr(arr, sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%c", arr[i]);
	}
	system("pause");
	return 0;
}