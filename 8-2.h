#pragma once
#include<iostream>
#include<assert.h>

void MergeSort(int arr[], int startIndex, int midIndex, int endIndex)
{
	
	int start = startIndex; int mid = midIndex + 1; int i = 0;
	while (start <= midIndex && mid <= endIndex)
	{
		if (arr[start] > arr[mid])
		{
			str[i++] = arr[mid++];
		}
		else
		{
			str[i++] = arr[start++];
		}
	}
	while (start <= midIndex)
	{
		str[i++] = arr[start++];
	}
	while (mid <= endIndex)
	{
		str[i++] = arr[mid++];
	}
	for (int j = 0; j <= endIndex; j++)
	{
		arr[j] = str[j];
	}
}
void MergeSort(int sourceArr[], int startIndex, int endIndex)
{
	assert(sourceArr);
	int mid;
	if (startIndex < endIndex)
	{
		mid = (startIndex + endIndex) / 2;
		MergeSort(sourceArr, startIndex, mid);
		MergeSort(sourceArr, mid + 1, endIndex);
		MergeSort(sourceArr, startIndex, mid, endIndex);
	}
}
void Text()
{
	int arr[] = { 3, 5, 7, 8, 2, 9, 1, 5, 8, 0 };
	MergeSort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
}