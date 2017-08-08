#pragma once

#include<iostream>
#include<queue>
#include<vector>
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
//int LeafageNode(binaryTree* Node)  //递归版本 求二叉树叶子节点的个数
//{
//	if (Node == NULL)
//		return 0;
//
//	if (Node ->_left == NULL && Node->_right == NULL)
//		return 1;
//	return LeafageNode(Node->_left) + LeafageNode(Node->_right);
//}

//int LeafageNode(binaryTree* Node)  //非递归版本
//{
//	if (Node == NULL)
//		return 0;
//	binaryTree* node = Node;
//	int Count = 0;
//	queue<binaryTree*> q;
//	q.push(node);
//	while (node != NULL &&!q.empty())
//	{
//		node = q.front();
//		if (node->_left == NULL && node->_right == NULL)
//			Count++;
//		  q.pop();
//		if (node->_left != NULL)
//			q.push(node->_left);
//		if (node->_right != NULL)
//			q.push(node->_right);
//	}
//	return Count;
//}
//void Text()
//{
//	binaryTree node(1);
//	binaryTree node1(2);
//	binaryTree node2(3);
//	binaryTree node3(4);
//
//	node._left = &node1;
//	node._right = &node2;
//	node1._left = &node3;
//	cout << LeafageNode(&node) << endl;
//}


//int K_Node_sum(binaryTree* Node,int K)//求二叉树第k层的节点个数
//{
//	if (Node == NULL)
//		return 0;
//
//	if (K == 1)
//		return 1;
//
//	return K_Node_sum(Node->_left, K - 1) + K_Node_sum(Node->_right, K - 1);
//}

int Find_num(int * arr,int length)  //时间复杂度O(n^2)    一个数组中有一个数字的次数超过了数组的一半，
//出这个字符。如：int a[]={2,3,2,2,2,2,2,5,4,1,2,3}，求出超过一半的数字是2。
{
	vector<pair<int, int>> x ;
	for (int i = 0; i < length; i++)
	{
		if (x.empty())
			x.push_back(make_pair(arr[i], 1));
		else
		{
			int j = 0;
			for (j; j < x.size();j++)
			{
				if (x[j].first == arr[i])
				{
					break;
				}
			}
			if (j == x.size())
			{
				x.push_back(make_pair(arr[i], 1));
			}
			else
			{
				x[j].second++;
			}
		}
	}
	
	int len = 0;
	for (len; len < x.size(); len++)
	{
		if (x[len].second > length / 2)
			break;
	}
	if (len != x.size())
		return x[len].first;
	else
	{
		cout << "没有找到！";
		return false;
	}
}

void Text()
{
	//binaryTree node(1);
	//binaryTree node1(2);
	//binaryTree node2(3);
	//binaryTree node3(4);

	//node._left = &node1;
	//node._right = &node2;
	//node1._left = &node3;
	//cout << K_Node_sum(&node,2) << endl;
	int arr[] = { 2, 2, 2, 2, 2, 3, 4, 5, 6, 7 };
	int length = sizeof(arr) / sizeof(arr[0]);
	cout << Find_num(arr, length) << endl;
}