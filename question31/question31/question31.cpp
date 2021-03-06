// question31.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <vector>
#include <string>
//输入两个整数序列，第一个序列表示栈的压入顺序，判断第二个序列是否为该栈的弹出顺序
//假设压入栈的所有数字均不相同(这个题有意思)

using namespace std;

//key:建立辅助栈，模拟出入过程
bool IsPopOrder(vector<int> &PushNum, vector<int> &PopNum)
{
	int lenpush = PushNum.size();
	int lenpop = PopNum.size();
	if (lenpop != lenpush)
		return false;
	if (lenpush == 0)
		return true;

	//建立辅助栈，模拟出入过程
	stack<int> s;
	int index_push = 0;
	int index_pop = 0;
	//对出栈序列进行扫描
	while (index_pop < lenpop)
	{
		//如果栈顶元素不等于当前出栈元素
		while(s.empty() || s.top() != PopNum[index_pop])
		{
			//入栈序列没有了，依旧和当前出栈元素不匹配
			if (index_push >= lenpush)
				return false;
			//入栈序列当前元素入栈
			s.push(PushNum[index_push++]);
		}
		//模拟出栈，出栈元素后移
		s.pop();
		index_pop++;
	}
	//完成出栈过程
	if (s.empty())
		return true;
	return false;
}

void Test(const string &testName, vector<int> &pPush, vector<int> &pPop ,bool expected)
{
	if (IsPopOrder(pPush, pPop) == expected)
		printf("Passed.\n");
	else
		printf("failed.\n");
}

void Test1()
{
	const int nLength = 5;
	vector<int> push = { 1, 2, 3, 4, 5 };
	vector<int> pop = { 4, 5, 3, 2, 1 };

	Test("Test1", push, pop,true);
}

void Test2()
{
	const int nLength = 5;
	vector<int> push = { 1, 2, 3, 4, 5 };
	vector<int> pop = { 3, 5, 4, 2, 1 };

	Test("Test2", push, pop, true);
}

void Test3()
{
	const int nLength = 5;
	vector<int> push = { 1, 2, 3, 4, 5 };
	vector<int> pop = { 4, 3, 5, 1, 2 };

	Test("Test3", push, pop, false);
}

void Test4()
{
	const int nLength = 5;
	vector<int> push = { 1, 2, 3, 4, 5 };
	vector<int> pop = { 3, 5, 4, 1, 2 };

	Test("Test4", push, pop, false);
}

// push和pop序列只有一个数字
void Test5()
{
	const int nLength = 1;
	vector<int> push = { 1 };
	vector<int> pop = { 2 };

	Test("Test5", push, pop, false);
}

void Test6()
{
	const int nLength = 1;
	vector<int> push = { 1 };
	vector<int> pop = { 1 };

	Test("Test6", push, pop,true);
}

void Test7()
{
	vector<int> push;
	vector<int> pop;
	Test("Test7",push,pop, true);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	system("pause");
    return 0;
}

