// qusetion15.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

//求一个整数二进制中1的个数

using namespace std;

//将n与1相与 若为1 则最低位为1 然后将n右移一位，不断执行直到n为n
int fun1(int n)
{
	int ans = 0;
	while (n)
	{
		if (n & 1)
			ans++;
		n = n >> 1;//n /= 2 也可 但是效率会下降
	}
	return ans;
}

//上面的做法遇到负数会出错 因为负数要保持最高位为1
//下面对n的每一位依次执行与运算
int fun2(int n)
{
	unsigned int flag = 1;
	int ans = 0;
	while (flag)
	{
		if (flag & n)
			ans++;
		flag = flag << 1;//左移
	}
	return ans;
}

//牛逼的做法
//把一个整数减1 就是把它最右边的1变成0，如果这个1右边还有0，这些0全部变成1
//把一个整数减去1，再和原数做与运算，会把整数最右边的1变成0。那么一个整数的二进制中有多少个零，
//就可以进行多少次这样的操作
//复杂度最低
int fun3(int n)
{
	int ans = 0;
	while (n)
	{
		ans++;
		n = n & (n - 1);
	}
	return ans;
}

int main()
{
	cout << fun1(0x7fffffff)<<endl;
	cout << fun2(0x7fffffff)<<endl;
	cout << fun2(0x80000000) << endl;
	system("pause");
    return 0;
}

