#include "game.h"
void test()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新输入");
			break;
		}
	} while (input);
}
void menu()
{
	printf("-------- 扫雷 -------\n");
	printf("-------1、开始-------\n");
	printf("-------0、退出-------\n");
	printf("-------@#￥%~&*-------\n");
}
void init_board(char mine[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mine[i][j] = set;
		}
	}
}
void set_boom(char mine[ROWS][COLS], int rows, int cols)
{
	srand((unsigned int)time(NULL));
	int count = boom_count;
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
void display_board(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (j = 0; j <= col; j++)
	{
		printf("%-3d", j);
	}
	printf("\n\n");
	for (i = 1; i <= row; i++)
	{
		printf("%-3d", i );
		for (j = 1; j <= col; j++)
		{
			printf("%-3c", show[i][j]);
		}
		printf("\n\n");
	}
}
int countcount(char mine[ROWS][COLS], int x, int y)
{
	return
		(mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1]) - 8 * '0';
}
void spread(char mine[ROWS][COLS], char show[ROWS][COLS], int x,int y )
{
	int i = 0;
	int j = 0;
	if (countcount(mine, x, y) == 0)
	{
		show[x][y] = ' ';
		for (i = -1; i <= 1; i++)
		{
			for (j = -1; j <= 1; j++)
			{
				if (((x + i >= 1 && x + i <= ROW) && (y + j >= 1 && y + j <= COL)) && (show[x + i][y + j] == '*'))
					spread(mine, show, x + i, y + j);
			}
		}
	}
	else
	{
		show[x][y] = countcount(mine, x, y) + '0';
	}
}
int win(char show[ROWS][COLS], int row, int col)
{
	int count = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}
void one_more_life(char mine[ROWS][COLS], int row, int col,int a,int b)
{
	printf("\n你第一次就踩到雷了，不过我让你one more life，但还是十个雷\n");
	init_board(mine, ROWS, COLS, '0');
	srand((unsigned int)time(NULL));
	int count = boom_count;
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if ((mine[x][y] == '0') && (x != a) && (y != b))
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
void find_boom(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int ret = 0;
	int count = 0;
	int input = 0;
	while (1)
	{
		display_board(mine, ROW, COL);
		printf("\n\n");
		display_board(show, ROW, COL);
		printf("请输入坐标");
		scanf("%d%d", &x, &y);
		input++;
		if ((x >= 1 && x <= 9) || (y >= 1 && y <= 9))
		{
			if ((1 == input) && (mine[x][y] == '1'))
			{
				one_more_life(mine, show, ROW, COL,x,y);
			}
			else if (mine[x][y] == '1')
			{
				printf("你被炸死");
				display_board(mine, ROW, COL);
				break;
			}
			if (mine[x][y] == '0')
			{
					spread(mine, show,x,y);
					if (win(show, ROW, COL) == boom_count)
					{
						printf("\n hhhhhh你赢了hhhhhh \n");
						break;
					}
			}
		}
		else
		{
			printf("输入错误，请重新输入");
		}
	}
}
void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');
	set_boom(mine, ROWS, COLS);
	/*display_board(mine, ROW, COL);*/ //可以提前看雷
	find_boom(mine,show, ROW, COL);
}