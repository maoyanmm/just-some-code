#include<stdio.h>
#include<stdlib.h>
//
//void Fnid_val(int *arr, int row, int col, int key)
//{
//	int tmpRow = 0;
//	int tmpCol = col - 1;
//	while ((tmpRow<row) && (tmpCol >= 0))
//	{
//		if (*(arr + tmpRow*col + tmpCol) == key)
//		{
//			printf("сп\n");
//			return 0;
//		}
//		else if (*(arr + tmpRow*col + tmpCol) > key)
//		{
//			tmpCol--;
//		}
//		else if (*(arr + tmpRow*col + tmpCol) < key)
//		{
//			tmpRow++;
//		} // a[2][1]   ==  a[7]   2*3+1
//	}
//	printf("ц╩сп\n");
//}
//
//int main()
//{
//	//0,3
//	int arr[4][4] = { 1, 2, 8, 9,
//		             2, 4, 9, 12,
//		             4, 7, 10, 13,
//		             6, 8, 11, 15 };
//
//	Fnid_val((int*)arr, 4, 4, 15);
//	system("pause");
//	return 0;
//}


#define ROW 3
void Func2(int arr[][ROW])
{
	int tmpRow = 0;
	int tmpCol = ROW / 2;
	int i = 2;
	arr[tmpRow][tmpCol] = 1;
	//2-n^2
	for (i = 2; i <= ROW*ROW; i++)
	{
		if (arr[(tmpRow - 1 + ROW) % ROW][(tmpCol + 1) % ROW] == 0)
		{
			tmpRow = (tmpRow - 1 + ROW) % ROW;
			tmpCol = (tmpCol + 1) % ROW;
			arr[tmpRow][tmpCol] = i;
		}
		else
		{
			tmpRow = (tmpRow+1)%ROW;
			arr[tmpRow][tmpCol] = i;
		}
	}

}
//+		arr	0x0053f8b0 {0x0053f8b0 {4, 1, 7}, 0x0053f8bc {3, 9, 6}, 0x0053f8c8 {8, 5, 2}}	int[3][3]  

int main()
{
	int arr[3][3] = { 0 };
	Func2(arr);
	char a[6] = { '0' };
	system("pause");

	return 0;
}
