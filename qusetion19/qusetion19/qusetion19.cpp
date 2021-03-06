// qusetion19.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

//用一个函数匹配包含. 和 * 的正则表达式。模式中的.表示任意字符
//*表示它前面的字符可以出现0或任意次
using namespace std;

bool matchCore(string &str, string &pattern, int s_index, int p_index);

bool match(string &str, string &pattern)
{
	int s_len = str.size();
	int p_len = pattern.size();
	if (s_len == 0 && p_len == 0)
		return true;
	if (s_len == 0 || p_len == 0)
		return false;
	return matchCore(str, pattern, 0, 0);
}

bool matchCore(string &str, string &pattern, int s_index, int p_index)
{
	if (s_index == str.size() && p_index == pattern.size())
		return true;
	if (p_index == pattern.size() && s_index != str.size())
		return false;
	//下一个是*
	if (pattern[p_index + 1] == '*')
	{
		//当前匹配或者当前模式字符为'.'
		if (pattern[p_index] == str[s_index] || (pattern[p_index] == '.' && s_index < str.size()))
			return matchCore(str, pattern, s_index + 1, p_index + 2) || //下一个状态
			matchCore(str, pattern, s_index + 1, p_index) ||   //状态不变
			matchCore(str, pattern, s_index, p_index + 2);  //忽略这个*,即*前的字符取零个
		else
			return matchCore(str, pattern, s_index, p_index + 2);  //忽略这个*,即*前的字符取零个
	}
	//当前匹配
	if (pattern[p_index] == str[s_index] || (pattern[p_index] == '.' && s_index < str.size()))
		return matchCore(str, pattern, s_index + 1, p_index + 1);
	
	return false;
}

int main()
{
	string str1("aaa");
	string p1("ab*a");
	cout << match(str1,p1);
	system("pause");
    return 0;
}

