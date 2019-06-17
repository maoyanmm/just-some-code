#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//void Function(int* left, int* right)
//{
//	assert(left != NULL && right != NULL);
//	int tmp = 0;
//	while (left <= right)
//	{
//		if (*left % 2 == 0)
//		{
//			while (left <= right)
//			{
//				if (*right % 2 == 1)
//				{
//					tmp = *left;
//					*left = *right;
//					*right = tmp;
//					break;
//				}
//				right--;
//			}
//		}
//		left++;
//	}
//}
//void Show(int* arr,int len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[] = { 1, 2,3,4,5,6,7,8,9 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	Function(arr, arr + len - 1);
//	Show(arr, len);
//	system("pause");
//	return 0;
//}
//void find(int arr[3][3], int* px, int* py, int key)
//{
//	int x = 0;
//	int y = *py - 1;
//	while (x < *px && y >= 0)
//	{
//		if (arr[x][y] > key)
//		{
//			y--;
//		}
//		else if (arr[x][y] < key)
//		{
//			x++;
//		}
//		else if (arr[x][y] == key)
//		{
//			*px = x;
//			*py = y;
//			return;
//		}
//	}
//	*px = -1;
//	*py = -1;
//}
//int main()
//{
//	int arr[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
//	int px = 3;
//	int py = 3;
//	find(arr, &px, &py,7);
//	printf("%d,%d", px, py);
//	system("pause");
//	return 0;
//}
//void reverse(char* arr,int left,int right)
//{
//	char tmp = 0;
//	while (left<right)
//	{
//		tmp = *(arr + left);
//		*(arr + left) = *(arr + right);
//		*(arr + right) = tmp;
//		left++;
//		right--;
//	}
//}
//void left_move(char* str, int k)
//{
//	int left = 0;
//	int right = strlen(str);
//	reverse(str, left, k-1);
//	reverse(str, k, right - 1);
//	reverse(str, left, right - 1);
//}
//int is_left_move(char* arr, const char* p)
//{
//	assert(arr != NULL && p != NULL);
//	if (strlen(arr) != strlen(p))
//	{
//		return 0;
//	}
//	strncat(arr, arr, strlen(arr));
//	if (strstr(arr, p) == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char arr[20] = "abcdefg";
//	char p[] = "cdefgab";
//	left_move(arr, 2);
//	printf("%s", arr);
//	system("pause");
//	return 0;
//}
