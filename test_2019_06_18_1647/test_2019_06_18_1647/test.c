#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


void *Mymemcpy(void *dest, const void *src, int n)
{
	void* p = dest;
	while (n--)
	{
		*(char*)dest = *(char*)src;
		((char*)dest)++;
		((char*)src)--;
	}
	return p;
}

int main()
{
	int dest[20] = { 0 };
	int src[] = { 1, 2, 3, 4, 5, 6 };
	Mymemcpy(dest, src, 8);
	system("pause");
	return 0;
}