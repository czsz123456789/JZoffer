// question20.cpp: 定义控制台应用程序的入口点。
//
/*
实现一个函数用来判断字符串是否表示数值（包括整数和小数）
。例 +100,、5e2、-123、3.1416、-1e-16 都表示数值
12e、1a3.14、1.2.3、+-5、12e5.4 都 不是数值
*/

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
//key：表示数值的字符串模式为A[.[B]][e|EC]或者.B[e|EC]
bool scanUnsignedInterger(string &str, unsigned &index);
bool scanInterger(string &str, unsigned &index);

bool IsNumber(string &str)
{
	if (str.size() == 0)
		return false;
	unsigned index = 0;
	//先扫描整数部分
	bool num = scanInterger(str,index);
	
	//小数部分
	if (str[index] == '.')
	{
		index++;

		//小数可以没有整数部分，小数点后可以没有数字
		num = num || scanUnsignedInterger(str, index);
	}

	//指数部分
	if (str[index] == 'e' || str[index] == 'E')
	{
		index++;

		//e的前后都一定要有整数
		num = num && scanUnsignedInterger(str, index);
	}
	if (num && index == str.size())
		return true;
	return false;
}

bool scanInterger(string &str, unsigned &index)
{
	if (str[index] == '+' || str[index] == '-')
		index++;
	return scanUnsignedInterger(str, index);
}

bool scanUnsignedInterger(string &str, unsigned &index)
{
	bool flag = false;
	unsigned before = index;
	while (index < str.size() && str[index] >= '0' && str[index] <= '9')
		index++;
	//存在整数
	if (index > before)
		flag = true;
	return flag;
}

int main()
{
	string str1("1.2.3");
	string str2("5e2");
	string str3("12e+5.4");
	string str4("233.");

	cout << IsNumber(str1)<<endl;
	cout << IsNumber(str2) << endl;
	cout << IsNumber(str3) << endl;
	cout << IsNumber(str4) << endl;
	system("pause");
    return 0;
}

