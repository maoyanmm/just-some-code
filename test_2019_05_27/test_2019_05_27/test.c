#include <stdio.h>
#include <stdlib.h>
#include<math.h>
unsigned int reverse_bit(unsigned int value)
{
	int i = 31;
	int tmp = 0;
	unsigned int count = 0;
	while (value)
	{
		tmp = value & 1;
		count = count + tmp*pow(2, i);
		value = value >> 1;
		i--;
	}
	return count;
}
int main()
{
	unsigned int n = 25;
	printf("%d \n", reverse_bit(n));
	system("pause");
	return 0;
}