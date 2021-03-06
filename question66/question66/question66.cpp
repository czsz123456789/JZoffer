// question66.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
//给定一个数组A[0,1,2,....N - 1]
//构建一个数组B[0,1,2.....N - 1]
//其中B[i] = A[0] * A[1] * .....*A[i -1]* A[i + 1]*....*A[N - 1]
//但不能用除法
using namespace std;

//其实这题用除法的话会遇到除0和被除数为零的情况，很麻烦
//还是左右乘积好

//key：构建两个数组left 和 right
//left[i]表示小于i下标的所有元素的积
//right[i]表示大于i下标的所有元素的积
//因此B[i] = left[i]*right[i]

vector<int> MultiplyNums(const vector<int> &A)
{
	int len = A.size();
	if (len == 0)
		return {};
	vector<int> left(len, 1);
	vector<int> right(len, 1);
	vector<int> ans(len, 0);
	for (int i = 1; i < len; i++)
		left[i] = left[i - 1] * A[i - 1];
	for (int i = len - 2; i >= 0; i--)
		right[i] = right[i + 1] * A[i + 1];

	for (int i = 0; i < len; i++)
		ans[i] = left[i] * right[i];
	return ans;
}

//================= Test Code =================

static void test(const char* testName, const vector<int>& input,const vector<int>& expected)
{
	printf("%s Begins: ", testName);

	auto ans = MultiplyNums(input);
	if (ans == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

static void test1()
{
	// 输入数组中没有0
	vector<int> input = { 1, 2, 3, 4, 5 };
	vector<int> expected = { 120, 60, 40, 30, 24 };

	test("test1",input,expected);
}

static void test2()
{
	// 输入数组中有一个0
	vector<int> input = { 1, 2, 0, 4, 5 };
	vector<int> expected = { 0, 0, 40, 0, 0 };

	test("test2", input, expected);
}

static void test3()
{
	// 输入数组中有两个0
	vector<int> input = { 1, 2, 0, 4, 0 };
	vector<int> expected = { 0, 0, 0, 0, 0 };

	test("test3", input, expected);
}

static void test4()
{
	// 输入数组中有正、负数
	vector<int> input = { 1, -2, 3, -4, 5 };
	vector<int> expected = { 120, -60, 40, -30, 24 };

	test("test4", input, expected);
}

static void test5()
{
	// 输入输入中只有两个数字
	vector<int> input = { 1, -2 };
	vector<int> expected = { -2, 1 };

	test("test5", input, expected);
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

