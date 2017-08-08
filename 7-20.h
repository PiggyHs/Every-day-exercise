#pragma once
#include<iostream>
#include<stack>
using namespace std;

bool RightPop(int* push,int* pop,const int length) //
{
	bool flag = false;

	if (pop != NULL && push != NULL && length > 0)
	{
		int* ppop = pop;
		int* ppush = push;
		stack<int> s;
		while (ppop - pop < length)//判断输出序列是否为空
		{
			while (s.empty() || s.top() != *ppop)  //判断是栈是否为空，或者栈顶数据与出栈数组中的数字是否相同.
			{
				if (ppush - push == length)//判断输入序列是否为空
					break;

				s.push(*ppush);
				ppush++;
			}
			if (s.top() != *ppop)
				break;

			s.pop();
			ppop++;
		}
		if (s.empty() && ppop - pop == length)
			flag = true;
	}
	return flag;

}

void Text()
{
	int pop[] = {4,5,3,2,1};
	int push[] = {1,2,3,4,5};
	cout << "出栈顺序是否合法" << RightPop(push, pop, 5) << endl;
}

int one_nums(int num)
{
	int count = 0;
	while (num != 0)
	{
		++count;
		num = (num - 1) & num;
	}

	return count;
}

void Text()
{

	cout << one_nums(-1) << endl;
}