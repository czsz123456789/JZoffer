// qusetion2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

//设计一个单例模式
using namespace std;

class A
{
	//1.构造函数必须为private
private:
	A() 
	{
		cout << "construct called" << endl;
	}
	A(const A&);
public:
	//接口为静态函数，创建一个静态成员，此为懒汉单例
	static A & get_instance()
	{
		static A singleA;
		return singleA;
	}
};

int main()
{
	A& single1 = A::get_instance();
	A& single2 = A::get_instance();
	system("pause");
    return 0;
}

