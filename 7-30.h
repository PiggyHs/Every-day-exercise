#pragma once
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<assert.h>
#include<string>
using namespace std;

//void InsertSort(int* arr, int size)  //插入排序
//{
//	if (arr == NULL || size <= 0)
//		return;
//	for (int i = 1; i < size; i++)
//	{
//		int j = i;
//		int temp = arr[i];
//		while (j>0 && temp < arr[j - 1])
//		{
//			arr[j] = arr[j - 1];
//			j--;
//		}
//		arr[j] = temp;  //插入
//	}
//}
//
//void Ajustdown(int* arr, int pos, int size)
//{
//	int parent = pos;
//	int child = parent * 2 + 1;
//	while (child <= size)
//	{
//		if (child < size && arr[child] < arr[child + 1])
//			child++;
//
//		if (arr[parent] < arr[child])
//		{
//			swap(arr[parent], arr[child]);
//			parent = child;
//			child = child * 2 + 1;
//		}
//		else
//			break;
//	}
//}
//void Ajustdown(int *arr, int size)
//{
//	int pos = (size - 2) / 2;
//	while (pos >= 0)
//	{
//		Ajustdown(arr, pos, size-1);
//		pos--;
//	}
//}
//
//void Heap_sort(int*arr, int size)
//{
//	Ajustdown(arr, size);
//
//	while (size > 1)
//	{
//		int temp = arr[0];
//		arr[0] = arr[size - 1]; 
//		arr[size - 1] = temp;
//		size--;
//		Ajustdown(arr, size);
//	}
//}
//
//void select_sort(int* arr,int size)
//{
//	assert(arr);
//	int min;
//	int i;
//	for (i = 0; i < size-1; i++)
//	{
//		min = i;
//		for (int j = i+1; j < size; j++)
//		{
//			if (arr[min] > arr[j])
//			{
//				min = j;
//			}
//		}
//		if (min != i)
//		{
//			int temp = arr[i];
//			arr[i] = arr[min];
//			arr[min] = temp;
//		}
//	}
//}
//void Text()
//{
//	int arr[] = { 1, 3, 4, 2, 5 };
//	select_sort(arr, sizeof(arr) / sizeof(arr[0]));
//}

void PrintMap(const map<string, int>& fruit)  //打印map内容
{
	map<string, int>::const_iterator inter = fruit.begin();
	while (inter != fruit.end())
	{
		cout << (*inter).first << " :" << (*inter).second << " ";
		inter++;
	}
	cout << endl;
}

void GetFavoriteFruit(const vector<string>& fruits,size_t k)  //获取前K个喜爱的水果
{
	map<string, int> countfruit;
	for (int i = 0; i < fruits.size(); i++)
	{
		countfruit[fruits[i]]++;
	}

	PrintMap(countfruit);

	vector<map<string, int>::iterator> v;
	map<string, int>::iterator begin = countfruit.begin();
	while (begin != countfruit.end())
	{
		v.push_back(begin);
		begin++;
	}

	struct Complate
	{
		bool operator()(map<string, int>::iterator l1, map<string, int>::iterator l2)
		{
			return (*l1).second > (*l2).second;
		}
	};

	sort(v.begin(), v.end(), Complate());

	for (int i = 0; i < k; i++)
	{
		cout << (*v[i]).first << ":" << (*v[i]).second << "    ";
		if (i !=0 && i % 5 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

void Text()
{
	vector<string> fruit;
	string fruits[] = { "苹果", "葡萄", "苹果", "葡萄", "香蕉", "西瓜", "西瓜", "西瓜", "西瓜", "西瓜", "西瓜", "西瓜", "西瓜", "苹果", "苹果", "苹果", "苹果" };
	for (int i = 0; i < sizeof(fruits) / sizeof(fruits[0]); i++)
	{
		fruit.push_back(fruits[i]);
	}
	GetFavoriteFruit(fruit, 3);
}

