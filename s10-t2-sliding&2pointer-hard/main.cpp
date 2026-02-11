#include <iostream>
using namespace std;

int helperSubarraysWithKDistinct(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> freq;
    int cnt = 0, i = 0, dist = 0;
    for (int j = 0; j < n; j++)
    {
        freq[nums[j]]++;
        if (freq[nums[j]] == 1)
            dist++;
        while (dist > k)
        {
            freq[nums[i]]--;
            if (freq[nums[i]] == 0)
                dist--;
            i++;
        }
        cnt += (j - i + 1);
    }
    return cnt;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return helperSubarraysWithKDistinct(nums, k) - helperSubarraysWithKDistinct(nums, k - 1);
}

string minWindow(string s, string t)
{
    int n = s.length(), m = t.length();
    if(n < m)
        return "";
    vector<int> freq(128, 0);
    for (char c : t)
        freq[c]++;
    int i = 0, matched = 0;
    int start = 0, len = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        if (freq[s[j]] > 0)
            matched++;
        freq[s[j]]--;
        while (matched == m)
        {
            if (j - i + 1 < len)
            {
                start = i;
                len = j - i + 1;
            }
            freq[s[i]]++;
            if (freq[s[i]] > 0)
                matched--;
            i++;
        }
    }
    return (len == INT_MAX) ? "" : s.substr(start, len);
}

int main()
{
    int n, k;
    vector<int> arr;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> k;
    cout << subarraysWithKDistinct(arr, k) << endl;
    cout << "------------------------" << endl;

    string s, t;
    cin.ignore();
    getline(cin, s);
    getline(cin, t);
    cout << minWindow(s, t) << endl;
    cout << "------------------------" << endl;

    return 0;
}