// question59_1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <deque>
// 给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
// 如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
// 滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，

using namespace std;

vector<int> maxInWindows(const vector<int> &nums, unsigned size)
{
	int len = nums.size();
	if (len < size || size < 1)
		return {};
	vector<int> ans;
	deque<int> index;//存数组下标 最大值的下标保留在队列最前 后面是递减队列
	//队列达到size长度
	for (unsigned i = 0; i < size; i++)
	{
		while (!index.empty() && nums[i] > nums[index.back()])
			index.pop_back();
		
		index.push_back(i);
	}
	for (int i = size; i < nums.size(); i++)
	{
		//先输出
		ans.push_back(nums[index.front()]);
		//维护递减队列
		while (!index.empty() && nums[i] > nums[index.back()])
			index.pop_back();
		//窗口移动
		//若最大值正好被移出
		if (!index.empty() && index.front() <= i - size)
			index.pop_front();

		//插入当前下标到队尾
		index.push_back(i);
	}
	ans.push_back(nums[index.front()]);
	return ans;
}

// ====================测试代码====================
void Test(const char* testName, const vector<int>& num, unsigned int size, const vector<int>& expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	vector<int> result = maxInWindows(num, size);

	vector<int>::const_iterator iterResult = result.begin();
	vector<int>::const_iterator iterExpected = expected.begin();
	while (iterResult < result.end() && iterExpected < expected.end())
	{
		if (*iterResult != *iterExpected)
			break;

		++iterResult;
		++iterExpected;
	}

	if (iterResult == result.end() && iterExpected == expected.end())
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

void Test1()
{
	int num[] = { 2, 3, 4, 2, 6, 2, 5, 1 };
	vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

	int expected[] = { 4, 4, 6, 6, 6, 5 };
	vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

	unsigned int size = 3;

	Test("Test1", vecNumbers, size, vecExpected);
}

void Test2()
{
	int num[] = { 1, 3, -1, -3, 5, 3, 6, 7 };
	vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

	int expected[] = { 3, 3, 5, 5, 6, 7 };
	vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

	unsigned int size = 3;

	Test("Test2", vecNumbers, size, vecExpected);
}

// 输入数组单调递增
void Test3()
{
	int num[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
	vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

	int expected[] = { 7, 9, 11, 13, 15 };
	vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

	unsigned int size = 4;

	Test("Test3", vecNumbers, size, vecExpected);
}

// 输入数组单调递减
void Test4()
{
	int num[] = { 16, 14, 12, 10, 8, 6, 4 };
	vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

	int expected[] = { 16, 14, 12 };
	vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

	unsigned int size = 5;

	Test("Test4", vecNumbers, size, vecExpected);
}

// 滑动窗口的大小为1
void Test5()
{
	int num[] = { 10, 14, 12, 11 };
	vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

	int expected[] = { 10, 14, 12, 11 };
	vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

	unsigned int size = 1;

	Test("Test5", vecNumbers, size, vecExpected);
}

// 滑动窗口的大小等于数组的长度
void Test6()
{
	int num[] = { 10, 14, 12, 11 };
	vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

	int expected[] = { 14 };
	vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

	unsigned int size = 4;

	Test("Test6", vecNumbers, size, vecExpected);
}

// 滑动窗口的大小为0
void Test7()
{
	int num[] = { 10, 14, 12, 11 };
	vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

	vector<int> vecExpected;

	unsigned int size = 0;

	Test("Test7", vecNumbers, size, vecExpected);
}

// 滑动窗口的大小大于输入数组的长度
void Test8()
{
	int num[] = { 10, 14, 12, 11 };
	vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));

	vector<int> vecExpected;

	unsigned int size = 5;

	Test("Test8", vecNumbers, size, vecExpected);
}

// 输入数组为空
void Test9()
{
	vector<int> vecNumbers;
	vector<int> vecExpected;

	unsigned int size = 5;

	Test("Test9", vecNumbers, size, vecExpected);
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

