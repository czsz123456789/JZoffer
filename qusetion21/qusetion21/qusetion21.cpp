// qusetion21.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
/*
输入一个整数数组，实现一个函数来调整该数组中数值的顺序，
是的所有奇数位于数组的前半部分，所有偶数位于数组后半部分
*/

using namespace std;

//key：快速排序的双指针思想
//指针i和j分别指向数组头尾
//指针i每遇到偶数就停止，j遇到奇数停止
//交换i，j元素，继续移动


//使用函数指针进行复用
void ReorderOddEven(vector<int> &nums,bool(*func)(int))
{
	int len = nums.size();
	if (len == 0)
		return;
	int begin = 0;
	int end = len - 1;
	while (begin < end)
	{
		//遇到奇数往后移动
		while (begin < end && func(nums[begin]))
			begin++;
		//遇到偶数往前移动
		while (begin < end && !func(nums[end]))
			end--;
		if (begin == end)
			break;

		//交换
		int temp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = temp;
	}
}
//修改这个函数的功能就可以重新确定分组条件，不需要改ReorderOddEven
bool isOdd(int n)
{
	return n & 1;
}

//还可以使用函数对象进行复用
//实现方法：在类中重载()运算符!!!!!!!!!
class Func
{
public:
	bool operator()(int n)
	{
		return n & 1;
	}
};

void ReorderOddEven(vector<int> &nums, Func &func)
{
	int len = nums.size();
	if (len == 0)
		return;
	int begin = 0;
	int end = len - 1;
	while (begin < end)
	{
		//遇到奇数往后移动
		while (begin < end && func(nums[begin]))
			begin++;
		//遇到偶数往前移动
		while (begin < end && !func(nums[end]))
			end--;
		if (begin == end)
			break;

		//交换
		int temp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = temp;
	}
}
int main()
{
	//函数指针法
	vector<int> nums = { 1,3,59,46,78,6,3,4,5,3 };
	ReorderOddEven(nums, isOdd);
	for (int num : nums)
		cout << num << "\t";
	cout << endl;
	//函数对象法
	Func fun1;
	vector<int> nums2 = { -5,6,8,3,-99,66,100,0,0,75,99 };
	ReorderOddEven(nums2, fun1);
	for (int num : nums2)
		cout << num << "\t";
	cout << endl;

	system("pause");
    return 0;
}

