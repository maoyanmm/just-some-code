#include<assert.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void Swap(int* a, int* b)
{
	/**a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;*/
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void _MergeSort(int* arr, int left,int right,int* tmp)
{
	assert(arr);
	//划分
	if (left >= right)
	{
		return;
	}
	int mid = left + (right - left) / 2;
	_MergeSort(arr, left, mid,tmp);
	_MergeSort(arr, mid + 1, right,tmp);
	//合并
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int start = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] <= arr[begin2])
		{
			tmp[start++] = arr[begin1++];
		}
		else
		{
			tmp[start++] = arr[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[start++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[start++] = arr[begin2++];
	}
	memcpy(arr + left, tmp + left, sizeof(int)*(right - left +1));
}

void MergeSort(int* arr, int n)
{
	assert(arr);
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
}

void PrintArray(int* a,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int PartSort(int* arr, int left, int right)
{
	assert(arr);
	int key = arr[left];
	int begin = left;
	while (left < right)
	{
		while (left < right && arr[right] >= key)//注意里面是两个while循环
		{
			right--;
		}
		while (left < right && arr[left] <= key)
		{
			left++;
		}
		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[begin], &arr[left]);//注意要用begin 而不是arr[0]
	return left;
}

void QuickSort(int* arr, int left, int right)
{
	assert(arr);
	if (left >= right)//注意有最后递归中止的条件
	{
		return;
	}
	int mid = PartSort(arr, left, right);
	QuickSort(arr, left, mid - 1);
	QuickSort(arr, mid + 1, right);
}

void test()
{
	int arr[] = { 6, 5, 7, 4, 8, 3, 9, 2, 0, 1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	PrintArray(arr, len);
	QuickSort(arr, 0,len-1);
	PrintArray(arr, len);
}

int main()
{
	test();
	system("pause");
	return 0;
}