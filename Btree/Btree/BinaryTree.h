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

BTNode* BinaryTreeCreate(BTDataType* a, int* pi);//创建二叉树
void BinaryTreeDestory(BTNode** root);//摧毁二叉树
int BinaryTreeSize(BTNode* root);//求二叉树的结点数
int BinaryTreeLeafSize(BTNode* root);//求二叉树的叶子结点数
int BinaryTreeLevelKSize(BTNode* root, int k);//求二叉树第k层的结点数
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);//找到值为x的结点
void BinaryTreePrevOrder(BTNode* root);//前序遍历
void BinaryTreeInOrder(BTNode* root);//中序遍历
void BinaryTreePostOrder(BTNode* root);//后序遍历
