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
		printf("ͨѶ¼���ˣ��Ӳ��˹p\n");
		return;
	}
	printf("��������:");
	scanf("%s", pCon->per[pCon->usedSize].name);

	printf("��������:");
	scanf("%d", &(pCon->per[pCon->usedSize].age));

	printf("����绰:");
	scanf("%s", pCon->per[pCon->usedSize].tele);

	printf("�����ַ:");
	scanf("%s", &pCon->per[pCon->usedSize].addr);

	printf("�����Ա�:");
	scanf("%s", &pCon->per[pCon->usedSize].sex);
	printf("��ӳɹ���\n");
	(pCon->usedSize)++;
}
int SearchContact(Contact* pCon)
{
	char name[MAX_NAME] = { 0 };
	printf("����������:");
	scanf("%s", name);
	int i = 0;
	if (pCon->usedSize == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	else
	{
		for (i = 0; i < pCon->usedSize; i++)
		{
			if (strcmp(name, pCon->per[i].name)== 0)
			{
				printf("%-20s%-10s%-10s%-11s%-15s\n", "����", "�Ա�", "����", "�绰", "��ַ");
				printf("%-20s%-10s%-10d%-11s%-15s\n", pCon->per[i].name, pCon->per[i].sex, pCon->per[i].age, pCon->per[i].tele, pCon->per[i].addr);
				return;
			}
		}
		printf("û�����\n");
		return;
	}
}

void DelContact(Contact* pCon) 
{
	char name[MAX_NAME];
	printf("����������:");
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
				printf("ɾ���ɹ�\n");
				return;
			}
		}
		printf("���޴���\n");
}

void ShowContact(Contact* pCon)
{
	printf("%-20s%-10s%-10s%-11s%-15s\n", "����","�Ա�","����","�绰","��ַ");
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
	printf("����ɹ�\n");
}