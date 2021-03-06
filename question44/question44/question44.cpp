// question44.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

//数字以12345678910111213.....的格式序列化到一个字符序列中。在这个序列中，第5位是5，第13位是1
//请写一个函数，求任意第n位的数字
using namespace std;
int beginNum(int base);
int digitAtIndex(int index)
{
	if (index < 1)
	{
		cout << "error input" << endl;
		return 0;
	}
	int base = 1;
	int count = 0;
	while (1)
	{
		//0-9有十个 剩下的都是9*10^(n-1)!!!!!!!!!!
		if (base == 1)
			count = 10;
		else 
			count = 9 * pow(10, base - 1)*base;
		if (count >= index)
			break;
		index -= count;//从index中减去前面的数
		base++;
	}
	//index在base位数字中
	//计算base位数字的开头
	int begin = beginNum(base);
	int number = begin + index / base; //当前数字是开头数字的后面第几个数字
	
	string str = to_string(number);
	int loc = index % base; //number的从左到右第几位

	return (str[loc] - '0');
}

//计算base位数字的开头的数字
int beginNum(int base)
{
	if (base == 1)
		return 0;
	return (int)pow(10, base - 1);
}

// ====================测试代码====================
void test(const char* testName, int inputIndex, int expectedOutput)
{
	if (digitAtIndex(inputIndex) == expectedOutput)
		cout << testName << " passed." << endl;
	else
	{
		//cout << digitAtIndex(inputIndex) << endl;
		cout << testName << " FAILED." << endl;
	}
		
}
int main()
{
	test("Test2", 1, 1);
	test("Test3", 9, 9);
	test("Test4", 10, 1);
	test("Test5", 189, 9);  // 数字99的最后一位，9
	test("Test6", 190, 1);  // 数字100的第一位，1
	test("Test7", 1000, 3); // 数字370的第一位，3
	test("Test8", 1001, 7); // 数字370的第二位，7
	test("Test9", 1002, 0); // 数字370的第三位，0

	system("pause");
    return 0;
}

