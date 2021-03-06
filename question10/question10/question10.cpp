// question10.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

//求旋转数组的最小数字，二分法
using namespace std;

//最小数字就是旋转点
//这个函数没法解决形如 1,0,1,1,1 的数组
int searchmin(vector<int> &nums)
{
	int len = nums.size();
	if (len == 0)
	{
		throw "empty array";
		return -1;
	}
	int begin = 0;
	int end = len - 1;
	
	while (begin < end)
	{
		if (nums[begin] < nums[end])
			return nums[begin];
		if (begin + 1 == end)
		{
			return min(nums[begin], nums[end]);
		}

		int mid = (begin + end) / 2;
		//中间的数在前半部分
		if (nums[begin] <= nums[mid])
			begin = mid;
		//中间的数在后半部分
		else
			end = mid;
	}
	return nums[begin];
}

int main()
{
	vector<int> nums = {15,17, 1,3,5,7,10};
	cout << searchmin(nums);
	system("pause");
    return 0;
}

