#pragma once

#include<stack>
#include<queue>
#include<iostream>
using namespace std;

//class Queue{   //两个栈模拟实现队列
//public:
//	void push(int node) {
//		s1.push(node);
//	}
//
//	int pop() {
//		if (s2.empty())
//		{
//			while (!s1.empty())
//			{
//				int temp = s1.top();
//				s1.pop();
//				s2.push(temp);
//			}
//		}
//		if (s2.size() == 0)
//		{
//			return NULL;
//		}
//		int top = s2.top();
//			s2.pop();
//			return top;
//	}
//private:
//	stack<int> s1;
//	stack<int> s2;
//};
//
//class Stack{   //两个队列实现栈
//public:
//	void push(int node) {
//
//		q1.push(node);
//	}
//
//	int pop() {
//		if (q2.empty() && !q1.empty())
//		{
//			while (q1.size() > 1)
//			{
//				int temp = q1.front();
//				q2.push(temp);
//				q1.pop();
//			}
//			int pop = q1.front();
//			q1.pop();
//			return pop;
//		}
//		if (q1.empty() && !q2.empty())
//		{
//			while (q2.size() > 1)
//			{
//				int temp = q2.front();
//				q1.push(temp);
//				q2.pop();
//			}
//			int pop = q2.front();
//			q2.pop();
//			return pop;
//		}
//		if (q1.empty() && q2.empty())
//			return NULL;
//	}
//private:
//	queue<int> q1;
//	queue<int> q2;
//};
//
//void Text()  //测试用例
//{
//	Stack s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.push(4);
//	s.push(5);
//	cout << s.pop();
//	cout << s.pop();
//	cout << s.pop();
//	cout << s.pop();
//	cout << s.pop();
//	cout << s.pop() << endl;
//	Queue q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);
//	q.push(5);
//	cout << q.pop();
//	cout << q.pop();
//	cout << q.pop();
//	cout << q.pop();
//	cout << q.pop();
//	cout << q.pop()<<endl;
//}

void replaceSpace(char *str, int length) ///空格替换
{
	int count = 0;
	int  oldend = 0;
	while (str[oldend] != '\0')
	{
		oldend++;
		if (str[oldend] == ' ')
			count++;
	}

	int newend = count * 2 + oldend;
	if (newend > length)
		return;
	while (oldend >= 0 && newend >= oldend)
	{
		if (str[oldend] == ' ')
		{
			str[newend--] = '$';
			str[newend--] = '$';
			str[newend--] = '$';
		}
		else
		{
			str[newend--] = str[oldend];
		}
		--oldend;
	}
}

void Text()   //测试用例
{
	char str[50] = "talk is cheap show me the code";
	replaceSpace(str, 50);

	for (int i = 0; i < strlen(str); i++)
	{
		cout << str[i];
	}
	cout << endl;
}