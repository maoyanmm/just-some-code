#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define F(X,Y) ((X)+(Y))
int Num_one(unsigned int x)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		if (x & 1 == 1)
		{
			count++;
		}
		x = x >> 1;
	}
	return count;
}
int main()
{
	unsigned int x = 0;
	printf(" ‰»Î£∫\n");
	scanf("%d", &x);
	int ret = Num_one(x);
	printf("%d\n", ret);
	system("pause");
	return 0;
}