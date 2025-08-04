#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void printArr(vector<int> &arr)
{
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

//! This is if we can do only 1 transaction
void stockBuyAndSell(vector<int> &prices)
{
    int n = prices.size();
    int minPrice = INT_MAX, maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    cout << "Max Profit with 1 transaction: " << maxProfit << endl;
}

void stockBuyAndSell2(vector<int> &prices)
{
    bool buy = false;
    int n = prices.size();
    int boughtAt = 0, profit = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (prices[i + 1] > prices[i] && !buy)
        {
            buy = true;
            boughtAt = prices[i];
        }
        else if (buy && prices[i] > prices[i + 1])
        {
            buy = false;
            profit += prices[i] - boughtAt;
        }
    }
    if (buy)
    {
        profit += prices[n - 1] - boughtAt;
    }
    cout << "Max Profit with many transaction: " << profit << endl;
}

void alternatingArray(vector<int> &arr)
{
    int n = arr.size();
    vector<int> posArr;
    vector<int> negArr;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            posArr.push_back(arr[i]);
        else
            negArr.push_back(arr[i]);
    }
    for (int i = 0; i < n / 2; i++)
    {
        arr[2 * i] = posArr[i];
    }
    for (int i = 0; i < n / 2; i++)
    {
        arr[2 * i + 1] = negArr[i];
    }
}
void alternatingArray2(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n, 0);
    int posIdx = 0, negIdx = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            res[negIdx] = arr[i];
            negIdx += 2;
        }
        else
        {
            res[posIdx] = arr[i];
            posIdx += 2;
        }
    }
    arr = res;
}

//? if no.(+ve) != no.(-ve)
void alternatingArray3(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n);
    int posIdx = 0, negIdx = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && posIdx < n)
        {
            res[posIdx] = arr[i];
            posIdx += 2;
        }
        else if (arr[i] < 0 && negIdx < n)
        {
            res[negIdx] = arr[i];
            negIdx += 2;
        }
    }
    // Fill remaining elements if any
    for (int i = 0; i < n; i++)
    {
        if (posIdx < n && arr[i] > 0)
        {
            res[posIdx] = arr[i];
            posIdx++;
        }
        else if (negIdx < n && arr[i] < 0)
        {
            res[negIdx] = arr[i];
            negIdx++;
        }
    }
    arr = res;
}

void nextPermutation(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
    cout << "Done next permutation" << endl;
}
void nextPermutation2(vector<int> &nums)
{
    int n = nums.size(), k = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            k = i;
            break;
        }
    }
    if (k == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    else
    {
        for (int j = n - 1; j > k; j--)
            if (nums[j] > nums[k])
            {
                swap(nums[j], nums[k]);
                break;
            }
        reverse(nums.begin() + k + 1, nums.end());
    }
    cout << "Done next permutation" << endl;
}

void leaderInArray(vector<int> &arr)
{
    int n = arr.size();
    int maxEle = INT_MIN;
    vector<int> res;
    for (int i = n - 1; i >= 0; i--)
    {
        if (maxEle < arr[i])
        {
            maxEle = arr[i];
            res.push_back(arr[i]);
        }
    }
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

//? Optimal Approach
void longestConsSequence(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int maxSeq = 1, seq = 1, n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[i] = nums[i - 1] + 1)
            seq++;
        else
            seq = 1;
        maxSeq = max(maxSeq, seq);
    }
    cout << "Longest Consecutive Sequence: " << maxSeq << endl;
}

//? Using set data structure
void longestConsSequence2(vector<int> &nums)
{
    unordered_set<int> s;
    int cnt = 0, longest = 1;
    for (int i : nums)
        s.insert(i);
    for (int it : s)
    {
        if (s.find(it - 1) == s.end())
        {
            int x = it;
            while (s.find(x) != s.end())
            {
                cnt++;
                x++;
            }
            longest = max(cnt, longest);
        }
        else
            cnt = 0;
    }
    cout << "Longest Consecutive Sequence: " << longest << endl;
}

void setMatrixZero(vector<int> arr)
{
}

int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    stockBuyAndSell(prices);
    cout << "-----------------------------------" << endl;
    stockBuyAndSell2(prices);
    cout << "-----------------------------------" << endl;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printArr(arr);
    alternatingArray(arr);
    printArr(arr);
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printArr(arr);
    alternatingArray2(arr);
    printArr(arr);
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printArr(arr);
    alternatingArray3(arr);
    printArr(arr);
    cout << "-----------------------------------" << endl;
    int m;
    cin >> m;
    vector<int> nums(m);
    for (int i = 0; i < m; i++)
        cin >> nums[i];
    printArr(nums);
    nextPermutation(nums);
    printArr(nums);
    cout << "-----------------------------------" << endl;
    printArr(nums);
    nextPermutation2(nums);
    printArr(nums);
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < m; i++)
        cin >> nums[i];
    printArr(nums);
    leaderInArray(nums);
    cout << "-----------------------------------" << endl;
    for (int i = 0; i < m; i++)
        cin >> nums[i];
    printArr(nums);
    longestConsSequence(nums);
    cout << "-----------------------------------" << endl;
    printArr(nums);
    longestConsSequence2(nums);
    cout << "-----------------------------------" << endl;
    int x, y;
    cin >> x >> y;
    vector<vector<int>> matrix(x, vector<int>(y));
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cin >> matrix[x][y];
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cout << matrix[x][y];

    return 0;
}
