#include<stdio.h>
#include<stdlib.h>
#if 0
void Sumk(int *arr, int len, int num,int *num1, int *num2)
{
	int l = 0;
	int r = len - 1;
	while (l<r)
	{
		if (*(arr+l) + *(arr+r) == num)
		{
			*num1 = l;
			*num2 = r;
			return 0;
		}
		if (*(arr + l) + *(arr + r) > num)
		{
			r--;
		}
		if (*(arr + l) + *(arr + r) < num)
		{
			l++;
		}
	}
	*num1 = -1;
	*num2 = -1;
	return 0;
}
void Qsort(int a[],int left,int right)
{
	if (left >= right)
	{
		return 0;
	}
	int tmp = a[left];
	int l = left;
	int r = right;
	while (l < r)
	{

		while (l < r && a[r] >= tmp)
		{
			r--;
		}
		a[l] = a[r];
		while (l < r && a[l] <= tmp)
		{
			l++;
		}
		a[r] = a[l];
	}
	a[l] = tmp;
	Qsort(a, left, l - 1);
	Qsort(a, l + 1, right);
}
int My_pow(int x,int n)
{
	if (n == 0)
	{
		return 1;
	}

	int result = 0;
	int tmp = My_pow(x, n / 2);
	if ((n & 1) == 0)  //如果是偶数，则乘以自己的一半
	{
		result = tmp * tmp;
	}
	else        //如果是奇数，则乘以自己的一半，再乘以x
	{           //如7/2 = 3；x^3 * x^3 = x^6;x^6 * x = x^7
		result = tmp * tmp * x;
	}                        
	return result;
}



int main()
{

	int a[] = { 1, 3, 10, 10, 13, 8, 17, 9 };  5
		             l   r
	int len = sizeof(a) / sizeof(a[0]);
	int num = 15;
	int num1 = 0;
	int num2 = 0;
	Sumk(a, len, num, &num1, &num2);
	printf("%d,%d\n", num1, num2);

	int a[] = { 123,123,5,23,4,523,123,12,513, 346};
	int len = sizeof(a) / sizeof(a[0]);
	int l = 0;
	int r = len - 1;
	int i = 0;
	Qsort(a, l, r);
	for (i = 0; i < len; i++)
	{
		printf("%d,", a[i]);
	}

	int x = 2;
	int n = 5;
	printf("%d\n", My_pow(x, n));


	system("pause");
	return 0;
}
#endif


int romanToInt(char * s)
{
	char *p = s;
	int result = 0;
	while (*p)
	{
		switch (*p)
		{
		case 'I':
			if (*(p + 1) == 'V')
			{
				result += 4;
				p++;
				break;
			}
			if (*(p + 1) == 'X')
			{
				result += 9;
				p++;
				break;
			}
			result += 1;
			break;
		case 'V':
			result += 5;
			break;
		case'X':
			if (*(p + 1) == 'L')
			{
				result += 40;
				p++;
				break;
			}
			if (*(p + 1) == 'C')
			{
				result += 90;
				p++;
				break;
			}
			result += 10;
			break;
		case 'L':
			result += 50;
			break;
		case 'C':
			if (*(p + 1) == 'D')
			{
				result += 400;
				p++;
				break;
			}
			if (*(p + 1) == 'M')
			{
				result += 900;
				p++;
				break;
			}
			result += 100;
			break;
		case 'D':
			result += 500;
			break;
		case 'M':
			result += 1000;
			break;

		}
		p++;
	}
	return result;
}


int main()
{
	char a[] = "MCMXCIV";
	int ret = romanToInt(a);
	printf("%d\n", ret);
	system("pause");
	return 0;
}