#define _CRT_SECURE_NO_WARNINGS 1
#include"constact.h"
void menu()
{
	printf("**********1、添加联系人************************\n");
	printf("**********2、查找联系人************************\n");
	printf("**********3、删除联系人************************\n");
	printf("**********4、展示联系人************************\n");
	printf("**********5、清空联系人************************\n");
	printf("**********6、排序联系人************************\n");
}

void InitContact(Contact *p)
{
	assert(p != NULL);  //断言指针不为空
	memset(p, 0, sizeof(p));  //清零
	p->usedsize = 0;   //把联系人的统计数记为0
}

void AddContact(Contact *p)
{
	assert(p != NULL);
	printf("姓名：");
	scanf("%s", p->per[p->usedsize].name);
	printf("电话：");
	scanf("%s", p->per[p->usedsize].tele);
	printf("年龄：");
	scanf("%d", &(p->per[p->usedsize].age));
	printf("地址：");
	scanf("%s", p->per[p->usedsize].addr);
	printf("性别：");
	scanf("%s", p->per[p->usedsize].sex);
	printf("添加成功！\n\n");
	(p->usedsize)++;   //每添加一个联系人，数值就加1
}

int SearContact(Contact *p)
{
	assert(p != NULL);
	char name[MAX_NAME];
	printf("输入姓名：");
	scanf("%s", name);
	int i = 0;
	if (p->usedsize == 0)  //如果联系人的总数为0就不找了
	{
		printf("查无此人\n\n");
		return -1;                       //这个函数里的return 是为了下面的删除del函数的调用
	}
	for (i = 0; i < p->usedsize; i++)
	{
		if (strcmp(name, p->per[i].name) == 0)  //如果输入的姓名找到了就打印出来
		{
			printf("%-20s%-11s%-7s%-20s%-11s\n\n", "姓名", "电话", "年龄", "地址", "性别");
			printf("%-20s%-11s%-7d%-20s%-11s\n\n", p->per[i].name, p->per[i].tele, p->per[i].age, p->per[i].addr, p->per[i].sex);
			return i;
		}
	}
	printf("查无此人\n\n");
	return -1;
}

void DelContact(Contact *p)
{
	assert(p != NULL);
	int j = 0;
	int i = SearContact(p);   //把找到的i的返回值赋值给这里的i
	if (i != -1)
	{
		for (j = i; j < p->usedsize - 1; j++)
		{
			p->per[j] = p->per[j + 1];         //把后面的联系人赋给前面的联系人，最后的效果是把i之后的联系人向前移动一位
		}
		printf("删除成功！\n\n");
	}
	else
	{
		printf("查无此人\n\n");
	}
	p->usedsize--;           //删除了要把总数减1
}

void ShowContact(Contact *p)
{
	assert(p != NULL);
	int i = 0;
	printf("%-20s%-11s%-7s%-20s%-11s\n\n", "姓名", "电话", "年龄", "地址", "性别");//注意规格
	for (i = 0; i < p->usedsize; i++)
	{
		printf("%-20s%-11s%-7d%-20s%-11s\n\n", p->per[i].name, p->per[i].tele, p->per[i].age, p->per[i].addr, p->per[i].sex);
	}
}

void ClearContact(Contact *p)
{
	assert(p != NULL);
	InitContact(p);            //调用前面的重置函数来清空
	printf("清空成功!\n\n");
}

void SortContact(Contact *p)
{
	assert(p != NULL);
	int i = 0;
	int j = 0;
	int flag = 0;
	Personinfo tmp;   //创立一个结构体变量
	for (i = 0; i < p->usedsize - 1; i++)       //冒泡排序
	{
		for (j = 0; j < p->usedsize - 1 - i; j++)
		{
			if (strcmp(p->per[j].name, p->per[j + 1].name) == 1)
			{
				tmp = p->per[j];
				p->per[j] = p->per[j + 1];  
				p->per[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return;
		}
	}
	printf("按字母排序成功，按4看看吧！\n\n");
}