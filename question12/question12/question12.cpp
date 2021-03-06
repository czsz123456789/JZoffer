// question12.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <assert.h>
#include <iostream>

//判断一个字符矩阵中是否存在一个包含某字符串所有字符的路径
//一条路径已经访问过的位置不能再访问
using namespace std;

bool dfs(vector<vector<char> > &mat, string &target,vector<vector<bool> > &visited, int index,int row,int col)
{
	if (index == target.size())
		return true;
	if (row < 0 || row >= mat.size() || col < 0 || col >= mat[0].size() || target[index] != mat[row][col] || visited[row][col])
		return false;
	
	visited[row][col] = true;
	if (col - 1 >= 0 && dfs(mat, target, visited, index + 1, row, col - 1))//向左搜索
		return true;
	if (col + 1 < mat[0].size() && dfs(mat, target, visited, index + 1, row, col + 1))//向右搜索
		return true;
	if (row - 1 >= 0 && dfs(mat, target, visited, index + 1, row - 1, col)) //向下搜索
		return true;
	if (row + 1 < mat.size() && dfs(mat, target, visited, index + 1, row + 1, col))//向上搜索
		return true;
	visited[row][col] = false;
	return false;
}

bool fun(vector<vector<char> > &mat, string &target)
{
	if (target.size() == 0)
		return true;
	if (mat.size() == 0)
		return false;
	//记录位置是否访问过
	vector<vector<bool> > visited(mat.size(), vector<bool>(mat[0].size(), false));

	//遍历找起点
	for (int i = 0; i < mat.size(); i++)
		for (int j = 0; j < mat[0].size(); j++)
		{
			if (mat[i][j] == target[0])
			{
				if (dfs(mat, target, visited, 0, i, j))
					return true;
			}
		}
	return false;
}

int main()
{
	vector<vector<char> > mat = {{'a','b','t','g'},
								{'c','f','c','s'},
								{'j','d','e','h'}};
	vector<vector<char> > mat2 = { {'a','b','t','g'} };
	vector<vector<char> > mat3 = { {} };
	string target1 = "abfb";
	string target2 = "bfce";
	string target3 = "abtg";
	string target4 = "abtb";
	string target5 = "a";
	string target6 = "";

	assert(fun(mat, target1) == false);
	assert(fun(mat, target2) == true);
	assert(fun(mat2, target3) == true);
	assert(fun(mat2, target4) == false);
	assert(fun(mat3, target5) == false);
	assert(fun(mat3, target6) == true);

	system("pause");
    return 0;
}

