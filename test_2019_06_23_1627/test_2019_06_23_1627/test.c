#define _CRT_SECURE_NO_WARNINGS 1
#include"constact.h"
int main()
{
	Contact con;   //�ȴ���һ���ṹ�����
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)   
		{
		case ADD:                 //��switchѡ���õ�ö��
			AddContact(&con);
			break;
		case SEAR:
			SearContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case CLEAR:
			ClearContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		default:
			printf("��������\n");
			break;
		}
	} while (input);
	return 0;
}