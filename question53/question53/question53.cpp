// question53.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
//查找一个数字在排序数组中出现的次数

using namespace std;
//key：为了保证logn的时间复杂度，用二分查找分别查找这个数在数组中的左右边界
//二分查找详细知识见labuladong


int GetLeft(vector<int> &nums, int target);
int GetRight(vector<int> &nums, int target);

int GetNumOfK(vector<int> &nums, int target)
{
	int len = nums.size();
	if (len == 0)
		return 0;
	int left = GetLeft(nums,target);
	int right = GetRight(nums, target);
	if (left == -1 || right == -1)
		return 0;
	return (right - left) + 1;
}

//求target的左边界
int GetLeft(vector<int> &nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
		else if (nums[mid] == target)
			right = mid - 1;//关键 收缩右侧边界
	}
	//检测出界情况
	//1.target大于数组中所有元素 此时left==nums.size()
	//2.target不在数组中 此时nums[left] != target
	if (left >= nums.size() || nums[left] != target)
		return -1;
	return left;
}

//求target的右边界
int GetRight(vector<int> &nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
		else if (nums[mid] == target)
			left = mid + 1;//收缩左侧边界
	}
	//检测出界情况
	//1.target小于数组中所有元素 此时right < 0
	//2.target不在数组中 此时nums[right] != target
	if (right < 0 || nums[right] != target)
		return -1;
	return right;
}
// ====================测试代码====================
void Test(const char* testName, vector<int> &data, int k, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	int result = GetNumOfK(data, k);
	if (result == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 查找的数字出现在数组的中间
void Test1()
{
	vector<int> data = { 1, 2, 3, 3, 3, 3, 4, 5 };
	Test("Test1", data, 3, 4);
}

// 查找的数组出现在数组的开头
void Test2()
{
	vector<int> data = { 3, 3, 3, 3, 4, 5 };
	Test("Test2", data, 3, 4);
}

// 查找的数组出现在数组的结尾
void Test3()
{
	vector<int> data = { 1, 2, 3, 3, 3, 3 };
	Test("Test3", data, 3, 4);
}

// 查找的数字不存在
void Test4()
{
	vector<int> data = { 1, 3, 3, 3, 3, 4, 5 };
	Test("Test4", data, 2, 0);
}

// 查找的数字比第一个数字还小，不存在
void Test5()
{
	vector<int> data = { 1, 3, 3, 3, 3, 4, 5 };
	Test("Test5", data, 0, 0);
}

// 查找的数字比最后一个数字还大，不存在
void Test6()
{
	vector<int> data = { 1, 3, 3, 3, 3, 4, 5 };
	Test("Test6", data, 6, 0);
}

// 数组中的数字从头到尾都是查找的数字
void Test7()
{
	vector<int> data = { 3, 3, 3, 3 };
	Test("Test7", data, 3, 4);
}

// 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
void Test8()
{
	vector<int> data = { 3, 3, 3, 3 };
	Test("Test8", data, 4, 0);
}

// 数组中只有一个数字，是查找的数字
void Test9()
{
	vector<int> data = { 3 };
	Test("Test9", data, 3, 1);
}

// 数组中只有一个数字，不是查找的数字
void Test10()
{
	vector<int> data = { 3 };
	Test("Test10", data, 4, 0);
}

// 鲁棒性测试，数组空指针
void Test11()
{
	vector<int> data;
	Test("Test11", data, 0, 0);
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
	Test10();
	Test11();

	system("pause");
    return 0;
}

