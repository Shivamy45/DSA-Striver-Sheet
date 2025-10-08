#include <iostream>
#include <map>
using namespace std;

// ------------------------------
// Parentheses Manipulation Functions
// ------------------------------

// Time Complexity: O(n)
// Space Complexity: O(n)
// Explanation: Removes outermost parentheses of every primitive substring.
string removeOuterParentheses(string s)
{
    int n = s.length();
    int cnt = 0;
    string output;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            cnt++;
            if (cnt != 1)
                output.push_back(s[i]);
        }
        else
        {
            cnt--;
            if (cnt != 0)
                output.push_back(s[i]);
        }
    }
    return output;
}

// ------------------------------
// String Manipulation Functions
// ------------------------------

// Time Complexity: O(n)
// Space Complexity: O(n)
// Explanation: Reverses the order of words in a string.
string reverseWords(string s)
{
    int n = s.size(), i = 0;
    vector<string> words;

    while (i < n)
    {
        while (i < n && s[i] == ' ')
            i++; // skip spaces
        if (i >= n)
            break;
        int j = i;
        while (j < n && s[j] != ' ')
            j++;
        words.push_back(s.substr(i, j - i));
        i = j;
    }

    string res;
    for (int k = words.size() - 1; k >= 0; k--)
    {
        res += words[k];
        if (k != 0)
            res += ' ';
    }

    return res;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
// Explanation: Returns largest odd number substring from the start after trimming leading zeros.
string largestOddNumber(string num)
{
    int last = -1;
    int n = num.length(), i;
    for (i = n - 1; i >= 0; i--)
    {
        if ((num[i] - '0') % 2 == 1)
        {
            last = i;
            break;
        }
    }
    i = 0;
    while (num[i] == '0' && i <= last)
        i++;

    return num.substr(i, last + 1);
}

// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(n)
// Explanation: Finds the longest common prefix among a vector of strings.
string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());
    int n = strs.size();
    string first = strs[0], last = strs[n - 1];
    int cnt = 0;
    for (int i = 0; i < first.length(); i++)
    {
        if (first[i] != last[i])
            break;
        cnt++;
    }
    return first.substr(0, cnt);
}

// ------------------------------
// Isomorphism Checking Functions
// ------------------------------

// Time Complexity: O(n)
// Space Complexity: O(n)
// Explanation: Checks if two strings are isomorphic using maps.
bool isIsomorphic(string s, string t)
{
    int n = s.length(), m = t.length();
    if (n != m)
        return false;
    map<char, char> mpp, mpp2;
    for (int i = 0; i < n; i++)
    {
        if (mpp.find(s[i]) != mpp.end() || mpp2.find(t[i]) != mpp2.end())
        {
            if (mpp[s[i]] != t[i] || mpp2[t[i]] != s[i])
                return false;
        }
        else
        {
            mpp[s[i]] = t[i];
            mpp2[t[i]] = s[i];
        }
    }
    return true;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
// Explanation: Checks if two strings are isomorphic using fixed size arrays.
bool isIsomorphic_1(string s, string t)
{
    int m1[256] = {0}, m2[256] = {0};
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (m1[s[i]] != m2[t[i]])
            return false;
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    return true;
}

// ------------------------------
// String Rotation Functions
// ------------------------------

// Time Complexity: O(n^2)
// Space Complexity: O(n)
// Explanation: Checks if one string is a rotation of another.
bool rotateString(string s, string goal)
{
    int n = s.length(), m = goal.length();
    if (n != m)
        return false;
    s += s;
    for (int i = 0; i < n; i++)
    {
        string subStr = s.substr(i, m);
        if (subStr == goal)
            return true;
    }
    return false;
}

// ------------------------------
// Anagram Checking Functions
// ------------------------------

// Time Complexity: O(n)
// Space Complexity: O(1)
// Explanation: Checks if two strings are anagrams of each other.
bool isAnagram(string s, string t)
{
    int m1[26] = {0};
    int n = s.length(), m = t.length();
    if (n != m)
        return false;
    for (int i = 0; i < n; i++)
    {
        m1[s[i] - 'a']++;
        m1[t[i] - 'a']--;
    }
    for (int cnt : m1)
        if (cnt != 0)
            return false;
    return true;
}

int main()
{
    string s;
    getline(cin, s);
    cout << removeOuterParentheses(s) << endl;
    cout << "--------------------" << endl;

    getline(cin, s);
    cout << reverseWords(s) << endl;
    cout << "--------------------" << endl;

    getline(cin, s);
    cout << largestOddNumber(s) << endl;
    cout << "--------------------" << endl;

    int n;
    cin >> n;
    cin.ignore();
    vector<string> strs(n);
    for (string &a : strs)
        getline(cin, a);
    cout << longestCommonPrefix(strs) << endl;
    cout << "--------------------" << endl;

    string s2;
    getline(cin, s);
    getline(cin, s2);
    cout << isIsomorphic(s, s2) << endl;
    cout << "--------------------" << endl;
    cout << isIsomorphic_1(s, s2) << endl;
    cout << "--------------------" << endl;

    getline(cin, s);
    getline(cin, s2);
    cout << rotateString(s, s2) << endl;
    cout << "--------------------" << endl;

    getline(cin, s);
    getline(cin, s2);
    cout << isAnagram(s, s2) << endl;
    cout << "--------------------" << endl;

    return 0;
}