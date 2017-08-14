#pragma once

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int GetValue(const vector<int>& v, int n)
{
	if (v.size() != n || v.size() == 0)
		return 0;
	map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		m[v[i]]++;
	}
	map<int, int>::iterator l1 = m.begin();
	while (l1 != m.end())
	{
		if (l1->second >(n / 2))
		{
			return l1->first;
		}
		l1++;
	}
	return 0;
}
void Text()
{
	vector<int> v;
	int arr[] = { 1, 2, 3, 2, 2 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		v.push_back(arr[i]);
	}
	cout << GetValue(v, sizeof(arr) / sizeof(arr[0])) << endl;

	vector<int> v1;
	int arr1[] = { 1, 2, 3, 4, 5,3,4,5,6,7,8,9,0,12,34,2,4,5,6,7,4,3,3,3,3,3,3,3,3,3,3,3,3,3};
	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		v1.push_back(arr1[i]);
	}
	cout << GetValue(v1, sizeof(arr1) / sizeof(arr1[0])) << endl;

	vector<int> v3;
	cout << GetValue(v3, 0) << endl;
}