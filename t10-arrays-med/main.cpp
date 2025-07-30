#include <iostream>
#include <map>
using namespace std;

void printArr(vector<int> arr)
{
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

//! O(n^2)
void twoSum(vector<int> nums, int target)
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

//? Using Map - O(nlog n)
//? Using Unordered Map - O(n) / O(n^2)
void twoSum2(vector<int> nums, int target)
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

//! This uses functions that are not suitable for interviews
void twoSum3(vector<int> nums, int target)
{
    for (int i = 0; i <= nums.size(); i++)
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

void majorityElement(vector<int> nums)
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

void majorityElement2(vector<int> nums)
{
    int n = nums.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;
    }
    for (int i = 0; i < mpp.size(); i++)
    {
        if (mpp[i] > n / 2)
        {
            cout << i << " came " << mpp[i] << " times in the array." << endl;
            return;
        }
    }
    cout << "None" << endl;
}

// Moore’s Voting Algorithm
void majorityElement3(vector<int> nums)
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

void maxSumOfSubArray(vector<int> nums)
{
    int n = nums.size(), res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
        }
        res = max(sum, res);
    }
    cout << "Max Sum of SubArray: " << res << endl;
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
    maxSumOfSubArray(nums2);

    return 0;
}

/*
2 0 2 1 1 0
0 2 2 1 1 0

 */