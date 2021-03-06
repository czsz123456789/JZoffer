// question4.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <assert.h>
#include <iostream>

/*
在一个二维数组中，每行左到右递增，每列从上到下递增
判断数组中是否有目标数值
*/
using namespace std;

//key:从左下角或者右下角开始比较，每次只需要移动一步

bool my_find(int mat[][4], int s_row, int s_col, int target)
{
	//左下角开始
	int row = s_row;
	int col = 0;
	while (row >= 0 && col < 4)
	{
		if (mat[row][col] < target)
			col++;
		else if (mat[row][col] > target)
			row--;
		else if (mat[row][col] == target)
			return true;
	}
	return false;
}

int main()
{
	int test1[4][4] = { {1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15} };
	assert(my_find(test1, 4, 4, 9) == true);
	
	system("pause");

    return 0;
}

