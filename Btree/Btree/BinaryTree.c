#include"BinaryTree.h"

BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{//传*pi是因为如果是pi，根节点的左边是a[0]，左边也有一左一右，也就是一左一右赋值是a[1]和a[2]，而根节点的右边还是一开始进来的pi+1，也就是a[1]，我们要的应该是a[3]
	assert(a);
	if (a[*pi] != '#')//#视为空格
	{
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		++(*pi); //每插入一个元素都要将输入的数组后移
		root->_left = BinaryTreeCreate(a, pi);
		++(*pi);
		root->_right = BinaryTreeCreate(a, pi);
		return root;
	}
	else //如果是空格就是空
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
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;//如果不为空说明本身就是一个有效的结点，所以要加一
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;//只有左右都为空才是一个叶子，否则根据不同情况继续往下找
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
	//第四层相当于第二层的第二层，也就是第二层要再走两层才能到第四层
	//k == 1 代表到了这一层了
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
{//这里一定要传二级指针，如果是一级指针，在下面的root置为空，只是给函数的指针变量置为空，并没有给我们在外面创建的二叉树的结点的地址置为空
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
{    // 先序遍历：ABD##E#H##CF##G##
	//  中序遍历：#D#B#E#H#A#F#C#G#
	//  后序遍历：##D###HEB##F##GCA
	int pi = 0;
	char a[] = { 'A', 'B', 'D', '#', '#', 'E', '#', 'H', '#', '#', 'C', 'F', '#', '#', 'G', '#', '#' };
	BTNode* root = BinaryTreeCreate(a, &pi);
	int b = BinaryTreeSize(root);
	printf("一共有%d个结点\n", b);
	b = BinaryTreeLeafSize(root);
	printf("一共有%d个叶子结点\n ", b);
	int k = 3;
	b = BinaryTreeLevelKSize(root, k);
	printf("第%d层一共有%d个结点\n ", k, b);
	BTNode* tmp = BinaryTreeFind(root, 'H');
	if (tmp)
		printf("找到了%c \n", tmp->_data);
	else
	{
		printf("没有找到\n");
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