// question7.cpp: 定义控制台应用程序的入口点。
//

//根据二叉前序和中序遍历构建二叉树
//常规做法 没什么好说的
#include "stdafx.h"
#include <assert.h>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v):val(v),left(nullptr),right(nullptr)
	{}
	~TreeNode()
	{
		delete left;
		left = nullptr;
		delete right;
		right = nullptr;
	}
};

//在中序遍历中找根节点的位置
int findInorder(vector<int> &inorder, int begin, int end,int target)
{
	for (int i = begin; i <= end; i++)
	{
		if (inorder[i] == target)
			return i;
	}
	return -1;
}

TreeNode *build(vector<int> &preorder, vector<int> &inorder, int s_pre, int e_pre, int s_in, int e_in)
{
	if (s_pre > e_pre || preorder.size() == 0 || inorder.size() == 0)
		return nullptr;

	//前序遍历的第一个节点是根节点
	TreeNode *root = new TreeNode(preorder[s_pre]);

	int index = findInorder(inorder, s_in, e_in, preorder[s_pre]);

	if (index != -1)
	{
		int leftlen = index - s_in;
		//在前序和中序遍历中划分出左右子树的范围，递归建立
		root->left = build(preorder, inorder, s_pre + 1, s_pre + leftlen, s_in, index - 1);
		root->right = build(preorder, inorder, s_pre + leftlen + 1, e_pre, index + 1, e_in);
	}

	return root;
}

TreeNode* reconstruct(vector<int> &preorder, vector<int> &inorder)
{
	return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

int main()
{
    return 0;
}

