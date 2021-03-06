// question58_1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
//输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变，标点符号和普通字符一样处理
//例，输入"I am a student." 则输出 "student. a am I"

using namespace std;
//key:第一步句子中所有字符
//第二步翻转每个单词中的字符
void MyReverse(string &str, int start, int end);

void ReverseSentence(string &str)
{
	int len = str.size();
	if (len == 0)
		return;
	MyReverse(str, 0, len - 1);

	//开始翻转单词
	int i = 0;
	int j = 0;
	while (i < len)
	{
		while (j < len && str[j] != ' ')
			j++;
		MyReverse(str, i, j - 1);
		i = j + 1;
		j = i + 1;
	}
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
void Test(const char* testName, string &input, const string &expectedResult)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    ReverseSentence(input);

    if(input == expectedResult)
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// 功能测试，句子中有多个单词
void Test1()
{
    string input = "I am a student.";
    string expected = "student. a am I";

    Test("Test1", input, expected);
}

// 功能测试，句子中只有一个单词
void Test2()
{
    string input = "Wonderful";
    string expected = "Wonderful";

    Test("Test2", input, expected);
}

// 边界值测试，测试空字符串
void Test3()
{
	string input;
	string expected;
    Test("Test3", input, expected);
}

// 边界值测试，字符串中只有空格
void Test5()
{
    string input = "   ";
    string expected = "   ";
    Test("Test5", input, expected);
}


int main()
{
	Test1();
	Test2();
	Test3();

	Test5();
	system("pause");
    return 0;
}

