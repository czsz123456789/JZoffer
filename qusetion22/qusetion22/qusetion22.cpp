// qusetion22.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
/*
求链表倒数第k个节点
*/

using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int v) :val(v), next(nullptr)
	{}
};

ListNode* FindKthToTail(ListNode *head, int  K)
{
	//判断是否为空 k是否为负，保证代码鲁棒性
	if (head == nullptr || K < 1)
		return nullptr;

	//双指针法  快指针指向nullptr时 慢指针指向目标节点
	int count = 0;
	//先移动快指针
	ListNode *pfast = head;
	while (pfast)
	{
		pfast = pfast->next;
		count++;
		//快指针已经k次
		if (count == K)
			break;
	}
	//链表长度不及K
	if (pfast == nullptr)
		return nullptr;

	ListNode *pslow = head;
	while (pfast)
	{
		pfast = pfast->next;
		pslow = pslow->next;
	}
	return pslow;
}

//创建链表
ListNode* CreatList(vector<int> &nums)
{
	int len = nums.size();
	if (len == 0)
		return nullptr;
	ListNode *head = new ListNode(nums[0]);
	ListNode *tail = head;
	for (int i = 1; i < len; i++)
	{
		ListNode *newnode = new ListNode(nums[i]);
		tail->next = newnode;
		tail = tail->next;
	}
	return head;
}
int main()
{
	vector<int> nums = { 0,1,2,3,4,5,6 };
	ListNode *head = CreatList(nums);

	ListNode* ans = FindKthToTail(head, 3);
	if (ans)
	{
		cout << ans->val << endl;
	}
	system("pause");
    return 0;
}

