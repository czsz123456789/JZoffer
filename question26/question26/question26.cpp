// question26.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

//输入两棵二叉树A和B，判断B是不是A的子结构。
//key:第一步，在树A中找到和树B的根节点的值一样的节点R；第二步，判断树A中以R为根节点的子树是不是包含和树B一样的结构
using namespace std;

//-----功能代码-----
struct BinaryTreeNode
{
	int val;
	shared_ptr<BinaryTreeNode> left;
	shared_ptr<BinaryTreeNode> right;
	BinaryTreeNode(int v):val(v),left(nullptr),right(nullptr)
	{}
};

bool HasSubTree(shared_ptr<BinaryTreeNode> root1, shared_ptr<BinaryTreeNode> root2);
bool DoesTree1HaveTree2(shared_ptr<BinaryTreeNode> root1, shared_ptr<BinaryTreeNode> root2);

//递归搜索tree1,找一个节点和tree2根节点相等，之后比较子树是否相同
bool HasSubTree(shared_ptr<BinaryTreeNode> root1, shared_ptr<BinaryTreeNode> root2)
{
	if (root1 == nullptr || root2 == nullptr)
		return false;
	//A中找到一个节点和B根节点相同
	if (root1->val == root2->val)
	{
		//递归搜索子树
		if (DoesTree1HaveTree2(root1, root2))
			return true;
	}
	//根节点不同，继续找
	//向左搜索
	if (HasSubTree(root1->left, root2))
		return true;
	if (HasSubTree(root1->right, root2))
		return true;
	return false;
}

//比较tree1和tree2中每一个节点
bool DoesTree1HaveTree2(shared_ptr<BinaryTreeNode> root1, shared_ptr<BinaryTreeNode> root2)
{
	//搜索完毕
	if (root2 == nullptr)
		return true;
	//tree1没有节点而tree2还有节点
	if (root1 == nullptr)
		return false;
	if (root1->val != root2->val)
		return false;
	//递归左右子树
	return DoesTree1HaveTree2(root1->left, root2->left) && DoesTree1HaveTree2(root1->right, root2->right);
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


//-----测试代码-----
void Test(string testName, shared_ptr<BinaryTreeNode> pRoot1, shared_ptr<BinaryTreeNode> pRoot2, bool expected)
{
	if (HasSubTree(pRoot1, pRoot2) == expected)
		cout << testName << " passed" << endl;
	else
		cout << testName << " failed" << endl;
}

// 树中结点含有分叉，树B是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//  
void Test1()
{
	shared_ptr<BinaryTreeNode> pNodeA1 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeA2 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeA3 = CreatNode(7);
	shared_ptr<BinaryTreeNode> pNodeA4 = CreatNode(9);
	shared_ptr<BinaryTreeNode> pNodeA5 = CreatNode(2);
	shared_ptr<BinaryTreeNode> pNodeA6 = CreatNode(4);
	shared_ptr<BinaryTreeNode> pNodeA7 = CreatNode(7);

	ConnectNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectNodes(pNodeA5, pNodeA6, pNodeA7);

	shared_ptr<BinaryTreeNode> pNodeB1 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeB2 = CreatNode(9);
	shared_ptr<BinaryTreeNode> pNodeB3 = CreatNode(2);

	ConnectNodes(pNodeB1, pNodeB2, pNodeB3);

	Test("Test1", pNodeA1, pNodeB1, true);

}

// 树中结点含有分叉，树B不是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     3
//               / \
//              4   7
void Test2()
{
	shared_ptr<BinaryTreeNode> pNodeA1 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeA2 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeA3 = CreatNode(7);
	shared_ptr<BinaryTreeNode> pNodeA4 = CreatNode(9);
	shared_ptr<BinaryTreeNode> pNodeA5 = CreatNode(3);
	shared_ptr<BinaryTreeNode> pNodeA6 = CreatNode(4);
	shared_ptr<BinaryTreeNode> pNodeA7 = CreatNode(7);

	ConnectNodes(pNodeA1, pNodeA2, pNodeA3);
	ConnectNodes(pNodeA2, pNodeA4, pNodeA5);
	ConnectNodes(pNodeA5, pNodeA6, pNodeA7);

	shared_ptr<BinaryTreeNode> pNodeB1 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeB2 = CreatNode(9);
	shared_ptr<BinaryTreeNode> pNodeB3 = CreatNode(2);

	ConnectNodes(pNodeB1, pNodeB2, pNodeB3);

	Test("Test2", pNodeA1, pNodeB1, false);

}

// 树中结点只有左子结点，树B是树A的子结构
//                8                  8
//              /                   / 
//             8                   9   
//           /                    /
//          9                    2
//         /      
//        2        
//       /
//      5
void Test3()
{
	shared_ptr<BinaryTreeNode> pNodeA1 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeA2 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeA3 = CreatNode(9);
	shared_ptr<BinaryTreeNode> pNodeA4 = CreatNode(2);
	shared_ptr<BinaryTreeNode> pNodeA5 = CreatNode(5);

	ConnectNodes(pNodeA1, pNodeA2, nullptr);
	ConnectNodes(pNodeA2, pNodeA3, nullptr);
	ConnectNodes(pNodeA3, pNodeA4, nullptr);
	ConnectNodes(pNodeA4, pNodeA5, nullptr);

	shared_ptr<BinaryTreeNode> pNodeB1 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeB2 = CreatNode(9);
	shared_ptr<BinaryTreeNode> pNodeB3 = CreatNode(2);

	ConnectNodes(pNodeB1, pNodeB2, nullptr);
	ConnectNodes(pNodeB2, pNodeB3, nullptr);

	Test("Test3", pNodeA1, pNodeB1, true);

}

// 树中结点只有左子结点，树B不是树A的子结构
//                8                  8
//              /                   / 
//             8                   9   
//           /                    /
//          9                    3
//         /      
//        2        
//       /
//      5
void Test4()
{
	shared_ptr<BinaryTreeNode> pNodeA1 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeA2 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeA3 = CreatNode(9);
	shared_ptr<BinaryTreeNode> pNodeA4 = CreatNode(2);
	shared_ptr<BinaryTreeNode> pNodeA5 = CreatNode(5);

	ConnectNodes(pNodeA1, pNodeA2, nullptr);
	ConnectNodes(pNodeA2, pNodeA3, nullptr);
	ConnectNodes(pNodeA3, pNodeA4, nullptr);
	ConnectNodes(pNodeA4, pNodeA5, nullptr);

	shared_ptr<BinaryTreeNode> pNodeB1 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeB2 = CreatNode(9);
	shared_ptr<BinaryTreeNode> pNodeB3 = CreatNode(3);

	ConnectNodes(pNodeB1, pNodeB2, nullptr);
	ConnectNodes(pNodeB2, pNodeB3, nullptr);

	Test("Test4", pNodeA1, pNodeB1, false);

}

// 树中结点只有右子结点，树B是树A的子结构
//       8                   8
//        \                   \ 
//         8                   9   
//          \                   \
//           9                   2
//            \      
//             2        
//              \
//               5
void Test5()
{
	shared_ptr<BinaryTreeNode> pNodeA1 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeA2 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeA3 = CreatNode(9);
	shared_ptr<BinaryTreeNode> pNodeA4 = CreatNode(2);
	shared_ptr<BinaryTreeNode> pNodeA5 = CreatNode(5);

	ConnectNodes(pNodeA1, nullptr, pNodeA2);
	ConnectNodes(pNodeA2, nullptr, pNodeA3);
	ConnectNodes(pNodeA3, nullptr, pNodeA4);
	ConnectNodes(pNodeA4, nullptr, pNodeA5);

	shared_ptr<BinaryTreeNode> pNodeB1 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeB2 = CreatNode(9);
	shared_ptr<BinaryTreeNode> pNodeB3 = CreatNode(2);

	ConnectNodes(pNodeB1, nullptr, pNodeB2);
	ConnectNodes(pNodeB2, nullptr, pNodeB3);

	Test("Test5", pNodeA1, pNodeB1, true);

}

// 树A中结点只有右子结点，树B不是树A的子结构
//       8                   8
//        \                   \ 
//         8                   9   
//          \                 / \
//           9               3   2
//            \      
//             2        
//              \
//               5
void Test6()
{
	shared_ptr<BinaryTreeNode> pNodeA1 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeA2 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeA3 = CreatNode(9);
	shared_ptr<BinaryTreeNode> pNodeA4 = CreatNode(2);
	shared_ptr<BinaryTreeNode> pNodeA5 = CreatNode(5);

	ConnectNodes(pNodeA1, nullptr, pNodeA2);
	ConnectNodes(pNodeA2, nullptr, pNodeA3);
	ConnectNodes(pNodeA3, nullptr, pNodeA4);
	ConnectNodes(pNodeA4, nullptr, pNodeA5);

	shared_ptr<BinaryTreeNode> pNodeB1 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeB2 = CreatNode(9);
	shared_ptr<BinaryTreeNode> pNodeB3 = CreatNode(3);
	shared_ptr<BinaryTreeNode> pNodeB4 = CreatNode(2);

	ConnectNodes(pNodeB1, nullptr, pNodeB2);
	ConnectNodes(pNodeB2, pNodeB3, pNodeB4);

	Test("Test6", pNodeA1, pNodeB1, false);

}

// 树A为空树
void Test7()
{
	shared_ptr<BinaryTreeNode> pNodeB1 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeB2 = CreatNode(9);
	shared_ptr<BinaryTreeNode> pNodeB3 = CreatNode(3);
	shared_ptr<BinaryTreeNode> pNodeB4 = CreatNode(2);

	ConnectNodes(pNodeB1, nullptr, pNodeB2);
	ConnectNodes(pNodeB2, pNodeB3, pNodeB4);

	Test("Test7", nullptr, pNodeB1, false);

}

// 树B为空树
void Test8()
{
	shared_ptr<BinaryTreeNode> pNodeA1 = CreatNode(8);
	shared_ptr<BinaryTreeNode> pNodeA2 = CreatNode(9);
	shared_ptr<BinaryTreeNode> pNodeA3 = CreatNode(3);
	shared_ptr<BinaryTreeNode> pNodeA4 = CreatNode(2);

	ConnectNodes(pNodeA1, nullptr, pNodeA2);
	ConnectNodes(pNodeA2, pNodeA3, pNodeA4);

	Test("Test8", pNodeA1, nullptr, false);

}

// 树A和树B都为空
void Test9()
{
	Test("Test9", nullptr, nullptr, false);
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
	Test8();
	Test9();

	system("pause");
    return 0;
}

