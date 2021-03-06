// question38.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
//打印字符串的全排列
//可能涉及重复字母，因此用交换法做

using namespace std;
void my_swap(string &str, int i, int j);
void RecurPermutation(string &str, int index);

void Permutaion(string &str)
{
	int len = str.size();
	if (len == 0)
		return;
	RecurPermutation(str, 0);
}

void RecurPermutation(string &str, int index)
{
	if (index == str.size())
	{
		cout << str<<" ";
		return;
	}
	for (int i = index; i < str.size(); i++)
	{
		//深度优先+回溯
		my_swap(str, index, i);//和后面交换位置
		RecurPermutation(str, index + 1);//递归
		my_swap(str, index, i);//递归完了要交换回来，很重要
	}
}

//定义交换函数
void my_swap(string &str, int i, int j)
{
	auto temp = str[i];
	str[i] = str[j];
	str[j] = temp;
}

//==============测试代码===========
void Test(string name,string &str)
{
	if (name != "")
		cout << name << "begin:" << endl;
	Permutaion(str);
	cout << endl;
}

void Test1()
{
	string str("abc");
	Test("test1", str);
}
void Test2()
{
	string str("a");
	Test("test2", str);
}
void Test3()
{
	string str("eaab");
	Test("test3", str);
}
void Test4()
{
	string str("");
	Test("test4", str);
}
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();

	system("pause");
    return 0;
}

