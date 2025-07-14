#include <iostream>
#include <math.h>
#include <set>
using namespace std;

int countDigit(int n)
{
    int count = 0;
    while (n)
    {
        count++;
        n /= 10;
    }
    return count;
}

int reverseNumber(int n)
{
    int revNum = 0;
    while (n)
    {
        if (revNum < INT_MIN / 10 || revNum > INT_MAX / 10)
            return -1;
        revNum = revNum * 10 + n % 10;
        n /= 10;
    }
    return revNum;
}

bool isPalindrome(int n)
{
    if (n < 0)
        return false;
    int x = reverseNumber(n);
    if (n == x)
        return true;
    else
        return false;
}

int gcd(int n, int n1 = 8)
{
    if(n == 0 || n == n1)
        return n1;
    if(n > n1)
        return gcd(n % n1, n1);
    else
        return gcd(n1 % n, n);
}

bool isArmstrong(int n)
{
    int digits = countDigit(n);
    int x = 0, temp = n;
    while (temp)
    {
        x += pow(temp % 10, digits);
        temp /= 10;
    }
    if (n == x)
        return true;
    return false;
}

void allDivisors(int n)
{
    set<int> s;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            s.insert(i);
            s.insert(n / i);
        }
//     for (int i = 1; i * i <= n; i++)
//         if (n % i == 0)
//         {
//             cout << i << " ";
//             if (n / i != i)
//                 cout << n / i << " ";
//         }
    for(int i : s)
        cout << i << " ";
    cout << endl;
}

bool isPrime(int n)
{
    if (n % 2 == 0 || n <= 1)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    cout << countDigit(n) << endl;
    cout << reverseNumber(n) << endl;
    cout << isPalindrome(n) << endl;
    cout << gcd(n, 8) << endl;
    cout << isArmstrong(n) << endl;
    allDivisors(n);
    cout << isPrime(n) << endl;

    return 0;
}

/*
(36, 8)
(28, 8)
(20, 8)
(12, 8)
(4, 8)
(4, 4)
*/