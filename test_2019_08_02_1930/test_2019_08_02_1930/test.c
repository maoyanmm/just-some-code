#include<stdio.h>
#include<stdlib.h>
void Delete_word(char a[],char b[],int la,int lb)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < lb; i++)
	{
		for (j = 0; j < la; j++)
		{
			if (a[j] == b[i])
			{
				for (k = j; k < la; k++)
				{
					a[k] = a[k + 1];
				}
			}
		}
	}
}
int main()
{
	char a[] = "They are students.";
	char b[] = "aeiou";
	int len_a = strlen(a);
	int len_b = strlen(b);
	Delete_word(a, b, len_a, len_b);
	printf("%s", a);
	system("pause");
	return 0;
}