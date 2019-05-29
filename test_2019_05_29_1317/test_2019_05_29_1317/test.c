#include<stdio.h>
#include<stdlib.h>
void reverse(char arr[], int sz)
{
	int left = 0;
	int right = sz-1;
	char tmp = 0;
	while (left <= right)
	{
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < sz+1 ;i++)
	{
		if ((arr[i] != ' ') && (arr[i] != '\0'))
		{
			count++;
		}
		else
		{
			left = i - count;
			right = i - 1;
			while (left <= right)
			{
				tmp = arr[left];
				arr[left] = arr[right];
				arr[right] = tmp;
				left++;
				right--;
			}
			count = 0;
		}
	}
}
int main()
{                               
	char arr[] = "student a am i"; // retep ma a tneduts  
	int sz = sizeof(arr) / sizeof(arr[0])-1;
	reverse(arr, sz);
	printf("%s", arr);
	system("pause");
	return 0;
}