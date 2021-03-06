// qusetion8.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

//给定二叉树和一个节点求中序遍历的下一个节点
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int v) :val(v), left(nullptr), right(nullptr)
	{}
};

bool search(TreeNode* root, TreeNode *target, queue<TreeNode*> &q)
{
	if (root == nullptr || target == nullptr)
		return false;
	
	if (root == target)
	{
		return true;
	}
	else if (search(root->left, target, q))
	{
		q.push(root);
		return true;
	}
	else if (search(root->right, target, q))
	{
		q.push(root);
		return true;
	}
	return false;
}

TreeNode* GetNext(TreeNode* root, TreeNode* target)
{
	if (root == nullptr || target == nullptr)
		return nullptr;
	TreeNode* nextnode = nullptr;
	
	//如果目标节点有右节点，则下一个节点是右子树最左节点
	if (target->right)
	{
		TreeNode* temp = target->right;
		while (temp->left)
		{
			temp = temp->left;
		}
		nextnode = temp;
	}
	else//如果没有右节点，则要看该节点是父节点的左节点还是右节点
	{
		queue<TreeNode*> q;
		search(root, target, q);
		TreeNode* anc = q.front();
		q.pop();

		//如果是左节点
		if (target == anc->left)
			nextnode = anc;
		//如果是右节点 相对麻烦
		else if (target == anc->right)
		{
			TreeNode *aanc = nullptr;
			//向上找，直到找打某个节点是他父节点的左节点，返回那个父节点
			while (!q.empty())
			{
				aanc = q.front();
				q.pop();
				if (aanc->left = anc)
				{
					nextnode = aanc;
					break;
				}
				else
				{
					anc = aanc;
				}
			}
		}
	}
	return nextnode;
}

int main()
{
    return 0;
}

