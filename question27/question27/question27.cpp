// question27.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

//完成一个函数，输入一个二叉树，该函数输出它的镜像

using namespace std;
//-----功能代码-----
struct BinaryTreeNode
{
	int val;
	shared_ptr<BinaryTreeNode> left;
	shared_ptr<BinaryTreeNode> right;
	BinaryTreeNode(int v) :val(v), left(nullptr), right(nullptr)
	{}
};

void MirrorRecursively(shared_ptr<BinaryTreeNode> root)
{
	if (root == nullptr)
		return;
	if (root->left == nullptr && root->right == nullptr)
		return;

	//交换当前左右子树
	shared_ptr<BinaryTreeNode> temp = root->left;
	root->left = root->right;
	root->right = temp;
	
	//递归左右子树
	if (root->left)
		MirrorRecursively(root->left);
	if (root->right)
		MirrorRecursively(root->right);
}

//-------辅助测试代码-------
//创建树节点
shared_ptr<BinaryTreeNode> CreatNode(int num)
{
	shared_ptr<BinaryTreeNode> node(new BinaryTreeNode(num));
	node->left = nullptr;
	node->right = nullptr;
	return node;
}

//连接节点
void ConnectNodes(shared_ptr<BinaryTreeNode> root, shared_ptr<BinaryTreeNode> leftchild, shared_ptr<BinaryTreeNode> rightchild)
{
	if (root != nullptr)
	{
		root->left = leftchild;
		root->right = rightchild;
	}
}


//懒，先不写测试代码了
int main()
{
    return 0;
}

