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

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	ListNode* p1 = pHead1;
	ListNode* p2 = pHead2;

	while (p1 != p2)
	{
		p1 = (p1 == NULL ? pHead1 : p1->next);
		p2 = (p2 == NULL ? pHead2 : p2->next);
	}
	return p1;
}

pair<ListNode*, bool> IsExitsLoop(ListNode* Head)  //求环
{
	assert(Head != NULL);
	ListNode* slow = Head;  //快指针
	ListNode* fast = Head;  //慢指针

	while (slow != NULL && slow->next != NULL)
	{
		slow = slow->next->next;
		fast = fast->next;
		if (slow == fast)
			return make_pair(fast, true);
	}

	return make_pair(slow, false);
}

ListNode* FindLoopPort(ListNode* head)
{
	ListNode* ptr = head;
	ListNode* end = NULL;
	if (IsExitsLoop(head).second)
	end = IsExitsLoop(head).first;

	while (ptr != end)
	{
		ptr = ptr->next;
		end = end->next;
	}
	if (ptr == end)
		return ptr;
	else
		return NULL;
}

ListNode* FindCommonNode(ListNode* Head1, ListNode* Head2)
{
	if (((IsExitsLoop(Head1).second) && (!IsExitsLoop(Head2).second)) || \
		((IsExitsLoop(Head2).second && (!IsExitsLoop(Head1).second))))
		return NULL;

	if (IsExitsLoop(Head1).second && IsExitsLoop(Head2).second)
	{
		ListNode* node1 = FindLoopPort(Head1);
		ListNode* node2 = FindLoopPort(Head2);

		if (node1 != node2)    //两个链表在一个环中的不同入口节点
			return node1;
		else  //一个环中的相同入口节点
		{
			ListNode* p1 = Head1;
			ListNode* p2 = Head2;

			while (p1 != p2)
			{
				p1 = (p1 == node1 ? Head1 : p1->next);
				p2 = (p2 == node1 ? Head2 : p2->next);
			}
			return p1;
		}
	}
}

