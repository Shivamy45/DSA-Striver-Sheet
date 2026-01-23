#include <iostream>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> mpp;
    vector<int> res(nums1.size());
    for (int i = 0; i < nums1.size(); i++)
        mpp[nums1[i]] = i;
    for (int i = 0; i < nums2.size(); i++)
    {
        if (mpp.find(nums2[i]) != mpp.end())
        {
            int j = i + 1;
            for (; j < nums2.size(); j++)
                if (nums2[j] > nums2[i])
                    break;
            if (j == nums2.size())
                res[mpp[nums2[i]]] = -1;
            else
                res[mpp[nums2[i]]] = nums2[j];
        }
    }
    return res;
}

vector<int> nextGreaterElement2(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    stack<int> st;
    unordered_map<int, int> mpp;
    vector<int> res(n);
    for (int i = 0; i < n; i++)
        mpp[nums1[i]] = i;
    for (int i = m - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums2[i])
            st.pop();
        if (mpp.find(nums2[i]) != mpp.end())
        {
            if (st.empty())
                res[mpp[nums2[i]]] = -1;
            else
                res[mpp[nums2[i]]] = st.top();
        }
        st.push(nums2[i]);
    }
    return res;
}

vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> res(n, -1);
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }
        if (!st.empty())
            res[i % n] = st.top();
        st.push(nums[i % n]);
    }
    return res;
}

vector<int> nextSmallerElement(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> res(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() >= nums[i])
            st.pop();
        if (!st.empty())
            res[i] = st.top();
        st.push(nums[i]);
    }
    return res;
}

int trap(vector<int> &height)
{
    int n = height.size();
    int water = 0;
    vector<int> rightMax(n);
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }
    int leftMax = height[0];
    for (int i = 1; i < n - 1; i++)
    {
        leftMax = max(leftMax, height[i]);
        water += (min(leftMax, rightMax[i]) - height[i]);
    }
    return water;
}

int sumSubarrayMins(vector<int> &arr)
{
    int MOD = 1e9 + 7, n = arr.size();
    vector<int> prevSmallest(n, -1);
    vector<int> nextSmallest(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        if (!st.empty())
            prevSmallest[i] = st.top();
        st.push(i);
    }
    st = stack<int>();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        if (!st.empty())
            nextSmallest[i] = st.top();
        st.push(i);
    }
    long long totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        long long left = ((prevSmallest[i] != -1) ? (i - prevSmallest[i]) : i + 1);
        long long right = ((nextSmallest[i] != -1) ? (nextSmallest[i] - i) : n - i);
        totalSum += (long long)(arr[i] * left * right) % MOD;
    }
    return totalSum % MOD;
}

vector<int> asteroidCollision(vector<int> &asteroids)
{
    vector<int> st;
    int n = asteroids.size();
    for (int i = 0; i < n; i++)
    {
        if (asteroids[i] > 0)
            st.push_back(asteroids[i]);
        else
        {
            while (!st.empty() && st.back() > 0 && abs(asteroids[i]) > st.back())
                st.pop_back();
            if (!st.empty() && st.back() > 0 && abs(asteroids[i]) == st.back())
                st.pop_back();
            else if (st.empty() || st.back() < 0)
                st.push_back(asteroids[i]);
        }
    }
    return st;
}

long long subArrayRanges(vector<int> &nums)
{
    int n = nums.size();
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        long long minNum = nums[i], maxNum = nums[i];
        for (int j = i; j < n; j++)
        {
            if (minNum > nums[j])
                minNum = nums[j];
            else if (maxNum < nums[j])
                maxNum = nums[j];

            res += maxNum - minNum;
        }
    }
    return res;
}

long long subArrayRanges2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> psee(n, -1), nse(n, -1), pgee(n, -1), nge(n, -1);
    stack<int> st;
    // calculate prev smaller or equal element(psee)
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            st.pop();
        }
        if (!st.empty())
            psee[i] = st.top();
        st.push(i);
    }
    st = stack<int>();
    // calculate next smaller element(nse)
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
        {
            st.pop();
        }
        if (!st.empty())
            nse[i] = st.top();
        st.push(i);
    }
    st = stack<int>();
    // calculate prev greater or equal element(pgee)
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] < nums[i])
        {
            st.pop();
        }
        if (!st.empty())
            pgee[i] = st.top();
        st.push(i);
    }
    st = stack<int>();
    // calculate next greater element(nge)
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            st.pop();
        }
        if (!st.empty())
            nge[i] = st.top();
        st.push(i);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << nums[i] << endl;
    //     cout << " psee:" << psee[i] << endl;
    //     cout << " nse:" << nse[i] << endl;
    //     cout << " pgee:" << pgee[i] << endl;
    //     cout << " nge:" << nge[i] << endl;
    // }
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        long long maxNum = ((pgee[i] == -1) ? i + 1 : i - pgee[i]) *
                     ((nge[i] == -1) ? n - i : nge[i] - i);
        long long minNum = ((psee[i] == -1) ? i + 1 : i - psee[i]) *
                     ((nse[i] == -1) ? n - i : nse[i] - i);
        // cout << nums[i] << " " << maxNum << " " << minNum << endl;
        res += nums[i] * (maxNum - minNum);
    }
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> nums1(n), nums2(m);
    for (int &a : nums1)
        cin >> a;
    for (int &a : nums2)
        cin >> a;

    vector<int> res = nextGreaterElement(nums1, nums2);
    for (int &a : res)
        cout << a << " ";
    cout << endl;
    cout << "--------------------------" << endl;

    res = nextGreaterElement2(nums1, nums2);
    for (int &a : res)
        cout << a << " ";
    cout << endl;
    cout << "--------------------------" << endl;

    cin >> n;
    nums1.resize(n);
    for (int &a : nums1)
        cin >> a;
    res = nextGreaterElements(nums1);
    for (int &a : res)
        cout << a << " ";
    cout << endl;
    cout << "--------------------------" << endl;

    cin >> n;
    nums1.resize(n);
    for (int &a : nums1)
        cin >> a;
    res = nextSmallerElement(nums1);
    for (int &a : res)
        cout << a << " ";
    cout << endl;
    cout << "--------------------------" << endl;

    cin >> n;
    nums1.resize(n);
    for (int &a : nums1)
        cin >> a;
    cout << trap(nums1) << endl;
    cout << "--------------------------" << endl;

    cin >> n;
    nums1.resize(n);
    for (int &a : nums1)
        cin >> a;
    cout << sumSubarrayMins(nums1) << endl;
    cout << "--------------------------" << endl;

    cin >> n;
    nums1.resize(n);
    for (int &a : nums1)
        cin >> a;
    res = asteroidCollision(nums1);
    for (int &a : res)
        cout << a << " ";
    cout << endl;
    cout << "--------------------------" << endl;

    cin >> n;
    nums1.resize(n);
    for (int &a : nums1)
        cin >> a;
    cout << subArrayRanges(nums1) << endl;
    cout << "--------------------------" << endl;

    cout << subArrayRanges2(nums1) << endl;
    cout << "--------------------------" << endl;

    return 0;
}