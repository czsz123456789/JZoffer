// question40.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <set>

//输入n个整数，找出其中最小的k个数
//sol1：排序，时间复杂度O(n*logn)
//sol2：快排分治，时间复杂度O(n) 上一道题写了 这里不写
//sol3：最大堆，时间复杂度O(n*logk) 适合海量数据的情况 这里分别用stl库中的优先队列和重复集合实现

using namespace std;

//用优先队列实现最大值堆
struct cmp
{
	bool operator()(int a,int b)
	{
		return a < b;//大顶堆
	}
};
vector<int> solution1(vector<int> &nums,int K)
{
	if (K <= 0)
		return {};
	int len = nums.size();
	if (len == 0 || len <= K)
		return nums;
	//创建大顶堆
	priority_queue<int, vector<int>, cmp> q;
	int count = 0;
	for (int num : nums)
	{
		//把前K个元素先填入
		if (count < K)
		{
			q.push(num);
			count++;
		}
		//堆中元素达到k后 若当前元素小于堆顶元素 则将堆顶元素出 当前元素入 堆会自动调整
		else
		{
			if (num < q.top())
			{
				q.pop();
				q.push(num);
			}
		}
	}
	//保存堆中结果
	vector<int> ans;
	while (!q.empty())
	{
		ans.push_back(q.top());
		q.pop();
	}
	return ans;
}

//使用重复集合 stl中的set和multiset都是用红黑树实现的，会自动排序
vector<int> solution2(vector<int> &nums, int K)
{
	if (K <= 0)
		return {};
	int len = nums.size();
	if (len == 0 || len <= K)
		return nums;
	multiset<int,greater<int> > s;
	for (int num : nums)
	{
		if (s.size() < K)
			s.insert(num);
		else
		{
			if (num < *s.begin())
			{
				s.erase(s.begin());
				s.insert(num);
			}
		}
	}
	//保存集合结果
	vector<int> ans;
	for (auto iter = s.begin(); iter != s.end(); iter++)
		ans.push_back(*iter);
	return ans;
}

//==============辅助测试代码==============
//打印数组
void myprint(vector<int> &nums)
{
	for (int num : nums)
		cout << num << " ";
	cout << endl;
}
//==============测试代码==============
void Test(const char* name, vector<int> &nums,int K)
{
	if(name)
		cout << name << "  begin" << endl;
	auto ans1 = solution1(nums, K);
	auto ans2 = solution2(nums, K);
	cout << "solution1 print: " << endl;
	myprint(ans1);
	cout << "solution2 print: " << endl;
	myprint(ans2);
	cout << endl;
}
void Test1()
{
	vector<int> data = { 7,7,7,7,7,7,1,2,3,4,5 };
	Test("test1", data,7);
}
void Test2()
{
	vector<int> data = { 0,1,0,5,0 };
	Test("test2", data,5);
}
void Test3()
{
	vector<int> data = { 1,2,3,4,5 };
	Test("test3", data,99);
}
void Test4()
{
	vector<int> data = { 1 };
	Test("test4", data,1);
}
void Test5()
{
	vector<int> data;
	Test("test5", data,0);
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

