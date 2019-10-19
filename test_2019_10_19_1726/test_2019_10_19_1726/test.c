#include<stdio.h>
#include<assert.h>
void Swap(int* a, int* b){
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void ShellSort(int* a, int n){
	assert(a);
	int gap = n;
	while (gap > 0)
	{
		gap /= 2;
		for (int i = 0; i < n - gap; i++)
		{
			int key = a[i+gap];
			int flag = i;
			while (a[flag] > key && flag >= 0)
			{
				a[flag + gap] = a[flag];
				flag -= gap;
			}
			a[flag + gap] = key;
		}
	}
}

int PartSort(int* a, int left, int right)
{
	assert(a);
	int key = a[left];
	int begin = left;
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
		Swap(&a[left], &a[right]);
	}
	Swap(&a[begin], &a[left]);
	return left;
}

void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
	{
		return;
	}
	else
	{
		int mid = PartSort(a, left, right);
		QuickSort(a, left, mid - 1);
		QuickSort(a, mid + 1, right);
	}
}

void PrintArray(int* a, int n){
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void test(){
	int a[] = { 20, 17, 4, 16, 5, 3 };
	int len = sizeof(a) / sizeof(a[0]);
	PrintArray(a, len);
	QuickSort(a, 0, len - 1);
	PrintArray(a, len);
}

int main(){
	test();
	system("pause");
	return 0;
}