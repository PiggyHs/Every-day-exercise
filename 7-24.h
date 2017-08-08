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
	int right = High_Tree(Node->_right);

	return (left > right) ? (left + 1) : (right + 1);
}

bool IsBalanced(binaryTree* root)//判断一棵二叉树是否是平衡二叉树  递归解法  空间复杂度大  时间复杂度大
{
	if (root == NULL)
		return true;
	
	int left = High_Tree(root->_left);
	int right = High_Tree(root->_right);
	int dist = left - right;

	if (dist > 1 || dist < -1)
	{
		return false;
	}

	return IsBalanced(root->_left) && IsBalanced(root->_right);
}

bool IsBalanced(binaryTree* root,int* depth)//判断一棵二叉树是否是平衡二叉树  时间复杂度较小
{
	if (root == NULL)
	{
		*depth = 0;
		return true;
	}


	int leftdepth, rightdepth;
	bool left = IsBalanced(root->_left, &leftdepth);
	bool right = IsBalanced(root->_right, &rightdepth);


	if (left && right)
	{
		int dist = leftdepth - rightdepth;
		if (dist<=1 && dist >=-1)
		{
			*depth =1+((leftdepth > rightdepth) ? leftdepth : rightdepth);
			return true;
		}
	}

	return false;
}
bool IsBalanced(binaryTree* root)
{
	int depth = 0;
	return IsBalanced(root, &depth);
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

	node->_left = node1;
	node->_right = node2;
	node1->_left = node3;
	/*node3->_left = node4;*/

	cout << IsBalanced(node) << endl;
}

void reverse_binaryTree(binaryTree* root)//求二叉树的镜像
{
	if (root == NULL)
		return;

	reverse_binaryTree(root->_left);
	reverse_binaryTree(root->_right);

	binaryTree* temp = root->_left;
	root->_left = root->_right;
	root->_right = temp;
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

	node->_left = node1;
	node->_right = node2;
	node1->_left = node3;
	/*node3->_left = node4;*/
	reverse_binaryTree(node);
}

bool Find_num(int *arr,int m,int n,int num)//二维数组的查找问题
{
	assert(arr);
	for (int i = 0, j = n - 1; i < m, j >= 0;)
	{
		if (num > arr[i*n+j])
			i++;
		else
		if (num < arr[i*n+j])
			j--;
		else
			return true;
	}
	return false;
}

void Text()
{
	int arr[3][2] = { 1, 2, 3, 5, 4, 6 };
	cout << Find_num((int*)arr, 3, 2, 8) << endl;
}