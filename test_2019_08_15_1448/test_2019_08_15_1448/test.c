#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//int Power(int x, int y)
//{
//	int num = 1;
//	while (y--)
//	{
//		num *= x;
//	}
//	return num;
//}
//


//void Add_k(int arr[], int k,int len, int* x,int* y)
//{
//	int p = 0;
//	int q = p+1;
//	while (p<len-1)
//	{
//		if (arr[p] + arr[q] == k)
//		{
//			*x = p;
//			*y = q;
//			return ;
//		}
//		else if (q == len-1)
//		{
//			p++;
//			q = p + 1;
//		}
//		else
//		{
//			q++;
//		}
//	}
//}


//void Gudge(int n)
//{
//	int i = 0;
//	for (i = 0; pow(2, i) < 2147483647; i++)
//	{
//		if (pow(2,i) == n)
//		{
//			printf("ÊÇ");
//			return 0;
//		}
//	}
//	printf("²»ÊÇ");
//}


//void Zip(char arr[])
//{
//	int i = 1;
//	int j = 0;
//	int count = 1;
//	while (arr[i])
//	{
//		if (arr[i] == arr[i - 1])
//		{                                  //xxxyyyyzk
//			count++;
//		}
//		else if (count>1)
//		{
//			arr[j] = count+48;
//			j++;
//			arr[j] = arr[i-1];
//			j++;
//			count = 1;
//		}
//		else if (count == 1)
//		{
//			arr[j] = arr[i - 1];
//			j++;
//		}
//		i++;
//	}
//	arr[j] = arr[i];
//	j++;
//	while (arr[j])
//	{
//		arr[j] = '\0';
//		j++;
//	}
//}

void Zip_blank(char arr[],int len)
{
	int i = 1;
	int q = 0;
	for (i = 1; i < len;i++)
	{
		if ((arr[i] != ' ') && (arr[i - 1] == ' '))
		{
			arr[q] = ' ';
			q++;
			while ((arr[i] != ' ') && (arr[i] != '\0'))
			{
				arr[q] = arr[i];
				q++;
				i++;
			}
		}
	}
	arr[q] = '\0';
	q++;
	while (arr[q])
	{
		arr[q] = 0;
		q++;
	}
	if (arr[0] == ' ')
	{
		i = 0;
		while (arr[i])
		{
			arr[i] = arr[i + 1];
			i++;
		}
	}

}
int main()
{
	/*int x = 3;
	int y = 4;
	int ret = Power(x, y);
	printf("%d", ret);*/

	/*int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int k = 10;
	int x = -1;
	int y = -1;
	Add_k(arr, k, len, &x, &y);
	printf("%d,%d\n", x, y);*/

	/*int n = 128;
	Gudge(n);*/

	/*char arr[] = "xxxyyyyzk";
	Zip(arr);
	printf("%s", arr);*/

	char arr[] = "     as    adadq     ";
	int len = strlen(arr);
	Zip_blank(arr, len);
	printf("%s", arr);
	system("pause");
	return 0;
}