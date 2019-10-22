#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Stack.h"

void ShellSort(int* a, int n)
{
	assert(a);
	int gap = n;
	while (gap > 0)
	{
		gap /= 2;
		for (int i = 0; i < n - gap; i++)
		{
			int begin = i;
			int key = a[i + gap];
			while (begin >= 0 && key < a[begin])
			{
				a[begin + gap] = a[begin];
				begin -= gap;
			}
			a[begin + gap] = key;
		}
	}
}

void PrintArrary(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* a, int* b)
{
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void QuickSortNor(int* a, int n)
{
	assert(a);
	Stack st;
	StackInit(&st);
	int left = 0;
	int right = n - 1;
	StackPush(&st, right);
	StackPush(&st, left);
	while (StackEmpty(&st) == 1)
	{
		left = StackTop(&st);
		StackPop(&st);
		right = StackTop(&st);
		StackPop(&st);
		int key = a[left];
		int begin = left;
		int end = right;
		while (left < right)
		{
			while (left < right && a[right] >= key)
			{
				right--;
			}
			while (left < right && a[left] <= key)
			{
				left++;
			}
			Swap(&a[right], &a[left]);
		}
		Swap(&a[left], &a[begin]);
		if (left + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, left + 1);
		}
		if (begin < left - 1)
		{
			StackPush(&st, left - 1);
			StackPush(&st, begin);
		}
	}
}

void test()
{
	int a[] = { 6, 5, 7, 4, 8, 3, 9, 2, 0, 1 };
	int len = sizeof(a) / sizeof(a[0]);
	PrintArrary(a, len);
	QuickSortNor(a, len);
	PrintArrary(a, len);
}

int main()
{
	test();
	system("pause");
	return 0;
}