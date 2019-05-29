#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//if (*string != '\0')
//{
//	tmp = *string;
//	*string = *(string + 1);
//	*(string + 1) = tmp;
//}
void reverse_string(char * string)
{
	char tmp;
	if (*string != '\0')
	{
		reverse_string(string + 1);
	}
	tmp = *string;
	*string = *(string - 1);
	*(string - 1) = tmp;
}
int main()
{
	char a[] = "abcd";
	int i = 0;
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%c ", a[i]);
	}
	printf("反向排列后\n");
	reverse_string(a);
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%c ", a[i]);
	}
	system("pause");
	return 0;
}