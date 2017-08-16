#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

// //
int main()
{
	int n;
	cin >> n;
	int i;
	vector<int> v1;
	int *arr = new int[n];
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		v1.push_back(arr[i]);
	}
	sort(v1.begin(), v1.end());
	vector<int> v2;

	int flag = 1;
	int left = -1;
	int right = n-1;

	v2.push_back(v1[n - 1]);
	while (left + 1 < right)
	{
		if (flag)
		{
			v2.insert(v2.begin(), v1[++left]);
			if (left+1 < right)
				v2.push_back(v1[++left]);
		}
		else
		{
			v2.insert(v2.begin(), v1[--right]);
			if (left+1 < right)
				v2.push_back(v1[--right]);
		}
		flag ^= 1;//保证一左一右
	}
	if (abs(v2[n - 1] - v2[n - 2]) < abs(v2[n - 1] - v2[0]))
	{
		//swap(v2[n - 2], v2[0]);
		int tmp = v2[n - 1];
		v2.erase(v2.end() - 1);
		v2.insert(v2.begin(), tmp);
	}
	int count = 0;
	for (i = 1; i < v2.size(); i++)
	{
		count += abs(v2[i] - v2[i - 1]);
	}
	cout << count << endl;
	return 0;
}
//string solve(int *arr, int n)//
//{
//	sort(arr, arr + n);
//	if (n <= 2)return "Possible";
//	else
//	{
//		int dex = arr[1] - arr[0];
//		int i = 2;
//		for (i; i < n; i++)
//		{
//			if ((arr[i] - arr[i - 1]) != dex)
//				return "Impossible";
//		}
//
//		return "Possible";
//	}
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	int *arr = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//	cout << solve(arr, n) << endl;
//	return 0;
//}

//int main()//网易3
//{
//	string s;
//	cin >> s;
//	int i, count = 1, cont = 1;
//	for (i = 1; i < s.size();i++)
//	{ 
//		if (s[i] != s[i - 1])
//			cont++;
//		else
//			cont = 1;
//		count = max(cont, count);
//	}
//	cout << count << endl;
//	return 0;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	int* arr = new int[n];
//	for (int i = 0; i < n; i++)
//		cin >> arr[i];
//	sort(arr, arr + n);
//
//	return 0;
//}
//int solve(int x, int f, int d, int p)
//{
//	int count = d / x;
//	if (count <= f)
//		return count;
//	else
//	{
//		d = (count - f)*x;
//	return f + d / (p + x);
//	}
//}
//int main()
//{
//	int x, f, d, p;
//	cin >> x >> f >>d >> p;
//	cout<< solve(x, f, d, p)<<endl;
//	return 0;
//}

//int main()
//{
//	int n;
//	int i;
//	cin >> n;
//	int* arr = new int[n];
//	for (i = 0; i < n; i++)
//		cin >> arr[i];
//
//	if (n % 2 == 0)
//	{
//		for (i = n - 1; i>0; i = i - 2)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << arr[0];
//		for (i = 2; i < n-1; i = i + 2)
//		{
//			cout << " "<<arr[i];
//		}
//	}
//	else
//	{
//		for (i = n - 1; i>0; i = i - 2)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << arr[0];
//		for (i = 1; i < n - 1; i += 2)
//		{
//			cout << " "<<arr[i];
//		}
//	}
//	return 0;
//}


int main()
{
	int n;
	cin >> n;
	int i;
	vector<int> v1;
	int *arr = new int[n];
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
		v1.push_back(arr[i]);
	}
	sort(v1.begin(), v1.end());
	vector<int> v2;

	int flag = 1;
	int left = -1;
	int right = n-1;

	v2.push_back(v1[n - 1]);
	while (left + 1 < right)
	{
		if (flag)
		{
			v2.insert(v2.begin(), v1[++left]);
			if (left+1 < right)
				v2.push_back(v1[++left]);
		}
		else
		{
			v2.insert(v2.begin(), v1[--right]);
			if (left+1 < right)
				v2.push_back(v1[--right]);
		}
		flag ^= 1;//保证一左一右
	}
	if (abs(v2[n - 1] - v2[n - 2]) < abs(v2[n - 1] - v2[0]))
	{
		//swap(v2[n - 2], v2[0]);
		int tmp = v2[n - 1];
		v2.erase(v2.end() - 1);
		v2.insert(v2.begin(), tmp);
	}
	int count = 0;
	for (i = 1; i < v2.size(); i++)
	{
		count += abs(v2[i] - v2[i - 1]);
	}
	cout << count << endl;
	return 0;
}