#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//int reverse(int x)
//{
//	int arr[10] = { 0 };
//	int i = 0;
//	int result = 0;
//	for (i = 0; x != 0;i++)
//	{
//		arr[i] = x % 10;
//		x /= 10;
//	}
//	int j = 0;
//	while (i)
//	{
//		result += arr[j] * pow(10, i-1);
//		i--;
//		j++;
//		if (result > (pow(2, 31) - 1) || result <-pow(2, 31))
//		{
//			return 0;
//		}
//	}
//	return result;
//}


int reverse(int x)
{
	int result = 0;
	int tmp = 0;
	while (x)
	{
		tmp = x % 10;
		result = result * 10 + tmp;
		x /= 10;
	}
	return result;
}




int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize <= 0)
	{
		return 0;
	}
	int i = 0;
	int j = 0;
	for (j = 1; j<numsSize; j++)
	{
		if (nums[j] != nums[i])
		{
			i++;
			nums[i] = nums[j];
		}
	}
	return i + 1;
}



//
//int removeDuplicates(int* nums, int numsSize)
//{
//	int *b = nums;
//	int *f = nums;
//	int count = 0;
//	while (numsSize--)
//	{
//		if (*b != *(b - 1))
//		{
//			*f = *b;
//			b++;
//			f++;
//			count++;
//		}
//		else
//		{
//			b++;
//		}
//	}
//	numsSize = count;
//	return numsSize;
//}
int main()
{
	/*int a = -123;
	printf("%d", reverse(a));*/
	int a[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int ret = removeDuplicates(a, 10);
	printf("ret = %d\n", ret);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d,", a[i]);
	}
	system("pause");
	return 0;
}