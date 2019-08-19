#include<stdio.h>
#include<stdlib.h>
int MaxArray(int *arr, int len)
{
	if (arr == NULL || len < 0)
	{
		return -1;

	}
	int j = 0;
	int sum = 0;
	int i = 0;
	int max = 0x80000000;
	for (i = 0; i < len; i++)
	{
		sum = 0;
		for (j = i; j < len; j++)
		{
			sum += arr[j];
			if (sum > max)
			{
				max = sum;

			}
		}
	}
	return max;
}
//int MaxArray2(int *arr, int len)
//{
//	int max = arr[0];
//	int sum = arr[0];
//	int i = 1;
//	for (i = 1; i < len; i++)
//	{
//		sum = max + arr[i];
//		if (sum < arr[i])
//		{
//			max = arr[i];
//		}      
//
//	}
//
//}
char FindOnceChar(char *str)
{
	int arr[256] = { 0 };
	char *p = str;
	while (*p!='\0')
	{
		arr[*p]++;
		p++;
	}
	while (*str!='\0')
	{
		if (arr[*str] == 1)
		{
			return *str;
		}
		str++;
	}
	return NULL;
}
void func(char arr[])
{
	int ret = sizeof(arr);
	printf("%d", ret);
}

int Max_array(int arr[],int len)
{
	int sum = arr[0];
	int max = arr[0];
	int i = 0;
	for (i = 1; i < len; i++)
	{
		if (sum < 0 )
		{
			sum = arr[i];
		}
		else
		{
			sum += arr[i];
		}
		if (sum > max)
		{
			max = sum;
		}
	}

	return max;
}

char Only_once(char arr[])
{
	int tmp[256] = { 0 };
	char *p = arr;
	while (*p != '\0')
	{
		tmp[*p]++;
		p++;
	}
	while (*arr != '\0')
	{
		if (tmp[*arr] == 1)
		{
			return *arr;
		}
		arr++;
	}
	return NULL;
}

int Patition(int arr[], int left, int right)
{
	int tmp = arr[left];
	while (left < right)
	{
		while (arr[right] >= tmp && left < right)
		{
			right--;
		}
		if (left >= right)
		{
			break;
			arr[left] = tmp;
		}
		else
		{
			arr[left] = arr[right];
		}

		while (arr[left] <= tmp && left < right)
		{
			left++;
		}
		if (left >= right)
		{
			break;
			arr[left] = tmp;
		}
		else
		{
			arr[right] = arr[left];
		}
	}
	return left;
}

int BeyondArrayLengthHalf(int *arr, int len)
{
	int mid = len / 2;
	int left = 0;
	int right = len - 1;
	int par = Patition(arr, left, right);

	while ( par != mid)
	{
		if (par > mid)
		{
			right = mid -1;
			par = Patition(arr, left, right);
		}
		else
		{
			left = mid+1;
			par = Patition(arr, left, right);
		}
	}
	if (Check(arr, arr[par], len) == 1)
	{
		return arr[par];
	}
	else
	{
		return NULL;
	}
}

int Check(int *arr, int val, int len)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (arr[i] == val)
		{
			count++;
		}
	}
	if (count > len / 2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	/*int arr[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret = MaxArray(arr, len);
	printf("%d", ret);*/
	/*char arr[] = "abaccdeff";
	char a = FindOnceChar(arr);
	printf("%c", a);
	printf("%d", 'a');*/
	/*int s = 0;
	int n = 0;
	for (n = 0; n < 4; n++)
	{
		switch (n)
		{
		default:s += 4;
		case 1:s += 1;
		case 2:s += 2;
		case 3:s += 3;
		}
	}
	printf("%d\n", s);*/
	/*char arr[] = "hello";*/
	/*func(arr);*/
	/*int ret = sizeof(arr);
	printf("%d", ret);*/
	/*printf("%d", sizeof(&arr));*/

	/*int arr[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret = Max_array(arr, len);
	printf("%d\n", ret);*/
	char arr[] = "abaccdeff";
	char ret = Only_once(arr);
	printf("%c", ret);
	system("pause");
	return 0;
}