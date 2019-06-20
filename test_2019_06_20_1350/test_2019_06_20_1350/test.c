#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

void swap(char* a,char* b)
{
		*a = *a ^ *b;
		*b = *b ^ *a;
		*a = *b ^ *a;
}

int cmp(const void* str1,const void* str2)
{
	char* a = (char*)str1;
	char* b = (char*)str2;
	if (*a > *b)
	{
		return 1;
	}
	else if (*a < *b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void Myqsort(void* base, int num, int width,int cmp(void* ,void*))
{
	assert((char*)base);
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - 1 - i; j++)
		{
			if ((cmp((char*)base + j*width, (char*)base + (j + 1)*width)) == 1)
			{
				swap((char*)base+j*width, (char*)base + (j+1)*width);
				flag = 1;
			}
		}
		if (0 == flag)
		{
			break;
		}
	}
}

int main()
{
	/*int arr[] = {1,9,2,8,3,7,4,6,5};
	int num = sizeof(arr) / sizeof(arr[0]);
	int width = sizeof(int);
	for (i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}*/
	char arr[] = "gfedcba";
	int num = strlen(arr);
	int width = sizeof(char);
	Myqsort(arr, num, width, cmp);
	int i = 0;
	printf("%s\n", arr);
	system("pause");
	return 0;
}