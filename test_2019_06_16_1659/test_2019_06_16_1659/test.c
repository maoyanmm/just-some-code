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
	while (*str1)  // ������Ϊ��
	{
		p2 = str2;     //ÿ����������str2ʱ������p2ָ�� str2�ĵ�һ��Ԫ��
		p1 = st;           //ÿ��p2��ֻ��ǰ��һ����Ȼ������������Ѱ�ң������������st++�����忴Ҳ����ÿ��p1����stΪ��ʼ������
		while (*p1 == *p2 && *p2 != '\0' && *p1 != '\0')  //str2������ƥ����ͬʱ�Ž���
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')    //ѭ�������������������Ϊstr2�ߵ�ͷ�ˣ���˵���ҵ��ˣ��Ǿͷ���st��Ҳ�������ѭ����ʼ�ҵ�λ��
		{
			return st;
		}
		if (*p1 == '\0')   //ѭ�������������� �����ߵ�ͷ�ˣ���ô����û���ҵ����򷵻�p1������\0
		{
			return p1;
		}
		st++;           //ѭ������������ ���ѭ��û���ҵ������´�Ѱ��str2����ʼλ���ټ�һλ

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