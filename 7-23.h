#pragma once

#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<assert.h>
using namespace std;

struct binaryTree
{
	int _val;
	binaryTree* _left;
	binaryTree* _right;
	binaryTree(int val)
		:_val(val)
		, _left(NULL)
		, _right(NULL)
	{}
	~binaryTree()
	{
		_val = 0;
		_left = NULL;
		_right = NULL;
	}
};

int High_Tree(binaryTree* Node)
{
	if (Node == NULL)
		return 0;
	int left = High_Tree(Node->_left);
	int right = High_Tree(Node->_left);
	if (left > right)
	{
		return left + 1;
	}
	else
		return right + 1;
}
void Destroy(binaryTree* root)
{
	if (root == NULL)
		return;
	else{
		if (root->_left != NULL)
		{
			Destroy(root->_left);
			root->_left = NULL;
		}
		if (root->_right != NULL)
		{
			Destroy(root->_right);
			root->_right = NULL;
		}
		if (root != NULL)
		{
			delete root;
			root = NULL;
		}
	}
}

void Text()
{
	binaryTree* node = new binaryTree(1);
	binaryTree* node1 = new binaryTree(2);
	binaryTree* node2 = new binaryTree(3);
	binaryTree* node3 = new binaryTree(4);

	node->_left = node1;
	node->_right = node2;
	node1->_left = node3;
	/*cout << High_Tree(&node) << endl;*/
	Destroy(node);
}

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int _val)
		:val(_val)
		, next(NULL)
	{}
};
ListNode* RotateList(ListNode* list, size_t k)
{
	assert(list);
	assert(k >= 0);

	ListNode* head;
	if (k == 0)
		return list;
	else
	{
		stack<ListNode*> s;
		ListNode* p = list;
		for (int i = 0; i < k; i++)  //将需要翻转的结点压入栈中
		{
			if (p != NULL)
			{
				s.push(p);
				p = p->next;
			}
		}

		ListNode* node = p;//保存需翻转结点的后一个节点
		head = p = s.top();//连接节点数据
		s.pop();
		int size = s.size();
		for (int i = 0; i < size; i++)
		{
			p->next = s.top();
			s.pop();
			p = p->next;
		}
		p->next = node;
	}
	return head;
}

void Text()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	ListNode* n;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	/* n = RotateList(n1, 0);
	 n = RotateList(n1, 1);
	 n = RotateList(n1, 2);*/
	/* n = RotateList(n1, 3);*/
	/* n = RotateList(n1, 4);*/
	/* n = RotateList(n1, 5);*/
	 n = RotateList(n1, 6);
}