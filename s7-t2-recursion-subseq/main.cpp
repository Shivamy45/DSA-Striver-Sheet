#include <iostream>
#include <set>
using namespace std;

void helperValidString(int n, string s, vector<string> &res)
{
    if (s.size() == n)
    {
        res.push_back(s);
        return;
    }
    if (s.empty() || s.back() != '0')
    {
        s.push_back('0');
        helperValidString(n, s, res);
        s.pop_back();
    }
    s.push_back('1');
    helperValidString(n, s, res);
    s.pop_back();
}
// 3211. Generate Binary Strings Without Adjacent Zeros
vector<string> validStrings(int n)
{
    vector<string> res;
    helperValidString(n, "", res);
    return res;
}
void helperGenerateParenthesis(int n, vector<string> &res, string &temp, int open, int close)
{
    if (temp.length() == 2 * n)
    {
        res.push_back(temp);
        return;
    }
    if (close < open)
    {
        temp.push_back(')');
        helperGenerateParenthesis(n, res, temp, open, close + 1);
        temp.pop_back();
    }
    if (open < n)
    {

        temp.push_back('(');
        helperGenerateParenthesis(n, res, temp, open + 1, close);
        temp.pop_back();
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> res;
    string temp;
    helperGenerateParenthesis(n, res, temp, 0, 0);
    return res;
}

void helperSubsets(vector<int> &nums, vector<vector<int>> &res, vector<int> &temp, int idx)
{
    if (idx == nums.size())
    {
        res.push_back(temp);
        return;
    }
    helperSubsets(nums, res, temp, idx + 1);
    temp.push_back(nums[idx]);
    helperSubsets(nums, res, temp, idx + 1);
    temp.pop_back();
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> temp;
    helperSubsets(nums, res, temp, 0);
    return res;
}

int helperCountOfAllSubsequence(vector<int> &nums, int idx, int k)
{
    if (k == 0)
        return 1;
    if (k < 0 || idx == nums.size())
        return 0;
    return helperCountOfAllSubsequence(nums, idx + 1, k) + helperCountOfAllSubsequence(nums, idx + 1, k - nums[idx]);
}

int countOfAllSubsequence(vector<int> &nums, int k)
{
    return helperCountOfAllSubsequence(nums, 0, k);
}

bool helperCheckSubsequenceSum(int n, vector<int> &nums, int idx, int k)
{
    if (k == 0)
        return true;
    if (k < 0 || idx == n)
        return false;
    return helperCheckSubsequenceSum(n, nums, idx + 1, k) || helperCheckSubsequenceSum(n, nums, idx + 1, k - nums[idx]);
}

bool checkSubsequenceSum(int n, vector<int> &arr, int k)
{
    return helperCheckSubsequenceSum(n, arr, 0, k);
}

void helperCombinationSum(vector<int> &arr, int k, vector<vector<int>> &res, int idx, vector<int> &temp)
{
    if (k == 0)
    {
        res.push_back(temp);
        return;
    }
    if (k < 0 || idx == arr.size())
        return;
    helperCombinationSum(arr, k, res, idx + 1, temp);
    temp.push_back(arr[idx]);
    helperCombinationSum(arr, k - arr[idx], res, idx, temp);
    temp.pop_back();
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> temp;
    helperCombinationSum(candidates, target, res, 0, temp);
    return res;
}

void helperCombinationSum2(vector<int> &candidates, int idx, int target, vector<vector<int>> &res, vector<int> &temp)
{
    if (target == 0)
    {
        res.push_back(temp);
        return;
    }
    for (int i = idx; i < candidates.size(); i++)
    {
        if (i > idx && candidates[i] == candidates[i - 1])
            continue;
        if (candidates[i] > target)
            break;
        temp.push_back(candidates[i]);
        helperCombinationSum2(candidates, i + 1, target - candidates[i], res, temp);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> temp;
    helperCombinationSum2(candidates, 0, target, res, temp);
    return res;
}

void helperSumOfSubsets(vector<int> &nums, vector<int> &res, int sum, int idx)
{
    if (idx == nums.size())
    {
        res.push_back(sum);
        return;
    }
    helperSumOfSubsets(nums, res, sum, idx + 1);
    helperSumOfSubsets(nums, res, sum + nums[idx], idx + 1);
}

vector<int> sumOfSubsets(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), greater<int>());
    vector<int> res;
    helperSumOfSubsets(nums, res, 0, 0);
    return res;
}

void helperSubsetsWithDup(vector<int> &nums, int idx, vector<vector<int>> &res, vector<int> &temp, int n)
{
    res.push_back(temp);
    for (int i = idx; i < n; i++)
    {
        if (i > idx && nums[i] == nums[i - 1])
            continue;
        temp.push_back(nums[i]);
        helperSubsetsWithDup(nums, i + 1, res, temp, n);
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> temp;
    helperSubsetsWithDup(nums, 0, res, temp, nums.size());
    return res;
}

void helperCombinationSum3(int k, int n, vector<int> &temp, vector<vector<int>> &res)
{
    if (k == 0 && n == 0)
        res.push_back(temp);
    else if (k <= 0 || n <= 0)
        return;
    int start = (temp.empty()) ? 0 : temp.back();
    for (int i = start + 1; i <= 9; i++)
    {
        temp.push_back(i);
        helperCombinationSum3(k - 1, n - i, temp, res);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> res;
    vector<int> temp;
    helperCombinationSum3(k, n, temp, res);
    return res;
}

void helperLetterCombinations(string digits, int idx, int n, vector<string> &keypad, string &temp, vector<string> &res)
{
    if (idx == n)
    {
        res.push_back(temp);
        return;
    }
    for (char c : keypad[digits[idx] - '0'])
    {
        temp.push_back(c);
        helperLetterCombinations(digits, idx + 1, n, keypad, temp, res);
        temp.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> keypad = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"};
    string temp = "";
    int n = digits.size();
    vector<string> res;
    helperLetterCombinations(digits, 0, n, keypad, temp, res);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> res = validStrings(n);
    for (string s : res)
        cout << s << endl;
    cout << "--------------------------" << endl;

    cin >> n;
    res = generateParenthesis(n);
    for (string s : res)
        cout << s << endl;
    cout << "--------------------------" << endl;

    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    vector<vector<int>> ans = subsets(arr);
    for (auto vec : ans)
    {
        for (int &a : vec)
            cout << a << " ";
        cout << endl;
    }
    cout << "--------------------------" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    int k;
    cin >> k;
    cout << countOfAllSubsequence(arr, k) << endl;
    cout << "--------------------------" << endl;

    cout << checkSubsequenceSum(6, arr, k) << endl;
    cout << "--------------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> k;
    ans = combinationSum(arr, k);
    for (auto vec : ans)
    {
        for (int &a : vec)
            cout << a << " ";
        cout << endl;
    }
    cout << "--------------------------" << endl;

    ans = combinationSum2(arr, k);
    for (auto vec : ans)
    {
        for (int &a : vec)
            cout << a << " ";
        cout << endl;
    }
    cout << "--------------------------" << endl;

    vector<int> output = sumOfSubsets(arr);
    for (int s : output)
        cout << s << " ";
    cout << endl;
    cout << "--------------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    ans = subsetsWithDup(arr);
    for (auto vec : ans)
    {
        for (int &a : vec)
            cout << a << " ";
        cout << endl;
    }
    cout << "--------------------------" << endl;

    cin >> k;
    cin >> n;
    ans = combinationSum3(k, n);
    for (auto vec : ans)
    {
        for (int &a : vec)
            cout << a << " ";
        cout << endl;
    }
    cout << "--------------------------" << endl;

    string s;
    cin.ignore();
    getline(cin, s);
    cout << s << endl;
    res = letterCombinations(s);
    for (string s : res)
        cout << s << ", ";
    cout << endl;
    cout << "--------------------------" << endl;

    return 0;
}