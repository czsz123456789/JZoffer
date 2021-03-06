// question39.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字

using namespace std;
//复杂度为n 比较巧的方法，抵消思想
//因为如果存在一个数出现的次数超过数组长度的一半，通过不同数的抵消，最后剩下来的一定是这个数
bool CheckInvalid(vector<int> &nums, int target);

int solution1(vector<int> &nums)
{
	int len = nums.size();
	if (len == 0)
	{
		cout << "invalid input" << endl;
		return 0;
	}
	int ans = nums[0];
	int count = 1;
	for (int i = 1; i < len; i++)
	{
		if (nums[i] == ans)
			count++;
		else
			count--;
		if (count == 0)
		{
			ans = nums[i];
			count = 1;
		}
	}
	//检查最后得到的数是否满足条件，防止无效输入
	bool flag = CheckInvalid(nums, ans);
	if (!flag)
	{
		cout << "invalid input" << endl;
		return 0;
	}
	return ans;
}
bool CheckInvalid(vector<int> &nums, int target)
{
	int len = nums.size();
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (nums[i] == target)
			count++;
	}
	return count > len / 2;
}

//如果存在一个数出现的次数超过数组长度的一半，那数组的中位数也一定是这个数
//此方法涉及排序，会修改数组内容
int MyQuick(vector<int> &nums, int begin, int end);
int solution2(vector<int> &nums)
{
	//分治法 快速排序思想 求中位数
	int len = nums.size();
	if (len == 0)
	{
		cout << "invalid input" << endl;
		return 0;
	}
	int mid = len / 2;//中位数下标
	int start = 0;
	int end = len - 1;
	int index = MyQuick(nums, start, end);

	while (index != mid)
	{
		if (index < mid)
			start = index + 1;
		else if (index > mid)
			end = index - 1;
		else if (index == mid)
			break;
		index = MyQuick(nums, start, end);
	}
	int ans = nums[mid];
	bool flag = CheckInvalid(nums, ans);
	if (!flag)
	{
		cout << "invalid input" << endl;
		return 0;
	}
	return ans;
}

int MyQuick(vector<int> &nums,int begin,int end)
{
	//基准
	int current = nums[begin];
	int i = begin;
	int j = end;
	while (i < j)
	{
		while (i < j && nums[j] > current)
			j--;
		while (i < j && nums[i] <= current)
			i++;
		if (i == j)
			break;
		//交换
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
	//交换游标和结束位置
	nums[begin] = nums[i];
	nums[i] = current;

	//返回结束位置
	return i;
}

void Test(const char* name,vector<int> &nums,int expected)
{
	if (name)
		cout << name << "  begin" << endl;
	if (expected == solution1(nums))
		cout << name << "  solution1 passed" << endl;
	if (expected == solution2(nums))
		cout << name << "  solution1 passed" << endl;
	cout << endl << endl;
}
void Test1()
{
	vector<int> data = { 1,2,3,4,5,7,7,7,7,7,7 };
	Test("test1", data, 7);
}
void Test2()
{
	vector<int> data = { 0,1,0,5,0 };
	Test("test2", data, 0);
}
void Test3()
{
	vector<int> data = { 1,2,3,4,5};
	Test("test3", data, 0);
}
void Test4()
{
	vector<int> data = { 1};
	Test("test4", data, 1);
}
void Test5()
{
	vector<int> data;
	Test("test5", data, 0);
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

