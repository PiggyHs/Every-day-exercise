#pragma once
#include<iostream>
#include<stack>
#include<assert.h>

//void MergeSort(int arr[], int left, int midIndex, int right)
//{
//	int* str = new int[right - left + 1];
//	int i = left; int j = midIndex + 1; int k = 0;
//	while (i <= midIndex && j <= right)
//	{
//		if (arr[i] > arr[j])
//		{
//			str[k++] = arr[j++];
//		}
//		else
//		{
//			str[k++] = arr[i++];
//		}
//	}
//	while (i <= midIndex)
//	{
//		str[k++] = arr[i++];
//	}
//	while (j <= right)
//	{
//		str[k++] = arr[j++];
//	}
//	for (int p = 0; p <= (right-left); p++)
//	{
//		arr[left+p] = str[p];
//	}
//}
//void MergeSort(int sourceArr[], int startIndex, int endIndex)
//{
//	assert(sourceArr);
//	int mid;
//	if (startIndex < endIndex)
//	{
//		mid = (startIndex + endIndex) / 2;
//		MergeSort(sourceArr, startIndex, mid);
//		MergeSort(sourceArr, mid + 1, endIndex);
//		MergeSort(sourceArr, startIndex, mid, endIndex);
//	}
//	return;
//}
//void Text()
//{
//	int arr[] = { 3, 5, 7, 8, 2, 9, 1, 5, 8, 0 };
//	MergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
//}

void CountSort(int arr[], int size)
{
	assert(arr);
	assert(size > 0);

	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}
	int length = max - min + 1;
	int* str = new int[length];

	memset(str, 0, sizeof(int*)*length);

	for (int j = 0; j < size; j++)
	{
		int pos = arr[j];
		if (min != 0)
	 pos = arr[j] % min;
		str[pos]++;
	}
	int index = 0;
	for (int i = 0; i < length; i++)
	{
		while (str[i] != 0)
		{
			arr[index++] = i;
			str[i]--;
		}
	}

}
void Text()
{
	int arr[] = { 3, 5, 7, 8, 2, 9, 1, 5, 8, 0 };
	CountSort(arr, sizeof(arr) / sizeof(arr[0]));
}

int mid(int* arr, int left, int right) //三数取中
{
	int mid = (left + right) / 2;
	if (arr[left] > arr[mid])
		swap(arr[left], arr[mid]);
	if (arr[left] > arr[right])
		swap(arr[left], arr[right]);
	if (arr[mid] < arr[right])
		swap(arr[mid], arr[right]);
	return right;
}

int PastSort(int* arr, int start, int end)
{
	assert(arr);
	int left = start;
	int right = end;
	int midnum = arr[mid(arr, start, end)];
	while (left < right)
	{
		while (left < right && arr[left] <= midnum)
			left++;
		if (left < right)
			arr[right] = arr[left];
		while (left < right && arr[right] >= midnum)
			right--;
		if (left < right)
			arr[left] = arr[right];
	}
	arr[left] = midnum;
	return left;
}

int Fid_midnum(int* arr, int start, int end,int size) //求一个无序数组的中位数
{
	int index = (size - 1) / 2;
	if (start >= end)
		return 0;
	int mid = PastSort(arr, start, end);
	if (mid < index)
	{
		Fid_midnum(arr, mid + 1, end, size);
	}
	else if (mid > index)
	{
		Fid_midnum(arr, start, mid - 1, size);
	}
	else
	{
		return arr[index];
	}
}

void Ajustdown(int* arr, int pos, int size)
{
	int parent = pos;
	int child = parent * 2 + 1;
	while (child <= size)
	{
		if (child < size && arr[child] < arr[child + 1])
			child + 1;
		if (arr[parent] < arr[child])
		{
			swap(arr[parent], arr[child]);
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void Ajustdown(int *arr, int size)
{
	int pos = (size - 2) / 2;
	while (pos >= 0)
	{
		Ajustdown(arr, pos, size - 1);
		pos--;
	}
}

void Heap_sort(int*arr, int size)
{
	Ajustdown(arr, size);

	while (size > 1)
	{
		int temp = arr[0];
		arr[0] = arr[size - 1];
		arr[size - 1] = temp;
		size--;
		Ajustdown(arr, size);
	}
}
int Fid_midnum(int* arr, int start, int end, int size) //求一个无序数组的中位数
{
	int index = (size + 1) / 2;
	int* str = arr;
	int i;
	for (i = 0; i < index; i++)
	{
		str[i] = arr[i];
	}
	Ajustdown(str, index);
	for (int j = i; j < size; j++)
	{
		if (str[0] > arr[j])
		{
			swap(str[0], arr[j]);
		}
		Ajustdown(str, index);
	}
	return str[0];
}
void Text()
{
	int arr[] = { 2,5, 4, 9, 3, 6, 8, 7, 1 };
	int i = Fid_midnum(arr, 0, sizeof(arr) / sizeof(arr[0]), sizeof(arr) / sizeof(arr[0]));
}