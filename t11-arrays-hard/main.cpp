#include <iostream>
#include <set>
using namespace std;

void printArr(vector<int> &arr)
{
	for (int i : arr)
		cout << i << " ";
	cout << endl;
}

// O(r)
long long computeNCR(int n, int r)
{
	long long res = 1;
	for (int i = 0; i < r; i++)
	{
		res *= (n - i);
		res /= (i + 1);
	}
	return res;
}

// O(r)
// Prints value at (r, c) in Pascal's Triangle (1-indexed)
void printPascalCell(int r, int c)
{
	// 1
	// 1 1
	// 1 2 1
	// 1 3 3 1
	// 1 4 6 4 1
	cout << computeNCR(r - 1, c - 1) << endl;
}

// O(r)
// Efficiently prints the r-th row of Pascal's Triangle (0-indexed)
void printPascalRow(int r)
{
	int res = 1;
	for (int i = 0; i <= r; i++)
	{
		cout << res << " ";
		res *= (r - i);
		res /= (i + 1);
	}
	cout << endl;
}

// O(n^2)
// Prints Pascal's Triangle up to n rows
void printPascalTriangle(int n)
{
	for (int r = 0; r < n; r++)
	{
		int res = 1;
		printPascalRow(r);
	}
}

// O(n)
// Element present more than N/3 times
void majorityElement(vector<int> &arr)
{
	int n = arr.size();
	unordered_map<int, int> mpp;
	for (int i : arr)
		mpp[i]++;
	for (auto it : mpp)
		if (it.second > n / 3)
			cout << it.first << " ";
	cout << endl;
}

// O(n)
// Element present more than N/3 times
void majorityElement2(vector<int> &arr)
{
	int n = arr.size();
	unordered_map<int, int> mpp;
	vector<int> res;
	for (int num : arr)
	{
		mpp[num]++;
		if (mpp[num] == n / 3 + 1)
			res.push_back(num);
		if (res.size() == 2)
			break;
	}
	for (int i : res)
		cout << i << " ";
	cout << endl;
}

// O(n)
// Element present more than N/3 times
void majorityElement3(vector<int> &arr)
{
	int n = arr.size();
	int cnt1 = 0, cnt2 = 0;
	int el1, el2;
	for (int i = 0; i < n; i++)
	{
		if (!cnt1 && arr[i] != el2)
		{
			cnt1 = 1;
			el1 = arr[i];
		}
		else if (!cnt2 && arr[i] != el1)
		{
			cnt2 = 1;
			el2 = arr[i];
		}
		else if (arr[i] == el1)
		{
			cnt1++;
		}
		else if (arr[i] == el2)
		{
			cnt2++;
		}
		else
		{
			cnt1--;
			cnt2--;
		}
	}
	int nCnt1 = 0, nCnt2 = 0;
	for (int num : arr)
	{
		if (num == el1)
			nCnt1++;
		else if (num == el2)
			nCnt2++;
	}
	if (nCnt1 > n / 3)
		cout << el1 << " ";
	if (nCnt2 > n / 3)
		cout << el2 << endl;
}

void threeSum(vector<int> &arr)
{
	int n = arr.size();
	set<vector<int>> res;
	vector<int> ans;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				if (arr[i] + arr[j] + arr[k] == 0)
				{
					ans = {arr[i], arr[j], arr[k]};
					sort(ans.begin(), ans.end());
					res.insert(ans);
				}
	for (auto it : res)
	{
		for (int num : it)
			cout << num << " ";
		cout << endl;
	}
}

void threeSum2(vector<int> &arr)
{
	int n = arr.size();
	set<vector<int>> res;
	for (int i = 0; i < n; i++)
	{
		set<int> mpp;
		for (int j = i + 1; j < n; j++)
		{
			int k = 0 - arr[i] - arr[j];
			if (mpp.find(k) != mpp.end())
			{
				vector<int> ans = {arr[i], arr[j], k};
				sort(ans.begin(), ans.end());
				res.insert(ans);
			}
			mpp.insert(arr[j]);
		}
	}
	for (auto it : res)
	{
		for (int num : it)
			cout << num << " ";
		cout << endl;
	}
}

void threeSum3(vector<int> &arr)
{
	sort(arr.begin(), arr.end());
	int n = arr.size();
	vector<vector<int>> res;
	for (int i = 0; i < n; i++)
	{
		if (i != 0 && arr[i] == arr[i - 1])
			continue;
		int j = i + 1, k = n - 1;
		while (j < k)
		{
			int sum = arr[i] + arr[j] + arr[k];
			if (sum < 0)
				j++;
			else if (sum > 0)
				k--;
			else
			{
				res.push_back({arr[i], arr[j], arr[k]});
				j++;
				k--;
				while (j < k && arr[j] == arr[j - 1])
					j++;
				while (j < k && arr[k] == arr[k + 1])
					k--;
			}
		}
	}
	for (auto it : res)
	{
		for (int num : it)
			cout << num << " ";
		cout << endl;
	}
}

void fourSum(vector<int> &arr, int target = 0)
{
	int n = arr.size();
	set<vector<int>> res;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				for (int l = k + 1; l < n; l++)
					if (arr[i] + arr[j] + arr[k] + arr[l] == target)
					{
						vector<int> quads = {arr[i], arr[j], arr[k], arr[l]};
						sort(quads.begin(), quads.end());
						res.insert(quads);
					}
	for (auto it : res)
	{
		for (int num : it)
			cout << num << ' ';
		cout << endl;
	}
}

void fourSum2(vector<int> &arr, int target = 0)
{
	int n = arr.size();
	set<vector<int>> res;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			set<int> mpp;
			for (int k = j + 1; k < n; k++)
			{
				int fourth = target - (arr[i] + arr[j] + arr[k]);
				if (mpp.find(fourth) != mpp.end())
				{
					vector<int> quads = {arr[i], arr[j], arr[k], fourth};
					sort(quads.begin(), quads.end());
					res.insert(quads);
				}
				mpp.insert(arr[k]);
			}
		}
	for (auto it : res)
	{
		for (int num : it)
			cout << num << ' ';
		cout << endl;
	}
}

void fourSum3(vector<int> arr, int target = 0)
{
	sort(arr.begin(), arr.end());
	vector<vector<int>> res;
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && arr[i] == arr[i - 1])
			continue;
		for (int j = i + 1; j < n; j++)
		{
			if (j > i + 1 && arr[j] == arr[j - 1])
				continue;
			int k = j + 1, l = n - 1;
			while (k < l)
			{
				int sum = arr[i] + arr[j] + arr[k] + arr[l];
				if (sum < 0)
					k++;
				else if (sum > 0)
					l--;
				else
				{
					res.push_back({arr[i], arr[j], arr[k], arr[l]});
					k++;
					l--;
					while (k < l && arr[k] == arr[k - 1])
						k++;
					while (k < l && arr[l] == arr[l + 1])
						l--;
				}
			}
		}
	}
	for (auto it : res)
	{
		for (int num : it)
			cout << num << " ";
		cout << endl;
	}
}

void fourSum4(vector<int> &arr, int target = 0)
{
}

int main()
{
	int r, c;
	cin >> r >> c;
	// Pascal Triangle
	// Variation 1
	printPascalCell(r, c);
	cout << "---------------------------" << endl;
	// Variation 2
	printPascalRow(r);
	cout << "---------------------------" << endl;
	// Variation 3
	printPascalTriangle(r);
	cout << "---------------------------" << endl;
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int &a : arr)
		cin >> a;
	printArr(arr);
	majorityElement(arr);
	cout << "---------------------------" << endl;
	printArr(arr);
	majorityElement2(arr);
	cout << "---------------------------" << endl;
	printArr(arr);
	majorityElement3(arr);
	cout << "---------------------------" << endl;
	cin >> n;
	arr.resize(n);
	for (int &a : arr)
		cin >> a;
	printArr(arr);
	threeSum(arr);
	cout << "---------------------------" << endl;
	printArr(arr);
	threeSum2(arr);
	cout << "---------------------------" << endl;
	printArr(arr);
	threeSum3(arr);
	cout << "---------------------------" << endl;
	for (int &a : arr)
		cin >> a;
	printArr(arr);
	fourSum(arr);
	cout << "---------------------------" << endl;
	printArr(arr);
	fourSum2(arr);
	cout << "---------------------------" << endl;
	printArr(arr);
	fourSum3(arr, 8);
	cout << "---------------------------" << endl;
	printArr(arr);
	fourSum4(arr);
	cout << "---------------------------" << endl;

	return 0;
}