#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
 struct TreeNode {
    int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q)//判断两个二叉树是否相同
{
	if (p == NULL && q == NULL)//如果左右都是空也相同
	{
		return true;
	}
	if (p == NULL || q == NULL)//如果有一个为空一个不为空，则不同
	{
		return false;
	}
	if (p->val == q->val)
	{    //该节点的值相同则判断该节点的左右值是否相同
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
	else
		return false;
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)//判断t二叉树是不是s的子树
{
	if (t == NULL)
	{
		return true;
	}
	if (s)
	{
		if ((s->val == t->val) && (isSameTree(s, t) == true))//如果以该s节点为根的树和t相同的话，则是
		{
			return true;
		}
		else
		{
			return isSubtree(s->left, t) || isSubtree(s->right, t);//否则再看左边或者右边有没有子树
		}
	}
	else
	{
		return false;
	}
}

int maxDepth(struct TreeNode* root)//二叉树的最大深度
{
	if (root)
	{
		return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;//+1加的是该层的深度1
	}
	return 0;
}

bool isBalanced(struct TreeNode* root)//判断是否为平衡二叉树
{
	if (root)
	{ //如果这个结点为根的二叉树是平衡的，而且左右子树也平衡则是平衡二叉树（递归）
		if ((abs(maxDepth(root->left) - maxDepth(root->right)) <= 1) && (isBalanced(root->left) == true) && (isBalanced(root->right) == true))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
		return true;//如果是空的，则肯定是平衡二叉树
}

bool isSymmetric2(struct TreeNode* r1, struct TreeNode* r2)//判断是否是对称二叉树
{
	if (r1 == NULL && r2 == NULL)
	{
		return true;
	}
	if (r1 == NULL || r2 == NULL)//如果有一个为空一个不为空则不是对称二叉树
	{
		return false;
	}
	if (r1->val == r2->val)
	{    //两点相等，再去判断相对应的点是否相等
		return isSymmetric2(r1->left, r2->right) && isSymmetric2(r1->right, r2->left);
	}
	else
	{
		return false;
	}
}

bool isSymmetric(struct TreeNode* root)//判断是否是对称二叉树
{
	if (root)
	{
		return isSymmetric2(root->left, root->right);
	}
	return true;
}