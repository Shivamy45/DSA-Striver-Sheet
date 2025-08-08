#include <iostream>
using namespace std;

// O(r)
long long computeNCR(int n, int r)
{
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

// O(r)
// Prints value at (r, c) in Pascal's Triangle (1-indexed)
void printPascalCell(int r, int c)
{
    // 1
    // 1 1
    // 1 2 1
    // 1 3 3 1
    // 1 4 6 4 1
    cout << computeNCR(r - 1, c - 1) << endl;
}

// O(r)
// Efficiently prints the r-th row of Pascal's Triangle (0-indexed)
void printPascalRow(int r)
{
    int res = 1;
    for (int i = 0; i <= r; i++)
    {
        cout << res << " ";
        res *= (r - i);
        res /= (i + 1);
    }
    cout << endl;
}

// O(n^2)
// Prints Pascal's Triangle up to n rows
void printPascalTriangle(int n)
{
    for (int r = 0; r < n; r++)
    {
        int res = 1;
        printPascalRow(r);
    }
}

// O(n)
// Element present more than N/3 times
void majorityElement(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mpp;
    for (int i : arr)
        mpp[i]++;
    for (auto it : mpp)
        if (it.second > n / 3)
            cout << it.first << " ";
}

// O(n)
// Element present more than N/3 times
void majorityElement2(vector<int> &arr)
{
    int n = arr.size();
}

int main()
{
    int r, c;
    cin >> r >> c;
    // Pascal Triangle
    // Variation 1
    printPascalCell(r, c);
    // Variation 2
    printPascalRow(r);
    // Variation 3
    printPascalTriangle(r);

    return 0;
}