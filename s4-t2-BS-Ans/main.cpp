#include <iostream>
using namespace std;

int findSqrtUsingBS(int n)
{

    for (int i = 1; i < n; i++)
    {
        if (i * i >= n)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    findSqrtUsingBS(n);
    

    return 0;
}