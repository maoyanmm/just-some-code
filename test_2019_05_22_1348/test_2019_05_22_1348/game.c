#include"game.h"
void menu()
{
	printf("---------------------\n");
	printf("-----1����ʼ��Ϸ-----\n");
	printf("-----0���˳���Ϸ-----\n");
	printf("--------��ѡ��-------\n");
	printf("---------------------\n");
}
void test1()
{
	int x = 0;
	do
	{
		menu();
		scanf("%d",&x);
		switch (x)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("�����������������");
			break;
		}
	} while (x);
}
void init_board(char arr[N][N])
{
	memset(arr, ' ', sizeof(arr)*N*N);
}
void board(char arr[N][N])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j < N - 1)
			{
				printf(" %c |", arr[i][j]);
			}
			else
			{
				printf(" %c ", arr[i][j]);
			}
		}
		printf("\n");
		for (j = 0; j < N; j++)
		{
			if (i < N - 1)
			{
				if (j < N - 1)
				{
					printf("---|");
				}
				else
				{
					printf("---");
				}
			}
		}
		printf("\n");
	}
}
void player_move(char arr[N][N])
{
	int a, b;
	while (1)
	{
		printf("���������̵�����");
		scanf("%d%d", &a, &b);
		if ((a <= N)&&(a>=1)&&(b <= N)&&(b>=1))
		{
			if (arr[a - 1][b - 1]==' ')
			{
				arr[a - 1][b - 1] = '*';
				break;
			}
			else
			{
				printf("�����Ѿ��¹������ˣ���������");
			}
		}
		else
		{
			printf("����������������������");
		}
    }
}
void computer_move(char arr[N][N])
{
	int a = 0;
	int b = 0;
	while (1)
	{
		a = rand() % N;
		b = rand() % N;
		if (arr[a][b] == ' ')
		{
			arr[a][b] = '#';
			break;
		}
	}
}
char win(char arr[N][N])
{
	int i = 0;
	int j = 0;
	int heng = 0;
	int shu = 0;
	int pie = 0;
	int na = 0;
	for (i = 0; i < N; i++)    //����Ӯ
	{
		heng = 0;
		for (j = 0; j < N - 1; j++)
		{
			if ((arr[i][j] == arr[i][j + 1]) && (arr[i][j] != ' '))
			{
				heng++;
			}
			else
			{
				break;
			}
		}
		if (N - 1 == heng)
		{
			return arr[i][j];
		}
	}
	for (j = 0; j < N; j++)          //����Ӯ
	{
		shu = 0;
		for (i = 0; i < N - 1; i++)
		{
			if ((arr[i][j] == arr[i + 1][j]) && (arr[i][j] != ' '))
			{
				shu++;
			}
			else 
			break;
		}
		if (N - 1 == shu)
		{
			return arr[i][j];
		}
	}
	for (i = 0; i < N-1; i++)     //����Ӯ
	{
		if ((arr[i][i] == arr[i + 1][i + 1]) && (arr[i][i] != ' '))
		{
			pie++;
		}
	}
	if (N - 1 == pie)
	{
		return arr[i][i];
	}
	for (i = 0; i < N-1; i++)       //Ʋ��Ӯ
	{
		if ((arr[i][N - i - 1] == arr[i + 1][N - i - 2]) && (arr[i][N - i - 1] != ' '))
		{
			na++;
		}
	}
	if (N - 1 == na)
	{
		return arr[i][N - i - 1];
	}
	return '0';
}
int full(char arr[N][N])                
{
	int i = 0;
	int j = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 1;
			}
		}
	}
	return 2;
}
void game()
{
	srand((unsigned int)time(NULL));
	char arr[N][N] = {0};
	init_board(arr);
	while (1)
	{
		board(arr);
		player_move(arr);
		board(arr);
		if (win(arr) == '0')
		{
			if (full(arr) == 2)
			{
				printf("ƽ��\n");
				break;
			}
		}
		else if (win(arr) == '*')
		{
			printf("��Ӯ��\n");
			break;
		}
		else if (win(arr) == '#')
		{
			printf("������\n");
			break;
		}
		computer_move(arr);
		if (win(arr) == '0')
		{
			if (full(arr) == 2)
			{
				printf("ƽ��\n");
				break;
			}
		}
		else if (win(arr) == '*')
		{
			printf("��Ӯ��\n");
			break;
		}
		else if (win(arr) == '#')
		{
			printf("������\n");
			break;
		}
	}
	board(arr);
}