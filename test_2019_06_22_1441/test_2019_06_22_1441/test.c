#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
/*
1. 添加联系人信息
2. 删除指定联系人信息
3. 查找指定联系人信息
5. 显示所有联系人信息
6. 清空所有联系人
7. 以名字排序所有联系人
8. 保存联系人到文件
9. 加载联系人
*/
void menu()
{
	printf("*********1.add************2.search***********\n");
	printf("*********3.del*************4.show************\n");
	printf("*********5.clear***********6.sort**************\n");
	printf("*********0.exit********************************\n");
}

void start()
{
	int input = 0;
	//初始化通讯录   数组   usedSize
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("请输入你的操作>>");
		scanf("%d", &input);
		switch (input)
		{
		case  ADD:
			AddContact(&con);
			break;
		case SEAR:
			SearchContact(&con);
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
		}
	} while (input);
}

int main()
{
	start();
	return 0;
	system("pause");
}
