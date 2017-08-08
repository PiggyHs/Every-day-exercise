#pragma once

#include<iostream>
#include<stack>
using namespace std;

int mid(int*arr, int left, int right)  //三数取中法 使基准中间数存于right
{
	int Mid = (left + right) / 2;
	if (arr[left] > arr[Mid])
		swap(arr[left], arr[Mid]);
	if (arr[left] > arr[right])
		swap(arr[left], arr[right]);
	if (arr[Mid] < arr[right])
		swap(arr[Mid], arr[right]);
	return right;
}

int PastSort1(int *arr, int left, int right)  //挖坑法
{
	int begin = left;
	int end = right;
	int temp = arr[mid(arr, left, right)];
	while (begin < end)
	{
		while (begin < end && arr[begin] <= temp)
			begin++;
		if (begin < end)
			arr[end] = arr[begin];//begin成为新坑
		while (begin < end && arr[end] >= temp)
			end--;
		if (begin < end)
			arr[begin] = arr[end];  //end成为新坑
	}

	arr[begin] = temp;  //将temp填补进去
	return begin;
}

int PastSort2(int* arr, int left, int right)  //前后指针法
{
	int cur = left;  //找小
	int ptr = left - 1;//找大
	int temp = arr[mid(arr, left, right)];
	while (cur < right)
	{
		if (arr[cur] < temp)
		{
			swap(arr[cur], arr[++ptr]);
		}
		cur++;
	}
	swap(arr[++ptr], arr[right]);
	return ptr;
}

void QuickSort(int *arr, int left, int right)
{
	if (arr == NULL || left > right)
		return;

	int pos = PastSort2(arr, left, right);

	QuickSort(arr, left, pos - 1);
	QuickSort(arr, pos + 1, right);
}
void QuickSort_NoF(int *arr, int left, int right)//非递归版本
{
	if (arr == NULL || left > right)
		return;
	stack<int> s;
	s.push(left);
	s.push(right);
	while (!s.empty())
	{
		int Right = s.top();
		s.pop();
		int Left = s.top();
		s.pop();

		if (Left < Right)
		{
			int mid = PastSort1(arr, Left, Right);
			//左
			s.push(Left);
			s.push(mid - 1);
			//
			s.push(mid + 1);
			s.push(Right);
		}
	}
}
void Text()
{
	int arr[] = { 3, 5, 7, 8, 2, 9, 1, 5, 8, 0 };
	//QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
	QuickSort_NoF(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1); 

}