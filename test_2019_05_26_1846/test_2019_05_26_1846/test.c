#include <stdio.h>
#include <stdlib.h>
unsigned int reverse_bit(unsigned int value)
{
	int t = 0;
	int tmp = 0;
	int i = 0;
	for (i = 0; i < 7; i++)
	{
		t = value & 1;
		tmp = tmp + t;
		tmp *= 10;
		value = value >> 1;
	}
	return tmp;
}
int main()
{
	int n = 7;
	printf("%d \n", reverse_bit(n));
	system("pause");
	return 0;
}