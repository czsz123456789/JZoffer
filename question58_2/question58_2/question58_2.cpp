// question58_2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部
//定义函数实现这个功能
//例如，输入字符串"abcdefg"和数字2 函数返回 "cdefgab"
using namespace std;
//key：最直观的想法是把字符串重新拼接，用一个中转字符串即可
//但此题也可以用旋转做，比较巧妙
void MyReverse(string &str, int start, int end);

string LeftRotateString(string &str, int n)
{
	int len = str.size();
	if (len < n)
		return "";
	string ans(str);
	//三次翻转
	//1.翻转[0,n - 1]
	MyReverse(ans, 0, n - 1);
	//2.翻转[n,len - 1]
	MyReverse(ans, n, len - 1);
	//3.翻转[0.len - 1]
	MyReverse(ans, 0, len - 1);

	return ans;
}

//翻转str[start,end]
void MyReverse(string &str, int start, int end)
{
	if (start < 0 || end >= str.size())
		return;
	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

// ====================测试代码====================
void Test(const char* testName, string &input, int num, const string &expectedResult)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	auto result = LeftRotateString(input,num);

	if (result == expectedResult)
		printf("Passed.\n\n");
	else
		printf("Failed.\n\n");
}

// 功能测试
void Test1()
{
	string input = "abcdefg";
	string expected = "cdefgab";

	Test("Test1", input, 2, expected);
}

// 边界值测试
void Test2()
{
	string input = "abcdefg";
	string expected = "bcdefga";

	Test("Test2", input, 1, expected);
}

// 边界值测试
void Test3()
{
	string input = "abcdefg";
	string expected = "gabcdef";

	Test("Test3", input, 6, expected);
}

// 鲁棒性测试
void Test4()
{
	string input;
	string expected;
	Test("Test4", input, 6, expected);
}

// 鲁棒性测试
void Test5()
{
	string input = "abcdefg";
	string expected = "abcdefg";

	Test("Test5", input, 0, expected);
}

// 鲁棒性测试
void Test6()
{
	string input = "abcdefg";
	string expected = "abcdefg";

	Test("Test6", input, 7, expected);
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

