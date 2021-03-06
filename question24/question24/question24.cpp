// question24.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
//反转一个链表
using namespace std;

struct ListNode
{
	int val;
	shared_ptr<ListNode> next;
	ListNode(int v) :val(v),next(nullptr)
	{}
};

//递归实现
//key：递归最重要的是不要自己把递归展开，而只用关心当前这一层的功能
//以及状态的转移、递归结束条件
shared_ptr<ListNode> ReverseList(shared_ptr<ListNode> head)
{
	//递归结束条件，节点为空或者是尾节点
	if (head == nullptr || head->next == nullptr)
		return head;

	//新头节点
	shared_ptr<ListNode> newhead = ReverseList(head->next);
	//让当前节点的后一个节点next指向当前节点，实现反转
	head->next->next = head;
	//当前节点的后一个要指向空,因为链表的尾节点要指向空，不然链表会有环
	head->next = nullptr;

	return newhead;
}

//迭代实现
shared_ptr<ListNode> ReverseList2(shared_ptr<ListNode> head)
{
	if (head == nullptr)
		return nullptr;
	//key:使用一个前节点和一个后节点，遍历反转
	shared_ptr<ListNode> prev = nullptr;
	shared_ptr<ListNode> after = nullptr;
	shared_ptr<ListNode> cur = head;
	shared_ptr<ListNode> newhead = nullptr;
	while (cur)
	{
		after = cur->next;
		if (cur->next == nullptr)//新头节点
			newhead = cur;
		cur->next = prev;//反转
		prev = cur;
		cur = after;
	}
	return newhead;
}
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
	vector<int> nums = { 1,2,3,4,5,6 };
	shared_ptr<ListNode> head = CreatList(nums);
	shared_ptr<ListNode> newhead = ReverseList2(head);

	while (newhead)
	{
		cout << newhead->val;
		newhead = newhead->next;
	}
	system("pause");
    return 0;
}

