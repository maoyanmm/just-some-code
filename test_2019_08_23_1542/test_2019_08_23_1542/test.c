#include<stdio.h>
#include<stdlib.h>
#if 0
int isPalindrome(int x)
{
	if (x < 0)
	{
		return 0;
	}
	int y = x;
	int rev = 0;
	int result = 0;
	while (x)
	{
		rev = x % 10;
		result = result * 10 + rev;
		x /= 10;
	}
	if (result == y)
	{
		return 1;
	}
	else
		return 0;
}
#endif

int romanToInt(char * s)
{
	int *f = s;
	int *b = s;
	int result = 0;
	enum ENUM
	{
		I = 1,
		V = 5,
		X = 10,
		L = 50,
		C = 100,
		D = 500,
		M = 1000
	};
	int i = 0;
	int j = 0;
	while (s[i] != '\0')
	{
		result += (enum ENUM)s[i];
		i++;
	}
	return result;
}
int main()
{
	///*int a = -121;
	//int ret = isPalindrome(a);
	//printf("最后的结果是%d\n", ret);*/
	char a[] = "I";
	int ret = romanToInt(a);
	printf("%d\n", ret);
	system("pause");
	return 0;
}