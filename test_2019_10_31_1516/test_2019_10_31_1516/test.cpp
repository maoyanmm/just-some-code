#include<stdio.h>

//移除某个数
int removeElement(int* nums, int numsSize, int val){

	int *fast = nums;
	int *slow = nums;
	int newsize = numsSize;
	while (numsSize)
	{
		if (*slow != val)
		{
			*fast = *slow;
			fast++;
			slow++;
		}
		else
		{
			slow++;
			newsize--;
		}
		numsSize--;
	}
	return newsize;
}

//整数翻转
int reverse(int x)
{
	int result = 0;
	int tmp = 0;
	while (x)
	{
		tmp = x % 10;
		if ((result == -pow(2, 31) && (tmp <-8)) || (result < -pow(2, 31) / 10))
		{
			return 0;
		}
		if ((result == (pow(2, 31) - 1) / 10 && tmp >7) || (result > pow(2, 31) / 10))
		{
			return 0;
		}

		result = result * 10 + tmp;
		x /= 10;
	}
	return result;
}