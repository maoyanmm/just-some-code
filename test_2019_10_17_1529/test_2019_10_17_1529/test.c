#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void Swap(int* a, int* b){
	*a = (*a) ^ (*b);
	*b = (*a) ^ (*b);
	*a = (*a) ^ (*b);
}

void ShiftDown(int* a, int root,int n){
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
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

void HeapSort(int* a, int n){
	assert(a);
	int root = (n - 2) / 2;
	for (; root >= 0; root--)
	{
		ShiftDown(a, root, n);
	}
	while (n > 0)
	{
		n--;
		Swap(&a[0], &a[n]);
		ShiftDown(a, 0, n);
	}
}

void PrintArray(int* a,int n){
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void test(){
	int a[] = { 5, 6, 4, 7, 3, 8, 2, 9, 1 };
	int len = sizeof(a) / sizeof(a[0]);
	PrintArray(a, len);
	HeapSort(a, len);
	PrintArray(a, len);
}

int main()
{
	test();
	system("pause");
	return 0;
}