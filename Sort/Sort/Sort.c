#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

void Swap(int* a, int* b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertSort(int* a, int n)
{
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
	printf("\n");
}

void BubbleSort(int* a, int n)
{
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
		if ((child+1 < n) && a[child + 1] > a[child])
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

void HeapSort(int* a,int n){
	while (n > 1)
	{
		int root = (n - 2) / 2;
		for (; root >= 0; root--)
		{
			ShiftDown(a, n, root);
		}
		Swap(&a[0], &a[n - 1]);
		n--;
	}
}

void PrintArray(int* a,int n){
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}
	printf("\n");
}

void SelectSort(int* a, int n)
{
	int i = 0;
	int flag = i;
	for (i = 0; i < n - 1; i++)
	{
		flag = i;
		for (int j = i; j < n - 1; j++)
		{
			if (a[flag] > a[j + 1])
			{
				flag = j+1;
			}
		}
		Swap(&a[flag], &a[i]);
	}
}

void test()
{
	int a[] = { 20, 17, 4, 16, 5, 3 };
	int len = sizeof(a) / sizeof(a[0]);
	PrintArray(a, len);
	SelectSort(a, len);
	PrintArray(a, len);
}

int main()
{
	test();
	system("pause");
	return 0;
}