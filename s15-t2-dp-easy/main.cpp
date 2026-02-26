#include <iostream>
using namespace std;

int climb(int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = climb(n - 1, dp) + climb(n - 2, dp);
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, -1);
    return climb(n, dp);
}

int r(vector<int> &nums, int idx, vector<int> &dp)
{
    if (idx >= nums.size())
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    return dp[idx] = max(r(nums, idx + 1, dp), nums[idx] + r(nums, idx + 2, dp));
}
// Memoization
int rob(vector<int> &nums)
{
    vector<int> dp(nums.size() + 1, -1);
    return r(nums, 0, dp);
}

// Tabulation - Space Optimised
int rob2(vector<int> &nums)
{
    int prev2 = 0, prev = nums[0], curr;
    for (int i = 1; i < nums.size(); i++)
    {
        curr = max(nums[i] + prev2, prev);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

// circular houses
// 1. exclude 1st house
// 2. excluse n-1th house
int rob3(vector<int> &nums)
{
    int n = nums.size();
    vector<int> arr, arr2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            arr.push_back(nums[i]);
        if (i != n - 1)
            arr2.push_back(nums[i]);
    }
    return max(rob(arr), rob(arr2));
}

int fj(int i, vector<int> &heights, vector<int> &dp)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int a = abs(heights[i] - heights[i - 1]) + fj(i - 1, heights, dp);
    int b = (i > 1) ? abs(heights[i] - heights[i - 2]) + fj(i - 2, heights, dp) : INT_MAX;
    return dp[i] = min(a, b);
}
// Memoization
int frogJump(vector<int> &heights)
{
    int n = heights.size();
    vector<int> dp(n, -1);
    return fj(n - 1, heights, dp);
}

// Tabulation
int frogJump2(vector<int> &heights)
{
    int n = heights.size();
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int a = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int b = INT_MAX;
        if (i > 1)
            b = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        dp[i] = min(a, b);
    }
    return dp[n - 1];
}
// Tabulation - Space Optimised
int frogJump3(vector<int> &heights)
{
    int n = heights.size();
    int prev = 0, prev2 = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        int a = prev + abs(heights[i] - heights[i - 1]);
        int b = INT_MAX;
        if (i > 1)
            b = prev2 + abs(heights[i] - heights[i - 2]);
        int curr = min(a, b);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int fjkd(int idx, int k, vector<int> &heights, vector<int> &dp)
{
    if (idx == 0)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];
    int res = INT_MAX;
    for (int i = 1; i <= k && idx - i >= 0; i++)
    {
        res = min(res, abs(heights[idx] - heights[idx - i]) + fjkd(idx - i, k, heights, dp));
    }
    return dp[idx] = res;
}
// Memoization
int frogJumpKDist(vector<int> &heights, int k)
{
    int n = heights.size();
    vector<int> dp(n, -1);
    return fjkd(n - 1, k, heights, dp);
}

// Tabulation
int frogJumpKDist2(vector<int> &heights, int k)
{
    int n = heights.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k && i - j >= 0; j++)
        {
            dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
        }
    }
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
    cout << "------------------" << endl;

    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    cout << rob(arr) << endl;
    cout << "------------------" << endl;
    cout << rob2(arr) << endl;
    cout << "------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cout << rob3(arr) << endl;
    cout << "------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cout << frogJump(arr) << endl;
    cout << "------------------" << endl;
    cout << frogJump2(arr) << endl;
    cout << "------------------" << endl;
    cout << frogJump3(arr) << endl;
    cout << "------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    int k;
    cin >> k;
    cout << frogJumpKDist(arr, k) << endl;
    cout << "------------------" << endl;
    cout << frogJumpKDist2(arr, k) << endl;
    cout << "------------------" << endl;

    return 0;
}