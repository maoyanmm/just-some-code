#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char* Mystrncmp(const char *dest,const char *src,int n)
{
	assert(dest != NULL && src != NULL);
	char* p = dest;
	while ( (n) && (*dest) && (*src))
	{
		if (*dest == *src)
		{
			dest++;
			src++;
		}
		else if (*dest > *src)
		{
			return 1;
		}
		else
		{
			return -1;
		} 
		n--;
	}
	if (0 == n && *dest != '\0')
	{
		return 1;
	}
	if (0 == n && *dest == '\0')
	{
		return 0;
	}
	else if ((*dest == '\0') && (*src == '\0'))
	{
		return 0;
	}
	else if (*dest == '\0')
	{
		return -1;
	}
	else if (*src == '\0')
	{
		return 1;
	}
}

int main()
{
	char arr1[20] = "abcd";
	char arr2[] = "abce";
	printf("%d\n", Mystrncmp(arr1, arr2,3));
	system("pause");
	return 0;
}