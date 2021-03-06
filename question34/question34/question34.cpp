// question34.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
//输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
//从根节点开始往下一直到叶节点所经过的节点形成一条路径

using namespace std;

struct BinaryTreeNode
{
	int val;
	shared_ptr<BinaryTreeNode> left;
	shared_ptr<BinaryTreeNode> right;
	BinaryTreeNode(int v) :val(v), left(nullptr), right(nullptr)
	{}
};

//key：前序遍历的深度优先搜索
//注意路径的回溯

vector<vector<int> > FindPath(shared_ptr<BinaryTreeNode> root, int target);

void Path(shared_ptr<BinaryTreeNode> root, int target, vector<vector<int> > &ans, vector<int> &now)
{
	if (root == nullptr)
		return;
	//路径中加入当前节点
	target -= root->val;
	now.push_back(root->val);
	//到达target且为叶节点
	if (target == 0 && root->left == nullptr && root->right == nullptr)
	{
		ans.push_back(now);
		now.pop_back();
		return;
	}
	//继续向左右子树搜索
	Path(root->left, target, ans, now);
	Path(root->right, target, ans, now);
	//回溯
	now.pop_back();
}

vector<vector<int> > FindPath(shared_ptr<BinaryTreeNode> root, int target)
{
	vector<vector<int> > ans;
	if (root == nullptr)
		return ans;
	vector<int> now;
	Path(root, target, ans, now);
	for (auto nums : ans)
	{
		for (auto num : nums)
			cout << num << " ";
		cout << endl;
	}
	return ans;
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
void Test(const char* testName, shared_ptr<BinaryTreeNode> pRoot, int expectedSum)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);
	printf("target is %d\n", expectedSum);
	FindPath(pRoot, expectedSum);

	printf("\n");
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// 有两条路径上的结点和为22
void Test1()
{
	shared_ptr<BinaryTreeNode> pNode10 = CreatNode(10);
	shared_ptr<BinaryTreeNode> pNode5 = CreatNode(5);
	shared_ptr<BinaryTreeNode> pNode12 = CreatNode(12);
	shared_ptr<BinaryTreeNode> pNode4 = CreatNode(4);
	shared_ptr<BinaryTreeNode> pNode7 = CreatNode(7);

	ConnectNodes(pNode10, pNode5, pNode12);
	ConnectNodes(pNode5, pNode4, pNode7);

	printf("Two paths should be found in Test1.\n");
	Test("Test1", pNode10, 22);

}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// 没有路径上的结点和为15
void Test2()
{
	shared_ptr<BinaryTreeNode> pNode10 = CreatNode(10);
	shared_ptr<BinaryTreeNode> pNode5 = CreatNode(5);
	shared_ptr<BinaryTreeNode> pNode12 = CreatNode(12);
	shared_ptr<BinaryTreeNode> pNode4 = CreatNode(4);
	shared_ptr<BinaryTreeNode> pNode7 = CreatNode(7);

	ConnectNodes(pNode10, pNode5, pNode12);
	ConnectNodes(pNode5, pNode4, pNode7);

	printf("No paths should be found in Test2.\n");
	Test("Test2", pNode10, 15);

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
// 有一条路径上面的结点和为15
void Test3()
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

	printf("One path should be found in Test3.\n");
	Test("Test3", pNode5, 15);

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
// 没有路径上面的结点和为16
void Test4()
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

	printf("No paths should be found in Test4.\n");
	Test("Test4", pNode1, 16);

}

// 树中只有1个结点
void Test5()
{
	shared_ptr<BinaryTreeNode> pNode1 = CreatNode(1);

	printf("One path should be found in Test5.\n");
	Test("Test5", pNode1, 1);

}

// 树中没有结点
void Test6()
{
	printf("No paths should be found in Test6.\n");
	Test("Test6", nullptr, 0);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	system("pause");
    return 0;
}

