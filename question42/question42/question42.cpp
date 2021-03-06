// question42.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

//输入一个整形数组，数组中有正数也有负数。数组中的一个或多个连续整数组成一个子数组
//求所有子数组和的最大值
using namespace std;

bool g_Invalid = false;
//key：1动态规划
//2.动态规划可以压缩路径，只需要保存两个变量

int FindMaxSumOfSubArray(vector<int> &nums)
{
	//普通DP
	//int len = nums.size();
	//if (len == 0)
	//	return 0;
	//vector<int> dp(len, 0);
	////dp[i]表示以nums[i]结尾的子数组最大和
	//dp[0] = nums[0];
	//int ans = dp[0];
	//for (int i = 1; i < len; i++)
	//{
	//	dp[i] = (dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i]);
	//	ans = max(ans, dp[i]);
	//}
	//return ans;
	
	//DP压缩路径
	int len = nums.size();
	if (len == 0)
	{
		g_Invalid = true;
		return 0;
	}
	g_Invalid = false;
	int CurrrentSum = nums[0];//记录当前值
	int MaxSum = nums[0];//距离最大值
	for (int i = 1; i < len; i++)
	{
		//如果当前数之前的和为负数
		if (CurrrentSum <= 0)
			CurrrentSum = nums[i];//重新设定当前和
		else
			CurrrentSum += nums[i];//加上当前的数，更新当前和

		MaxSum = max(MaxSum, CurrrentSum);//更新最大和
	}
	return MaxSum;
}

// ====================测试代码====================
void Test(const char* testName, vector<int>& pData,int expected, bool expectedFlag)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	int result = FindMaxSumOfSubArray(pData);
	if (result == expected && expectedFlag == g_Invalid)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
	vector<int> data = { 1, -2, 3, 10, -4, 7, 2, -5 };
	Test("Test1", data,18, false);
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2()
{
	vector<int> data = { -2, -8, -1, -5, -9 };
	Test("Test2", data, -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3()
{
	vector<int> data = { 2, 8, 1, 5, 9 };
	Test("Test3", data,25, false);
}

// 无效输入
void Test4()
{
	vector<int> data;
	Test("Test4", data, 0, true);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();

	system("pause"); 
    return 0;
}

