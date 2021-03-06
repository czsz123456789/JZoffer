// question56.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
//一个整形数组中除两个数字之外，其他数字都出现了两次，找出这两个数字
//要求时间复杂度为o（n） 空间复杂度为o（1）

using namespace std;
//key:本题要使用异或的方法。
//如果只有一个数只出现一次，将整个数组按位异或，最后的结果就是只出现一次的数
//现在有两个数只出现一次，如果我们将这两个数分别放到两个数组中，再对这两个数组求异或，就能得到这两个数
//首先将整个数组异或，结果就是这两个数异或的结果，结果必不为零
//找到结果二进制任意一位为1的位置，在该位这两个数必不相同
//根据该位为 0 或 1 将数组分成两半
//之后可解
bool IsBit1(int num, unsigned index);
unsigned FindFirstBit1(int num);
vector<int> TwoNumAppearOnce(vector<int> nums)
{
	int len = nums.size();
	if (len == 0)
		return {};
	
	int res = 0;
	for (int i = 0; i < len; i++)
		res ^= nums[i];
	//找res中第一个为1的位
	auto indexof1 = FindFirstBit1(res);

	vector<int> ans;
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < len; i++)
	{
		//判断对应位是否为1，分离两个数组
		if (IsBit1(nums[i], indexof1))
			num1 ^= nums[i];
		else
			num2 ^= nums[i];
	}
	ans.push_back(num1);
	ans.push_back(num2);
	return ans;
}

unsigned FindFirstBit1(int num)
{
	int index = 0;
	unsigned help = 1;
	while (index < 8*sizeof(int))
	{
		if (num & help)
			break;
		help = help << 1;
		index++;
	}
	return index;
}

bool IsBit1(int num, unsigned index)
{
	unsigned help = 1;
	help = help << index;
	return (num & help);
}

// ====================测试代码====================
void Test(const char* testName, vector<int> data, int expected1, int expected2)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	auto ans = TwoNumAppearOnce(data);
	if (ans.size() < 2)
	{
		printf("Failed.\n\n");
		return;
	}
	int result1 = ans[0];
	int result2 = ans[1];
	if ((expected1 == result1 && expected2 == result2) ||
		(expected2 == result1 && expected1 == result2))
		printf("Passed.\n\n");
	else
		printf("Failed.\n\n");
}

void Test1()
{
	vector<int> data = { 2, 4, 3, 6, 3, 2, 5, 5 };
	Test("Test1", data, 4, 6);
}

void Test2()
{
	vector<int> data = { 4, 6 };
	Test("Test2", data,  4, 6);
}

void Test3()
{
	vector<int> data = { 4, 6, 1, 1, 1, 1 };
	Test("Test3", data,  4, 6);
}


int main()
{
	Test1();
	Test2();
	Test3();
	system("pause");
    return 0;
}

