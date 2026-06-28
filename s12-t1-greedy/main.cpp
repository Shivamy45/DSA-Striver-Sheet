#include <iostream>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0, j = 0, res = 0;
    while (i < g.size() && j < s.size())
    {
        if (g[i] > s[j])
        {
            j++;
            continue;
        }
        res++;
        i++;
        j++;
    }
    return res;
}

struct Item
{
    int val;
    int wt;
};

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();
    vector<Item> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = {val[i], wt[i]};
    sort(arr.begin(), arr.end(), [](Item &a, Item &b)
         { return ((double)a.val / a.wt) > ((double)b.val / b.wt); });
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].wt <= capacity)
        {
            ans += arr[i].val;
            capacity -= arr[i].wt;
        }
        else
        {
            ans += (arr[i].val / (double)(arr[i].wt)) * (double)capacity;
            break;
        }
    }
    return ans;
}

bool lemonadeChange(vector<int> &bills)
{
    int five = 0, ten = 0;
    for (int bill : bills)
    {
        if (bill == 5)
            five++;
        else if (bill == 10)
        {
            if (--five < 0)
                return false;
            ten++;
        }
        else
        {
            if (ten > 0 && five > 0)
            {
                ten--;
                five--;
            }
            else if (five >= 3)
                five -= 3;
            else
                return false;
        }
    }
    return true;
}

bool checkValidString(string s)
{
    int star = 0;
    stack<char> st;
    for (char c : s)
    {
        if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            if (!st.empty())
                st.pop();
            else if (--star < 0)
                return false;
        }
        else
            star++;
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    cin >> m;
    vector<int> arr2(m);
    for (int &a : arr2)
        cin >> a;
    cout << findContentChildren(arr, arr2) << endl;
    cout << "--------------" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cin >> m;
    arr2.resize(m);
    for (int &a : arr2)
        cin >> a;
    int c;
    cin >> c;
    cout << fractionalKnapsack(arr, arr2, c) << endl;
    cout << "--------------" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    cout << lemonadeChange(arr) << endl;
    cout << "--------------" << endl;
    string s;
    getline(cin, s);
    cout << checkValidString(s) << endl;
    
    cout << "--------------" << endl;

    return 0;
}