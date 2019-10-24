#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>

void Swap(int* a, int* b){
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertSort(int* a, int n){
	assert(a);
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0 && a[end] > tmp)
		{
			a[end + 1] = a[end];
			end--;
		}
		a[end + 1] = tmp;
	}
}

void BubbleSort(int* a, int n){
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 1;
			}
		}
		if (0 == flag)
		{
			break;
		}
	}
}

void ShiftDown(int* a, int n, int root){
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if ((child + 1 < n) && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	int root = (n - 2) / 2;
	for (; root >= 0; root--)
	{
		ShiftDown(a, n, root);
	}
	while (n>0)
	{
		n--;
		Swap(&a[0], &a[n]);
		ShiftDown(a, n, 0);
	}
}

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void test()
{
	int arr[] = { 6, 5, 7, 4, 8, 3, 9, 2, 0, 1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	PrintArray(arr, len);
	HeapSort(arr, len);
	PrintArray(arr, len);
}

int main()
{
	test();
	system("pause");
	return 0;
}