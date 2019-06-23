#define _CRT_SECURE_NO_WARNINGS 1
#include"constact.h"
int main()
{
	Contact con;   //先创建一个结构体变量
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("请选择");
		scanf("%d", &input);
		switch (input)   
		{
		case ADD:                 //该switch选项用的枚举
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
			printf("输入有误\n");
			break;
		}
	} while (input);
	return 0;
}