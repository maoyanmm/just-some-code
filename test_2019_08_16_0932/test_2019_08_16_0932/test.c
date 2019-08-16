#include<stdio.h>
#include<stdlib.h>
//int Frog_jump(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else if (n <= 2)
//	{
//		return 2;
//	}
//	return Frog_jump(n - 1) + Frog_jump(n - 2);
//}
//int main() 
//{
//
//	int n = 6;
//	int ret = Frog_jump(n);
//	printf("%d", ret);
//	system("pause");
//	return 0;
//}

void Move(char pos1, char pos2)
{
	printf("%c->%c ", pos1, pos2);
}
/*
n:代表盘子个数
pos1：
pos2:
pos3:
*/
void Hanota(int n, char pos1, char pos2, char pos3)
{
	if (n == 1)
	{
		Move(pos1, pos3);
	}
	else
	{
		Hanota(n - 1, pos1, pos3, pos2);
		Move(pos1, pos3);
		Hanota(n - 1, pos2, pos1, pos3);
	}
}
int main()
{
	/*Hanota(1, 'A', 'B', 'C');
	Hanota(2, 'A', 'B', 'C');*/
	Hanota(3, 'A', 'B', 'C');

	system("pause");
	return 0;
}
