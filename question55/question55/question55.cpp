// question55.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

//输入一棵二叉树的根节点，求该树的深度
using namespace std;

struct TreeNode {
	int val;
	shared_ptr<TreeNode> left;
	shared_ptr<TreeNode> right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{}
};

//key:递归遍历左右取最深
int TreeDepth(shared_ptr<TreeNode> root)
{
	if (root == nullptr)
		return 0;
	//左子树的深度
	int left = TreeDepth(root->left);
	int right = TreeDepth(root->right);

	return max(left, right) + 1;
}
// ------ - 辅助测试代码------ -
//创建树节点
shared_ptr<TreeNode> CreatNode(int num)
{
	shared_ptr<TreeNode> node(new TreeNode(num));

	return node;
}

//连接节点
void ConnectNodes(shared_ptr<TreeNode> root, shared_ptr<TreeNode> leftchild, shared_ptr<TreeNode> rightchild)
{
	if (root != nullptr)
	{
		root->left = leftchild;
		root->right = rightchild;
	}
}

// ====================测试代码====================
void Test(const char* testName, const shared_ptr<TreeNode> pRoot, int expected)
{
	int result = TreeDepth(pRoot);
	if (expected == result)
		printf("%s passed.\n", testName);
	else
		printf("%s FAILED.\n", testName);
}

//            1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
void Test1()
{
	shared_ptr<TreeNode>pNode1 = CreatNode(1);
	shared_ptr<TreeNode>pNode2 = CreatNode(2);
	shared_ptr<TreeNode>pNode3 = CreatNode(3);
	shared_ptr<TreeNode>pNode4 = CreatNode(4);
	shared_ptr<TreeNode>pNode5 = CreatNode(5);
	shared_ptr<TreeNode>pNode6 = CreatNode(6);
	shared_ptr<TreeNode>pNode7 = CreatNode(7);

	ConnectNodes(pNode1, pNode2, pNode3);
	ConnectNodes(pNode2, pNode4, pNode5);
	ConnectNodes(pNode3, nullptr, pNode6);
	ConnectNodes(pNode5, pNode7, nullptr);

	Test("Test1", pNode1, 4);

}

//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test2()
{
	shared_ptr<TreeNode>pNode1 = CreatNode(1);
	shared_ptr<TreeNode>pNode2 = CreatNode(2);
	shared_ptr<TreeNode>pNode3 = CreatNode(3);
	shared_ptr<TreeNode>pNode4 = CreatNode(4);
	shared_ptr<TreeNode>pNode5 = CreatNode(5);

	ConnectNodes(pNode1, pNode2, nullptr);
	ConnectNodes(pNode2, pNode3, nullptr);
	ConnectNodes(pNode3, pNode4, nullptr);
	ConnectNodes(pNode4, pNode5, nullptr);

	Test("Test2", pNode1, 5);

}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3()
{
	shared_ptr<TreeNode>pNode1 = CreatNode(1);
	shared_ptr<TreeNode>pNode2 = CreatNode(2);
	shared_ptr<TreeNode>pNode3 = CreatNode(3);
	shared_ptr<TreeNode>pNode4 = CreatNode(4);
	shared_ptr<TreeNode>pNode5 = CreatNode(5);

	ConnectNodes(pNode1, nullptr, pNode2);
	ConnectNodes(pNode2, nullptr, pNode3);
	ConnectNodes(pNode3, nullptr, pNode4);
	ConnectNodes(pNode4, nullptr, pNode5);

	Test("Test3", pNode1, 5);

}

// 树中只有1个结点
void Test4()
{
	shared_ptr<TreeNode>pNode1 = CreatNode(1);
	Test("Test4", pNode1, 1);

}

// 树中没有结点
void Test5()
{
	Test("Test5", nullptr, 0);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	system("pause");
    return 0;
}

