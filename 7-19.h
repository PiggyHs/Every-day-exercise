#pragma once
#include<iostream>
using namespace std;
#include<assert.h>

template<class T>
class Stack      //实现一个栈Stack
{
public:
	Stack()
	:_val(NULL)
	, _size(0)
	, _capacity(0)
	{}

	~Stack()
	{
		if (_val != NULL)
		{
			delete[] _val;
			_val = NULL;
		}
		_size = 0;
		_capacity = 0;
	}

	void push(const T& data)
	{
		Check_Capacity();
		if (_size == 0)
		{
			_min[_size] = data;
		}
		else if (data < _min[_size - 1])
		{
			_min[_size] = data;
		}
		else
			_min[_size] = _min[_size - 1];

		_val[_size] = data;
		_size++;

	}

	void pop()
	{
		if (Emplty())
		{
			cout << "栈已经为空" << endl;
			return;
		}
		else
		_size--;
	}

	T Top()
	{
		assert(_size > 0);
		return _val[_size - 1];
	}
	T Min()
	{
		return _min[_size - 1];
	}
	bool Emplty()
	{
		return _size == 0 ? 1 : 0;
	}
	int Size()
	{
		return _size;
	}

	bool Full()
	{
		return _size == _capacity ? 1 : 0;
	}

private:
	void Check_Capacity()
	{
		if (Full())
		{
			int NewCapacity = _capacity * 2 + 1;
			T* tmp = new T[NewCapacity];
			T* mintmp = new T[NewCapacity];
			for (int i = 0; i < _size; ++i)
			{
				tmp[i] = _val[i];
				mintmp[i] = _min[i];
			}
			delete[] _val;
			delete[] _min;
			_min = mintmp;
			_val = tmp;
			_capacity = NewCapacity;
		}
	}
private:
	T* _val;
	T* _min;
	size_t _size;
	size_t _capacity;
};

void Text()
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	cout << "栈的数据数量："<<s.Size() << endl;
	cout << "栈是否满：" << s.Full() << endl;
	cout << "栈是否空：" << s.Emplty() << endl;
	s.pop();
	s.push(0);
	cout << "栈中最小的数据：" << s.Min() << endl;
}


char Find_FirstTwoStr(char* str)  //查找一个字符串中第一个只出现两次的字符
{
	char order[256] ={0,};
	int hashtable[256] = {0,};
	int i = 0;
	int j;
	char tmp;
	for (size_t size = 0; size < strlen(str);size++)
	{
		if (hashtable[str[size]] == 0)
			order[i++] = str[size];

		hashtable[str[size]]++;
	}

	for (j = 0; j < i; j++)
	{
		if (hashtable[order[j]] == 2)
		{
			tmp = order[j];
			break;
		}
	}

	if (j == i)
	{
		return '#';
	}
	else
		return tmp;

}

void Text()
{
	char* str = "abcabca";
	cout << Find_FirstTwoStr(str) << endl;
}
