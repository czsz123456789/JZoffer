// question51.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
//在数组中的两个数字，如果前面一个数字大于后面的数字，
//则这两个数字组成一个逆序对。输入一个数组，求这个数组中的逆序对的总数目
//例如数组{7,5,6,4}中，一共存在5个逆序对。

using namespace std;
//key：归并排序的同时计算逆序对数量
int InversePairs(vector<int> &nums, int start, int end)
{
	if (start >= end)
		return 0;
	int mid = (start + end) / 2;
	int left = InversePairs(nums, start, mid);
	int right = InversePairs(nums, mid + 1, end);

	//合并
	vector<int> temp(end - start + 1,0);
	int count = 0;
	//指针从尾部开始 关键
	int i = mid;
	int j = end;
	int index = temp.size() - 1; 
	while (i >= start && j >= mid + 1)
	{
		if (nums[i] > nums[j])
		{
			temp[index--] = nums[i--];
			count += j - mid ; //这一步是求逆序的关键
		}
		else
			temp[index--] = nums[j--];
	}
	//处理剩下的数
	while(i >= start)
		temp[index--] = nums[i--];
	while (j >= mid + 1)
		temp[index--] = nums[j--];

	//复制回原数组
	for (int m = 0; m < temp.size(); m++)
		nums[start + m] = temp[m];
	
	return count + left + right;
}

// ====================测试代码====================
void Test(const char* testName, vector<int> &data,int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (InversePairs(data,0,data.size() - 1) == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

void Test1()
{
	vector<int> data = { 1, 2, 3, 4, 7, 6, 5 };
	int expected = 3;

	Test("Test1", data,  expected);
}

// 递减排序数组
void Test2()
{
	vector<int> data = { 6, 5, 4, 3, 2, 1 };
	int expected = 15;

	Test("Test2", data,  expected);
}

// 递增排序数组
void Test3()
{
	vector<int> data = { 1, 2, 3, 4, 5, 6 };
	int expected = 0;

	Test("Test3", data,  expected);
}

// 数组中只有一个数字
void Test4()
{
	vector<int> data = { 1 };
	int expected = 0;

	Test("Test4", data,  expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
	vector<int> data = { 1, 2 };
	int expected = 0;

	Test("Test5", data,  expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
	vector<int> data = { 2, 1 };
	int expected = 1;

	Test("Test6", data,  expected);
}

// 数组中有相等的数字
void Test7()
{
	vector<int> data = { 1, 2, 1, 2, 1 };
	int expected = 3;

	Test("Test7", data,  expected);
}

void Test8()
{
	int expected = 0;
	vector<int> data;
	Test("Test8", data,expected);
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

	system("pause");
    return 0;
}

