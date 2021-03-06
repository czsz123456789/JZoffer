// question1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <assert.h>
#include <cstring>
//面试问题1：实现类A的赋值运算符
using namespace std;

class A
{
private:
	char *text;
public:
	A(const char *c = nullptr)
	{
		if (c != nullptr)
		{
			int len = strlen(c);
			text = new char[len + 1];
			strcmp(text, c);
		}
	}

	A(const A& other)
	{
		int len = strlen(other.text);
		text = new char[len + 1];
		strcmp(text, other.text);
	}

	~A()
	{
		delete[] text;
	}

	/*
	1.返回值要为类型的引用，这样才能连续赋值
	2.注意形参加const
	3.要释放自身的内存
	4.判断传入的参数和当前是不是同一个示例
	*/
	A& operator=(const A& other)
	{
		//高级写法，考虑了异常安全性
		//创建临时变量tempA，交换tempA和自身的text，if执行完后tempA自动被析构，空间被释放
		if (this != &other)
		{
			A tempA(other);
			char *temp = tempA.text;
			tempA.text = this->text;
			this->text = temp;
		}
		//一般写法
		//if (this != &other)
		//{
			//先释放内存后，如果后续内存不足导致new char抛出异常，text将是一个空指针，容易造成程序崩溃！！！
		//	delete[] this->text;
		//	this->text = nullptr;

		//	this->text = new char[strlen(other.text) + 1];
		//	strcmp(this->text, other.text);
		//}
		return *this;
	}

	
};

int main()
{
	char str[] = "sdsdsd";
	char *bb = new char[5];
	strcmp(bb, "abab");
	
	A a(str);
	A b;
	A c = b = a;

    return 0;
}

