// question6.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <assert.h>
#include <iostream>

/*
从尾到头打印链表
*/
using namespace std;

class Node
{
public:
	int val;
	Node* next;
	Node():val(0),next(nullptr)
	{}
	Node(int v) :val(v), next(nullptr)
	{}

	~Node()
	{
		delete next;
		next = nullptr;
		
	}
};

//递归法反向输出链表 但是当链表及其长时，可能导致调用栈溢出，因此用栈的方法代码鲁棒性更好
void reversePrintList(Node *head)
{
	if (head == nullptr)
		return;
	if (head->next != nullptr)
		reversePrintList(head->next);
	cout << head->val << endl;
}

void insert(Node *head,int num)
{
	if (head == nullptr)
		return;
	while (head->next)
		head = head->next;
	Node *newnode = new Node(num);
	newnode->next = nullptr;

	head->next = newnode;
}

int main()
{
	Node *head = new Node(1);
	
	insert(head, 3);
	insert(head, -1);
	insert(head, 5);
	insert(head, 70);

	reversePrintList(head);

	system("pause");
    return 0;
}

