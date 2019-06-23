#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void InitContact(Contact* pCon)
{
	assert(pCon != NULL);
	memset(pCon->per, 0, sizeof(pCon->per));
	pCon->usedSize = 0;
}

void AddContact(Contact* pCon)
{
	if (pCon->usedSize == MAX_NUMPERSON)
	{
		printf("通讯录满了，加不了筽\n");
		return;
	}
	printf("输入姓名:");
	scanf("%s", pCon->per[pCon->usedSize].name);

	printf("输入年龄:");
	scanf("%d", &(pCon->per[pCon->usedSize].age));

	printf("输入电话:");
	scanf("%s", pCon->per[pCon->usedSize].tele);

	printf("输入地址:");
	scanf("%s", &pCon->per[pCon->usedSize].addr);

	printf("输入性别:");
	scanf("%s", &pCon->per[pCon->usedSize].sex);
	printf("添加成功！\n");
	(pCon->usedSize)++;
}
int SearchContact(Contact* pCon)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入姓名:");
	scanf("%s", name);
	int i = 0;
	if (pCon->usedSize == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	else
	{
		for (i = 0; i < pCon->usedSize; i++)
		{
			if (strcmp(name, pCon->per[i].name)== 0)
			{
				printf("%-20s%-10s%-10s%-11s%-15s\n", "姓名", "性别", "年龄", "电话", "地址");
				printf("%-20s%-10s%-10d%-11s%-15s\n", pCon->per[i].name, pCon->per[i].sex, pCon->per[i].age, pCon->per[i].tele, pCon->per[i].addr);
				return;
			}
		}
		printf("没这个人\n");
		return;
	}
}

void DelContact(Contact* pCon) 
{
	char name[MAX_NAME];
	printf("请输入姓名:");
	scanf("%s", name);
	int j = 0;
	int i = 0;
		for (i = 0; i < pCon->usedSize; i++)
		{
			if(strcmp(name, pCon->per[i].name) == 0)
			{
				for (j = i; j < pCon->usedSize - 1; j++)
				{
					pCon->per[j] = pCon->per[j + 1];
				}
				(pCon->usedSize)--;
				printf("删除成功\n");
				return;
			}
		}
		printf("查无此人\n");
}

void ShowContact(Contact* pCon)
{
	printf("%-20s%-10s%-10s%-11s%-15s\n", "姓名","性别","年龄","电话","地址");
	int i = 0;
	for (i = 0; i < pCon->usedSize; i++)
	{
		printf("%-20s%-10s%-10d%-11s%-15s\n", pCon->per[i].name, pCon->per[i].sex, pCon->per[i].age, pCon->per[i].tele, pCon->per[i].addr);
	}
}

void ClearContact(Contact* pCon)
{
	/*assert(pCon != NULL);
	memset(pCon->per, 0, sizeof(pCon->per));
	pCon->usedSize = 0;*/
	InitContact(pCon);
	printf("清除成功\n");
}