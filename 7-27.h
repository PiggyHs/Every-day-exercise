#pragma once

#include<iostream>
#include<stack>
#include<queue>
#include<list>
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
//判断一棵树是否是完全二叉树

bool isallTree(binaryTree* Node)
{
	if (Node != NULL)
	{
		queue<binaryTree*> s;
		s.push(Node);
		bool flag = false;
		while (!s.empty())
		{
			binaryTree* p = s.front();
			s.pop();
			if (p != NULL)
			{
				if (flag == true)
					return false;
				s.push(p->_left);
				s.push(p->_right);
			}
			else
			{
				flag = true;
			}
		}
		return true;
	}
	return true;
}
//求二叉树中两个节点的最近公共祖先
//1：二叉树每个节点有parent（三叉链）
struct binaryTree
{
	int _val;
	binaryTree* _left;
	binaryTree* _right;
	binaryTree* _parent;
	binaryTree(int val)
		:_val(val)
		, _left(NULL)
		, _right(NULL)
		, _parent(NULL)
	{}
	~binaryTree()
	{
		_val = 0;
		_left = NULL;
		_right = NULL;
	}
};
binaryTree* grandfather(binaryTree* Node1, binaryTree* Node2)
{
	assert(Node1);
	assert(Node2);
	binaryTree* p1 = Node1;
	while (p1 != NULL)
	{
		binaryTree* p2 = Node2;
		while (p2 != NULL)
		{
			if (p1 == p2)
			{
				return p1;
			}
			p2 = p2->_parent;
		}

		p1 = p1->_parent;
	}

	return NULL;
}
//2：二叉树是搜索二叉树。
binaryTree* grandfather(binaryTree* Node, binaryTree* Node1, binaryTree* Node2)
{
	assert(Node);
	assert(Node1);
	assert(Node2);
	if (Node->_val > Node1->_val && Node->_val < Node2->_val \
		|| Node->_val < Node1->_val && Node->_val > Node2->_val)
	{
		return Node;
	}
	else if (Node->_val > Node1->_val && Node->_val > Node2->_val)
	{
		return grandfather(Node->_right, Node1, Node2);
	}
	else if (Node->_val > Node1->_val && Node->_val > Node2->_val)
	{
		return grandfather(Node->_right, Node1, Node2);
	}
	return NULL; 
}

//3：就是普通二叉树。（尽可能实现时间复杂度为O（N））
bool Path(binaryTree* Node, binaryTree* Node1,list<binaryTree*>& l)
{
	if (Node == Node1)
		return true;

	l.push_back(Node);

	bool flag = false;
	if (Node->_left  && flag == false)
		flag =  Path(Node->_left, Node1, l);
	if (Node->_right && flag == false)
		flag =  Path(Node->_right, Node1, l);

	if (flag == false)
		l.pop_back();

	return flag;
}
binaryTree* finlastNode(const list<binaryTree*>& l1, const list<binaryTree*>& l2)
{
	list<binaryTree*>::const_iterator interator1 = l1.begin();
	list<binaryTree*>::const_iterator interator2 = l2.begin();

	binaryTree* node = NULL;
	while (interator1 != l1.end() && interator2 != l2.end())
	{
		if (*interator1 == *interator2)
		{
			node = *interator1;
		}
			interator1++;
			interator2++;
	}
	return node;
}

binaryTree* grandfather(binaryTree* Node, binaryTree* Node1, binaryTree* Node2)
{
	assert(Node);
	assert(Node1);
	assert(Node2);

	list<binaryTree*> l1;
	Path(Node, Node1, l1);
	list<binaryTree*> l2;
	Path(Node, Node2, l2);

	return finlastNode(l1, l2);
}
void Text()
{
	binaryTree* node = new binaryTree(1);
	binaryTree* node1 = new binaryTree(2);
	binaryTree* node2 = new binaryTree(3);
	binaryTree* node3 = new binaryTree(4);
	binaryTree* node4 = new binaryTree(5);
	binaryTree* node5 = new binaryTree(6);
	binaryTree* node6 = new binaryTree(7);
	binaryTree* node7 = new binaryTree(8);


	node->_left = node1;
	node->_right = node2;
	node1->_left = node3;
	node3->_right = node4;
	node3->_left = node5;
	node5->_left = node6;
	list<binaryTree*> l;
	node7 = grandfather(node, node3, node2);
}