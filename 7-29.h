#pragma once

#include<iostream>
#include<stack>
#include<queue>
#include<list>
#include<assert.h>
using namespace std;

struct TreeNode
{
	int _val;
	TreeNode* _left;
	TreeNode* _right;
	TreeNode(int val)
		:_val(val)
		, _left(NULL)
		, _right(NULL)
	{}
	~TreeNode()
	{
		_val = 0;
		_left = NULL;
		_right = NULL;
	}
};

void BinaryTreeConvert(TreeNode* node, TreeNode** prev)//¶þ²æËÑË÷Ê÷×ª»»ÎªÅÅÐòË«ÏòÁ´±í
{
	if (node == NULL)
		return;
	if (node->_left)
		BinaryTreeConvert(node->_left, prev);

	node->_left = *prev;
	if (*prev)
	{
		(*prev)->_right = node;
	}
	*prev = node;
	if (node->_right)
		BinaryTreeConvert(node->_right, prev);
}
void Text()
{
	TreeNode* node = new TreeNode(1);
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(3);
	TreeNode* node3 = new TreeNode(4);
	TreeNode* node4 = new TreeNode(5);
	TreeNode* node5 = new TreeNode(6);
	TreeNode* node6 = new TreeNode(7);
	TreeNode* node7 = new TreeNode(8);


	node->_left = node1;
	node->_right = node2;
	node1->_left = node3;
	node3->_right = node4;
	node3->_left = node5;
	node5->_left = node6;
	TreeNode* prev = NULL;
	BinaryTreeConvert(node, &prev);
}