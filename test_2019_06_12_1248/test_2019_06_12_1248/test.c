#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void left_move(char *str, int k)
{
	int i = 0;
	char tmp = 0;
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	for (i = 0; i < count; i++)
	{
		str--;
	}
	for (i = 0; i < k; i++)
	{
		tmp = str[0];
		int j = 0;
		while (str[j+1])
		{
			str[j] = str[j + 1];
			j++;
		}
		str[count - 1] = tmp;
	}




	//char arr[5] = { 0 };
	//char* a1 = str;
	//char* a2 = str;
	//char* q = arr;
	//char*p = arr;    //abcde
	//while (k--)
	//{
	//	*q = *a2;
	//	q++;
	//	a2++;
	//}
	//while (*a2)
	//{
	//	*a1 = *a2;
	//	a1++;
	//	a2++;
	//}                 //decde
	//while (*p)
	//{
	//	*a1 = *p;
	//	a1++;
	//	p++;
	//}



	/*int i = 0;
	int count = 0;
	char tmp[10] = "0";
	while (*str != '\0')  
	{
		count++;
		str++;
	}
	for (i = 0; i < count; i++) 
	{
		str--;
	}
	for (i = 0; i < k; i++) 
	{
		tmp[i] = str[i];
	}
	for (i = 0; i < count - k ; i++) 
	{
		str[i] = str[i + k];
	}
	for (i = 0 ; i < k; i++)
	{
		str[i + count - k] = tmp[i];
	}*/
}
int is_left_move(char *arr, const char *p)
{
	int count = 0;
	while (*arr != '\0')
	{
		count++;
		arr++;
	}
	int i = 0;
	for (i = 0; i < count; i++)
	{
		arr--;
	}
	int k = count;   
	while (k)
	{
		left_move(arr, 1);
		k--;
		int j = 0;
		int count2 = 0;
		for (j = 0; j < count; j++)
		{
			if (arr[j] == p[j])
			{
				count2++;
			}
		}
		if (count2 == count)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	char arr1[] = "abcde";
	char arr2[] = "cdeaj";
	int ret = is_left_move(arr1, arr2);
	printf("%d", ret);
	system("pause");
	return 0;
}