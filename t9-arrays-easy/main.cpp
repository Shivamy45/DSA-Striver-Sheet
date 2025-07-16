#include <iostream>
#include <map>
#include <set>
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

void leftRotateByK(vector<int> &arr, int n, int k)
{
    k %= n;
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}
//? Does LeftRotateOne K times
// void leftRotateByK2(vector<int> &arr, int n, int k)
// {
//     k %= n;
//     while (k--)
//     {
//         leftRotateByOne(arr, n);
//     }
// }

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

void findElement(vector<int> arr, int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num)
        {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

void unionOfArray(vector<int> arr, int n, vector<int> temp, int m)
{
    sort(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        while (i < n && i > 0 && arr[i] == arr[i - 1])
            i++;
        while (j < m && j > 0 && temp[j] == temp[j - 1])
            j++;

        if (arr[i] < temp[j])
        {
            cout << arr[i] << " ";
            i++;
        }
        else if (temp[j] < arr[i])
        {
            cout << temp[j] << " ";
            j++;
        }
        else
        {
            cout << arr[i] << " ";
            i++;
            j++;
        }
    }
    while (i < n)
    {
        if (i == 0 || arr[i] != arr[i - 1])
            cout << arr[i] << " ";
        i++;
    }
    while (j < m)
    {
        if (j == 0 || temp[j] != temp[j - 1])
            cout << temp[j] << " ";
        j++;
    }
    cout << endl;
}

//? Using MAP
// void unionOfArray1(vector<int> arr1, int n, vector<int> arr2, int m)
// {
//     map<int, int> freq;
//     for (int i = 0; i < n; i++)
//         freq[arr1[i]]++;
//     for (int i = 0; i < m; i++)
//         freq[arr2[i]]++;
//     for (auto &it : freq)
//         cout << it.first << " ";
//     cout << endl;
// }

//? Using SET
// void unionOfArray2(vector<int> arr1, int n, vector<int> arr2, int m)
// {
//     set<int> res;
//     for (int i = 0; i < n; i++)
//         res.insert(arr1[i]);
//     for (int i = 0; i < m; i++)
//         res.insert(arr2[i]);
//     for(int i : res)
//         cout << i << " ";
//     cout << endl;
// }

//? Using vector.back() to check for duplicated
// void unionOfArray3(vector<int> arr, int n, vector<int> temp, int m)
// {
//     sort(arr.begin(), arr.end());
//     sort(temp.begin(), temp.end());
//     int i = 0, j = 0;
//     vector<int> res;
//     while (i < n && j < m)
//     {

//         if (arr[i] <= temp[j])
//         {
//             if (i == 0 || res.back() != arr[i])
//                 res.push_back(arr[i]);
//             i++;
//         }
//         else if (j == 0 || temp[j] < arr[i])
//         {
//             if (res.back() != temp[j])
//                 res.push_back(temp[j]);
//             j++;
//         }
//     }
//     while (i < n)
//     {
//         if (i == 0 || res.back() != arr[i])
//             res.push_back(arr[i]);
//         i++;
//     }
//     while (j < m)
//     {
//         if (j == 0 || temp[j] != temp[j - 1])
//             res.push_back(temp[j]);
//         j++;
//     }
//     printArr(res, res.size());
// }

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
    // leftRotateByK2(arr, n, 3);
    printArr(arr, n);
    cout << "----------------------" << endl;
    printArr(arr, n);
    moveZeroes(arr, n);
    printArr(arr, n);
    cout << "----------------------" << endl;
    printArr(arr, n);
    findElement(arr, n, 2);
    cout << "----------------------" << endl;
    int m;
    cin >> m;
    vector<int> temp(m);
    for (int i = 0; i < m; i++)
        cin >> temp[i];
    printArr(arr, n);
    cout << "        +        " << endl;
    printArr(temp, m);
    cout << "        =        " << endl;
    unionOfArray(arr, n, temp, m);
    // unionOfArray1(arr, n, temp, m);
    // unionOfArray2(arr, n, temp, m);
    // unionOfArray3(arr, n, temp, m);
    cout << "----------------------" << endl;
    
    return 0;
}