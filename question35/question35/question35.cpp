// question35.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
// 请实现函数复制一个复杂链表。在复杂链表中，每个结点除了有一个Next指针指向下一个
// 结点外，还有一个Sibling 指向链表中的任意结点或者nullptr。
using namespace std;
struct ComplexListNode
{
	int val;
	shared_ptr<ComplexListNode> next;
	shared_ptr<ComplexListNode> sibling;
	ComplexListNode(int v) :val(v), next(nullptr), sibling(nullptr)
	{}
};

//key:本题可以在O(N)复杂度内完成目标
//首先在原链表每一个节点后面插入一个和他相同值的节点
//然后将每个新节点的sibling指向它前一个节点的sibling的后一个节点
//然后分离两链表即可
//真的牛皮

//在原链表的每一个节点后面clone一个相同值的节点，相当于插入
void CloneList(shared_ptr<ComplexListNode> head)
{
	if (head == nullptr)
		return;
	shared_ptr<ComplexListNode> tail = head;
	while (tail)
	{
		shared_ptr<ComplexListNode> clonenode(new ComplexListNode(tail->val));
		clonenode->next = tail->next;
		tail->next = clonenode;
		tail = clonenode->next;
	}
}

//连接sibling
void ConnectSibling(shared_ptr<ComplexListNode> head)
{
	if (head == nullptr)
		return;
	auto tail = head;
	while (tail)
	{
		if(tail->sibling)
			tail->next->sibling = tail->sibling->next;
		tail = tail->next->next;
	}
}

//分离两个链表
shared_ptr<ComplexListNode> ReconnectNodes(shared_ptr<ComplexListNode> head)
{
	if (head == nullptr)
		return nullptr;
	auto CloneHead = head->next;
	auto CloneNode = CloneHead;
	auto tail = head;
	
	while (tail)
	{
		tail->next = CloneNode->next;
		tail = tail->next;

		if (tail == nullptr)
			break;
		CloneNode->next = tail->next;
		CloneNode = CloneNode->next;
	}
	return CloneHead;
}

//本题目标函数
shared_ptr<ComplexListNode> Clone(shared_ptr<ComplexListNode> head)
{
	if (head == nullptr)
		return nullptr;
	CloneList(head);
	ConnectSibling(head);
	return ReconnectNodes(head);
}
// ====================辅助测试代码==================== 
shared_ptr<ComplexListNode> CreateNode(int val)
{
	shared_ptr<ComplexListNode> newnode(new ComplexListNode(val));
	return newnode;
}

void BuildNodes(shared_ptr<ComplexListNode> node1, shared_ptr<ComplexListNode> node2, shared_ptr<ComplexListNode> node3)
{
	node1->next = node2;
	node1->sibling = node3;
}

void PrintList(shared_ptr<ComplexListNode> head)
{
	auto node = head;
	while (node)
	{
		cout << "value is "<<node->val<<endl;
		if (node->sibling)
			cout << "sibling is " << node->sibling->val << endl;
		else
			cout << "no sibling" << endl;
		node = node->next;
	}
	cout << endl;
}
// ====================测试代码====================
void Test(const char* testName, shared_ptr<ComplexListNode> pHead)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("The original list is:\n");
	PrintList(pHead);
	shared_ptr<ComplexListNode> pClonedHead = Clone(pHead);

	printf("The cloned list is:\n");
	PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
	shared_ptr<ComplexListNode> pNode1 = CreateNode(1);
	shared_ptr<ComplexListNode> pNode2 = CreateNode(2);
	shared_ptr<ComplexListNode> pNode3 = CreateNode(3);
	shared_ptr<ComplexListNode> pNode4 = CreateNode(4);
	shared_ptr<ComplexListNode> pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, pNode3);
	BuildNodes(pNode2, pNode3, pNode5);
	BuildNodes(pNode3, pNode4, nullptr);
	BuildNodes(pNode4, pNode5, pNode2);

	Test("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
	shared_ptr<ComplexListNode> pNode1 = CreateNode(1);
	shared_ptr<ComplexListNode> pNode2 = CreateNode(2);
	shared_ptr<ComplexListNode> pNode3 = CreateNode(3);
	shared_ptr<ComplexListNode> pNode4 = CreateNode(4);
	shared_ptr<ComplexListNode> pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, nullptr);
	BuildNodes(pNode2, pNode3, pNode5);
	BuildNodes(pNode3, pNode4, pNode3);
	BuildNodes(pNode4, pNode5, pNode2);

	Test("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3()
{
	shared_ptr<ComplexListNode> pNode1 = CreateNode(1);
	shared_ptr<ComplexListNode> pNode2 = CreateNode(2);
	shared_ptr<ComplexListNode> pNode3 = CreateNode(3);
	shared_ptr<ComplexListNode> pNode4 = CreateNode(4);
	shared_ptr<ComplexListNode> pNode5 = CreateNode(5);

	BuildNodes(pNode1, pNode2, nullptr);
	BuildNodes(pNode2, pNode3, pNode4);
	BuildNodes(pNode3, pNode4, nullptr);
	BuildNodes(pNode4, pNode5, pNode2);

	Test("Test3", pNode1);
}

// 只有一个结点
void Test4()
{
	shared_ptr<ComplexListNode> pNode1 = CreateNode(1);
	BuildNodes(pNode1, nullptr, pNode1);

	Test("Test4", pNode1);
}

// 鲁棒性测试
void Test5()
{
	Test("Test5", nullptr);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	
	system("pause");
    return 0;
}

