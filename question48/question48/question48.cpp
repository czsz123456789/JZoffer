// question48.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
//请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度
//假设字符串中只包含'a'~'z'的字符。例如，在字符串"arabcacfr"中，最长的不含重复字符
//的子字符串是"acfr"，长度为4

using namespace std;
//此题可以用滑动窗口或者动态规划做，以下分别实现

//动态规划，压缩维度
int longestSubstring1(const string &str)
{
	int len = str.size();
	if (len == 0)
		return 0;
	int maxlen = 1;
	int curlen = 1;
	//dp[i]表示以str[i]结尾的字符串的最长不重复子串长度 可以压缩dp，只用一个变量表示

	//记录每个字符出现的位置
	unordered_map<char, int> m;
	m[str[0]] = 0;
	for (int i = 1; i < len; i++)
	{
		auto iter = m.find(str[i]);
		if (iter == m.end())
			curlen++;
		else
		{
			//i - m[str[i]]表示第i个字符和上次出现在字符串中的位置的距离d
			if (i - m[str[i]] > curlen)//d大于当前长度，此时第i个字符上层出现在dp[i - 1]对应的最长子字符串之前
				curlen++;
			else//d小于等于当前长度，说明第i个字符上次出现在dp[i - 1]对应的最长子字符串中
			{
				maxlen = max(maxlen, curlen);
				curlen = i - m[str[i]];
			}
		}
		m[str[i]] = i;
		maxlen = max(maxlen, curlen);
	}
	return maxlen;
}

//滑动窗口法
int longestSubstring2(const string &str)
{
	int len = str.size();
	if (len == 0)
		return 0;
	//记录字符有无出现
	vector<bool> m(26, false);
	int fast = 0;
	int slow = 0;
	
	int maxlen = 0;
	int curlen = 0;
	while (fast < len)
	{
		//窗口扩张
		while (fast < len && m[str[fast] - 'a'] == false)
		{
			m[str[fast] - 'a'] = true;
			fast++;
			curlen++;
		}
		maxlen = max(maxlen, curlen);
		//窗口收缩
		m[str[slow] - 'a'] = false;
		curlen--;
		slow++;
	}

	return maxlen;
}

// ====================测试代码====================
void testSolution1(const std::string& input, int expected)
{
	int output = longestSubstring1(input);
	if (output == expected)
		std::cout << "Solution 1 passed, with input: " << input << std::endl;
	else
		std::cout << "Solution 1 FAILED, with input: " << input << std::endl;
}

void testSolution2(const std::string& input, int expected)
{
	int output = longestSubstring2(input);
	if (output == expected)
		std::cout << "Solution 2 passed, with input: " << input << std::endl;
	else
		std::cout << "Solution 2 FAILED, with input: " << input << std::endl;
}

void test(const std::string& input, int expected)
{
	testSolution1(input, expected);
	testSolution2(input, expected);
}

void test1()
{
	const std::string input = "abcacfrar";
	int expected = 4;
	test(input, expected);
}

void test2()
{
	const std::string input = "acfrarabc";
	int expected = 4;
	test(input, expected);
}

void test3()
{
	const std::string input = "arabcacfr";
	int expected = 4;
	test(input, expected);
}

void test4()
{
	const std::string input = "aaaa";
	int expected = 1;
	test(input, expected);
}

void test5()
{
	const std::string input = "abcdefg";
	int expected = 7;
	test(input, expected);
}

void test6()
{
	const std::string input = "aaabbbccc";
	int expected = 2;
	test(input, expected);
}

void test7()
{
	const std::string input = "abcdcba";
	int expected = 4;
	test(input, expected);
}

void test8()
{
	const std::string input = "abcdaef";
	int expected = 6;
	test(input, expected);
}

void test9()
{
	const std::string input = "a";
	int expected = 1;
	test(input, expected);
}

void test10()
{
	const std::string input = "";
	int expected = 0;
	test(input, expected);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	system("pause");
    return 0;
}

