// question50_1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
//在字符串中找到第一个只出现一次的字符

using namespace std;
//key：哈希表记录字符出现次数，两次扫描完成

char FirstNotRepeationChar(const string &str)
{
	int len = str.size();
	if (len == 0)
		return '\0';
	//因为字符没有限定范围，这里直接用模板，不用数组的哈希了
	unordered_map<char, int> m;
	for (auto c : str)
		m[c]++;//第一遍统计次数
	
	//第二遍检测第一个只出现一次的字符
	for (int i = 0; i < len; i++)
		if (m[str[i]] == 1)
			return str[i];
	
	return '\0';
}

// ====================测试代码====================
void Test(const string pString, char expected)
{
	if (FirstNotRepeationChar(pString) == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}


int main()
{
	// 常规输入测试，存在只出现一次的字符
	Test("google", 'l');

	// 常规输入测试，不存在只出现一次的字符
	Test("aabccdbd", '\0');

	// 常规输入测试，所有字符都只出现一次
	Test("abcdefg", 'a');

	// 鲁棒性测试，输入""
	Test("", '\0');

	system("pause");
    return 0;
}

