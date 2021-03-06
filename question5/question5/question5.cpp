// question5.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <assert.h>

/*
把字符串中的空格换成"%20"
*/
using namespace std;

void ReplaceBlank(char s[], int len)
{
	//1.用双指针，计算更新后的字符串长度
	//2.从后往前更新

	if (s == nullptr || len <= 0)
		return;

	int currentlen = 0;
	int blankcount = 0;
	int i = 0;
	while (s[i] != '\0')
	{
		currentlen++;
		if (s[i] == ' ')
			blankcount++;
		i++;
	}
	
	//一个空格变为%20，长度增加2
	int newlen = currentlen + 2 * blankcount;

	if (newlen > len)
		return;
	//从后往前更新
	int currentIndex = currentlen;
	int newIndex = newlen;

	while (currentIndex >= 0)
	{
		if (s[currentIndex] == ' ')
		{
			s[newIndex--] = '0';
			s[newIndex--] = '2';
			s[newIndex--] = '%';
		}
		else
			s[newIndex--] = s[currentIndex];
		currentIndex--;
	}
	for (int i = 0; i < newlen; i++)
		cout << s[i];
	cout << endl;
}

void ReplaceBlank(string &s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			s[i] = '%';
			s.insert(i + 1, "20");
		}
	}
	for (auto c : s)
		cout << c;
}

int main()
{
	char test1[100] = "how are you";
	char test2[100] = " how are you ";
	char test3[100] = "   ";
	char test4[100] = "asdasd";
	ReplaceBlank(test1, 100);
	ReplaceBlank(test2, 100);
	ReplaceBlank(test3, 100);
	ReplaceBlank(test4, 100);
	ReplaceBlank(nullptr, 100);


	string tests = " how how how ";
	ReplaceBlank(tests);
	system("pause");
    return 0;
}

