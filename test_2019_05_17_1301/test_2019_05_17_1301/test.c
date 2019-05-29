#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[3][4] = { { 1, 2, 3, 4 },{ 5, 2, 9, 6 },{3, 6, 1, 6} };
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int max = arr[0][0];
	for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
	{
		for (j = 0; j < sizeof(arr[0])/sizeof(arr[0][0]); j++)
		{
			if (arr[i][j]>max)
			{
				max = arr[i][j];
				x = i;
				y = j;
			}
		}
	}
	printf("%d–– %d¡–", x+1, y+1);

	system("pause");
	return 0;

}