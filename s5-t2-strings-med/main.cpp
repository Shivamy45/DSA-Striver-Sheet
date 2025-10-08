#include <iostream>
#include <sstream>
#include <map>
using namespace std;

string frequencySort(string &s)
{
    vector<pair<char, int>> freq(256);

    for (auto &c : s)
    {
        int fr = freq[c].second;
        freq[c] = {c, fr + 1};
    }

    sort(freq.begin(), freq.end(), [](auto &a, auto &b)
         { return a.second > b.second; });

    string res;

    for (int i = 0; i < 256; i++)
    {
        if (freq[i].second > 0)
        {
            char t = freq[i].first;
            int f = freq[i].second;
            string temp = string(f, t);
            res += temp;
        }
    }
    return res;
}

int maxDepth(string s)
{
    int res = 0, cnt = 0;
    for (char c : s)
    {
        if (c == '(')
            cnt++;
        else if (c == ')')
            cnt--;
        res = max(res, cnt);
    }
    return res;
}

int romanToInt(string s)
{
}

int myAtoi(string s)
{
    long long res = 0;
    int n = s.length();
    bool neg = false;
    int i = 0;
    while (i < n && s[i] == ' ')
        i++;
    if (i < n && (s[i] == '-' || s[i] == '+'))
    {
        neg = (s[i] == '-');
        i++;
    }

    while (i < n && s[i] == '0')
        i++;

    while (i < n && isdigit(s[i]))
    {
        res = res * 10 + (s[i] - '0');

        if (!neg && res > INT_MAX)
            return INT_MAX;
        if (neg && -res < INT_MIN)
            return INT_MIN;

        i++;
    }

    return (neg) ? 0 - res : res;
}

int atMostKDistinct(string &s, int k, int n)
{
    vector<int> freq(256, 0);
    int left = 0, dist = 0;
    long long count = 0;
    for (int right = 0; right < n; right++)
    {
        if (freq[s[right]] == 0)
            dist++;
        freq[s[right]]++;
        while (dist > k)
        {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                dist--;
            left++;
        }
        count += (right - left + 1);
    }
    return count;
}

int countSubStrings(string s, int k)
{
    int n = s.length();
    return atMostKDistinct(s, k, n) - atMostKDistinct(s, k - 1, n);
}

string reverseWords(string s)
{
    int n = s.length();
    string temp = "", res = "";
    bool first = true;
    int i = 0;
    while (i < n)
    {
        temp = "";
        while (i < n && s[i] == ' ')
            i++;
        if (i >= n)
            break;
        while (i < n && s[i] != ' ')
            temp += s[i++];
        res = temp + " " + res;
    }
    int m = res.length();
    return res.substr(0, m - 1);
}

string reverseWords_1(string s)
{
    stringstream ss(s);
    vector<string> words;
    string word, res;
    while (ss >> word)
        words.push_back(word);

    reverse(words.begin(), words.end());
    for (int i = 0; i < words.size(); i++)
    {
        if (i > 0)
            res += ' ';
        res += words[i];
    }
    return res;
}

string reverseWords_2(string &s)
{
    reverse(s.begin(), s.end());
    int n = s.size();
    int i = 0, j = 0;

    while (i < n)
    {
        while (i < n && s[i] == ' ')
            i++;
        if (i >= n)
            break;
        if (j > 0)
            s[j++] = ' ';

        int start = j;
        while (i < n && s[i] != ' ')
            s[j++] = s[i++];
        reverse(s.begin() + start, s.begin() + j);
    }
    s.resize(j);
    return s;
}

int main()
{
    string s;
    getline(cin, s);
    cout << frequencySort(s) << endl;
    cout << "-------------------" << endl;
    getline(cin, s);
    cout << maxDepth(s) << endl;
    cout << "-------------------" << endl;
    getline(cin, s);
    cout << myAtoi(s) << endl;
    cout << "-------------------" << endl;
    getline(cin, s);
    int k;
    cin >> k;
    cout << countSubStrings(s, k) << endl;
    cout << "-------------------" << endl;
    cin.ignore();
    getline(cin, s);
    cout << reverseWords(s) << endl;
    cout << "-------------------" << endl;
    cout << reverseWords_1(s) << endl;
    cout << "-------------------" << endl;
    cout << reverseWords_2(s) << endl;
    cout << "-------------------" << endl;

    return 0;
}