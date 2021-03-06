// question32.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <string>
//从上到下打印二叉树，即二叉树的的层寻遍历，分行

using namespace std;

//key：用队列辅助记录
struct BinaryTreeNode
{
	int val;
	shared_ptr<BinaryTreeNode> left;
	shared_ptr<BinaryTreeNode> right;
	BinaryTreeNode(int v) :val(v), left(nullptr), right(nullptr)
	{}
};
void PrintFromTopToBottom(shared_ptr<BinaryTreeNode> root)
{
	if (root == nullptr)
		return;
	queue<shared_ptr<BinaryTreeNode> > q;
	q.push(root);
	
	//相比不分行，只需要加一个for循环打印本层所有节点
	while (!q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			auto node = q.front();
			q.pop();
			if (node == nullptr)
			{
				cout << "nullptr" << " ";
				continue;
			}
			cout << node->val << " ";
			if (node->left == nullptr && node->right == nullptr)
				continue;
			q.push(node->left);
			q.push(node->right);
		}
		cout << endl;
		
	}
}

//-------辅助测试代码-------
//创建树节点
shared_ptr<BinaryTreeNode> CreatNode(int num)
{
	shared_ptr<BinaryTreeNode> node(new BinaryTreeNode(num));

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

// ====================测试代码====================
void Test(const char* testName, shared_ptr<BinaryTreeNode> pRoot)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);



	printf("The nodes from top to bottom, from left to right are: \n");
	PrintFromTopToBottom(pRoot);

	printf("\n\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
	shared_ptr<BinaryTreeNode> pNode10 = CreatNode(10);
	shared_ptr<BinaryTreeNode> pNode6 = CreatNode(6);
	shared_ptr<BinaryTreeNode> pNode14 = CreatNode(14);
	shared_ptr<BinaryTreeNode> pNode4 = CreatNode(4);
	shared_ptr<BinaryTreeNode> pNode8 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNode12 = CreatNode(12);
	shared_ptr<BinaryTreeNode> pNode16 = CreatNode(16);

	ConnectNodes(pNode10, pNode6, pNode14);
	ConnectNodes(pNode6, pNode4, pNode8);
	ConnectNodes(pNode14, pNode12, pNode16);

	Test("Test1", pNode10);

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
void Test2()
{
	shared_ptr<BinaryTreeNode> pNode5 = CreatNode(5);
	shared_ptr<BinaryTreeNode> pNode4 = CreatNode(4);
	shared_ptr<BinaryTreeNode> pNode3 = CreatNode(3);
	shared_ptr<BinaryTreeNode> pNode2 = CreatNode(2);
	shared_ptr<BinaryTreeNode> pNode1 = CreatNode(1);

	ConnectNodes(pNode5, pNode4, nullptr);
	ConnectNodes(pNode4, pNode3, nullptr);
	ConnectNodes(pNode3, pNode2, nullptr);
	ConnectNodes(pNode2, pNode1, nullptr);

	Test("Test2", pNode5);

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
	shared_ptr<BinaryTreeNode> pNode1 = CreatNode(1);
	shared_ptr<BinaryTreeNode> pNode2 = CreatNode(2);
	shared_ptr<BinaryTreeNode> pNode3 = CreatNode(3);
	shared_ptr<BinaryTreeNode> pNode4 = CreatNode(4);
	shared_ptr<BinaryTreeNode> pNode5 = CreatNode(5);

	ConnectNodes(pNode1, nullptr, pNode2);
	ConnectNodes(pNode2, nullptr, pNode3);
	ConnectNodes(pNode3, nullptr, pNode4);
	ConnectNodes(pNode4, nullptr, pNode5);

	Test("Test3", pNode1);

}

// 树中只有1个结点
void Test4()
{
	shared_ptr<BinaryTreeNode> pNode1 = CreatNode(1);
	Test("Test4", pNode1);

}

// 树中没有结点
void Test5()
{
	Test("Test5", nullptr);
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

