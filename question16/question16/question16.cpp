// question16.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;
//实现函数double Power(double base,int exponent)
//求base的exponent次方，不能使用库函数，不用考虑大数问题

//key:1.base为0时 exponent为负 结果非法
//key:2.exponent为负 需要取倒数

double CalPower(double, int);

double Power(double base, int exponent)
{
	//这里可以用全局变量或者 抛出异常作为提醒
	if (base == 0 && exponent < 0)
	{
		cout << "error input";
		return 0;
	}
	//这里认为0的0次方为0 注意
	if (base == 0)
		return 0;
	//次方取绝对值
	int absexponent = exponent;
	if (exponent < 0)
		absexponent = -absexponent;
	//求值
	double ans = CalPower(base,absexponent);
	//取倒
	if (exponent < 0)
		ans = 1 / ans;
	return ans;
}

//用递归减少计算次数 只能计算正数次方
double CalPower(double base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	
	//减小一半计算规模 因为2^32 = 2^16 * 2^16
	double ans = CalPower(base, exponent >> 1);
	ans *= ans;

	if (exponent & 1)//次方数为奇数
		ans *= base; //多乘一次

	return ans;
}

int main()
{
	double base1 = 2.01;
	int exponent1 = -5;
	cout<<Power(base1, exponent1)<<endl;

	double base2 = 0;
	int exponent2 = -5;
	cout << Power(base2, exponent2)<<endl;

	double base3 = -2.01;
	int exponent3 = -5;
	cout << Power(base3, exponent3)<<endl;

	double base4 = 2.01;
	int exponent4 = -5;
	cout << Power(base4, exponent4)<<endl;

	double base5 = 8;
	int exponent5 = 0;
	cout << Power(base5, exponent5)<<endl;

	system("pause");
	return 0;
}

