// question59_2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <deque>
#include <queue>

//实现一个队列，实现队列max、push_back、pop_front 函数
//并且复杂度均为o(1)

using namespace std;
//两个队列模拟

template<typename T>
class Myqueue
{
private:
	queue<T> q;
	deque<T> q_max;
public:
	void push_back(const T data)
	{
		q.push(data);
		while (!q_max.empty() && q_max.back() < data)
			q_max.pop_back();
		q_max.push_back(data);
	}
	void pop_front()
	{
		if (!q.empty())
		{
			auto now = q.front();
			q.pop();
			if (!q_max.empty() && now == q_max.front())
				q_max.pop_front();
		}
		else
		{
			cout << "queue is empty!!" << endl;
		}
	}
	T max() const
	{
		if (!q_max.empty())
			return q_max.front();
		else
			cout << "queue is empty" << endl;
	}
};

// ====================测试代码====================
void Test(const char* testName, const Myqueue<int>& mqueue, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (mqueue.max() == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

int main()
{
	Myqueue<int> queue;
	// {2}
	queue.push_back(2);
	Test("Test1", queue, 2);

	// {2, 3}
	queue.push_back(3);
	Test("Test2", queue, 3);

	// {2, 3, 4}
	queue.push_back(4);
	Test("Test3", queue, 4);

	// {2, 3, 4, 2}
	queue.push_back(2);
	Test("Test4", queue, 4);

	// {3, 4, 2}
	queue.pop_front();
	Test("Test5", queue, 4);

	// {4, 2}
	queue.pop_front();
	Test("Test6", queue, 4);

	// {2}
	queue.pop_front();
	Test("Test7", queue, 2);

	// {2, 6}
	queue.push_back(6);
	Test("Test8", queue, 6);

	// {2, 6, 2}
	queue.push_back(2);
	Test("Test9", queue, 6);

	// {2, 6, 2, 5}
	queue.push_back(5);
	Test("Test9", queue, 6);

	// {6, 2, 5}
	queue.pop_front();
	Test("Test10", queue, 6);

	// {2, 5}
	queue.pop_front();
	Test("Test11", queue, 5);

	// {5}
	queue.pop_front();
	Test("Test12", queue, 5);

	// {5, 1}
	queue.push_back(1);
	Test("Test13", queue, 5);

	system("pause");
    return 0;
}

