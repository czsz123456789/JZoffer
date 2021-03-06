// question30.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <assert.h>
//定义栈的数据结构，在该类型中实现一个能够得到栈的最小元素的min函数。在该栈中，调用min、push及pop的时间复杂度都是O（1）

//key:定义一个辅助min栈，当入栈元素小于等于min栈顶元素时，元素同时入min栈，当出栈元素等于min栈顶元素时，min栈顶元素出栈
using namespace std;
template <typename T>
class MyStack
{
private:
	//数据栈
	stack<T> data_s;
	//最小值栈
	stack<T> min_s;
public:
	void push(const T&);
	void pop();
	const T& top();
	const T& min();
};

template <typename T>
inline void MyStack<T>::push(const T& num)
{
	data_s.push(num);
	if (min_s.empty() || min_s.top() >= num)
		min_s.push(num);
}

//
template <typename T>
inline void MyStack<T>::pop()
{
	if (!data_s.empty())
	{
		T temp = data_s.top();
		data_s.pop();
		if (!min_s.empty() && temp == min_s.top())
			min_s.pop();
	}
}

template <typename T>
inline const T& MyStack<T>::top()
{
	assert(data_s.size() > 0);
	return data_s.top();
}

template <typename T>
inline const T& MyStack<T>::min()
{
	assert(min_s.size() > 0);
	return min_s.top();
}

template<typename T>
void Test(const string &testName, MyStack<T>& stack, int expected)
{
	if (stack.min() == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

void test1()
{
	MyStack<int> s1;

	s1.push(3);
	Test("Test1", s1, 3);

	s1.push(4);
	Test("Test2", s1, 3);

	s1.push(2);
	Test("Test3", s1, 2);

	s1.push(3);
	Test("Test4", s1, 2);

	s1.pop();
	Test("Test5", s1, 2);

	s1.pop();
	Test("Test6", s1, 3);

	s1.pop();
	Test("Test7", s1, 3);

	s1.push(0);
	Test("Test8", s1, 0);
	
}

int main()
{
	test1();
	system("pause");
    return 0;
}

