// question37.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>

//完成二叉树的序列化和反序列化，同leetcode279
using namespace std;

struct TreeNode {
	int val;
	shared_ptr<TreeNode> left;
	shared_ptr<TreeNode> right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr)
	{}	
};
//序列化为字符串
/*例：将以下二叉树：

    1
   / \
  2   3
 / \
4   5

序列化为 "[1,2,3,$,$,4,5]"
*/
string serialize(shared_ptr<TreeNode> root)
{
	if (root == nullptr)
		return "";
	//使用层序遍历将二叉树序列化
	string ans;
	queue<shared_ptr<TreeNode> > q;
	q.push(root);
	while (!q.empty())
	{
		auto temp = q.front();
		q.pop();
		if (temp == nullptr)
			ans += "$,";
		else
		{
			ans += to_string(temp->val);
			ans += ",";
			q.push(temp->left);
			q.push(temp->right);
		}
	}
	return ans;
}

//============辅助函数=============
vector<string> my_split(string &str)//这个函数只能分割逗号，功能不是很完善
{
	int len = str.size();
	if (len == 0)
		return {};
	vector<string> ans;
	int begin = 0;
	int end = 0;
	while (begin < len)
	{
		if (str[end] == ',')
		{
			ans.push_back(str.substr(begin, end - begin));
			begin = end + 1;
		}
		end++;
	}
	return ans;
}

//反序列化 需要几个辅助函数 字符串分割和字符串转数字
shared_ptr<TreeNode> deserialize(string data)
{
	vector<string> strs = my_split(data);
	int len = strs.size();
	if (len == 0 || strs[0] == "$")
		return nullptr;

	shared_ptr<TreeNode> root(new TreeNode(stoi(strs[0])));
	queue<shared_ptr<TreeNode> > q; //用队列保证顺序
	q.push(root);
	int i = 1;
	while (i < len)
	{
		//弹出队列头
		auto node = q.front();
		q.pop();
		//重建node的左节点
		if (strs[i] == "$")
			node->left = nullptr;
		else
		{
			node->left = shared_ptr<TreeNode>(new TreeNode(stoi(strs[i])));
			q.push(node->left);
		}
		i++;//注意
		//重建node的右节点
		if (strs[i] == "$")
			node->right = nullptr;
		else
		{
			node->right = shared_ptr<TreeNode>(new TreeNode(stoi(strs[i])));
			q.push(node->right);
		}
		i++;//注意
	}
	return root;
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

//先序遍历树
void PrintTree(shared_ptr<TreeNode> root)
{
	if (root == nullptr)
		return;
	cout << root->val << " ";
	PrintTree(root->left);
	PrintTree(root->right);
}

// ====================测试代码====================
void Test(const char* testName, shared_ptr<TreeNode> pRoot)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	cout << "origin tree is :" << endl;
	PrintTree(pRoot);
	cout << endl;
	
	cout << "serialize:" << endl;
	auto ans = serialize(pRoot);
	cout << ans << endl;

	cout << "deserialize:" << endl;
	auto newroot = deserialize(ans);
	PrintTree(pRoot);
	cout << endl;
	printf("\n\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
	shared_ptr<TreeNode> pNode10 = CreatNode(10);
	shared_ptr<TreeNode> pNode6 = CreatNode(6);
	shared_ptr<TreeNode> pNode14 = CreatNode(14);
	shared_ptr<TreeNode> pNode4 = CreatNode(4);
	shared_ptr<TreeNode> pNode8 = CreatNode(8);
	shared_ptr<TreeNode> pNode12 = CreatNode(12);
	shared_ptr<TreeNode> pNode16 = CreatNode(16);

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
	shared_ptr<TreeNode> pNode5 = CreatNode(5);
	shared_ptr<TreeNode> pNode4 = CreatNode(4);
	shared_ptr<TreeNode> pNode3 = CreatNode(3);
	shared_ptr<TreeNode> pNode2 = CreatNode(2);
	shared_ptr<TreeNode> pNode1 = CreatNode(1);

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
	shared_ptr<TreeNode> pNode1 = CreatNode(1);
	shared_ptr<TreeNode> pNode2 = CreatNode(2);
	shared_ptr<TreeNode> pNode3 = CreatNode(3);
	shared_ptr<TreeNode> pNode4 = CreatNode(4);
	shared_ptr<TreeNode> pNode5 = CreatNode(5);

	ConnectNodes(pNode1, nullptr, pNode2);
	ConnectNodes(pNode2, nullptr, pNode3);
	ConnectNodes(pNode3, nullptr, pNode4);
	ConnectNodes(pNode4, nullptr, pNode5);

	Test("Test3", pNode1);

}

// 树中只有1个结点
void Test4()
{
	shared_ptr<TreeNode> pNode1 = CreatNode(1);
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

