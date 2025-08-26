#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

// ==================== Find Missing and Duplicate ====================

// Time: O(n log n), Space: O(1)
// Finds missing and duplicate elements by sorting and comparing adjacent elements
void findMissingAndDuplicate(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            cout << "Duplicate: " << arr[i] << endl;
        else if (arr[i] - 1 != arr[i - 1])
            cout << "Missing: " << arr[i] - 1 << endl;
    }
}

// Time: O(n^2), Space: O(1)
// Naive approach: counts frequency of each number to find missing and duplicate
void findMissingAndDuplicate_1(vector<int> &arr)
{
    int n = arr.size(), freq = 0;
    int mis = -1, dup = -1;
    for (int i = 1; i <= n; i++)
    {
        freq = 0;
        for (int j = 0; j < n; j++)
            if (i == arr[j])
                freq++;

        if (freq > 1)
            cout << "Duplicate: " << i << endl;
        else if (freq == 0)
            cout << "Missing: " << i << endl;
        if (dup != -1 && mis != -1)
            break;
    }
}

// Time: O(n), Space: O(n)
// Uses hash map to count frequencies and find missing and duplicate
void findMissingAndDuplicate_2(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mpp;
    for (int i : arr)
        mpp[i]++;
    for (int i = 1; i <= n; i++)
    {
        if (mpp[i] == 0)
            cout << "Missing: " << i << endl;
        else if (mpp[i] > 1)
            cout << "Duplicate: " << i << endl;
    }
}

// Time: O(n), Space: O(1)
// Uses index marking by negation to find missing and duplicate in-place
void findMissingAndDuplicate_3(vector<int> arr)
{
    int n = arr.size();
    int dup = -1, missing = -1;

    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i]) - 1;
        if (arr[index] < 0)
            dup = abs(arr[i]);
        else
            arr[index] = -arr[index];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            missing = i + 1;
            break;
        }
    }
    cout << "Missing: " << missing << endl;
    cout << "Duplicate: " << dup << endl;
}

// Time: O(n), Space: O(1)
// Uses mathematical formulas for sum and sum of squares to find missing and duplicate
void findMissingAndDuplicate_4(vector<int> &arr)
{
    int n = arr.size();
    long long arraySum = 0, array2Sum = 0;

    for (int i = 0; i < n; i++)
    {
        arraySum += arr[i];
        array2Sum += (long long)arr[i] * arr[i];
    }

    long long nSum = (long long)n * (n + 1) / 2;
    long long n2Sum = (long long)n * (n + 1) * (2 * n + 1) / 6;

    long long firstEq = nSum - arraySum;             // missing - duplicate
    long long secEq = (n2Sum - array2Sum) / firstEq; // missing + duplicate

    long long missing = (firstEq + secEq) / 2;
    long long duplicate = secEq - missing;

    cout << "Missing: " << missing << endl;
    cout << "Duplicate: " << duplicate << endl;
}

// Time: O(n), Space: O(1)
// Uses XOR operation and bit manipulation to find missing and duplicate
void findMissingAndDuplicate_5(vector<int> &arr)
{
    int n = arr.size();
    int xr = 0;
    for (int i = 0; i < n; i++)
    {
        xr ^= arr[i];
        xr ^= (i + 1);
    }
    // Find rightmost set bit in xor result
    int bitNo = 0;
    while (1)
    {
        if ((xr & (1 << bitNo)) != 0)
            break;
        bitNo++;
    }
    int zero = 0, one = 0;
    for (int i = 0; i < n; i++)
    {
        // Divide elements into two sets based on bitNo and XOR separately
        if ((arr[i] & (1 << bitNo)) != 0)
            one ^= arr[i];
        else
            zero ^= arr[i];
        if (((i + 1) & (1 << bitNo)) != 0)
            one ^= (i + 1);
        else
            zero ^= (i + 1);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == one)
            cnt++;
    }
    if (cnt > 1)
    {
        cout << "Missing: " << zero << endl;
        cout << "Duplicate: " << one << endl;
    }
    else
    {
        cout << "Missing: " << one << endl;
        cout << "Duplicate: " << zero << endl;
    }
}

// ==================== Count Inversion ====================

// Time: O(n^2), Space: O(1)
// Counts number of inversion pairs by checking all pairs
void countInversion(vector<int> &arr)
{
    int n = arr.size(), cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                cnt++;
                cout << "(" << arr[i] << "," << arr[j] << ")" << endl;
            }
        }
    }
    cout << cnt << endl;
}

// Helper function for merge sort that merges two sorted halves and counts inversions
// Time: O(n), Space: O(n)
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low, right = mid + 1;
    int cnt = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
        {
            cnt += (mid - left + 1);
            temp.push_back(arr[right++]);
        }
    }
    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];

    return cnt;
}

// Merge sort that counts inversions recursively
// Time: O(n log n), Space: O(n)
int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);

    cnt += merge(arr, low, mid, high);
    return cnt;
}

// Wrapper function to count inversions using merge sort
void countInversion_1(vector<int> &arr)
{
    cout << mergeSort(arr, 0, arr.size() - 1) << endl;
}

// ==================== Reverse Pairs ====================

// Time: O(n^2), Space: O(1)
// Counts number of reverse pairs (arr[i] > 2*arr[j]) by checking all pairs
void reversePairs(vector<int> &arr)
{
    int n = arr.size(), cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > (arr[j] * 2))
            {
                cnt++;
                cout << "(" << arr[i] << "," << arr[j] << ")" << endl;
            }
        }
    }
    cout << cnt << endl;
}

// Helper function to merge two sorted halves without counting pairs
// Time: O(n), Space: O(n)
void merge2(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
        {
            temp.push_back(arr[right++]);
        }
    }
    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

// Counts reverse pairs in the current segment using two pointers
// Time: O(n), Space: O(1)
int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1, cnt = 0;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && ((long long)arr[i] > ((long long)2 * arr[right])))
            right++;
        cnt += (right - (mid + 1));
    }

    return cnt;
}

// Merge sort variation to count reverse pairs recursively
// Time: O(n log n), Space: O(n)
int mergeSort2(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort2(arr, low, mid);
    cnt += mergeSort2(arr, mid + 1, high);
    cnt += countPairs(arr, low, mid, high);
    merge2(arr, low, mid, high);
    return cnt;
}

// Wrapper function to count reverse pairs using merge sort
void reversePairs_1(vector<int> &arr)
{
    cout << mergeSort2(arr, 0, arr.size() - 1) << endl;
}

// ==================== Maximum Product Subarray ====================

// Time: O(n^3), Space: O(1)
// Naive approach: checks product of every subarray
void maxProductSubArray(vector<int> &arr)
{
    int n = arr.size();
    int mul = 1, res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            mul = 1;
            for (int k = i; k < j; k++)
            {
                mul *= arr[k];
            }
            res = max(res, mul);
        }
    }
    cout << res << endl;
}

// Time: O(n^2), Space: O(1)
// Improved naive: calculates product on the fly for subarrays starting at i
void maxProductSubArray_1(vector<int> &arr)
{
    int n = arr.size();
    int mul = 1, res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mul = 1;
        for (int j = i; j < n; j++)
        {
            mul *= arr[j];
            res = max(res, mul);
        }
    }
    cout << res << endl;
}

// Time: O(n), Space: O(1)
// Uses prefix and suffix product to handle zeroes and negative numbers
void maxProductSubArray_2(vector<int> &arr)
{
    int n = arr.size();
    int prefixProduct = 1, suffixProduct = 1, res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        prefixProduct *= arr[i];
        suffixProduct *= arr[n - i - 1];
        if (prefixProduct == 0)
            prefixProduct = 1;
        if (suffixProduct == 0)
            suffixProduct = 1;
        res = max(res, max(prefixProduct, suffixProduct));
    }
    cout << res << endl;
}

// Kadane's algorithm variant for max product subarray considering negative products
// Time: O(n), Space: O(1)
void maxProductSubArray_3(vector<int> &arr)
{
    int prod1 = arr[0], prod2 = arr[0], res = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        int curr = arr[i];
        int temp = max({curr, prod1 * curr, prod2 * curr});
        prod2 = min({curr, prod1 * curr, prod2 * curr});
        prod1 = temp;
        res = max(res, prod1);
    }
    cout << res << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    findMissingAndDuplicate(arr);
    cout << "-------------------" << endl;
    findMissingAndDuplicate_1(arr);
    cout << "-------------------" << endl;
    findMissingAndDuplicate_2(arr);
    cout << "-------------------" << endl;
    findMissingAndDuplicate_3(arr);
    cout << "-------------------" << endl;
    findMissingAndDuplicate_4(arr);
    cout << "-------------------" << endl;
    countInversion(arr);
    cout << "-------------------" << endl;
    countInversion_1(arr);
    cout << "-------------------" << endl;
    for (int &a : arr)
        cin >> a;
    reversePairs(arr);
    cout << "-------------------" << endl;
    reversePairs_1(arr);
    cout << "-------------------" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    maxProductSubArray(arr);
    cout << "-------------------" << endl;
    maxProductSubArray_1(arr);
    cout << "-------------------" << endl;
    maxProductSubArray_2(arr);
    cout << "-------------------" << endl;
    maxProductSubArray_3(arr);
    cout << "-------------------" << endl;
    return 0;
}