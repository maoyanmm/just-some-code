//���ֹ鲢����
void _MergeSort(int* a, int left, int right, int* tmp){
	//����
	if (left >= right)
	{
		return;
	}
	int mid = left + (right - left) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	//�鲢
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int flag = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[flag++] = a[begin1++];
		}
		else
		{
			tmp[flag++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[flag++] = a[begin1++];
	}
	while (begin2 < end2)
	{
		tmp[flag++] = a[begin2++];
	}
	memcpy(a + left, tmp + left, sizeof(int)*(right - left + 1));
}
//�鲢����
void MergeSort(int* a, int n){
	int* tmp = (int*)malloc(sizeof(int)* n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
//��������
void CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range = max - min + 1;
	int* countArr = (int*)malloc(sizeof(int)*range);
	memset(countArr, 0, range * sizeof(int)); //20, 17, 4, 16, 5, 3
	//����
	for (int i = 0; i < n; ++i)
	{
		countArr[a[i] - min]++;
	}
	//���θ�ֵ
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArr[i]--)
		{
			a[j++] = i + min;
		}
	}
}
