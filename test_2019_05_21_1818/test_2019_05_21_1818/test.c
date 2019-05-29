#include<stdio.h>
#include<stdlib.h>
#define N 8
void killer()
{
	int a, b, c, d;
	for (a = 0; a <= 1; a++)
	{
		for (b = 0; b <= 1; b++)
		{
			for (c = 0; c <= 1; c++)
			{
				for (d = 0; d <= 1; d++)
				{
					if (((a != 1) + (c == 1) + (d == 1) + (d != 1)) == 3)
					{
						if (a+b+c+d==1)
						{
							printf("a=%d,b=%d,c=%d,d=%d\n", a, b, c, d);
						}
					}
				}
			}
		}
	}
}
int main()
{
	killer();
	system("pause");
	return 0;
}