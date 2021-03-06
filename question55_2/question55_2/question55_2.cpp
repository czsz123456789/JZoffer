// question55_2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
//输入一棵二叉树的跟节点，判断该树是不是平衡二叉树。
//如果某二叉树中任意节点的左右子树深度相差不超过1，那么它就是一棵平衡二叉树。
using namespace std;
//key1：在上题的基础上遍历求每一个节点左右子树的深度，判断深度差是否小于1
//再递归比较子树。但是这种方法会遍历一个节点多次，不好
//使用后续遍历，先判断子节点，再判读父节点，可以只遍历一次
struct TreeNode {
	int val;
	shared_ptr<TreeNode> left;
	shared_ptr<TreeNode> right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{}
};

//pair记录节点深度和是否平衡
pair<bool, int> IsBalanced(shared_ptr<TreeNode> root)
{
	if (root == nullptr)
		return make_pair(true, 0);
	//先进行子节点的判断
	auto pairL = IsBalanced(root->left);
	auto pairR = IsBalanced(root->right);
	if (pairL.first && pairR.first && (abs(pairL.second - pairR.second) <= 1))
		return make_pair(true, max(pairL.second, pairR.second) + 1);
	else
		return make_pair(false, -1);
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
void Test(const char* testName, const shared_ptr<TreeNode> pRoot, bool expected)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("Solution begins: ");
	if (IsBalanced(pRoot).first == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 完全二叉树
//             1
//         /      \
//        2        3
//       /\       / \
//      4  5     6   7
void Test1()
{
	shared_ptr<TreeNode> pNode1 = CreatNode(1);
	shared_ptr<TreeNode> pNode2 = CreatNode(2);
	shared_ptr<TreeNode> pNode3 = CreatNode(3);
	shared_ptr<TreeNode> pNode4 = CreatNode(4);
	shared_ptr<TreeNode> pNode5 = CreatNode(5);
	shared_ptr<TreeNode> pNode6 = CreatNode(6);
	shared_ptr<TreeNode> pNode7 = CreatNode(7);

	ConnectNodes(pNode1, pNode2, pNode3);
	ConnectNodes(pNode2, pNode4, pNode5);
	ConnectNodes(pNode3, pNode6, pNode7);

	Test("Test1", pNode1, true);

}

// 不是完全二叉树，但是平衡二叉树
//             1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
void Test2()
{
	shared_ptr<TreeNode> pNode1 = CreatNode(1);
	shared_ptr<TreeNode> pNode2 = CreatNode(2);
	shared_ptr<TreeNode> pNode3 = CreatNode(3);
	shared_ptr<TreeNode> pNode4 = CreatNode(4);
	shared_ptr<TreeNode> pNode5 = CreatNode(5);
	shared_ptr<TreeNode> pNode6 = CreatNode(6);
	shared_ptr<TreeNode> pNode7 = CreatNode(7);

	ConnectNodes(pNode1, pNode2, pNode3);
	ConnectNodes(pNode2, pNode4, pNode5);
	ConnectNodes(pNode3, nullptr, pNode6);
	ConnectNodes(pNode5, pNode7, nullptr);

	Test("Test2", pNode1, true);

}

// 不是平衡二叉树
//             1
//         /      \
//        2        3
//       /\         
//      4  5        
//        /
//       6
void Test3()
{
	shared_ptr<TreeNode> pNode1 = CreatNode(1);
	shared_ptr<TreeNode> pNode2 = CreatNode(2);
	shared_ptr<TreeNode> pNode3 = CreatNode(3);
	shared_ptr<TreeNode> pNode4 = CreatNode(4);
	shared_ptr<TreeNode> pNode5 = CreatNode(5);
	shared_ptr<TreeNode> pNode6 = CreatNode(6);

	ConnectNodes(pNode1, pNode2, pNode3);
	ConnectNodes(pNode2, pNode4, pNode5);
	ConnectNodes(pNode5, pNode6, nullptr);

	Test("Test3", pNode1, false);

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
void Test4()
{
	shared_ptr<TreeNode> pNode1 = CreatNode(1);
	shared_ptr<TreeNode> pNode2 = CreatNode(2);
	shared_ptr<TreeNode> pNode3 = CreatNode(3);
	shared_ptr<TreeNode> pNode4 = CreatNode(4);
	shared_ptr<TreeNode> pNode5 = CreatNode(5);

	ConnectNodes(pNode1, pNode2, nullptr);
	ConnectNodes(pNode2, pNode3, nullptr);
	ConnectNodes(pNode3, pNode4, nullptr);
	ConnectNodes(pNode4, pNode5, nullptr);

	Test("Test4", pNode1, false);

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
void Test5()
{
	shared_ptr<TreeNode> pNode1 = CreatNode(1);
	shared_ptr<TreeNode> pNode2 = CreatNode(2);
	shared_ptr<TreeNode> pNode3 = CreatNode(3);
	shared_ptr<TreeNode> pNode4 = CreatNode(4);
	shared_ptr<TreeNode> pNode5 = CreatNode(5);

	ConnectNodes(pNode1, nullptr, pNode2);
	ConnectNodes(pNode2, nullptr, pNode3);
	ConnectNodes(pNode3, nullptr, pNode4);
	ConnectNodes(pNode4, nullptr, pNode5);

	Test("Test5", pNode1, false);

}

// 树中只有1个结点
void Test6()
{
	shared_ptr<TreeNode> pNode1 = CreatNode(1);
	Test("Test6", pNode1, true);

}

// 树中没有结点
void Test7()
{
	Test("Test7", nullptr, true);
}


int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	system("pause");
    return 0;
}

