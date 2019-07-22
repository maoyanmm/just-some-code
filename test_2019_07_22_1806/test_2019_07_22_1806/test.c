#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void Switch(char* str,int k)
{
	assert(*str != '\0');
	char arr[50] = { 0 };
	int i = 0;
	while (*str != '\0')
	{
		if (*str != ' ')
		{
			arr[i] = *str;
		}
		else
		{
			arr[i] = '%';
			i++;
			arr[i] = '2';
			i++;
			arr[i] = '0';
		}
		str++;
		i++;
	}
	while (k--)
	{
		str--;
	}
	int j = 0;
	for (j = 0; j < i; j++)
	{
		*str = arr[j];
		str++;
	}
}
int main()
{
	char str[50] = "abc defgx yz";
	int ret = strlen(str);
	Switch(str, ret);
	printf("%s", str);
	system("pause");
	return 0;
}