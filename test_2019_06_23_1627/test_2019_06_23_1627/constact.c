#define _CRT_SECURE_NO_WARNINGS 1
#include"constact.h"
void menu()
{
	printf("**********1�������ϵ��************************\n");
	printf("**********2��������ϵ��************************\n");
	printf("**********3��ɾ����ϵ��************************\n");
	printf("**********4��չʾ��ϵ��************************\n");
	printf("**********5�������ϵ��************************\n");
	printf("**********6��������ϵ��************************\n");
}

void InitContact(Contact *p)
{
	assert(p != NULL);  //����ָ�벻Ϊ��
	memset(p, 0, sizeof(p));  //����
	p->usedsize = 0;   //����ϵ�˵�ͳ������Ϊ0
}

void AddContact(Contact *p)
{
	assert(p != NULL);
	printf("������");
	scanf("%s", p->per[p->usedsize].name);
	printf("�绰��");
	scanf("%s", p->per[p->usedsize].tele);
	printf("���䣺");
	scanf("%d", &(p->per[p->usedsize].age));
	printf("��ַ��");
	scanf("%s", p->per[p->usedsize].addr);
	printf("�Ա�");
	scanf("%s", p->per[p->usedsize].sex);
	printf("��ӳɹ���\n\n");
	(p->usedsize)++;   //ÿ���һ����ϵ�ˣ���ֵ�ͼ�1
}

int SearContact(Contact *p)
{
	assert(p != NULL);
	char name[MAX_NAME];
	printf("����������");
	scanf("%s", name);
	int i = 0;
	if (p->usedsize == 0)  //�����ϵ�˵�����Ϊ0�Ͳ�����
	{
		printf("���޴���\n\n");
		return -1;                       //����������return ��Ϊ�������ɾ��del�����ĵ���
	}
	for (i = 0; i < p->usedsize; i++)
	{
		if (strcmp(name, p->per[i].name) == 0)  //�������������ҵ��˾ʹ�ӡ����
		{
			printf("%-20s%-11s%-7s%-20s%-11s\n\n", "����", "�绰", "����", "��ַ", "�Ա�");
			printf("%-20s%-11s%-7d%-20s%-11s\n\n", p->per[i].name, p->per[i].tele, p->per[i].age, p->per[i].addr, p->per[i].sex);
			return i;
		}
	}
	printf("���޴���\n\n");
	return -1;
}

void DelContact(Contact *p)
{
	assert(p != NULL);
	int j = 0;
	int i = SearContact(p);   //���ҵ���i�ķ���ֵ��ֵ�������i
	if (i != -1)
	{
		for (j = i; j < p->usedsize - 1; j++)
		{
			p->per[j] = p->per[j + 1];         //�Ѻ������ϵ�˸���ǰ�����ϵ�ˣ�����Ч���ǰ�i֮�����ϵ����ǰ�ƶ�һλ
		}
		printf("ɾ���ɹ���\n\n");
	}
	else
	{
		printf("���޴���\n\n");
	}
	p->usedsize--;           //ɾ����Ҫ��������1
}

void ShowContact(Contact *p)
{
	assert(p != NULL);
	int i = 0;
	printf("%-20s%-11s%-7s%-20s%-11s\n\n", "����", "�绰", "����", "��ַ", "�Ա�");//ע����
	for (i = 0; i < p->usedsize; i++)
	{
		printf("%-20s%-11s%-7d%-20s%-11s\n\n", p->per[i].name, p->per[i].tele, p->per[i].age, p->per[i].addr, p->per[i].sex);
	}
}

void ClearContact(Contact *p)
{
	assert(p != NULL);
	InitContact(p);            //����ǰ������ú��������
	printf("��ճɹ�!\n\n");
}

void SortContact(Contact *p)
{
	assert(p != NULL);
	int i = 0;
	int j = 0;
	int flag = 0;
	Personinfo tmp;   //����һ���ṹ�����
	for (i = 0; i < p->usedsize - 1; i++)       //ð������
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
	printf("����ĸ����ɹ�����4�����ɣ�\n\n");
}