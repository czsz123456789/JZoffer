// question57_1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

//输入一个递增排序数组和一个数字s，在数组中查找两个数
//是的它们的和的正好是s，如果有多对数字的和等于s，输出一对既可

//key:因为是排序数组，直接用双指针前后遍历既可
//若数组没有排序，可用哈希表记录

using namespace std;

bool FindNumsWithSum(vector<int> &nums, int sum, int &ans1, int &ans2)
{
	int len = nums.size();
	if (len <= 1)
		return false;
	int left = 0;
	int right = len - 1;
	
	while (left < right)
	{
		if (nums[left] + nums[right] == sum)
		{
			ans1 = nums[left];
			ans2 = nums[right];
			return true;
		}
		else if (nums[left] + nums[right] < sum)
			left++;
		else if (nums[left] + nums[right] > sum)
			right--;
	}
	return false;
}

// ====================测试代码====================
void Test(const char* testName, vector<int> data,int sum, bool expectedReturn)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	int num1, num2;
	auto result = FindNumsWithSum(data, sum, num1,num2);
	if (result == expectedReturn)
	{
		if (result)
		{
			if (num1 + num2 == sum)
				printf("Passed. \n");
			else
				printf("FAILED. \n");
		}
		else
			printf("Passed. \n");
	}
	else
		printf("FAILED. \n");
}

// 存在和为s的两个数字，这两个数字位于数组的中间
void Test1()
{
	vector<int> data = { 1, 2, 4, 7, 11, 15 };
	Test("Test1", data, 15, true);
}

// 存在和为s的两个数字，这两个数字位于数组的两段
void Test2()
{
	vector<int> data = { 1, 2, 4, 7, 11, 16 };
	Test("Test2", data, 17, true);
}

// 不存在和为s的两个数字
void Test3()
{
	vector<int> data = { 1, 2, 4, 7, 11, 16 };
	Test("Test3", data, 10, false);
}

// 鲁棒性测试
void Test4()
{
	vector<int> data;
	Test("Test4", data, 0, false);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	system("pause");
    return 0;
}

