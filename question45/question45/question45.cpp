// question45.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//输入一个正整数数组，把数组中所有数字拼接起来排成一个数
//打印能拼接出的所有数字中最小的一个。例如输入数组{3,32,321}
//则打印321323

//key:找到一个排序规则，数组根据这个规则排序后能得到最小数字
//比较两个数字m、n，判断哪个数字应该放在前面
//为了防止数据溢出，使用字符串表示数据
//原理：两个字符串自左向右逐个字符相比（按ASCII值大小相比较）
using namespace std;
bool cmp(string &s1, string &s2);
void PrintMinNumber(vector<int> &nums)
{
	//将数字数组转化为字符串数组
	vector<string> strnums;
	for (auto num : nums)
		strnums.push_back(to_string(num));
	//将字符串按从小到大排序
	sort(strnums.begin(), strnums.end(), cmp);
	for (auto strnum : strnums)
		cout << strnum;
	cout << endl;
}

bool cmp(string &s1, string &s2)//这个比较函数很关键
{
	return s1 + s2 < s2 + s1;
}

// ====================测试代码====================
void Test(const char* testName, vector<int> &nums, const string expectedResult)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	if (expectedResult != "")
		cout << "Expected result is:     " << expectedResult << endl;

	printf("Actual result is: \t");
	PrintMinNumber(nums);

	printf("\n");
}

void Test1()
{
	vector<int> nums = { 3, 5, 1, 4, 2 };
	Test("Test1", nums, "12345");
}

void Test2()
{
	vector<int> nums = { 3, 32, 321 };
	Test("Test2", nums, "321323");
}

void Test3()
{
	vector<int> nums = { 3, 323, 32123 };
	Test("Test3", nums, "321233233");
}

void Test4()
{
	vector<int> nums = { 1, 11, 111 };
	Test("Test4", nums, "111111");
}

// 数组中只有一个数字
void Test5()
{
	vector<int> nums = { 321 };
	Test("Test5", nums, "321");
}

void Test6()
{
	vector<int> nums;
	Test("Test6", nums, "Don't print anything.");
}


int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	system("pause");
    return 0;
}

