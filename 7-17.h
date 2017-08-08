#pragma once

#include<iostream>
using namespace std;
#include<assert.h>

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int _val)
		:val(_val)
		, next(NULL)
	{}
};


bool pop_back(ListNode* node)
{
	assert(node);
	ListNode* prev = NULL;
	if (node->next != NULL)
	{
		prev = node->next;
		node->next = prev->next;
		node->val = prev->val;

		free(prev);
		prev = NULL;
	}
}

void ReverPrint(ListNode* Head)
{
	ListNode* p = Head;
	ListNode* prev = NULL;
	ListNode* next = NULL;
	ListNode* head = NULL;

	while (p != NULL)
	{
		next = p->next;
		if (next->next == NULL)
			head = next;

		p->next = prev;
		prev = p;
		p = next;
	}

	while (head != NULL)
	{
		cout << "节点信息：" << head->val;
	}
	cout << endl;

}

typedef struct ComplexNode{

	int _data; // 数据 

	struct ComplexNode * _next; // 指向下一个节点的指针 

	struct ComplexNode * _random; // 指向随机节点（可以是链表中的任意节点 or 空） 
	ComplexNode(int data)
		:_data(data)
		, _next(NULL)
		, _random(NULL)
	{}

}ComplexNode;

ComplexNode* Cope(ComplexNode* Head)
{
	ComplexNode* ptr = Head;
	while (ptr != NULL)
	{
		ComplexNode* node = new ComplexNode(ptr->_data);
		node->_next = ptr->_next;
		ptr->_next = node;

		ptr = node->_next;
	}


	ptr = Head;
	while (ptr != NULL)
	{
		if (ptr->_random != NULL)
		{
			ptr->_next->_random = ptr->_random->_next;
		}
		ptr = ptr->_next->_next;
	}

	ptr = Head;
	ComplexNode* newHead = NULL;
	ComplexNode* newNode = NULL;
	if (ptr != NULL)
	{
		newNode = newHead = ptr->_next;
		ptr->_next = newNode->_next;
		ptr = ptr->_next;
	}
	while (ptr != NULL)
	{
		newNode->_next = ptr->_next;
		newNode = newNode->_next;

		ptr->_next = newNode->_next;
		ptr = ptr->_next;
	}
	return newHead;
}

void Text()
{
	ComplexNode n1(1);
	ComplexNode n2(2); 
	ComplexNode n3(3);
	ComplexNode n4(4);
	ComplexNode n5(5);
	n1._next = &n2;
	n2._next = &n3;
	n3._next = &n4;
	n4._next = &n5;

	n1._random = &n3;
	n2._random = &n1;
	n3._random = &n5;

	ComplexNode* node = Cope(&n1);
	while (node != NULL)
	{
		if (node->_random != NULL)
		cout <<"结点数据：" <<node->_data << "random:" << node->_random->_data << endl;
		else
			cout << "结点数据：" << node->_data << "random:" << node->_random << endl;
		node = node->_next;
	}
}