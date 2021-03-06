// qusetion17.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
//打印从1到最大的n位数

using namespace std;

void myprint(vector<char> &ans)
{
	int i = 0;
	while (i < ans.size() && ans[i] == '0')
		i++;
	if (i == ans.size())
		return;
	while (i < ans.size())
		cout << ans[i++];
	cout << endl;
}

//这道题要考虑大数，用字符数组
bool Print1ToMaxOfNDigits(int n)
{
	if (n < 1)
		return true;
	vector<char> ans(n, '0');
	bool overflow = false;
	while (!overflow)
	{
		//进位
		int carry = 0;

		for (int i = n - 1; i >= 0; i--)
		{
			int numtemp = 0;
			numtemp = carry + (ans[i] - '0');
			if (i == n - 1)
				numtemp++;
			if (numtemp >= 10)
			{
				if (i == 0)
				{
					overflow = true;
					return overflow;
				}
				else
				{
					numtemp -= 10;
					carry = 1;
					ans[i] = '0' + numtemp;
				}
			}
			else
			{
				ans[i] = '0' + numtemp;
				break;//这个break挺精髓的 发现没进位及时停止循环
			}
		}
		//打印当前数字
		myprint(ans);
	}
	return overflow;
}

//递归法，将问题转换成数字排列的解法，n位十进制数其实结束n个从0到9的全排列

void myrecursively(vector<char> &ans, int index)
{
	if (index == ans.size())
	{
		myprint(ans);
		return;
	}
		
	for (int i = 0; i < 10; i++)
	{
		ans[index] = '0' + i;
		myrecursively(ans, index + 1);
	}
}

bool Print1ToMaxOfNDigits2(int n)
{
	if (n < 1)
		return false;
	vector<char> ans(n, '0');

	for (int i = 0; i < 10; i++)
	{
		// 递归的入口是最高位
		ans[0] = '0' + i;
		myrecursively(ans, 1);
	}
	return true;
}

int main()
{
	Print1ToMaxOfNDigits(3);
	//Print1ToMaxOfNDigits(-2);
	//Print1ToMaxOfNDigits2(3);
	Print1ToMaxOfNDigits2(4);
	system("pause");
    return 0;
}

