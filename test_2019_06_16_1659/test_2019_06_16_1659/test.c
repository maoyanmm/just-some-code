#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
char* Mystrstr(const char* str1, const char* str2)
{
	assert(str1 != NULL && str2 != NULL);
	const char* p1 = str1;
	const char* p2 = str2;
	const char* st = str1;
	while (*str1)  // 主串不为空
	{
		p2 = str2;     //每次在主串找str2时，都将p2指向 str2的第一个元素
		p1 = st;           //每次p2都只向前走一步，然后再在主串中寻找，函数的最后有st++，整体看也就是每次p1都以st为起始点来找
		while (*p1 == *p2 && *p2 != '\0' && *p1 != '\0')  //str2与主串匹配相同时才进入
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')    //循环出来的条件如果是因为str2走到头了，就说明找到了，那就返回st，也就是这次循环开始找的位置
		{
			return st;
		}
		if (*p1 == '\0')   //循环出来的条件是 主串走到头了，那么就是没有找到，则返回p1，就是\0
		{
			return p1;
		}
		st++;           //循环出来条件是 这次循环没有找到，把下次寻找str2的起始位置再加一位

	}
}
int main()
{
	char str1[20] = "adefbbbc";
	char str2[] = "bbc";
	printf("%s", Mystrstr(str1,str2));
	system("pause");
	return 0;
}