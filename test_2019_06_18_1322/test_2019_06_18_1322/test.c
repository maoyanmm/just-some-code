#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


void *Mymemcpy(void *dest, const void *src, int n)
{
	void* t = dest;
	char* p = (char*)dest;
	char* q = (char*)src;
	while (n--)
	{
		*(char*)dest = *(char*)src;
		p++;
		q++;
	}
	return t;

}

int main()
{
	int dest[20] = { 0 };
	int src[] = {1,2,3,4,5,6};
	Mymemcpy(dest, src,8);
	system("pause");
	return 0;
}