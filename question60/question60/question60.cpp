// question60.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

//保证扩展性
#define MAX_VAL 6.0
//把n个骰子扔在地上，所有骰子朝上一面的点数之和为s
//输入n，求n所有可能的值出现的概率

using namespace std;
//key:本题可以用递归或者动态规划分析
//第n + 1个骰子出现k点的情况只和第n个骰子的情况有关,包括第n个骰子点数为1、2、3、4、5、6
//分别对应第n + 1个骰子出现k - 1、k - 2、k - 3、k - 4、k - 5、k - 6
//这几种情况相互独立，概率加起来除以6即可求得n + 1个骰子出现k点的概率

vector<pair<int, double> > dicesSum(int n)
{
	if (n < 1)
		return {};
	vector<pair<int, double> > ans;
	//dp[i][j]表示 第i个骰子掷出j点的概率 
	//i,j 均从1开始           n<= j <= MAX_VAL*n
	vector<vector<double> >  dp(n + 1, vector<double>(MAX_VAL * n + 1, 0));
	
	for (int i = 1; i <= MAX_VAL; i++)
		dp[1][i] = 1 / MAX_VAL;

	for(int i = 2;i <= n;i++)
		for (int j = 1; j <= MAX_VAL*i; j++)
		{
			for(int k = 1;k <= MAX_VAL;k++)
				if (j > k)
					dp[i][j] += dp[i - 1][j - k];
			dp[i][j] /= MAX_VAL;
		}
	
	for (int i = 1; i <= MAX_VAL * n; i++)
		ans.push_back(make_pair(i, dp[n][i]));
	
	return ans;
}

//也可以使用记忆化搜索+递归的方式
//这个函数只是求n个骰子出现k点的概率
double prob(int n, int k)
{
	if (n == 1 && k >= 1 && k <= MAX_VAL)
		return 1.0 / MAX_VAL;
	if (k < n || k > MAX_VAL * n || n == 0)
		return 0;
	double ans = 0;
	for (int i = 1; i <= MAX_VAL; i++)
		ans += prob(n - 1, k - i);
	return ans / MAX_VAL;
}

// ====================测试代码====================
void Test(int n)
{
	printf("Test for %d begins:\n", n);

	printf("Test for solution\n");
	auto ans = dicesSum(n);

	for (int i = 0; i < ans.size(); i++)
	{
		cout << "point " << ans[i].first << "probability: " << ans[i].second << endl;
	}

	printf("\n");
}

int main()
{
	Test(1);
	Test(2);
	Test(3);
	Test(4);

	Test(11);

	Test(0);

	system("pause");
    return 0;
}

