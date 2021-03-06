// qusetion9.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <queue>
#include <assert.h>


using namespace std;

//用两个栈实现队列 包括front(),push(),pop()方法
//key：用一个辅助栈，当pop或者front时先检查辅助栈是否为空，若不为空则直接操作辅助栈栈顶元素，为空则把主站的所有元素弹出到辅助栈
class My_pueue
{
private:
	stack<int> s;
	stack<int> sup;
public:
	My_pueue()
	{}
	void push(int val)
	{
		s.push(val);
	}
	void pop()
	{
		if (sup.empty())
		{
			while (!s.empty())
			{
				sup.push(s.top());
				s.pop();
			}
		}
		if (sup.empty())
			throw "queue is empty";
		sup.pop();
	}

	int front()
	{
		if (sup.empty())
		{
			while (!s.empty())
			{
				sup.push(s.top());
				s.pop();
			}
		}
		if (sup.empty())
			throw "queue is empty";
		return sup.top();
	}
};


int main()
{
	My_pueue q;
	q.push(5);
	q.push(7);
	q.push(9);
	q.push(10);
	q.pop();
	assert(q.front() == 7);


	system("pause");

    return 0;
}

