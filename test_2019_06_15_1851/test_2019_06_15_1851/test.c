#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#if 0
char* MyStrcat(char* dest, const char* src)
{
	assert(dest != NULL && src != NULL);
	char* tmp = dest;
	while (*dest++)
	{
		;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;

	}

	return tmp;

}
int main()
{
	char dest[20] = "hello";
	char* src = "bit";
	MyStrcat(dest, src);
	printf("%s",dest);
	system("pause");
	return 0;
}
int Mystrcmp(const char* str1, const char* str2)
{
	assert(str1 != NULL && str2 != NULL);
	char* p1 = str1;
	char* q1 = str2;
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
			str1++;
			str2++;
	}
	if (*str1 > *str2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main()
{
	char* str1 = "abc";
	char* str2 = "abc";
	int ret = Mystrcmp(str1, str2);
	printf("%d", ret);
	system("pause");
	return 0;
}

char* MysStrncpy(char* dest, const char* src, int n)
{
	assert(dest != NULL && src != NULL);
	char* p = dest;
	while (n--)
	{
		*dest++= *src++;
	}
	return p;
}
int main()
{
	char dest[20] = "abcd";
	char* src = "hello";
	MysStrncpy(dest, src, 2);
	printf("%s", dest);
	system("pause");
	return 0;
}
char* MyStrncat(char* dest, const char* src, int n)
{
	assert(dest != NULL && src != NULL);
	char* p = dest;
	while (*dest)
	{
		dest++;
	}
	while (n--)
	{
		*dest++ = *src++;
	}
	return p;
}
int main()
{
	char str[10] = "abcd";
	char* src = "hello";
	MyStrncat(str, src, 2);
	printf("%s\n", str);
	system("pause");
	return 0;
}

int MyStrncmp(const char* str1, const char* str2, int n)
{
	assert(str1 != NULL && str2 != NULL);
	int count = 0;
	while (*str1 == *str2 && count < n)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
		count++;
	}
	if (count == n)
	{
		return 0;
	}
	if (*str1 > *str2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main()
{
	char str[10] = "abcd";
	char* src = "aacd";
	
	int ret = MyStrncmp(str, src, 2);
	printf("%d\n",ret);
	system("pause");
	return 0;
}
char* MyStrstr(const char* str1, const char* str2)
{
	assert(str1 != NULL && str2 != NULL);
	char* p1 = str1;
	char* p2 = str2;
	char* st = p1;
	while (*str1 != '\0')
	{

		while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
		{
			str1++;
			str2++;
		}
		if (*str1 == '\0')
		{
			return 
		}
	}

}

int main()
{
	char dest[20] = "hello";
	char* src = "bit";
	MyStrcat(dest, src);
	printf("%s", dest);
	system("pause");
	return 0;
}
#endif
char* MyStrcat(char* dest, const char* src)
{
	assert(dest != NULL && src != NULL);
	char* tmp = dest;
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;

	}

	return tmp;

}
int main()
{
	char dest[20] = "hello";
	char* src = "bit";
	MyStrcat(dest, src);
	printf("%s", dest);
	system("pause");
	return 0;
}

