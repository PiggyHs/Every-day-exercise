#pragma once

#include<iostream>
#include<stack>
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
//判断一个节点是否在一棵二叉树中。（注意多测几个节点，看是否都能找到） 
bool isTreeNode(binaryTree* node, const binaryTree* Node)
{
	assert(node != NULL);

	if (node == Node)
		return true;
	bool left = false, right = false;
	if(node->_left != NULL)
	left = isTreeNode(node->_left, Node);
	if (node->_right != NULL)
	right = isTreeNode(node->_right, Node);

	if (left || right)
		return true;
	else
	{
		return false;
	}
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
	node3->_left = node4;
	node4->_left = node5;
	node5->_left = node6;

	cout << isTreeNode(node, node) << endl;
	cout << isTreeNode(node, node1) << endl;
	cout << isTreeNode(node, node2) << endl;
	cout << isTreeNode(node, node3) << endl;
	cout << isTreeNode(node, node4) << endl;
	cout << isTreeNode(node, node5) << endl;
	cout << isTreeNode(node, node6) << endl;
	cout << isTreeNode(node, node7) << endl;
}
//判断一颗二叉树是是否是另一颗树的子树。比如tree2是tree1的子树。
bool isSon_tree(binaryTree* node1, binaryTree* node2)
{
	assert(node1);
	assert(node2);
	stack<binaryTree*> s;
	stack<binaryTree*> s2;

	s.push(node1);
	binaryTree* node = NULL;
	while (!s.empty())
	{
		binaryTree* p = s.top();
		s.pop();
		if (p == node2)
		{
			node = p;
			break;
		}
		if (p->_right != NULL)
		{
			s.push(p->_right);
		}if (p->_left != NULL)
		{
			s.push(p->_left);
		}
	}
	if (node == NULL)
		return false;
	else
	{
		while (!s.empty())
		{
			s.pop();
		}
		s.push(node);
		s2.push(node2);
		bool flag = 1;
		while (!s.empty() && !s2.empty())
		{
			binaryTree* p1 = s.top();
			binaryTree* p2 = s2.top();
			s.pop();
			s2.pop();
			if (p1->_left == p2->_left && p2->_right == p1->_right)
			{
				if (p1->_left && p2->_left)
				{
					s.push(p1->_left);
					s2.push(p2->_left);
				}
				if (p1->_right && p2->_right)
				{
					s.push(p1->_right);
					s2.push(p2->_right);
				}
			}
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			return true;
		else
			return false;
	}
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
	node3->_left = node4;
	node4->_left = node5;
	node5->_left = node6;
	cout << isSon_tree(node, node1) << endl;
	cout << isSon_tree(node, node2) << endl;
	cout << isSon_tree(node, node3) << endl;
	cout << isSon_tree(node, node4) << endl;
	cout << isSon_tree(node, node5) << endl;
	cout << isSon_tree(node, node6) << endl;
	cout << isSon_tree(node, node7) << endl;
}