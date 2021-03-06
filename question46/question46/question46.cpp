// question46.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
//给定一个数字，我们按照以下规则把它翻译为字符串：0翻译成“a“，1翻译成”b“
//25翻译成”z“。一个数字可能有多个翻译。例如，12258有五种翻译。实现一个函数，计算一个数字有多少种不同的翻译方法

//key：基本动态规划题
//定义dp[i]为以第i个数结尾的有多少中翻译方法
//分析可知当第i个数可以和前一个数组成合法数字时(nums[i - 1] == 1 或者 (nums[i - 1] == 2 且 nums[i] <= 5))
//dp[i] = dp[i - 1] + dp[i - 2] 解释：最后一位有两种组合方式，和前一位组合或者自己单独作为一个数
//否则 dp[i] = dp[i - 1]

using namespace std;
int My_dp(const string &str);
int GetTranslationCount(int number)
{
	if (number < 0)
		return 0;
	//转化为字符串
	return My_dp(to_string(number));
}
//动态规划过程
int My_dp(const string &str)
{
	int len = str.size();
	vector<int> dp(len, 0);
	dp[0] = 1;
	for (int i = 1; i < len; i++)
	{
		if (str[i - 1] == '1' || (str[i - 1] == '2' && str[i] <= '5'))
		{
			if (i == 1)
				dp[i] = 2;
			else
				dp[i] = dp[i - 1] + dp[i - 2];
		}
		else
			dp[i] = dp[i - 1];
	}
	return dp[len - 1];
}

// ====================测试代码====================
void Test(const string& testName, int number, int expected)
{
	if (GetTranslationCount(number) == expected)
		cout << testName << " passed." << endl;
	else
		cout << testName << " FAILED." << endl;
}

void Test1()
{
	int number = 0;
	int expected = 1;
	Test("Test1", number, expected);
}

void Test2()
{
	int number = 10;
	int expected = 2;
	Test("Test2", number, expected);
}

void Test3()
{
	int number = 125;
	int expected = 3;
	Test("Test3", number, expected);
}

void Test4()
{
	int number = 126;
	int expected = 2;
	Test("Test4", number, expected);
}

void Test5()
{
	int number = 426;
	int expected = 1;
	Test("Test5", number, expected);
}

void Test6()
{
	int number = 100;
	int expected = 2;
	Test("Test6", number, expected);
}

void Test7()
{
	int number = 101;
	int expected = 2;
	Test("Test7", number, expected);
}

void Test8()
{
	int number = 12258;
	int expected = 5;
	Test("Test8", number, expected);
}

void Test9()
{
	int number = -100;
	int expected = 0;
	Test("Test9", number, expected);
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

