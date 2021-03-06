// question52.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

//输入两个链表，找出它们的第一个公共节点
using namespace std;
struct ListNode
{
	int val;
	shared_ptr<ListNode> next;
	ListNode(int v) :val(v), next(nullptr)
	{}
};
//key：1本题可以用两个栈记录两个链表节点，然后依次出栈比较，找到第一个两者不同的节点，返回上一个节点
//2还可以让短的的链表先走n步，n为两链表的长度之差，找到第一个两节点相等的返回
//但是，这都不够浪漫
//我们使用“走到头就走对方的路”
shared_ptr<ListNode> FindFirstCommonNode(shared_ptr<ListNode> head1, shared_ptr<ListNode> head2)
{
	if (head1 == nullptr || head2 == nullptr)
		return nullptr;
	auto p1 = head1;
	auto p2 = head2;

	while (p1 != p2)
	{
		p1 = (p1 == nullptr ? head2 : p1->next);//走到尾了就从另一个链表的头开始继续走，即“走你的路”
		p2 = (p2 == nullptr ? head1 : p2->next);
	}
	return p1;
}
// ====================辅助测试代码====================
//创建链表
shared_ptr<ListNode> CreateListNode(int val)
{
	shared_ptr<ListNode> node(new ListNode(val));
	return node;
}

//连接节点
void ConnectListNodes(shared_ptr<ListNode> node1, shared_ptr<ListNode> node2)
{
	node1->next = node2;
}
// ====================测试代码====================
void Test(const char* testName, shared_ptr<ListNode> pHead1, shared_ptr<ListNode> pHead2, shared_ptr<ListNode> pExpected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	shared_ptr<ListNode> pResult = FindFirstCommonNode(pHead1, pHead2);
	if (pResult == pExpected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 第一个公共结点在链表中间
// 1 - 2 - 3 \
//            6 - 7
//     4 - 5 /
void Test1()
{
	shared_ptr<ListNode> pNode1 = CreateListNode(1);
	shared_ptr<ListNode> pNode2 = CreateListNode(2);
	shared_ptr<ListNode> pNode3 = CreateListNode(3);
	shared_ptr<ListNode> pNode4 = CreateListNode(4);
	shared_ptr<ListNode> pNode5 = CreateListNode(5);
	shared_ptr<ListNode> pNode6 = CreateListNode(6);
	shared_ptr<ListNode> pNode7 = CreateListNode(7);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode6);
	ConnectListNodes(pNode4, pNode5);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);


	Test("Test1", pNode1, pNode4, pNode6);
}

// 没有公共结点
// 1 - 2 - 3 - 4
//            
// 5 - 6 - 7
void Test2()
{
	shared_ptr<ListNode> pNode1 = CreateListNode(1);
	shared_ptr<ListNode> pNode2 = CreateListNode(2);
	shared_ptr<ListNode> pNode3 = CreateListNode(3);
	shared_ptr<ListNode> pNode4 = CreateListNode(4);
	shared_ptr<ListNode> pNode5 = CreateListNode(5);
	shared_ptr<ListNode> pNode6 = CreateListNode(6);
	shared_ptr<ListNode> pNode7 = CreateListNode(7);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	Test("Test2", pNode1, pNode5, nullptr);
}

// 公共结点是最后一个结点
// 1 - 2 - 3 - 4 \
//                7
//         5 - 6 /
void Test3()
{
	shared_ptr<ListNode> pNode1 = CreateListNode(1);
	shared_ptr<ListNode> pNode2 = CreateListNode(2);
	shared_ptr<ListNode> pNode3 = CreateListNode(3);
	shared_ptr<ListNode> pNode4 = CreateListNode(4);
	shared_ptr<ListNode> pNode5 = CreateListNode(5);
	shared_ptr<ListNode> pNode6 = CreateListNode(6);
	shared_ptr<ListNode> pNode7 = CreateListNode(7);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode7);
	ConnectListNodes(pNode5, pNode6);
	ConnectListNodes(pNode6, pNode7);

	Test("Test3", pNode1, pNode5, pNode7);
}

// 公共结点是第一个结点
// 1 - 2 - 3 - 4 - 5
// 两个链表完全重合   
void Test4()
{
	shared_ptr<ListNode> pNode1 = CreateListNode(1);
	shared_ptr<ListNode> pNode2 = CreateListNode(2);
	shared_ptr<ListNode> pNode3 = CreateListNode(3);
	shared_ptr<ListNode> pNode4 = CreateListNode(4);
	shared_ptr<ListNode> pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test("Test4", pNode1, pNode1, pNode1);

}

// 输入的两个链表有一个空链表
void Test5()
{
	shared_ptr<ListNode> pNode1 = CreateListNode(1);
	shared_ptr<ListNode> pNode2 = CreateListNode(2);
	shared_ptr<ListNode> pNode3 = CreateListNode(3);
	shared_ptr<ListNode> pNode4 = CreateListNode(4);
	shared_ptr<ListNode> pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test("Test5", nullptr, pNode1, nullptr);

}

// 输入的两个链表有一个空链表
void Test6()
{
	Test("Test6", nullptr, nullptr, nullptr);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	system("pause");
    return 0;
}

