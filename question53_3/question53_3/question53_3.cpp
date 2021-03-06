// question53_3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
//假设一个单调递增的数组里的每个元素都是整数并且是唯一的
//请找出数组中任意一个数值等于其下标的元素,返回下标

using namespace std;

int GetNumSameAsIndex(vector<int> &nums)
{
	int len = nums.size();
	if (len == 0)
		return -1;
	int left = 0;
	int right = len - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == mid)
			return mid;
		else if (nums[mid] < mid)
			left = mid + 1;
		else if (nums[mid] > mid)
			right = mid - 1;
	}
	return -1;
}

// ====================测试代码====================
void Test(const char* testName, vector<int> numbers, int expected)
{
	if (GetNumSameAsIndex(numbers) == expected)
		printf("%s passed.\n", testName);
	else
		printf("%s FAILED.\n", testName);
}

void Test1()
{
	vector<int> numbers = { -3, -1, 1, 3, 5 };
	int expected = 3;
	Test("Test1", numbers, expected);
}

void Test2()
{
	vector<int> numbers = { 0, 1, 3, 5, 6 };
	int expected = 0;
	Test("Test2", numbers, expected);
}

void Test3()
{
	vector<int> numbers = { -1, 0, 1, 2, 4 };
	int expected = 4;
	Test("Test3", numbers, expected);
}

void Test4()
{
	vector<int> numbers = { -1, 0, 1, 2, 5 };
	int expected = -1;
	Test("Test4", numbers, expected);
}

void Test5()
{
	vector<int> numbers = { 0 };
	int expected = 0;
	Test("Test5", numbers, expected);
}

void Test6()
{
	vector<int> numbers = { 10 };
	int expected = -1;
	Test("Test6", numbers, expected);
}

void Test7()
{
	vector<int> numbers;
	Test("Test7", numbers,-1);
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

