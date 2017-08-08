#pragma once
#include<iostream>
#include<queue>
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
};

bool printNodeByLevel(binaryTree* node)  //实现一颗二叉树的层序遍历
{
	if (node == NULL)
		return false;
	queue<binaryTree*> s;
	binaryTree* p = node;
	s.push(p);
	while (p && !s.empty())
	{
		p = s.front();
		cout << p->_val << " ";
			s.pop();
		if (p->_left != NULL)
		{
			s.push(p->_left);
		}
		if (p->_right != NULL)
		{
			s.push(p->_right);
		}
	}
	cout << endl;
	return true;
}

//int countFactorialZero(int num) //- 给定一个整数N，那么N的阶乘N！末尾有多少个0呢？例如：N＝10，N！＝3 628 800，N！的末尾有两个0。
//{
//	int count = 0;
//	for (int i = 1; i < num; i++)
//	{
//		int j = i;
//		while (j % 5 == 0)
//		{
//			count++;
//			j /= 5;
//		}
//	}
//	return count;
//}

void Text()
{
	binaryTree node(1);
	binaryTree node1(2);
	binaryTree node2(3);
	binaryTree node3(4);

	node._left = &node1;
	node._right = &node2;
	node1._left = &node3;
	printNodeByLevel(&node);
}