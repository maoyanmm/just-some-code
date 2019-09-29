#include"BinaryTree.h"

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{//��*pi����Ϊ�����pi�����ڵ�������a[0]�����Ҳ��һ��һ�ң�Ҳ����һ��һ�Ҹ�ֵ��a[1]��a[2]�������ڵ���ұ߻���һ��ʼ������pi+1��Ҳ����a[1]������Ҫ��Ӧ����a[3]
	assert(a);
	if (a[*pi] != '#')//#��Ϊ�ո�
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		++(*pi); //ÿ����һ��Ԫ�ض�Ҫ��������������
		root->_left = BinaryTreeCreate(a, pi);
		++(*pi);
		root->_right = BinaryTreeCreate(a, pi);
		return root;
	}
	else //����ǿո���ǿ�
	{
		return NULL;
	}
}

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;//�����Ϊ��˵���������һ����Ч�Ľ�㣬����Ҫ��һ
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;//ֻ�����Ҷ�Ϊ�ղ���һ��Ҷ�ӣ�������ݲ�ͬ�������������
	}
	else if (root->_left == NULL)
	{
		return BinaryTreeLeafSize(root->_right);
	}
	else if (root->_right == NULL)
	{
		return BinaryTreeLeafSize(root->_left);
	}
	else
	{
		return BinaryTreeLeafSize(root->_right) + BinaryTreeLeafSize(root->_left);
	}
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k <= 0)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
	//���Ĳ��൱�ڵڶ���ĵڶ��㣬Ҳ���ǵڶ���Ҫ����������ܵ����Ĳ�
	//k == 1 ��������һ����
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	if (BinaryTreeFind(root->_left, x) != NULL)
	{
		return BinaryTreeFind(root->_left, x);
	}
	if (BinaryTreeFind(root->_right, x) != NULL)
	{
		return BinaryTreeFind(root->_right, x);
	}
	return NULL;
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
	}
	else
	{
		printf("%c ", root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
	}
	else
	{
		BinaryTreeInOrder(root->_left);
		printf("%c ",root->_data);
		BinaryTreeInOrder(root->_right);
	}
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
	}
	else
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		printf("%c ", root->_data);
	}
}

void BinaryTreeDestory(BTNode** root)
{//����һ��Ҫ������ָ�룬�����һ��ָ�룬�������root��Ϊ�գ�ֻ�Ǹ�������ָ�������Ϊ�գ���û�и����������洴���Ķ������Ľ��ĵ�ַ��Ϊ��
	if (*root)
	{
		BTNode* cur = *root;
		BinaryTreeDestory(&(*root)->_left);
		BinaryTreeDestory(&(*root)->_right);
		free(*root);
		*root = NULL;
	}
}

void BTtest()
{    // ���������ABD##E#H##CF##G##
	//  ���������#D#B#E#H#A#F#C#G#
	//  ���������##D###HEB##F##GCA
	int pi = 0;
	char a[] = { 'A', 'B', 'D', '#', '#', 'E', '#', 'H', '#', '#', 'C', 'F', '#', '#', 'G', '#', '#' };
	BTNode* root = BinaryTreeCreate(a, &pi);
	int b = BinaryTreeSize(root);
	printf("һ����%d�����\n", b);
	b = BinaryTreeLeafSize(root);
	printf("һ����%d��Ҷ�ӽ��\n ", b);
	int k = 3;
	b = BinaryTreeLevelKSize(root, k);
	printf("��%d��һ����%d�����\n ", k, b);
	BTNode* tmp = BinaryTreeFind(root, 'H');
	if (tmp)
		printf("�ҵ���%c \n", tmp->_data);
	else
	{
		printf("û���ҵ�\n");
	}
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	BinaryTreeDestory(&root);
	printf("\n");
	BinaryTreePrevOrder(root);
	printf("\n");
}
int main()
{
	BTtest();
	system("pause");
	return 0;
}