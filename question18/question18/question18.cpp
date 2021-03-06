// question18.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
//在O(1)时间内删除链表的节点,给定但链表的头指针和节点指针，定义一个函数在O(1)时间内删除该节点
using namespace std;
struct Node
{
	int val;
	Node* next;
	Node(int v):val(v),next(nullptr)
	{}
};

//head要设定为二级指针，因为若删除的是头指针，函数外部的链表头指针会指向被释放的空间（指针悬挂），表示和操纵都有问题，更担心重复释放的问题
void DeleteNode(Node **head,Node *target)
{
	if (head == nullptr || target == nullptr)
		return;
	//若删除的节点不为尾节点(普通情况）
	if (target->next != nullptr)
	{
		//直接用target的后一个节点的值替换target
		target->val = target->next->val;
		//把后一个节点删除
		Node *temp = target->next;
		target->next = target->next->next;
		delete temp;
		temp = nullptr;
	}
	//链表只有一个节点且要删除(既是头结点也是尾节点)
	else if (*head = target)
	{
		delete target;
		target = nullptr;
		*head = nullptr;//很关键
	}
	//链表中有多个节点，删除的是尾节点 
	{
		//需要从头往后搜索，复杂度O（n）
		Node* pNode = *head;
		while (pNode->next != target)
			pNode = pNode->next;
		delete target;
		target = nullptr;
		pNode->next = nullptr;
	}
}



int main()
{

	system("pause");
    return 0;
}

