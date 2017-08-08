#pragma once

#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

//struct binaryTree
//{
//	int _val;
//	binaryTree* _left;
//	binaryTree* _right;
//	binaryTree(int val)
//		:_val(val)
//		, _left(NULL)
//		, _right(NULL)
//	{}
//	~binaryTree()
//	{
//		_val = 0;
//		_left = NULL;
//		_right = NULL;
//	}
//};
////1、实现二叉树的前序/中序/后序非递归遍历
//void preOrder(binaryTree* Node) //前序遍历  根->左节点->右结点
//{
//	assert(Node);
//	stack<binaryTree*> s;
//	s.push(Node);
//	cout <<"前序遍历为：";
//	while (!s.empty())
//	{
//		binaryTree* p = s.top();
//		s.pop();
//		cout << p->_val << " ";  //打印节点内容
//		if (p->_right != NULL)
//		{
//			s.push(p->_right);
//		}
//		if (p->_left != NULL)
//		{
//			s.push(p->_left);
//		}
//	}
//	cout << endl;
//}
//
//void inOrder(binaryTree* Node)//中序遍历  左节点->根节点->右结点
//{
//	assert(Node);
//	stack<binaryTree*> s;
//	binaryTree* p = Node;
//	cout << "中序遍历为：";
//	while (!s.empty() || p != NULL)
//	{
//		while (p != NULL)
//		{
//			s.push(p);
//			p = p->_left;
//		}
//		binaryTree* node = s.top();
//		s.pop();
//		cout << node->_val << " ";  //打印节点内容
//		p = node->_right;
//	}
//	cout << endl;
//}
//
//void postOrder(binaryTree* Node)//后序遍历 左节点->右结点 ->根节点
//{
//	assert(Node);
//	stack<binaryTree*> s;
//	binaryTree* p = Node;
//	cout << "后序遍历为：";
//	binaryTree* prev = NULL;
//	while (p != NULL || !s.empty())
//	{
//		while (p != NULL)
//		{
//			s.push(p);
//			p = p->_left;
//		}
//		binaryTree* node = s.top();
//		if (prev == node->_right || node->_right == NULL)
//		{
//			cout << node->_val << " ";
//			prev = node;
//			s.pop();
//		}
//		else
//		{
//			p = node->_right;
//		}
//	}
//	cout << endl;
//}
//
//void Text()
//{
//	binaryTree* node = new binaryTree(1);
//	binaryTree* node1 = new binaryTree(2);
//	binaryTree* node2 = new binaryTree(3);
//	binaryTree* node3 = new binaryTree(4);
//	binaryTree* node4 = new binaryTree(5);
//	binaryTree* node5 = new binaryTree(6);
//	binaryTree* node6 = new binaryTree(7);
//
//	node->_left = node1;
//	node->_right = node2;
//	node1->_left = node3;
//	node3->_left = node4;
//	preOrder(node);
//	inOrder(node);
//	postOrder(node);
//}
//2、已知集合A和B的元素分别用不含头结点的单链表存储，函数difference()用于求解集合A与B的差集，并将结果保存在集合A的单链表中。例如，若集合A={5,10,20,15,25,30}，集合B={5,15,35,25}，完成计算后A={10,20,30}。 
//链表结点的结构类型定义如下：请完成函数void difference(node** LA, node* LB)；
struct node
{
	int elem;
	node* next;
	node(int val)
		:elem(val)
		, next(NULL)
	{}
};

void difference(node** LA, node* LB)
{
	assert(*LA);
	assert(LB);
	node* head = NULL;
	node* begin = NULL;
	node* node1 = *LA;
	node* p2 = LB;
	while (node1 != NULL)
	{
		int flag = 0;

		node* prev2 = NULL;
		node* node2 = p2;
		while (node2 != NULL)
		{
			if (node1->elem == node2->elem)
			{
				flag = 1;
				(prev2 == NULL) ? (p2 = node2->next) : (prev2->next = node2->next);
				break;
			}
			else
			{
 				prev2 = node2;
				node2 = node2->next;
				continue;
			}
		}
		if (flag  == 0)
		{
			if (begin == NULL)
				head = begin = node1;
			else
			{
				begin->next = node1;
				begin = begin->next;
			}
		}
		node1 = node1->next;
	}
	*LA = head;
}
void Text()
{
	node* A = new node(5);
	node* A1 = new node(10);
	node* A2 = new node(20);
	node* A3 = new node(15);
	node* A4 = new node(25);
	node* A5 = new node(30);
	A->next = A1;
	A1->next = A2;
	A2->next = A3;
	A3->next = A4;
	A4->next = A5;

	node* B = new node(5);
	node* B1 = new node(35);
	node* B2 = new node(25);
	node* B3 = new node(15);
	B->next = B1;
	B1->next = B2;
	B2->next = B3;
	difference(&A, B);
}
