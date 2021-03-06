// question54.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
//给定一棵二叉搜索树，找出其中第k小的节点。
//key：二叉搜索树（左子树均小于当前节点，右子树均大于当前节点，等于随意放）
//二叉搜索树的中序遍历就是从小到大排序的，求出即可
using namespace std;

struct TreeNode {
	int val;
	shared_ptr<TreeNode> left;
	shared_ptr<TreeNode> right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{}
};
void KthNodeCore(shared_ptr<TreeNode> root, vector<shared_ptr<TreeNode> > &ans);
shared_ptr<TreeNode> KthNode(shared_ptr<TreeNode> root, int k)
{
	if (k <= 0)
		return nullptr;
	vector<shared_ptr<TreeNode> > ans;
	KthNodeCore(root,ans);
	if (ans.size() < k)
		return nullptr;
	return ans[k - 1];
}

void KthNodeCore(shared_ptr<TreeNode> root,vector<shared_ptr<TreeNode> > &ans)
{
	if (root == nullptr)
		return;
	KthNodeCore(root->left,ans);
	ans.push_back(root);
	KthNodeCore(root->right,ans);
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
void Test(const char* testName, const shared_ptr<TreeNode> pRoot, unsigned int k, bool isNull, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	const shared_ptr<TreeNode> pTarget = KthNode(pRoot, k);
	if ((isNull && pTarget == nullptr) || (!isNull && pTarget->val == expected))
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void TestA()
{
	shared_ptr<TreeNode> pNode8 = CreatNode(8);
	shared_ptr<TreeNode> pNode6 = CreatNode(6);
	shared_ptr<TreeNode> pNode10 = CreatNode(10);
	shared_ptr<TreeNode> pNode5 = CreatNode(5);
	shared_ptr<TreeNode> pNode7 = CreatNode(7);
	shared_ptr<TreeNode> pNode9 = CreatNode(9);
	shared_ptr<TreeNode> pNode11 = CreatNode(11);

	ConnectNodes(pNode8, pNode6, pNode10);
	ConnectNodes(pNode6, pNode5, pNode7);
	ConnectNodes(pNode10, pNode9, pNode11);

	Test("TestA0", pNode8, 0, true, -1);
	Test("TestA1", pNode8, 1, false, 5);
	Test("TestA2", pNode8, 2, false, 6);
	Test("TestA3", pNode8, 3, false, 7);
	Test("TestA4", pNode8, 4, false, 8);
	Test("TestA5", pNode8, 5, false, 9);
	Test("TestA6", pNode8, 6, false, 10);
	Test("TestA7", pNode8, 7, false, 11);
	Test("TestA8", pNode8, 8, true, -1);


	printf("\n\n");
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void TestB()
{
	shared_ptr<TreeNode> pNode5 = CreatNode(5);
	shared_ptr<TreeNode> pNode4 = CreatNode(4);
	shared_ptr<TreeNode> pNode3 = CreatNode(3);
	shared_ptr<TreeNode> pNode2 = CreatNode(2);
	shared_ptr<TreeNode> pNode1 = CreatNode(1);

	ConnectNodes(pNode5, pNode4, nullptr);
	ConnectNodes(pNode4, pNode3, nullptr);
	ConnectNodes(pNode3, pNode2, nullptr);
	ConnectNodes(pNode2, pNode1, nullptr);

	Test("TestB0", pNode5, 0, true, -1);
	Test("TestB1", pNode5, 1, false, 1);
	Test("TestB2", pNode5, 2, false, 2);
	Test("TestB3", pNode5, 3, false, 3);
	Test("TestB4", pNode5, 4, false, 4);
	Test("TestB5", pNode5, 5, false, 5);
	Test("TestB6", pNode5, 6, true, -1);


	printf("\n\n");
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
void TestC()
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

	Test("TestC0", pNode1, 0, true, -1);
	Test("TestC1", pNode1, 1, false, 1);
	Test("TestC2", pNode1, 2, false, 2);
	Test("TestC3", pNode1, 3, false, 3);
	Test("TestC4", pNode1, 4, false, 4);
	Test("TestC5", pNode1, 5, false, 5);
	Test("TestC6", pNode1, 6, true, -1);


	printf("\n\n");
}

// There is only one node in a tree
void TestD()
{
	shared_ptr<TreeNode> pNode1 = CreatNode(1);

	Test("TestD0", pNode1, 0, true, -1);
	Test("TestD1", pNode1, 1, false, 1);
	Test("TestD2", pNode1, 2, true, -1);

	printf("\n\n");
}

// empty tree
void TestE()
{
	Test("TestE0", nullptr, 0, true, -1);
	Test("TestE1", nullptr, 1, true, -1);

	printf("\n\n");
}


int main()
{
	TestA();
	TestB();
	TestC();
	TestD();
	TestE();
	system("pause");
    return 0;
}

