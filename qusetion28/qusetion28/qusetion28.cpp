// qusetion28.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>

//判断二叉树是否是关于中间轴镜面对称的
using namespace std;

struct BinaryTreeNode
{
	int val;
	shared_ptr<BinaryTreeNode> left;
	shared_ptr<BinaryTreeNode> right;
	BinaryTreeNode(int v) :val(v), left(nullptr), right(nullptr)
	{}
};
bool isSymmertrical(shared_ptr<BinaryTreeNode> p1, shared_ptr<BinaryTreeNode> p2);

bool ans(shared_ptr<BinaryTreeNode> root)
{
	return isSymmertrical(root, root);
}

//递归法
bool isSymmertrical(shared_ptr<BinaryTreeNode> p1, shared_ptr<BinaryTreeNode> p2)
{
	if (p1 == nullptr && p2 == nullptr)
		return true;
	if (p1 == nullptr || p2 == nullptr)
		return false;
	if (p1->val != p2->val)
		return false;
	//递归比较一个节点的左和另一个节点的右
	return isSymmertrical(p1->left, p2->right) && isSymmertrical(p1->right,p2->left);
}

//迭代法，需要引入辅助队列
bool isSymmertrical2(shared_ptr<BinaryTreeNode> root)
{
	if (root == nullptr)
		return true;
	//为了镜像比较，将root推入两次
	queue<shared_ptr<BinaryTreeNode> > q;
	q.push(root);
	q.push(root);
	while (!q.empty())
	{
		//每次出两个
		auto p1 = q.front();
		q.pop();
		auto p2 = q.front();
		q.pop();
		if (p1 == nullptr && p2 == nullptr)
			continue;
		else if (p1 == nullptr || p2 == nullptr)
			return false;
		else if (p1->val != p2->val)
			return false;
		//这个推入顺序很重要,要保证是镜像位置
		q.push(p1->left);
		q.push(p2->right);
		q.push(p1->right);
		q.push(p2->left);
	}
	return true;
}

int main()
{
    return 0;
}

