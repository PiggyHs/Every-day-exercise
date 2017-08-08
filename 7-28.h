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

TreeNode* ConstructBinaryTree(int* startPerOrder, int* endPerOrder, int* startInOrder, int * endInOrder)
{
	TreeNode* node = new TreeNode(*startPerOrder);

	if (startPerOrder == endPerOrder)
	{
		if (startInOrder == endInOrder && *startInOrder == *startPerOrder)
		{
			return node;
		}
	}

	int* start = startInOrder;
	while (*startPerOrder != *start)
	{
		start++;
	}
	int length = start - startInOrder;
	int* leftendper = startPerOrder + length;

	if (length > 0)
	{
		node->_left = ConstructBinaryTree(startPerOrder + 1, leftendper, startInOrder, start - 1);
	}
	if (length < (endPerOrder - startPerOrder))
	{
		node->_right = ConstructBinaryTree(leftendper + 1, endPerOrder, start + 1, endInOrder);
	}
	return node;
}
TreeNode* reConstructBinaryTree(int* perOrder, int* InOrder, int length)
{
	if (perOrder == NULL || InOrder == NULL || length <= 0)
		return NULL;

	return ConstructBinaryTree(perOrder, perOrder + length - 1, InOrder, InOrder + length - 1);
}


void Text()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	int b[] = { 3, 2, 4, 1, 6, 5 };
	TreeNode* p = reConstructBinaryTree(a, b, 6);
}
typedef void (*FUN)();
struct _A
{
	int _a;
	FUN _fun;
};
struct _B
{
	int _b;
	_A _a;
};
void _fA()       //父类的同名函数
{
	printf("_A:_fun()\n");
}
void _fB()       //子类的同名函数
{
	printf("_B:_fun()\n");
}

void Text()
{
	_A a;
	_B b;
	a._fun = &_fA;
	b._a._fun = &_fB;

	_A* p = &a;
	p->_fun();
	p = (_A*)&b;
	p->_fun();

}