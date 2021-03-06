// question41.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>

//求数据流的中位数
//数字是不断进入数组的，在每次添加一个新的数进入数组的同时返回当前新数组的中位数

//key：最大值堆位于数组左半，保存数组中较小的一半元素 最小值堆位于数组右半，保存较大的一半元素
using namespace std;

template<typename T>
vector<T> medianII(vector<T> &nums) {
	// write your code here

	vector<T> ans;
	if (nums.size() == 0)
		return ans;

	//使用一个最大值堆，一个最小值堆来维护，最大值堆顶即为中位数
	//在数据流中求中位数、第k大的值这类问题均是此思想
	priority_queue<T, vector<T>, less<T> > MaxHeap;
	priority_queue<T, vector<T>, greater<T> > MinHeap;

	for (int i = 0; i < nums.size(); i++)
	{
		//先插入最大堆 然后将最大堆的顶，即最大元素弹出到最小堆，保证最小堆的每一个元素均比最大堆大
		//此为左右之分
		MaxHeap.push(nums[i]);
		MinHeap.push(MaxHeap.top());
		MaxHeap.pop();
		
		//保持两堆平衡
		if (MinHeap.size() > MaxHeap.size())
		{
			MaxHeap.push(MinHeap.top());
			MinHeap.pop();
		}

		//和为奇数 中位数出现在最大堆顶
		if ((MaxHeap.size() + MinHeap.size()) & 1)
		{
			ans.push_back(MaxHeap.top());
		}
		else //何为偶数，中位数为两堆顶的平均值
		{
			auto temp = (MaxHeap.top() + MinHeap.top()) / 2.0;
			ans.push_back(temp);
		}
	}
	return ans;
}
//==============辅助测试代码==============
//打印数组
template<typename T>
void myprint(vector<T> &nums)
{
	for (auto num : nums)
		cout << num << " ";
	cout << endl;
}
//==============测试代码=========

template<typename T>
void Test(const char* name, vector<T> &nums)
{
	if (name)
		cout << name << "  begin" << endl;
	auto ans = medianII(nums);
	myprint(ans);
	cout << endl;
}
void Test1()
{
	vector<int> data = { 1,2,3,4,5 };
	Test("test1", data);
}
void Test2()
{
	vector<int> data = { 4,5,1,3,2,6,0};
	Test("test2", data);
}
void Test3()
{
	vector<int> data = { 1};
	Test("test3", data);
}
void Test4()
{
	vector<double> data = { 3.2,5.56,7.8,10.0 };
	Test("test4", data);
}
void Test5()
{
	vector<int> data;
	Test("tes5", data);
}
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	system("pause");
    return 0;
}

