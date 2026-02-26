#include <iostream>
using namespace std;

int f(vector<int> &dp, int n)
{
    if (dp[n] != -1)
        return dp[n];
    if (n <= 1)
        return dp[n] = n;
    return dp[n] = f(dp, n - 1) + f(dp, n - 2);
}

// Memoization
int fibo(int n)
{
    vector<int> dp(n + 1, -1);
    return f(dp, n);
}
// Tabulation
int fibo2(int n)
{
    // vector<int> dp(n + 1, -1);
    // dp[0] = 0;
    // dp[1] = 1;
    // for (int i = 2; i <= n; i++)
    // {
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // }
    // return dp[n];
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    cout << "----------------" << endl;
    cout << fibo2(n) << endl;
    cout << "----------------" << endl;
    return 0;
}