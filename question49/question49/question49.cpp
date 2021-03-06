// question49.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
//把只包含因子2,3,5的数称为丑数，求第n个丑数，一般把1作为第一个丑数
using namespace std;
//key:判断丑数，如果一个数能被2整除，就连续除以2；如果能被3整除，就连续除以3；
//如果能被5整除，就连续除以5 。如果最后得到的是1，那就是丑数，否则不是
//但这里我们不用这个方法

//根据定义，丑数乘2，3,5仍然是丑数
//因此可以通过前面的丑数求得后面的丑数，只要注意将数字从小到大排列即可
int GetUglyNum(int n)
{
	if (n < 1)
		return 0;
	vector<int> nums(n, 0);//记录丑数 
	nums[0] = 1;//第一个丑数是1
	int index = 1;
	int i_2 = 0;//乘2的下标
	int i_3 = 0;
	int i_5 = 0;
	for (int i = 1; i < n; i++)
	{
		nums[i] = min(nums[i_2] * 2, min(nums[i_3] * 3, nums[i_5] * 5));//3个数中取最小值
		//取到最小值的对应下标要后移
		if (nums[i_2] * 2 == nums[i])
			i_2++;
		if (nums[i_3] * 3 == nums[i])
			i_3++;
		if (nums[i_5] * 5 == nums[i])
			i_5++;
	}
	return nums[n - 1];
}

// ====================测试代码====================
void Test(int index, int expected)
{
	if (GetUglyNum(index) == expected)
		printf("solution passed\n");
	else
		printf("solution failed\n");

}
int main()
{
	Test(1, 1);

	Test(2, 2);
	Test(3, 3);
	Test(4, 4);
	Test(5, 5);
	Test(6, 6);
	Test(7, 8);
	Test(8, 9);
	Test(9, 10);
	Test(10, 12);
	Test(11, 15);

	Test(1500, 859963392);

	Test(0, 0);
	system("pause");
    return 0;
}

