#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
int main()
{
	char arr[50];
	gets(arr);
	int i = 0;
	int count = 0;
	for (i = 0; i < 50-1; i++)
	{
		if ((arr[i] == ' ') && (arr[i + 1] != ' ') && (arr[i + 1] != '\0'))
		{
			count++;
		}
	}
	printf("%d", count);
	system("pause");
	return 0;

}