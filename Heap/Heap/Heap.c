#include"Heap.h"

void Swap(HPDataType* a, HPDataType* b)
{
	assert(a && b);
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}


void ShiftDown(HPDataType* a, int n, int root)
{
	assert(a);
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
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

void HeapInit(Heap* hp,HPDataType* a,int n)
{
	assert(hp);
	hp->_capicity = hp->_size = n;
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)* hp->_capicity);
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		hp->_a[i] = a[i];
	}
	for (i = (n - 2) / 2; i >= 0; --i)
	{
		ShiftDown(hp->_a, n, i);
	}
}

void HeapPrint(Heap* a)
{
	assert(a);
	int i = 0;
	for (i = 0; i < a->_size; ++i)
	{
		printf("%d,", a->_a[i]);
	}
	printf("\n");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_a = NULL;
	hp = NULL;
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	hp->_capicity++;
	hp->_size++;
	hp->_a = (HPDataType*)realloc(hp->_a,sizeof(HPDataType)*hp->_capicity);
	hp->_a[hp->_capicity - 1] = x;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void test()
{
	int arr[5] = { 1, 5, 3, 8, 7 };
	Heap h;
	HeapInit(&h, arr, sizeof(arr) / sizeof(arr[0]));
	HeapPrint(&h);
	HeapPush(&h, 6);
	HeapPrint(&h);

}