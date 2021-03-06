// question61.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
//从扑克牌中随机抽5张牌，判断是不是一个顺子
//即这5张牌是不是连续的。2—10为数字本身，A为1，J为11，Q为12，K为13
//大小王可以看成任意数字

using namespace std;

//key:三步走
//1.将数组排序，大小王当做0处理
//2.统计数组中零的个数和相邻数字间的空缺数
//3.若零的个数大于等于空缺数，则true
//若零的个数小于空缺数或者出现“对子”，则false

bool IsContinuous(vector<int> &nums)
{
	int len = nums.size();
	if (len == 0)
		return false;
	sort(nums.begin(), nums.end());

	int index = 0;
	int countzero = 0;
	//统计0的数量
	while (index < len && nums[index] == 0)
	{
		index++;
		countzero++;
	}
	//统计空缺
	int bigindex = index + 1;
	int countgap = 0;
	while (bigindex < len)
	{
		if (nums[index] == nums[bigindex])
			return false;//对子
		countgap += nums[bigindex] - (nums[index] + 1);
		index = bigindex;
		bigindex++;
	}
	return countzero >= countgap;
}

// ====================测试代码====================
void Test(const char* testName, vector<int> &numbers, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (IsContinuous(numbers) == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

void Test1()
{
	vector<int> numbers = { 1, 3, 2, 5, 4 };
	Test("Test1", numbers, true);
}

void Test2()
{
	vector<int> numbers = { 1, 3, 2, 6, 4 };
	Test("Test2", numbers, false);
}

void Test3()
{
	vector<int> numbers = { 0, 3, 2, 6, 4 };
	Test("Test3", numbers, true);
}

void Test4()
{
	vector<int> numbers = { 0, 3, 1, 6, 4 };
	Test("Test4", numbers, false);
}

void Test5()
{
	vector<int> numbers = { 1, 3, 0, 5, 0 };
	Test("Test5", numbers, true);
}

void Test6()
{
	vector<int> numbers = { 1, 3, 0, 7, 0 };
	Test("Test6", numbers, false);
}

void Test7()
{
	vector<int> numbers = { 1, 0, 0, 5, 0 };
	Test("Test7", numbers, true);
}

void Test8()
{
	vector<int> numbers = { 1, 0, 0, 7, 0 };
	Test("Test8", numbers, false);
}

void Test9()
{
	vector<int> numbers = { 3, 0, 0, 0, 0 };
	Test("Test9", numbers, true);
}

void Test10()
{
	vector<int> numbers = { 0, 0, 0, 0, 0 };
	Test("Test10", numbers, true);
}

// 有对子
void Test11()
{
	vector<int> numbers = { 1, 0, 0, 1, 0 };
	Test("Test11", numbers, false);
}

// 鲁棒性测试
void Test12()
{
	vector<int> numbers;
	Test("Test12", numbers,false);
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
	Test12();
	system("pause");
    return 0;
}

