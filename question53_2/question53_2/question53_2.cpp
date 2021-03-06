// question53_2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
//一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0~n-1之内。
//在范围0~n-1内的n个数字中有且只有一个数字不在该数组中，找出这个数字
using namespace std;

int GetMissingNum(vector<int> &nums)
{
	int len = nums.size();
	if (len == 0)
		return -1;
	int left = 0;
	int right = len - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == mid) //元素和下标相等时，往后找
			left = mid + 1;
		else
		{
			if (mid == 0 || nums[mid - 1] == mid - 1)//元素和下标不相等时，判断该数的前一个数和下标是否相等
				return mid;
			right = mid - 1;
		}
	}
	return -1;
}

// ====================测试代码====================
void Test(const char* testName, vector<int> numbers,int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	int result = GetMissingNum(numbers);
	if (result == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 缺失的是第一个数字0
void Test1()
{
	vector<int> numbers = { 1, 2, 3, 4, 5 };
	int expected = 0;
	Test("Test1", numbers,  expected);
}

// 缺失的是最后一个数字
void Test2()
{
	vector<int> numbers = { 0, 1, 2, 3, 4 ,6};
	int expected = 5;
	Test("Test2", numbers, expected);
}

// 缺失的是中间某个数字0
void Test3()
{
	vector<int> numbers = { 0, 1, 2, 4, 5 };
	int expected = 3;
	Test("Test3", numbers, expected);
}

// 数组中只有一个数字，缺失的是第一个数字0
void Test4()
{
	vector<int> numbers = { 1 };
	int expected = 0;
	Test("Test4", numbers,  expected);
}


// 空数组
void Test6()
{
	vector<int> numbers;
	int expected = -1;
	Test("Test6", numbers,expected);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();

	Test6();
	system("pause");
    return 0;
}

