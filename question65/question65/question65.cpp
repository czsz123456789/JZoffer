// question65.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
//求两个整数之和，要求不能使用+-*/四则运算符号

//key：用位运算代替加法
//两数异或的结果就是二进制不进位的加法
//先将两数异或，然后求进位
//求进位是用与运算然后左移

//这个思路非常牛逼 记住
using namespace std;
int Add(int num1, int num2)
{
	int sum = 0;
	int carry = 0;
	do
	{
		sum = num1 ^ num2;
		carry = (num1 & num2) << 1;
		num1 = sum;
		num2 = carry;
	} while (num2 != 0);
	
	return num1;
}

int main()
{
	cout << Add(9, 9) << endl;
	cout << Add(0, 0) << endl;
	cout << Add(-1, -1) << endl;
	cout << Add(-5, 9) << endl;

	system("pause");
    return 0;
}

