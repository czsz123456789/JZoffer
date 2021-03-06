// question50_2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

// 题目：请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从
// 字符流中只读出前两个字符"go"时，第一个只出现一次的字符是'g'。当从该字
// 符流中读出前六个字符"google"时，第一个只出现一次的字符是'l'。

using namespace std;
//key:用哈希表记录字符出现的位置，遍历整个哈希表输出位置最前的元素
//元素重复时将值设为-2,初始为-1

void SearchAndPrint(vector<int> &hash,const string &str)
{
	char ch = '\0';
	int minindex = INT_MAX;
	for (int i = 0; i < hash.size(); i++)
	{
		if (hash[i] >= 0 && hash[i] < minindex)
		{
			ch = str[hash[i]];
			minindex = hash[i];
		}
	}
	cout << "first not repeat char: "<<ch << endl;
}
void FirstNotRepeaChar(const string &str)
{
	int len = str.size();
	if (len == 0)
		return;
	//不用map因为不方便初始化
	//记录字符出现的位置
	vector<int> hash(256,-1);

	for (int i = 0; i < len; i++)
	{
		if (hash[str[i]] >= 0)
			hash[str[i]] = -2;
		else
		{
			if (hash[str[i]] == -1)
				hash[str[i]] = i;
		}
		SearchAndPrint(hash, str);
	}
}
int main()
{
	string str("google");
	FirstNotRepeaChar(str);
	system("pause");
    return 0;
}

