// question43.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

//输入一个整数n，求1~n这n个整数的十进制表示中1出现的次数
using namespace std;
//key：利用递归不断缩小问题规模
//PS:这个题我没懂
int NumberOf1(string &str, int index);
int NumberOf1Between1AndN(unsigned n)
{
	if (n <= 0)
		return 0;
	string str = to_string(n);
	return NumberOf1(str,0);
}

int NumberOf1(string &str,int index)
{
	if (index == str.size() - 1 && str[index] == '0')
		return 0;
	if (index == str.size() - 1 && str[index] > '0')
		return 1;
	//计算当前最高位上1出现的次数
	int numFirst = 0;
	int len = str.size() - index;//最高位的深度 len越大代表位数越高
	if (str[index] > '1') //最高位大于1，则最高位出现1的次数等于最高位的权重
		numFirst = pow(10, len - 1);
	else if(str[index] == '1')//最高位为1 则出现1的次数取决于低位的大小
	{
		int ans = 0;
		for (int i = index + 1; i < str.size(); i++)
			ans = ans * 10 + (str[i] - '0');
		numFirst = ans + 1;
	}
	//除第一位以外的数量
	int numOther = (str[index] - '0') * (len - 1) * pow(10, len - 2);
	//低位中的数量
	int numRecur = NumberOf1(str, index + 1);

	return numFirst + numOther + numRecur;
}

//==============测试代码===========
void Test(const char* testName, int n, int expected)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	if (NumberOf1Between1AndN(n) == expected)
		printf("Solution1 passed.\n");
	else
	{
		printf("Solution1 failed.\n");
		cout << NumberOf1Between1AndN(n);
	}
		

	printf("\n");
}
void FullTest()
{
	Test("test1", 1, 1);
	Test("test2", 5, 1);
	Test("test3", 10, 2);
	Test("test4", 55, 16);
	Test("test5", 99, 20);
	Test("test6", 10000, 4001);
	Test("test7", 21345, 18821);
	Test("test8", 0, 0);
}

int main()
{
	FullTest();
	system("pause");
    return 0;
}

