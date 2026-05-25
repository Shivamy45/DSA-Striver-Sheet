#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <queue>
using namespace std;

int power(int n, int k, int limit)
{
    int res = 1;
    for (int i = 0; i < k; i++)
    {
        if (res > limit / n)
            return limit + 1;
        res *= n;
    }
    return res;
}
int perfectPower(int n, int k)
{
    int l = 1, r = n, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (power(mid, k, n) <= n)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}
int countKthRoots(int l, int r, int k)
{
    long long left = perfectPower(l - 1, k);
    long long right = perfectPower(r, k);
    return right - left + 1;
}

int main()
{
    int l, r, k;
    cin >> l >> r >> k;
    cout << countKthRoots(l, r, k);
    return 0;
}