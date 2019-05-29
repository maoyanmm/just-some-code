#include<stdio.h>
#include<stdlib.h>
#define N 8
void rank()
{
	int a, b, c, d, e;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if ((((a == 3) && (b == 2) == 0) && ((a == 3) || (b == 2) == 1)) == 1)
						{
							if ((((e == 4) && (b == 2) == 0) && ((e == 4) || (b == 2) == 1))==1)
							{
								if ((((c == 1) && (d == 2) == 0) && ((c == 1) || (d == 2) == 1))==1)
								{
									if ((((c == 5) && (d == 3) == 0) && ((c == 5) || (d == 3) == 1))==1)
									{
										if ((((e == 4) && (a == 1) == 0) && ((e == 4) || (a == 1) == 1))==1)
										{
											printf("a=%d,b=%d,c=%d,e=%d", a, b, c, d, e);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
int main()
{
	rank();
	system("pause");
	return 0;
}