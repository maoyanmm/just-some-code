#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* _left;
	BTDataType _data;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode* BinaryTreeCreate(BTDataType* a, int* pi);//����������
void BinaryTreeDestory(BTNode** root);//�ݻٶ�����
int BinaryTreeSize(BTNode* root);//��������Ľ����
int BinaryTreeLeafSize(BTNode* root);//���������Ҷ�ӽ����
int BinaryTreeLevelKSize(BTNode* root, int k);//���������k��Ľ����
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);//�ҵ�ֵΪx�Ľ��
void BinaryTreePrevOrder(BTNode* root);//ǰ�����
void BinaryTreeInOrder(BTNode* root);//�������
void BinaryTreePostOrder(BTNode* root);//�������
