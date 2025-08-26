#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <climits>
using namespace std;

void printArr(vector<int> &arr)
{
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

//! Brute Force - O(n^2)
void twoSum(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                cout << "arr[" << i << "] + arr[" << j << "] => " << nums[i] << " + " << nums[j] << " = " << target << endl;
                return;
            }
        }
    }
}

//? Using Map - O(nlogn) and Using Unordered Map - O(n)/O(n^2)
void twoSum2(vector<int> &nums, int target)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = mpp.find(target - nums[i]);
        if (it != mpp.end())
        {
            cout << "arr[" << mpp[target - nums[i]] << "] + arr[" << i << "] = " << target - nums[i] << " + " << nums[i] << " => " << target << endl;
            return;
        }
        mpp[nums[i]] = i;
    }
}

//! Uses find() - Not suitable for interviews - O(n^2)
void twoSum3(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = find(nums.begin(), nums.end(), target - nums[i]);
        if (it != nums.end())
        {
            int x = distance(nums.begin(), it);
            if (i == x)
                continue;
            cout << "arr[" << i << "] + arr[" << x << "] = " << nums[i] << " + " << nums[x] << " => " << target << endl;
            return;
        }
    }
}

// Dutch National Flag Algo - 3 pointer
void sort0s1s2s(vector<int> &arr)
{
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid < high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low++], arr[mid++]);
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high--]);
        }
    }
}

void majorityElement(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[i] == nums[j])
                count++;
        }
        if (count > n / 2)
        {
            cout << nums[i] << " came " << count << " times in the array." << endl;
            return;
        }
    }
    cout << "None" << endl;
}

void majorityElement2(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }
    for (auto it : mpp)
    {
        if (it.second > n / 2)
        {
            cout << it.first << " came " << it.second << " times in the array." << endl;
            return;
        }
    }
    cout << "None" << endl;
}

// Moore’s Voting Algorithm
void majorityElement3(vector<int> &nums)
{
    int count = 0, element = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (!count)
        {
            count = 1;
            element = nums[i];
        }
        else if (nums[i] != element)
            count--;
        else
            count++;
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == element)
            count++;
    }
    if (count > n / 2)
    {
        cout << element << " came " << count << " times in the array." << endl;
        return;
    }
    cout << "None" << endl;
}

//? This works in O(n^2) time
void maxSumOfSubArray(vector<int> &nums)
{
    int n = nums.size(), res = INT_MIN, ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (res < sum)
            {
                res = sum;
                ansStart = i;
                ansEnd = j;
            }
        }
    }
    cout << "Max sum " << res << " starts from index " << ansStart << " to " << ansEnd << endl;
}

//! This only works for +ve MaxSum of SubArray
void maxSumOfSubArray2(vector<int> &nums)
{
    int n = nums.size(), sum = 0, res = INT_MIN, start = -1, ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            start = i;

        sum += nums[i];

        if (sum < 0)
            sum = 0;
        if (res < sum)
        {
            ansStart = start;
            ansEnd = i;
            res = sum;
        }
    }
    cout << "Max sum " << res << " starts from index " << ansStart << " to " << ansEnd << endl;
}

int main()
{
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cin >> target;
    printArr(nums);
    cout << "Target: " << target << endl;
    twoSum(nums, target);
    twoSum2(nums, target);
    twoSum3(nums, target);
    cout << "---------------------" << endl;

    vector<int> arr = {2, 0, 2, 1, 1, 0};
    printArr(arr);
    sort0s1s2s(arr);
    printArr(arr);
    cout << "---------------------" << endl;
    int m;
    cin >> m;
    vector<int> nums2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> nums2[i];
    }
    printArr(nums2);
    majorityElement(nums2);
    majorityElement2(nums2);
    majorityElement3(nums2);
    cout << "---------------------" << endl;
    printArr(nums2);
    maxSumOfSubArray(nums2);
    maxSumOfSubArray2(nums2);

    return 0;
}
