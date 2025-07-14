#include <iostream>
using namespace std;

void printArr(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void findMaxEle(vector<int> arr, int n)
{
    int maxEle = arr[0];
    for (int i = 1; i < n; i++)
        maxEle = max(maxEle, arr[i]);
    cout << maxEle << endl;
}

void findSecMinAndMax(vector<int> arr, int n)
{
    int maximum = INT_MIN, secondMax = INT_MIN, minimum = INT_MAX, secondMin = INT_MAX;
    for (int i : arr)
    {
        if (i > maximum)
        {
            secondMax = maximum;
            maximum = i;
        }
        else if (i > secondMax && i != maximum)
        {
            secondMax = i;
        }
        if (i < minimum)
        {
            secondMin = minimum;
            minimum = i;
        }
        else if (i < secondMin && i != minimum)
        {
            secondMin = i;
        }
    }
    cout << "Second Minimum: " << secondMin << " Second Maximum: " << secondMax << endl;
}

void isSorted(vector<int> arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            cout << "False" << endl;
            return;
        }
    }
    cout << "True" << endl;
}

void removeDuplicatesFromSortedArray(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int i = 1, j = 1;
    while (j < arr.size())
    {
        if (arr[j] != arr[i - 1])
        {
            arr[i++] = arr[j];
        }
        j++;
    }
}

void leftRotateByOne(vector<int> &arr, int n)
{
    int x = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = x;
}

//! Does LeftRotate K times
// void leftRotateByK(vector<int> &arr, int n, int k)
// {
//     k %= n;
//     while (k--)
//     {
//         leftRotateByOne(arr, n);
//     }
// }
void leftRotateByK(vector<int> &arr, int n, int k)
{
    k %= n;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

//! Has heap-buffer-overflow bug
// void moveZeroes(vector<int> &arr, int n)
// {
//     int i = 0, j = 0;
//     while (i < n && j < n)
//     {
//         while (j < n && arr[j] == 0)
//         {
//             j++;
//         }
//         if(i < n && j < n) swap(arr[i++], arr[j++]);
//     }
// }
void moveZeroes(vector<int> &arr, int n)
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
        return;
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j++]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    printArr(arr, n);
    cout << "----------------------" << endl;
    findMaxEle(arr, n);
    cout << "----------------------" << endl;
    findSecMinAndMax(arr, n);
    cout << "----------------------" << endl;
    isSorted(arr, n);
    cout << "----------------------" << endl;
    printArr(arr, n);
    removeDuplicatesFromSortedArray(arr, n);
    printArr(arr, n);
    cout << "----------------------" << endl;
    printArr(arr, n);
    leftRotateByOne(arr, n);
    printArr(arr, n);
    cout << "----------------------" << endl;
    printArr(arr, n);
    leftRotateByK(arr, n, 3);
    printArr(arr, n);
    cout << "----------------------" << endl;
    printArr(arr, n);
    moveZeroes(arr, n);
    printArr(arr, n);
    cout << "----------------------" << endl;

    return 0;
}