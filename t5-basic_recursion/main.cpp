#include <iostream>
using namespace std;

void printNtimes(int cnt)
{
    if (cnt == 10)
        return;
    cout << (cnt > 10 ? cnt-- : cnt++);
    printNtimes(cnt);
}

void printNameNtime(int n, int i = 1)
{
    if (i > n)
        return;
    cout << "Shivam ";
    printNameNtime(n, i + 1);
}

void print1toN(int n, int i = 1)
{
    if (i > n)
        return;
    print1toN(n, i + 1);
    cout << i << " ";
}
// void print1toN(int n, int i = 1)
// {
//     if (i > n)
//         return;
//     cout << i << " ";
//     print1toN(n, i + 1);
// }

void printNto1(int n)
{
    if (n <= 0)
        return;
    cout << n << " ";
    printNto1(n - 1);
}

// int sumOfFirstNnumbers(int n, int sum = 0)
// {
//     if (n <= 1)
//         return n;
//     return n + sumOfFirstNnumbers(n - 1);
// }
int sumOfFirstNnumbers(int n, int sum = 0)
{
    if (n <= 0)
        return sum;
    return sumOfFirstNnumbers(n - 1, sum + n);
}

// int factOfNnumbers(int n, int fact = 1)
// {
//     if (n <= 0)
//         return fact;
//     return factOfNnumbers(n - 1, fact * n);
// }
int factOfNnumbers(int n)
{
    if (n <= 1)
        return 1;
    return n * factOfNnumbers(n - 1);
}

void reverseArray(int arr[], int end, int start = 0){
    if(start >= end)
        return;
    swap(arr[start], arr[end]);
    reverseArray(arr, end - 1, start + 1);
}

// void reverseArray(int arr[], int n, int i = 0){
//     if(i >= n / 2)
//         return;
//     swap(arr[i], arr[n - i]);
//     reverseArray(arr, n, i + 1);
// }

bool isPalindrome(string s, int i = 0){
    if (i >= s.length() / 2)
        return true;
    if(s[i] != s[s.length() - i - 1])
        return false;
    return isPalindrome(s, i + 1);
}

int fib(int n){
    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;
    printNtimes(n);
    cout << endl;
    printNameNtime(n);
    cout << endl;
    print1toN(n);
    cout << endl;
    printNto1(n);
    cout << endl
         << sumOfFirstNnumbers(n) << endl;
    cout << factOfNnumbers(n) << endl;
    int arr[] = {1, 2, 3, 4, 5};
    reverseArray(arr, 4);
    for(int i : arr)
        cout << i << " ";
    cout << endl;
    string s = "amanaplanacanalpanama";
    cout << isPalindrome(s) << endl;
    cout << fib(n);

    return 0;
}