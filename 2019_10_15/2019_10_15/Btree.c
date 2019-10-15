/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

struct TreeNode* _build(int* preorder, int* pindex, int* inorder, int inbegin, int inend)
{
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	root->val = preorder[*pindex];
	int rootindex = inbegin;
	for (; rootindex <= inend; rootindex++)
	{
		if (inorder[rootindex] == root->val)
		{
			break;
		}
	}
	if (inbegin < rootindex)
	{
		++(*pindex);
		root->left = _build(preorder, pindex, inorder, inbegin, rootindex - 1);
	}
	else
	{
		root->left = NULL;
	}
	if (rootindex < inend)
	{
		++(*pindex);
		root->right = _build(preorder, pindex, inorder, rootindex + 1, inend);
	}
	else
	{
		root->right = NULL;
	}
	return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
	if (preorderSize <= 0)
	{
		return NULL;
	}
	int n = 0;
	return _build(preorder, &n, inorder, 0, inorderSize - 1);

}