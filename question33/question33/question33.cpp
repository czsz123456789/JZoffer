// question33.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
//输入一个整数数组，判断该数组是不是某二叉搜索树的后续遍历

using namespace std;
bool VerifySquenceOfBST(vector<int> &nums,int start,int end)
{
	int len = nums.size();
	if (len == 0)
		return false;
	//最后一个节点是根节点，从start开始根据大小将数组分为左右子树
	int root = nums[end];
	int indexl = start;
	//左子树
	for (indexl = start; indexl < end; indexl++)
		//左子树结束
		if (nums[indexl] > root)
			break;
	//右子树
	int indexr = indexl;
	for (; indexr < end; indexr++)
		if (nums[indexr] < root) //右子树存在小于根节点的，直接返回false
			return false;
	//递归左右子树，如果存在
	bool left = true;
	if (indexl - 1 > start)
		left = VerifySquenceOfBST(nums, start, indexl - 1);
	bool right = true;
	if (indexl < end)
		right = VerifySquenceOfBST(nums, indexl, end - 1);
	return left && right;
	
}

// ====================测试代码====================
void Test(const char* testName, vector<int> &sequence, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);
	int len = sequence.size();
	if (VerifySquenceOfBST(sequence, 0,len - 1) == expected)
		printf("passed.\n");
	else
		printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
	vector<int> data = { 4, 8, 6, 12, 16, 14, 10 };
	Test("Test1", data,  true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
	vector<int> data = { 4, 6, 7, 5 };
	Test("Test2", data,  true);
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
void Test3()
{
	vector<int> data = { 1, 2, 3, 4, 5 };
	Test("Test3", data,  true);
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
void Test4()
{
	vector<int> data = { 5, 4, 3, 2, 1 };
	Test("Test4", data, true);
}

// 树中只有1个结点
void Test5()
{
	vector<int> data = { 5 };
	Test("Test5", data, true);
}

void Test6()
{
	vector<int> data = { 7, 4, 6, 5 };
	Test("Test6", data,  false);
}

void Test7()
{
	vector<int> data = { 4, 6, 12, 8, 16, 14, 10 };
	Test("Test7", data,  false);
}
void Test8()
{
	vector<int> data = { 1,2,5,10,6,9,4,3 };
	Test("Test8", data, false);
}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	//Test7();
	Test8();
	system("pause");
    return 0;
}

