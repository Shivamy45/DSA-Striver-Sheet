#include <iostream>
using namespace std;

int lastFibo(int n)
{
    if(n <= 1)
        return n;
    long long a = 0, b = 1, c, i;
    for (i = 2; i <= n; i++)
    {
        c = (a + b) % 10;
        a = b;
        b = c;
    }
    cout << i - 1 << endl;
    return b;
}

int main()
{
    int n;
    cin >> n;
    cout << lastFibo(n);
    return 0;
}