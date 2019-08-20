#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#if 0
char *Delete_RepeateChar(char *str1, char *str2)
{
	int STR2[256] = { 0 };
	while ( *str2 != '\0')
	{
		STR2[*str2] = 1;
		str2++;
	}
	char *p = str1;
	char *q = str1;
	while ( *p != '\0')
	{
		if (STR2[*p] != 1)
		{
			*q = *p;
			q++;
		}
		p++;
	}
	*q = '\0';
	return str1;
}



int Howmany_jump(int arr[],int n)
{
	/*int *front = arr;
	int *behind = arr;
	int count = 0;
	while (count <n && *behind--)
	{
		if (*behind == 0)
		{
			return -1;
		}
		count += *behind;
		behind = behind + *behind;
	}*/
	int count = 0;
	int count_jump = 0;
}

void ARR(int a[])
{
	int *b = (char*)a+1;
	printf("%d\n", *b);
}
#endif
void Switch(char *a,int len)
{
	char *p = a;
	int count = 0;
	while ( *p != '\0')
	{
		if (*p == ' ')
		{
			count++;
		}
		p++;
	}
	char *front = a + len - 1;
	char *behind = a + len -1 + count*2;
	while ( behind > front)
	{
		if (*front != ' ')
		{
			*behind = *front;
		}
		else
		{
			*behind = '0';
			behind--;
			*behind = '2';
			behind--;
			*behind = '%';
		}
		behind--;
		front--;
	}

}

int main()
{
#if 0
	char arr[] = "Welcome to cvte";
	char arr2[] = "come";
	printf("%s", Delete_RepeateChar(arr,arr2));
	int a[4] = { 1,2,3,4};
	ARR(a);
#endif

	char arr[30] = "abc defgx yz"; 
	Switch(arr, strlen(arr));
	printf("%s\n", arr);
	system("pause");
	return 0;
}