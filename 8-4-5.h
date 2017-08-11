#pragma once
#include<iostream>
#include<assert.h>

//char*  Rotate_k(char* str, int k,int size) //将N个字符的数组，循环右移K位。时间复杂度O(N)
//{
//	assert(str);
//	if (k == 0)
//		return str;
//	else if (k > size)
//	{
//		k = size;
//	}
//		char * temp = new char[k+1];
//		memset(temp, 0, k + 1);
//		//char * tmp =(char*) malloc(k*sizeof(char));
//		char* end = str;
//		char* begin = str;
//		for (int i = k-1; i >= 0; i--)
//		{
//			temp[i] = *end++;
//		}
//
//		while (*end)
//		{
//			*begin++ = *end++;
//		}
//	    for (int i = 0; i < k; i++)
//		{
//			*begin++ = temp[i];
//		}
//		return str;
//}
//void Text()
//{
//	char arr[] = "abc";
//	char * str = Rotate_k(arr,9,strlen(arr));
//}
//char* Del_repetition(char*arr, int size) //删除小写字母字符串中重复字符。
////如果可以，优先删除重复字符中排在比他小字符前面的字符。 比如，输入：bbcacdww；输出：bacdw
//{
//	char* str = arr;
//	int* count = new int[256];
//	memset(count, 0, 256*sizeof(int*));
//	for (int i = 0; i < size; i++)
//	{
//		count[arr[i]]++;
//	}
//	for (int i = 0; i < size; i++)
//	{
//		if (count[arr[i]] > 1)
//		{
//			if (i < size - 1 && arr[i] <= arr[i + 1])
//			{
//				*str++ = arr[i];
//				count[arr[i]] = 0;
//			}
//			else
//				count[arr[i]]--;
//		}
//		else if (count[arr[i]] == 1)
//		{
//			*str++ = arr[i];
//			count[arr[i]] = 0;
//		}
//	}
//	*str = '\0';
//	return str;
//}
//void Text()
//{
//	char arr[] = "bbcacdww";
//	char * str = Del_repetition(arr,strlen(arr));
//}

#include<vector>
class BitMap
{
public:
	BitMap(size_t size)
	{
		_a.resize((size >> 5 + 1), 0);

	}

	bool set(size_t num) //添加数
	{
		int index = num >> 5; //寻找第几个int中
		int pos = num % 32;
		if ((1 << (31 - pos)) & _a[index])//存在
		{
			return false;
		}
		else
		{
			_a[index] |= (1 << (31 - pos));
			_size++;
		}
	}
	bool Reset(size_t num)//删除
	{
		int index = num >> 5;
		int pos = num % 32;
		if (Text(num))
		{
			_a[index] &= ~(1 << (31 - pos));
			return true;
		}
		else
			return false;
	}
	bool Text(size_t num)//查询是否存在
	{
		size_t index = num >> 5;
		size_t pos = num % 32;
		return _a[index] & (1 << (31 - pos));
	}
private:
	vector<int> _a;
	size_t _size;
};

void Text()
{

}