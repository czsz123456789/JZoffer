// question56_2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
//在一个数组中除一个数字只出现一次之外，其他数字都出现了三次
//请找出那个只出现一次的数字

using namespace std;
//key：把数组中所有数字的二进制表示的每一位都加起来
//如果某一位的和能被3整除，那么那个只出现一次的数字二进制表示中对应的那一位就是0，否则是1

int FindNumAppearingOnce(vector<int> &nums)
{
	int len = nums.size();
	if (len == 0)
	{
		cout << "error input" << endl;
		return 0;
	}
	vector<int> bitsum(32, 0);
	for (int i = 0; i < len; i++)
	{
		int bitMask = 1;
		for (int j = 31; j >= 0; j--)
		{
			int temp = nums[i] & bitMask;
			if (temp != 0)
				bitsum[j]++;
			bitMask = bitMask << 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < 32; i++)
	{
		ans = ans << 1;
		ans += bitsum[i] % 3;
	}
	return ans;
}

// ====================测试代码====================
void Test(const char* testName, vector<int> numbers, int expected)
{
	int result = FindNumAppearingOnce(numbers);
	if (result == expected)
		printf("%s passed.\n", testName);
	else
		printf("%s FAILED.\n", testName);
}

// 所有数字都是正数，唯一的数字是最小的
void Test1()
{
	vector<int> numbers = { 1, 1, 2, 2, 2, 1, 3 };
	int expected = 3;
	Test("Test1", numbers, expected);
}

// 所有数字都是正数，唯一的数字的大小位于中间
void Test2()
{
	vector<int> numbers = { 4, 3, 3, 2, 2, 2, 3 };
	int expected = 4;
	Test("Test2", numbers, expected);
}

// 所有数字都是正数，唯一的数字是最大的
void Test3()
{
	vector<int> numbers = { 4, 4, 1, 1, 1, 7, 4 };
	int expected = 7;
	Test("Test3", numbers, expected);
}

// 唯一的数字是负数
void Test4()
{
	vector<int> numbers = { -10, 214, 214, 214 };
	int expected = -10;
	Test("Test4", numbers, expected);
}

// 除了唯一的数字，其他数字都是负数
void Test5()
{
	vector<int> numbers = { -209, 3467, -209, -209 };
	int expected = 3467;
	Test("Test5", numbers, expected);
}

// 重复的数字有正数也有负数
void Test6()
{
	vector<int> numbers = { 1024, -1025, 1024, -1025, 1024, -1025, 1023 };
	int expected = 1023;
	Test("Test6", numbers, expected);
}

// 所有数字都是负数
void Test7()
{
	vector<int> numbers = { -1024, -1024, -1024, -1023 };
	int expected = -1023;
	Test("Test7", numbers, expected);
}

// 唯一的数字是0
void Test8()
{
	vector<int> numbers = { -23, 0, 214, -23, 214, -23, 214 };
	int expected = 0;
	Test("Test8", numbers, expected);
}

// 除了唯一的数字，其他数字都是0
void Test9()
{
	vector<int> numbers = { 0, 3467, 0, 0, 0, 0, 0, 0 };
	int expected = 3467;
	Test("Test9", numbers, expected);
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

