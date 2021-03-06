// question62.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
//0,1,2...n - 1这n个数字排成一个圆圈，从数字零开始，每次从这个圆圈删除第m个数字
//求输出序列和最后剩下的数字
//经典约瑟夫问题

using namespace std;
//用list模拟环形链表
int LastRemaining(unsigned n, unsigned m)
{
	if (n < 1 || m < 1)
		return -1;
	list<int> circle;//stl库中的链表
	for (int i = 0; i < n; i++)
		circle.push_back(i);

	//用迭代器模拟报数
	auto iter = circle.begin();
	while (circle.size() > 1)
	{
		//报数到n
		for (int i = 1; i < m; i++)
		{
			iter++;
			if (iter == circle.end())
				iter = circle.begin();
		}
		//准备删除该数
		auto next = ++iter;
		if (next == circle.end())
			next = circle.begin();
		
		//输出并删除该数
		iter--;
		cout << *iter << " out" << endl;
		circle.erase(iter);
		iter = next;
	}
	return *iter;
}

//数学法，没太看懂，看书复习
int LastRemainingMath(unsigned n, unsigned m)
{
	if (n < 1 || m < 1)
		return -1;
	int last = 0;
	for (int i = 2; i <= n; i++)
		last = (last + m) % i;
	return last;
}

// ====================测试代码====================
void Test(const char* testName, unsigned int n, unsigned int m, int expected)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	if (LastRemaining(n, m) == expected)
		printf("circle linklist passed.\n");
	else
		printf("circle linklist failed.\n");

	if (LastRemainingMath(n, m) == expected)
		printf("math passed.\n");
	else
		printf("math failed.\n");

	printf("\n");
}

void Test1()
{
	Test("Test1", 5, 3, 3);
}

void Test2()
{
	Test("Test2", 5, 2, 2);
}

void Test3()
{
	Test("Test3", 6, 7, 4);
}

void Test4()
{
	Test("Test4", 6, 6, 3);
}

void Test5()
{
	Test("Test5", 0, 0, -1);
}

void Test6()
{
	Test("Test6", 4000, 997, 1027);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	//Test6();
	system("pause");
    return 0;
}

