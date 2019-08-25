#include<stdio.h>
#include<stdlib.h>

int Kangaroo_CrossRiver(int * arr, int len)
{
	int ADD = 0;
	int count = 0;  // 2  0  1  1  1 
	for (int i = 0; i<len; i += arr[i])
	{
		if (arr[i] == 0)
		{
			return -1;
		}
		ADD += arr[i];
		count++;
	}
	return count;
}

void Add_k(int *a, int k, int len,int *num1, int *num2)
{
	int f = 0;
	int b = len - 1;
	while ( f < b )
	{
		if (a[f] + a[b] == k)
		{
			*num1 = f;
			*num2 = b;
			return ;
		}
		if (a[f] + a[b] > k)
		{
			b--;
		}
		if (a[f] + a[b] < k)
		{
			f++;
		}
	}
}

int Gudge(int n)
{
	if (n < 1)
	{
		return 0;
	}
	if ((n & (n - 1)) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Compress(char a[]) // xxxyyyyz
{
	int i = 0;
	int j = 0;
	int count = 1;
	while ( a[j] != '\0' ) 
	{
		if (a[j] == a[j + 1])
		{
			count++;
		}
		else if ( count != 1)
		{
			a[i++] = count + '0';
			a[i++] = a[j];
			count = 1;
		}
		else
		{
			a[i++] = a[j];
		}
		j++;
	}
	a[i] = '\0';
}

void Del_blank(char a[])
{
	char *left = a;
	char *right = a;
	int flag = 0;
	while (*right != '\0')    // ****as****adadq***
	{
		/*if ((*right == ' ') && (flag == 0))
		{
			right++;
		}
		else if ((*right == ' ') && (flag == 1))
		{
			*left = *right;
			left++;
			right++;
			flag = 0;
		}
		else if ((*right != ' ') && (flag == 0))
		{
			*left = *right;
			left++;
			right++;
			flag = 1;
		}
		else if ((*right != ' ') && (flag == 1))
		{
			*left = *right;
			left++;
			right++;
		}*/
		if ((*right == ' ') && (flag == 0))
		{
			right++;
		}
		else if ((*right == ' ') && (flag == 1))
		{
			*left = *right;
			left++;
			right++;
			flag = 0;
		}
		else if ((*right != ' ') && (flag == 0))
		{
			*left = *right;
			left++;
			right++;
			flag = 1;
		}
		else if ((*right != ' ') && (flag == 1))
		{
			*left = *right;
			left++;
			right++;
		}
	}
	if (*(left - 1) == ' ')
	{
        *(left-1) = '\0';
	}
	else
	{
		*left = '\0';
	}


}

void DelBlank(char *str)
{
	int flg = 0;//还没开始处理空格
	int i = 0;
	int j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && flg == 0)
		{
			i++;
		}
		else if (str[i] != ' ' && flg == 0)
		{
			str[j++] = str[i++];
			flg = 1;
		}
		else if (str[i] == ' ' && flg == 1)
		{
			str[j++] = str[i++];
			flg = 0;
		}
		else if (str[i] != ' ' && flg == 1)
		{
			str[j++] = str[i++];
		}
	}
	if (str[j - 1] == ' ')
	{
		str[j - 1] = '\0';
	}
	else
	{
		str[j] = '\0';
	}
}

int main()
{
	/*int a[] = { 1, 3, 5, 6, 7, 9, 10 };
	int x = -1;
	int y = -1;
	int len = sizeof(a) / sizeof(a[0]);
	int k = 15;
	Add_k(a, k, len, &x, &y);
	printf("%d,%d\n", x, y);*/
	/*char ch = -1;
	printf("%d\n", ch);*/
	/*char x = -65;
	printf("%c\n", x);*/
	/*char a[] = { 'h', 'l' };
	char *b = "hl";*/
	/*int n = 130;
	int ret = Gudge(n);
	printf("%d\n", ret);*/
	/*char a[] = "xxxyyyyz";
	Compress(a);
	printf("%s", a);*/
	/*int c = 1;
	int b = 5;
	int a = (c++, b++);
	printf("%d,%d,%d", a, b, c);*/
	char a[] = "    as    adadq   ";
	Del_blank(a);
	printf("%s", a);
	system("pause");
	return 0;
}