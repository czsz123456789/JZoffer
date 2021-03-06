// question29.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
using namespace std;

//尝试使用状态机,右->下->左->上，每次换方向时注意边界的修改
//可以实现，但是我写的代码太乱，可读性和维护性很差
enum direction
{
	right,
	down,
	left,
	up
};

void PrintMatrixClockwisely(vector<vector<int> > &mat)
{
	int row = mat.size();
	if (row == 0)
		return;
	int col = mat[0].size();
	int count = row * col;

	int RightEnd = col - 1;
	int LeftEnd = 0;
	int UpEnd = 0;
	int DownEnd = row - 1;
	direction dir = direction::right;
	int i = 0;
	int j = 0;

	while (count)
	{
		switch (dir)
		{
		case direction::right:
		{
			cout << mat[i][j]<<",";
			j++;
			count--;
			if (j > RightEnd)
			{
				j = RightEnd;
				i++;
				UpEnd++;
				dir = direction::down;
			}
		}
			break;
		case direction::down:
		{
			cout << mat[i][j] << ",";
			i++;
			count--;
			if (i > DownEnd)
			{
				i = DownEnd;
				j--;
				RightEnd--;
				dir = direction::left;
			}
		}
			break;
		case direction::left:
		{
			cout << mat[i][j] << ",";
			j--;
			count--;
			if (j < LeftEnd)
			{
				j = LeftEnd;
				i--;
				DownEnd--;
				dir = direction::up;
			}
		}
			break;
		case direction::up:
		{
			cout << mat[i][j] << ",";
			i--;
			count--;
			if (i < UpEnd)
			{
				i = UpEnd;
				j++;
				LeftEnd++;
				dir = direction::right;
			}
		}
			break;
		default:
			break;
		}
	}
}

//剑指offer官方解法
void PrintMatInCircle(vector<vector<int> > &mat, int start);
void PrintMatrixClockwisely2(vector<vector<int> > &mat)
{
	int row = mat.size();
	if (row == 0)
		return;
	int col = mat[0].size();
	
	//从(0,0)开始，一圈一圈遍历
	int start = 0;
	while (start * 2 < row && start * 2 < col)
	{
		PrintMatInCircle(mat, start);
		start++;
	}
}

//顺时针打印一圈
void PrintMatInCircle(vector<vector<int> > &mat, int start)
{
	int row = mat.size();
	int col = mat[0].size();

	int EndRow = row - 1 - start;
	int EndCol = col - 1 - start;
	//先向右移动，一定有这一步
	for (int i = start; i <= EndCol; i++)
		cout << mat[start][i] << ",";
	//满足条件才下移 注意边界条件的判断和改变，建议画图理解
	if (EndRow > start)
		for (int i = start + 1; i <= EndRow; i++)
			cout << mat[i][EndCol] << ",";
	//左移
	if (start < EndCol && start < EndRow)
		for (int i = EndCol - 1; i >= start; i--)
			cout << mat[EndRow][i] << ",";
	//上移
	if (start < EndRow - 1 && start < EndCol)
		for (int i = EndRow - 1; i >= start + 1; i--)
			cout << mat[i][start] << ",";
}

int main()
{
	vector<vector<int> > mat1 = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	vector<vector<int> > mat2 = {
		{1},
		{2},
		{3},
		{4}
	};
	PrintMatrixClockwisely(mat1);
	cout << endl;
	PrintMatrixClockwisely2(mat1);
	system("pause");
    return 0;
}

