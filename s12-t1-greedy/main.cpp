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
    cout << "--------------------" << endl;

    return 0;
}