// question14.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>

//有一段m长的绳子，将绳子剪成n段，求这n段绳子长度之积的最大值，n >= 2
//理解题意：m是给定的，但n没有给定，需要自己选择将绳子剪成几段能获得最大值

using namespace std;
//part1：绳子的长度只能为整数
//使用方法：1.递归 2.动态规划 3.贪婪算法

//递归法：考虑将m长的绳子剪成两段，则最大值为max(1 * (m - 1),2*(m - 2),3*(m - 3) .......)
//令f(n)为长度为n的绳子能获得的最大值，则有递推公式 f(n) = max(f(i) * f(n - i)) 0 < i < n
//因此能容易的写出递归方法了

class Rope
{
public:
	int fun1(int n)
	{
		//因为必须分为两段以上，所以长度小于4和大于4分开考虑
		if (n <= 1)
			return 0;
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		return recursion(n);
	}
	//这个函数适用于n > 4
	int recursion(int n)
	{
		//易知边界条件,长度小于等于4的时候不切
		if (n <= 0)
			return 0;
		if (n <= 4)
			return n;

		int ans = 0;
		for (int i = 1; i <= n / 2; i++)
			ans = max(ans, recursion(i) * recursion(n - i));
		return ans;
	}

	//动态规划：从下到上计算，先计算小的，相比递归可以免去重复计算
	int fun2(int n)
	{
		if (n <= 1)
			return 0;
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		vector<int> dp(n + 1, 0);
		dp[0] = 0;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;
		for (int i = 4; i <= n; i++)
		{
			for (int j = 1; j <= i / 2; j++)
			{
				dp[i] = max(dp[i], dp[j] * dp[i - j]);
			}
		}
		return dp[n];
	}

	//贪婪算法：当n大于等于5时，我们尽可能多的剪长度为3的绳子；
	/*当剩下的绳子长度为4时，把绳子剪成两段长度为2的绳子。 
	为什么选2，3为最小的子问题？因为2，3包含于各个问题中，
	如果再往下剪得化，乘积就会变小。 
	为什么选长度为3？因为当n≥5时，3(n−3)≥2(n−2)3(n-3)≥2(n-2)3(n−3)≥2(n−2)*/
	//我没法证明 但是是对的
	int fun3(int n)
	{
		if (n <= 1)
			return 0;
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		if (n == 4)
			return 4;
		//3的个数
		int cntof3 = n / 3;
		int remainder = n % 3;

		int ans = 1;
		if (remainder == 1)
		{
			cntof3--;
			ans = 4;
		}
		if (remainder == 2)
			ans = 2;
		for (int i = 0; i < cntof3; i++)
			ans *= 3;
		return ans;
	}
};
int main()
{
	Rope r;
	cout << r.fun1(8)<<endl;
	cout << r.fun2(50) << endl;
	cout << r.fun3(50) << endl;

	system("pause");
    return 0;
}



