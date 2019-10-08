#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
 struct TreeNode {
    int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q)//�ж������������Ƿ���ͬ
{
	if (p == NULL && q == NULL)//������Ҷ��ǿ�Ҳ��ͬ
	{
		return true;
	}
	if (p == NULL || q == NULL)//�����һ��Ϊ��һ����Ϊ�գ���ͬ
	{
		return false;
	}
	if (p->val == q->val)
	{    //�ýڵ��ֵ��ͬ���жϸýڵ������ֵ�Ƿ���ͬ
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
	else
		return false;
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)//�ж�t�������ǲ���s������
{
	if (t == NULL)
	{
		return true;
	}
	if (s)
	{
		if ((s->val == t->val) && (isSameTree(s, t) == true))//����Ը�s�ڵ�Ϊ��������t��ͬ�Ļ�������
		{
			return true;
		}
		else
		{
			return isSubtree(s->left, t) || isSubtree(s->right, t);//�����ٿ���߻����ұ���û������
		}
	}
	else
	{
		return false;
	}
}

int maxDepth(struct TreeNode* root)//��������������
{
	if (root)
	{
		return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;//+1�ӵ��Ǹò�����1
	}
	return 0;
}

bool isBalanced(struct TreeNode* root)//�ж��Ƿ�Ϊƽ�������
{
	if (root)
	{ //���������Ϊ���Ķ�������ƽ��ģ�������������Ҳƽ������ƽ����������ݹ飩
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
		return true;//����ǿյģ���϶���ƽ�������
}

bool isSymmetric2(struct TreeNode* r1, struct TreeNode* r2)//�ж��Ƿ��ǶԳƶ�����
{
	if (r1 == NULL && r2 == NULL)
	{
		return true;
	}
	if (r1 == NULL || r2 == NULL)//�����һ��Ϊ��һ����Ϊ�����ǶԳƶ�����
	{
		return false;
	}
	if (r1->val == r2->val)
	{    //������ȣ���ȥ�ж����Ӧ�ĵ��Ƿ����
		return isSymmetric2(r1->left, r2->right) && isSymmetric2(r1->right, r2->left);
	}
	else
	{
		return false;
	}
}

bool isSymmetric(struct TreeNode* root)//�ж��Ƿ��ǶԳƶ�����
{
	if (root)
	{
		return isSymmetric2(root->left, root->right);
	}
	return true;
}