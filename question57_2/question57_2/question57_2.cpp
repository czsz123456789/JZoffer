// question57_2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
//输入一个正数s，打印出所有和为s的连续正数序列，至少两个数
//例如输入15，打印[1,2,3,4,5] [4,5,6] [7,8]

using namespace std;
//key:本题使用滑动窗口
void PrintNum(int left, int right);
void FindContinuousSequence(int sum)
{
	if (sum < 3)
		return;
	int left = 1;
	int right = 2;
	int mid = (sum + 1) / 2; //这个上界很重要，根据至少需要两个数求出
	int nowsum = left + right;
	while (left < mid)
	{
		//缩小窗口
		while (nowsum > sum && left < mid)
		{
			nowsum -= left;
			left++;
		}		
		if (nowsum == sum)
			PrintNum(left, right);
		//扩大窗口
		right++;
		nowsum += right;
	}
}
void PrintNum(int left, int right)
{
	for (int i = left; i <= right; i++)
		cout << i << " ";
	cout << endl;
}

// ====================测试代码====================
void Test(const char* testName, int sum)
{
	if (testName != nullptr)
		printf("%s for %d begins: \n", testName, sum);

	FindContinuousSequence(sum);
}

int main()
{
	Test("test1", 1);
	Test("test2", 3);
	Test("test3", 4);
	Test("test4", 9);
	Test("test5", 15);
	Test("test6", 100);
	system("pause");
    return 0;
}

