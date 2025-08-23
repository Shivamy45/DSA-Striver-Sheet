#include <iostream>
#include <set>
using namespace std;

// ================== Pascal Triangle ==================
// Time: O(r), Space: O(1)
void printArr(vector<int> &arr)
{
	for (int i : arr)
		cout << i << " ";
	cout << endl;
}

// Time: O(r), Space: O(1)
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

// Time: O(r), Space: O(1)
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

// Time: O(r), Space: O(1)
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

// Time: O(n^2), Space: O(1)
// Prints Pascal's Triangle up to n rows
void printPascalTriangle(int n)
{
	for (int r = 0; r < n; r++)
	{
		int res = 1;
		printPascalRow(r);
	}
}

// ================== Majority Element Variants ==================

// Time: O(n), Space: O(n)
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

// Time: O(n), Space: O(n)
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

// Time: O(n), Space: O(1)
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

// ================== Three Sum Variants ==================

// Time: O(n^3), Space: O(number of triplets)
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

// Time: O(n^2), Space: O(n)
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

// Time: O(n^2), Space: O(1)
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

// ================== Four Sum Variants ==================

// Time: O(n^4), Space: O(number of quadruplets)
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

// Time: O(n^3), Space: O(n)
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

// Time: O(n^3), Space: O(1)
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
				if (sum < target)
					k++;
				else if (sum > target)
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

// ================== Longest Subarray with Sum 0 Variants ==================

// Time: O(n^2), Space: O(1)
void longestSubArrayWithSum0(vector<int> &arr)
{
	int sum = 0, n = arr.size(), res = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			sum += arr[j];
			if (sum == 0)
				res = max(res, j - i + 1);
		}
	}
	cout << res << endl;
}

// Time: O(n), Space: O(n)
void longestSubArrayWithSum0_2(vector<int> &arr)
{
	int n = arr.size(), res = -1, sum = 0;
	unordered_map<int, int> mpp;
	for (int j = 0; j < n; j++)
	{
		sum += arr[j];
		if (sum == 0)
			res = j + 1;
		if (mpp.find(sum) != mpp.end())
			res = max(res, j - mpp[sum]);
		else
			mpp[sum] = j;
	}
	cout << res << endl;
}

// ================== XOR Subarray Variants ==================
// Time: O(n^3), Space: O(1)
void noOfSubarrayWithXorK(vector<int> &arr, int k)
{
	int n = arr.size();
	int xorr = 0, cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			xorr = 0;
			for (int k = i; k <= j; k++)
				xorr ^= arr[k];
			if (xorr == k)
				cnt++;
		}
	}
	cout << cnt << endl;
}
// Time: O(n^2), Space: O(1)
void noOfSubarrayWithXorK_2(vector<int> &arr, int k)
{
	int n = arr.size();
	int xorr = 0, cnt = 0;
	for (int i = 0; i < n; i++)
	{
		xorr = 0;
		for (int j = i; j < n; j++)
		{
			xorr ^= arr[j];
			if (xorr == k)
				cnt++;
		}
	}
	cout << cnt << endl;
}
// Time: O(n), Space: O(n)
void noOfSubarrayWithXorK_3(vector<int> &arr, int k)
{
	int n = arr.size();
	int xorr = 0, cnt = 0;
	unordered_map<int, int> mpp;
	mpp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		xorr ^= arr[i];
		// No need as we did mpp[0] = 1;
		// if (xorr == k)
		// 	cnt++;
		cnt += mpp[xorr ^ k]; // if xorr ^ k is not present it will give 0
		mpp[xorr]++;
	}
	cout << cnt << endl;
}

// ================== Interval Merging Variants ==================

// Time: O(n log n), Space: O(n)
//! Alternate approach: O(n^2) because of nested loop, less efficient
void mergeSubInterval(vector<vector<int>> &arr)
{
	int n = arr.size();
	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;
	for (int i = 0; i < n; i++)
	{
		// select an interval:
		int start = arr[i][0];
		int end = arr[i][1];

		// Skip all the merged intervals:
		if (!ans.empty() && end <= ans.back()[1])
			continue;

		// check the rest of the intervals:
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j][0] <= end)
				end = max(end, arr[j][1]);
			else
				break;
		}
		ans.push_back({start, end});
	}
	cout << "Intervals;" << endl;
	for (auto &it : ans)
		printArr(it);
}

// Time: O(n log n), Space: O(n)
//? Optimal approach: O(n log n) for sorting + O(n) merging
void mergeSubInterval_2(vector<vector<int>> &arr)
{
	sort(arr.begin(), arr.end());
	vector<vector<int>> res;
	res.push_back(arr[0]);

	for (int i = 1; i < arr.size(); i++)
	{
		if (res.empty() || arr[i][0] > res.back()[1])
			res.push_back(arr[i]);
		else
			res.back()[1] = max(res.back()[1], arr[i][1]);
	}
	cout << "Intervals:" << endl;
	for (auto &it : res)
		printArr(it);
}

// ================== Merge Sorted Arrays Variants ==================

// Time: O(n + m), Space: O(n + m)
void mergeSortedArrays(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int> res;
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (arr1[i] <= arr2[j])
			res.push_back(arr1[i++]);
		else
			res.push_back(arr2[j++]);
	}
	while (i < n)
		res.push_back(arr1[i++]);
	while (j < m)
		res.push_back(arr2[j++]);
	printArr(res);
}

// Time: O(n log n + m log m), Space: O(1)
void mergeSortedArrays_2(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int i = n - 1, j = 0;
	while (i >= 0 && j < m)
	{
		if (arr1[i] > arr2[j])
			swap(arr1[i], arr2[j]);
		else
			break;
	}
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	for (int i = 0; i < n + m; i++)
		if (i < n)
			cout << arr1[i] << " ";
		else
			cout << arr2[i - n] << " ";
	cout << endl;
}

// Time: O((n+m) log(n+m)), Space: O(1)
// Note: Implementation of Shell sort gap method for merging
void mergeSortedArrays_3(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	int gap = ceil((n + m) / 2.0);
	while (gap >= 1)
	{
		int i = 0, j = gap;
		while (j < n + m)
		{
			int val1 = (i < n) ? arr1[i] : arr2[i - n];
			int val2 = (j < n) ? arr1[j] : arr2[j - n];
			if (val1 > val2)
			{
				if (i < n && j < n)
					swap(arr1[i], arr1[j]);
				else if (i < n && j >= n)
					swap(arr1[i], arr2[j - n]);
				else
					swap(arr2[i - n], arr2[j - n]);
			}
			i++;
			j++;
		}
		if (gap == 1)
			break;
		gap = ceil(gap / 2.0);
	}
	for (int i = 0; i < n + m; i++)
		if (i < n)
			cout << arr1[i] << " ";
		else
			cout << arr2[i - n] << " ";
	cout << endl;
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
	fourSum(arr, 8);
	cout << "---------------------------" << endl;
	printArr(arr);
	fourSum2(arr, 8);
	cout << "---------------------------" << endl;
	printArr(arr);
	fourSum3(arr, 8);
	cout << "---------------------------" << endl;
	for (int &a : arr)
		cin >> a;
	printArr(arr);
	longestSubArrayWithSum0(arr);
	cout << "---------------------------" << endl;
	printArr(arr);
	longestSubArrayWithSum0_2(arr);
	cout << "---------------------------" << endl;
	cin >> n;
	arr.resize(n);
	for (int &a : arr)
		cin >> a;
	printArr(arr);
	noOfSubarrayWithXorK(arr, 6);
	cout << "---------------------------" << endl;
	printArr(arr);
	noOfSubarrayWithXorK_2(arr, 6);
	cout << "---------------------------" << endl;
	printArr(arr);
	noOfSubarrayWithXorK_3(arr, 6);
	cout << "---------------------------" << endl;
	cin >> n;
	vector<vector<int>> mat(n, vector<int>(2));
	for (auto &it : mat)
		for (int &a : it)
			cin >> a;
	for (auto it : mat)
		printArr(it);
	mergeSubInterval(mat);
	cout << "---------------------------" << endl;
	for (auto it : mat)
		printArr(it);
	mergeSubInterval_2(mat);
	cout << "---------------------------" << endl;
	int m;
	cin >> n >> m;
	vector<int> arr2(n);
	arr.resize(m);
	for (int &a : arr2)
		cin >> a;
	for (int &a : arr)
		cin >> a;
	printArr(arr2);
	printArr(arr);
	mergeSortedArrays(arr2, n, arr, m);
	cout << "---------------------------" << endl;
	printArr(arr2);
	printArr(arr);
	mergeSortedArrays_2(arr2, n, arr, m);
	cout << "---------------------------" << endl;
	printArr(arr2);
	printArr(arr);
	mergeSortedArrays_3(arr2, n, arr, m);
	cout << "---------------------------" << endl;

	return 0;
}