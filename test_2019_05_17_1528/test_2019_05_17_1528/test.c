#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char arr1[20] = "i am ";
	char arr2[] = "peter";
	int x = strlen(arr1);
	int i = 0;
	int j = 0;
	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
	
		arr1[i+x] = arr2[i];
	}
	printf("%s", arr1);
	system("pause");
	return 0;

}