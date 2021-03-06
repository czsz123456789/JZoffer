// question47.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

//在一个m*n的棋盘的每一个都放有一个礼物，每个礼物都有一定的价值（价值大于零）。
//你可以从棋盘的左上角开始拿格子里的礼物，并每次向左或者向下移动一格，直到到达棋盘的右下角
//给定一个棋盘以及其上面的礼物，计算最多能拿到多少价值的礼物

//key:自底向上的动态规划和自顶向下的记忆化递归均可以实现
using namespace std;
int GetMaxValue1(vector<vector<int> > &nums)
{
	int row = nums.size();
	if (row == 0)
		return 0;
	int col = nums[0].size();
	//构建dp数组 dp[i][j] 表示到达坐标(i，j)能获得的礼物最大价值
	vector<vector<int> > dp(row, vector<int>(col, 0));
	//第一排，只能从左边到达
	dp[0][0] = nums[0][0];
	for (int i = 1; i < col; i++)
		dp[0][i] = nums[0][i] + dp[0][i - 1];
	//第一列，只能从上边到达
	for (int i = 1; i < row; i++)
		dp[i][0] = nums[i][0] + dp[i - 1][0];

	for (int i = 1; i < row; i++)
		for (int j = 1; j < col; j++)
			//从左边和上面两条路径中选择大的
			dp[i][j] = nums[i][j] + max(dp[i][j - 1], dp[i - 1][j]);
		
	return dp[row - 1][col - 1];
}
//在上面的基础上压缩dp维度，减小空间复杂度
int GetMaxValue2(vector<vector<int> > &nums)
{
	int row = nums.size();
	if (row == 0)
		return 0;
	int col = nums[0].size();
	//dp[i]表示当前位置能获得的最大礼物
	//每行从左向右遍历 dp[i - 1] 表示从左边到达
	//dp[i]表示从上到达，然后更新dp[i]
	vector<int> dp(col, 0);
	
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			//左边到达
			int left = (j > 0 ? dp[j - 1] : 0);
			//上边到达
			int up = (i > 0 ? dp[j] : 0); //注意dp的下标 很关键
			//更新当前位置
			dp[j] = nums[i][j] + max(left, up);
		}
	return dp[col - 1];
}

// ====================测试代码====================
void test(const char* testName, vector<vector<int> > &values, int expected)
{
	if (GetMaxValue1(values) == expected)
		std::cout << testName << ": solution1 passed." << std::endl;
	else
		std::cout << testName << ": solution1 FAILED." << std::endl;

	if (GetMaxValue2(values) == expected)
		std::cout << testName << ": solution2 passed." << std::endl;
	else
		std::cout << testName << ": solution2 FAILED." << std::endl;
}

void test1()
{
	// 三行三列
	vector<vector<int> > values = {
		{ 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 }
	};
	int expected = 29;
	test("test1", values,expected);
}

void test2()
{
	//四行四列
	vector<vector<int> > values = {
		{ 1, 10, 3, 8 },
	{ 12, 2, 9, 6 },
	{ 5, 7, 4, 11 },
	{ 3, 7, 16, 5 }
	};
	int expected = 53;
	test("test2", values, expected);
}

void test3()
{
	// 一行四列
	vector<vector<int> > values = {
		{ 1, 10, 3, 8 }
	};
	int expected = 22;
	test("test3",values,expected);
}

void test4()
{
	vector<vector<int> > values = {
		{ 1 },
	{ 12 },
	{ 5 },
	{ 3 }
	};
	int expected = 21;
	test("test4", values, expected);
}

void test5()
{
	// 一行一列
	vector<vector<int> > values = {
		{ 3 }
	};
	int expected = 3;
	test("test5", values, expected);
}

void test6()
{
	// 空
	vector<vector<int> > values;
	int expected = 0;
	test("test6", values, expected);
}


int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();

	system("pause");
    return 0;
}

