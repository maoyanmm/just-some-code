#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int Over_half(int a[],int k)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < k/2; i++)
//	{
//		int count = 0;
//		for (j = 0; j < k; j++)
//		{
//			if (a[i] == a[j])
//			{
//				count++;
//			}
//		}
//		if (count > k / 2)
//		{
//			return a[i];
//		}
//	}
//	return NULL;
//}
int main()
{
	//int arr[] = { 1,2,3,2,2,2,5,4,2};
	//int len = sizeof(arr) / sizeof(arr[0]);
	///*printf("%d\n", 9/2);*/
	//printf("%d\n", Over_half(arr, len));

	unsigned long a = 0x11000000;
	printf("%x\n", *(unsigned char *)&a);
	system("pause");
	return 0;
}