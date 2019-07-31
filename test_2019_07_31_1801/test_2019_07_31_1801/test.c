#include<stdio.h>
#include<stdlib.h>
//int Biggest(int arr[], int k)
//{
//	int i = 0;
//	int max = 0;
//	for (i = 0; i < k-1; i++)
//	{
//		max = arr[i]>arr[i + 1] ? arr[i] : arr[i + 1];
//	}
//	int j = 0;
//	for (i = 0; i < k; i++)
//	{
//		int count = 0;
//		for (j = i; j < k; j++)
//		{
//			count += arr[j];
//			if (count > max)
//			{
//				max = count;
//			}
//		}
//		
//	}
//	return max;
//}
//char Only_once(char* a)
//{
//	char* b = a;
//	int count = 0;
//	while (1)
//	{
//		if (count > 1)
//		{
//			a++;
//			b = a;
//			count = 0;
//		}
//		if (*b == '\0')
//		{
//			return *a;
//		}
//		if (*a == '\0')
//		{
//			return NULL;
//		}
//		if (*a == *b)
//		{
//			count++;
//		}
//		b++;
//	}
//}

char More_times(char* a)
{
	char* b = a;
	int count = 0;
	while (1)
	{
		if (count > 1)
		{
			return *a;
		}
		if (*b == '\0')
		{
			a++;
			b = a;
			count = 0;
		}
		if (*a == '\0')
		{
			return NULL;
		}
		if (*a == *b)
		{
			count++;
		}
		b++;
	}
}
int main()
{
	/*int a[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int len = sizeof(a) / sizeof(a[0]);
	printf("%d", Biggest(a, len));*/
	/*char a[] = "abaccdeff";
	printf("%c", Only_once(a));*/
	char a[] = "qywyer23tdd";
	printf("%c", More_times(a));
	system("pause");
	return 0;
}