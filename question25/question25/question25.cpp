// question25.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

//输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的
using namespace std;

struct ListNode
{
	int val;
	shared_ptr<ListNode> next;
	ListNode(int v) :val(v), next(nullptr)
	{}
};

shared_ptr<ListNode> Merge(shared_ptr<ListNode> head1, shared_ptr<ListNode> head2)
{
	//边界条件和初始空检查
	if (head1 == nullptr)
		return head2;
	else if (head2 == nullptr)
		return head1;

	//递归处理
	//当前两个节点中较小的成为新表的头节点，递归排序两表剩下的部分
	if (head1->val < head2->val)
	{
		head1->next = Merge(head1->next, head2);
		return head1;
	}
	else
	{
		head2->next = Merge(head1, head2->next);
		return head2;
	}
	return nullptr;
}

//创建链表
shared_ptr<ListNode> CreatList(vector<int> nums)
{
	int len = nums.size();
	if (len == 0)
		return nullptr;
	shared_ptr<ListNode> head(new ListNode(nums[0]));
	shared_ptr<ListNode> tail = head;
	for (int i = 1; i < len; i++)
	{
		shared_ptr<ListNode> newnode(new ListNode(nums[i]));
		tail->next = newnode;
		tail = tail->next;
	}
	return head;
}

int main()
{
	vector<int> nums1 = {};
	vector<int> nums2 = { 1,3,5,7,9 };
	shared_ptr<ListNode> head1 = CreatList(nums1);
	shared_ptr<ListNode> head2 = CreatList(nums2);
	shared_ptr<ListNode> newhead = Merge(head1, head2);
	while (newhead)
	{
		cout << newhead->val<<endl;
		newhead = newhead->next;
	}
	system("pause");
    return 0;
}

