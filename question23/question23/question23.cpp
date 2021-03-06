// question23.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
/*
如果一个链表中有环，如何找到环的入口节点？
*/
using namespace std;
struct ListNode
{
	int val;
	shared_ptr<ListNode> next;
	ListNode(int v) :val(v), next(nullptr)
	{}
};

//key1：用快慢指针遍历链表，若两指针相遇，则链表一定存在环
//key2：若链表环中有n个节点，则让p1指针先走n步，然后p2指针开始走
//p1 和 p2相遇的节点正好是环的入口节点

//找相遇节点
shared_ptr<ListNode> MeetNode(shared_ptr<ListNode> head)
{
	if (head == nullptr)
		return nullptr;
	//快慢指针
	shared_ptr<ListNode> slow = head;
	shared_ptr<ListNode> fast = slow->next;

	while (fast && fast->next)
	{
		if (fast == slow)
			return fast;
		fast = fast->next->next;
		slow = slow->next;
	}
	return nullptr;
}

//找环入口
shared_ptr<ListNode> FindEntryOfLoop(shared_ptr<ListNode> head)
{
	if (head == nullptr)
		return nullptr;
	shared_ptr<ListNode> pMeet = MeetNode(head);
	if (pMeet == nullptr)
		return nullptr;
	//计算环中的节点数量
	shared_ptr<ListNode> p1 = pMeet;
	int count = 1;
	while (p1->next != pMeet)
	{
		p1 = p1->next;
		count++;
	}
	
	p1 = head;
	shared_ptr<ListNode> p2 = head;
	//移动p1 count步
	while (count > 0)
	{
		p1 = p1->next;
		count--;
	}
	//双指针一起移动
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}


int main()
{
	//第一次用智能指针，可以不用手动调用delete
	shared_ptr<ListNode> head(new ListNode(1));
	shared_ptr<ListNode> p2(new ListNode(2));
	shared_ptr<ListNode> p3(new ListNode(3));
	shared_ptr<ListNode> p4(new ListNode(4));
	shared_ptr<ListNode> p5(new ListNode(5));
	shared_ptr<ListNode> p6(new ListNode(6));
	head->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p3;

	shared_ptr<ListNode> ans = FindEntryOfLoop(head);
	if (ans)
		cout << ans->val << endl;

	system("pause");
    return 0;
}

