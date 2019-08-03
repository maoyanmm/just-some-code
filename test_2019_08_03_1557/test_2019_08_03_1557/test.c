#include<stdio.h>
#include<stdlib.h>
int Huiwen_number(char a[],int left,int right)
{
	while (left<right)
	{
		if (a[left] != a[right])
		{
			return 0;
		}
		left++;
		right--;
	}
	return 1;
}
int main()
{
	char x[] = "121";
	int left = 0;
	int right = strlen(x)-1;
	int ret = Huiwen_number(x, left, right);
	printf("%d\n", ret);
	/*int a = 2, *p1, **p2;
	p2 = &p1;
	p1 = &a;
	a++;
	printf("%d,%d,%d\n", a, *p1, **p2);*/
	system("pause");
	return 0;
}