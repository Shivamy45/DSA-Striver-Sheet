#include <iostream>
using namespace std;

bool helperIsSubsetSum(int idx, vector<int> &arr, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (idx == 0)
        return arr[0] == target;
    if (dp[idx][target] != -1)
        return dp[idx][target];
    bool notTake = helperIsSubsetSum(idx - 1, arr, target, dp);
    bool take = false;
    if (arr[idx] <= target)
        take = helperIsSubsetSum(idx - 1, arr, target - arr[idx], dp);
    return dp[idx][target] = notTake || take;
}

bool isSubsetSum(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return helperIsSubsetSum(n - 1, arr, target, dp);
}

bool isSubsetSum2(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= k)
        dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTaken = dp[i - 1][target];
            bool taken = false;
            if (arr[i] <= target)
            {
                taken = dp[i - 1][target - arr[i]];
            }
            dp[i][target] = notTaken || taken;
        }
    }
    return dp[n - 1][k];
}

bool isSubsetSum3(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<bool> dp(k + 1, false);
    dp[0] = true;
    if (arr[0] <= k)
        dp[arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        vector<bool> temp(k + 1, false);
        temp[0] = true;
        for (int target = 1; target <= k; target++)
        {
            bool notTaken = dp[target];
            bool taken = false;
            if (arr[i] <= target)
                taken = dp[target - arr[i]];
            temp[target] = notTaken || taken;
        }
        dp = temp;
    }
    return dp[k];
}

bool helperCanPartition(vector<int> &nums, int idx, int target, vector<vector<int>> &dp)
{
    if (idx == 0)
        return nums[0] == target;
    if (target == 0)
        return true;
    if (dp[idx][target] != -1)
        return dp[idx][target];
    bool notTake = helperCanPartition(nums, idx - 1, target, dp);
    bool take = false;
    if (nums[idx] <= target)
        take = helperCanPartition(nums, idx - 1, target - nums[idx], dp);
    return dp[idx][target] = notTake || take;
}

bool canPartition(vector<int> &nums)
{
    int totalSum = 0;
    int n = nums.size();
    for (int &a : nums)
        totalSum += a;
    if (totalSum % 2 != 0)
        return false;
    vector<vector<int>> dp(n, vector<int>(totalSum / 2 + 1, -1));
    return helperCanPartition(nums, n - 1, totalSum / 2, dp);
}

bool canPartition2(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = 0;
    for (int &a : nums)
        totalSum += a;
    if (totalSum % 2 != 0)
        return false;
    int k = totalSum / 2;
    vector<vector<int>> dp(n, vector<int>(k + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][nums[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTake = dp[i - 1][target];
            bool take = false;
            if (nums[i] <= target)
            {
                take = dp[i - 1][target - nums[i]];
            }
            dp[i][target] = notTake || take;
        }
    }
    return dp[n - 1][k];
}

bool canPartition3(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = 0;
    for (int &a : nums)
        totalSum += a;
    if (totalSum % 2 != 0)
        return false;
    int k = totalSum / 2;
    vector<bool> dp(k + 1, false);
    dp[0] = true;
    if (nums[0] <= k)
        dp[nums[0]] = true;
    for (int i = 1; i < n; i++)
    {
        vector<bool> temp(k + 1, false);
        temp[0] = true;
        for (int target = 1; target <= k; target++)
        {
            bool notTake = dp[target];
            bool take = false;
            if (nums[i] <= target)
            {
                take = dp[target - nums[i]];
            }
            temp[target] = notTake || take;
        }
        dp = temp;
    }
    return dp[k];
}

bool helperMinSubsetSumDifference(vector<int> &nums, int idx, int target, vector<vector<int>> &dp)
{
    if (target == 0)
        return dp[idx][target] = true;
    if (idx == 0)
        return dp[idx][target] = (nums[0] == target);
    if (dp[idx][target] != -1)
        return dp[idx][target];
    bool notTake = helperMinSubsetSumDifference(nums, idx - 1, target, dp);
    bool take = false;
    if (nums[idx] <= target)
        take = helperMinSubsetSumDifference(nums, idx - 1, target - nums[idx], dp);
    return dp[idx][target] = notTake || take;
}

int minSubsetSumDifference(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = 0;
    for (int a : nums)
        totalSum += a;
    vector<vector<int>> dp(n, vector<int>(totalSum / 2 + 1, -1));
    for (int target = 0; target <= totalSum / 2; target++)
        helperMinSubsetSumDifference(nums, n - 1, target, dp);
    int ans = 1e9;
    for (int target = 0; target <= totalSum / 2; target++)
    {
        if (dp[n - 1][target] == 1)
        {
            int diff = abs(totalSum - 2 * target);
            ans = min(ans, diff);
        }
    }
    return ans;
}

int minSubsetSumDifference2(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = 0;
    for (int a : nums)
        totalSum += a;
    vector<vector<bool>> dp(n, vector<bool>(totalSum / 2 + 1, false));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (nums[0] <= totalSum / 2)
        dp[0][nums[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= totalSum / 2; target++)
        {
            bool notTake = dp[i - 1][target];
            bool take = false;
            if (nums[i] <= target)
                take = dp[i - 1][target - nums[i]];
            dp[i][target] = notTake || take;
        }
    }
    int ans = 1e9;
    for (int target = 0; target <= totalSum / 2; target++)
    {
        if (dp[n - 1][target])
        {
            int diff = abs(totalSum - 2 * target);
            ans = min(ans, diff);
        }
    }
    return ans;
}
int minSubsetSumDifference3(vector<int> &nums)
{
    int n = nums.size();
    int totalSum = 0;
    for (int a : nums)
        totalSum += a;
    vector<bool> dp(totalSum / 2 + 1, false);
    dp[0] = true;
    if (nums[0] <= totalSum / 2)
        dp[nums[0]] = true;
    for (int i = 1; i < n; i++)
    {
        vector<bool> temp(totalSum / 2 + 1, false);
        for (int target = 0; target <= totalSum / 2; target++)
        {
            bool notTake = dp[target];
            bool take = false;
            if (nums[i] <= target)
                take = dp[target - nums[i]];
            temp[target] = notTake || take;
        }
        dp = temp;
    }
    int ans = 1e9;
    for (int target = 0; target <= totalSum / 2; target++)
    {
        if (dp[target])
        {
            int diff = abs(totalSum - 2 * target);
            ans = min(ans, diff);
        }
    }
    return ans;
}

int minimumDifference(vector<int> &nums)
{
    int n = nums.size();
    
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    int k;
    cin >> k;
    cout << isSubsetSum(arr, k) << endl;
    cout << "--------------" << endl;
    cout << isSubsetSum2(arr, k) << endl;
    cout << "--------------" << endl;
    cout << isSubsetSum3(arr, k) << endl;
    cout << "--------------" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cout << canPartition(arr) << endl;
    cout << "--------------" << endl;
    cout << canPartition2(arr) << endl;
    cout << "--------------" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cout << minSubsetSumDifference(arr) << endl;
    cout << "--------------" << endl;
    cout << minSubsetSumDifference2(arr) << endl;
    cout << "--------------" << endl;
    cout << minSubsetSumDifference3(arr) << endl;
    cout << "--------------" << endl;

    return 0;
}