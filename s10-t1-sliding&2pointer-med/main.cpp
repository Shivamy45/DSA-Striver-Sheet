#include <iostream>
#include <set>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    vector<int> freq(128, 0);
    int i = 0, j = 0, res = 0;
    while (j < n)
    {
        while (freq[s[j]] != 0)
            freq[s[i++]]--;
        freq[s[j]]++;
        res = max(res, j - i + 1);
        j++;
    }
    return res;
}

int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0, j = 0, noOfZeros = 0, res = 0;
    while (j < n)
    {
        if (nums[j] == 0)
            noOfZeros++;
        while (noOfZeros > k)
        {
            if (nums[i] == 0)
                noOfZeros--;
            i++;
        }
        res = max(res, j - i + 1);
        j++;
    }
    return res;
}

int totalFruit(vector<int> &fruits)
{
    int n = fruits.size();
    if (n == 1)
        return 1;
    int lastSecondFruit = -1, lastFruit = -1, bStreak = 0, res = 0, currStreak = 0;
    for (int fruit : fruits)
    {
        if (fruit == lastSecondFruit || fruit == lastFruit)
            currStreak++;
        else
            currStreak = bStreak + 1;
        if (fruit == lastFruit)
            bStreak++;
        else
        {
            bStreak = 1;
            lastSecondFruit = lastFruit;
            lastFruit = fruit;
        }
        res = max(res, currStreak);
    }
    return res;
}

int characterReplacement(string s, int k)
{
    int n = s.length();
    vector<int> freq(26, 0);
    int maxf = 0, i = 0, j = 0, res = 0;
    while (j < n)
    {
        freq[s[j] - 'A']++;
        maxf = max(maxf, freq[s[j] - 'A']);
        int changes = j - i + 1 - maxf;
        if (changes > k)
        {
            freq[s[i++] - 'A']--;
            changes = j - i + 1 - maxf;
        }
        if (changes <= k)
            res = max(res, j - i + 1);
        j++;
    }
    return res;
}

int helperNumSubarraysWithSum(vector<int> &arr, int k)
{
    if (k < 0)
        return 0;
    int n = arr.size();
    int i = 0, sum = 0, cnt = 0;
    for (int j = 0; j < n; j++)
    {
        sum += arr[j];
        while (sum > k)
            sum -= arr[i++];

        cnt += (j - i + 1);
    }
    return cnt;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return helperNumSubarraysWithSum(nums, goal) - helperNumSubarraysWithSum(nums, goal - 1);
}

int helperNumberOfSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    int i = 0, oddCnt = 0, res = 0;
    for (int j = 0; j < n; j++)
    {
        if (nums[j] % 2 == 1)
            oddCnt++;
        while (oddCnt > k)
        {
            if (nums[i] % 2)
                oddCnt--;
            i++;
        }
        res += (j - i + 1);
    }
    return res;
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    return helperNumberOfSubarrays(nums, k) - helperNumberOfSubarrays(nums, k - 1);
}

int numberOfSubstrings(string s)
{
    int n = s.length();
    int i = 0, cnt = 0;
    int freq[3] = {0};
    for (int j = 0; j < n; j++)
    {
        freq[s[j] - 'a']++;
        while (freq[0] && freq[1] && freq[2])
        {
            cnt += (n - j);
            freq[s[i] - 'a']--;
            i++;
        }
    }
    return cnt;
}

int maxScore(vector<int> &cardPoints, int k)
{
    int n = cardPoints.size();
    int i = 0, j = n - 1, sum = 0, res = 0;
    for (i = 0; i < k; i++)
        sum += cardPoints[i];
    while (i >= 0)
    {
        sum -= cardPoints[i];
        sum += cardPoints[j];
        res = max(res, sum);
        j--;
        i--;
    }
    return res;
}

int main()
{
    string s;
    getline(cin, s);
    cout << lengthOfLongestSubstring(s) << endl;
    cout << "------------------------" << endl;

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    int k;
    cin >> k;
    cout << longestOnes(arr, k) << endl;
    cout << "------------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cout << totalFruit(arr) << endl;
    cout << "------------------------" << endl;

    cin.ignore();
    getline(cin, s);
    cin >> k;
    cout << characterReplacement(s, k) << endl;
    cout << "------------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> k;
    cout << numSubarraysWithSum(arr, k) << endl;
    cout << "------------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> k;
    cout << numberOfSubarrays(arr, k) << endl;
    cout << "------------------------" << endl;

    cin.ignore();
    getline(cin, s);
    cout << numberOfSubstrings(s) << endl;
    cout << "------------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> k;
    cout << maxScore(arr, k) << endl;
    cout << "------------------------" << endl;

    return 0;
}