#include <iostream>
using namespace std;

void findMissingAndDuplicate(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            cout << "Duplicate: " << arr[i] << endl;
        else if (arr[i] - 1 != arr[i - 1])
            cout << "Missing: " << arr[i] - 1 << endl;
    }
}

void findMissingAndDuplicate_1(vector<int> &arr)
{
    int n = arr.size(), freq = 0;
    int mis = -1, dup = -1;
    for (int i = 1; i <= n; i++)
    {
        freq = 0;
        for (int j = 0; j < n; j++)
            if (i == arr[j])
                freq++;

        if (freq > 1)
            cout << "Duplicate: " << i << endl;
        else if (freq == 0)
            cout << "Missing: " << i << endl;
        if (dup != -1 && mis != -1)
            break;
    }
}

void findMissingAndDuplicate_2(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> mpp;
    for (int i : arr)
        mpp[i]++;
    for (int i = 1; i <= n; i++)
    {
        if (mpp[i] == 0)
            cout << "Missing: " << i << endl;
        else if (mpp[i] > 1)
            cout << "Duplicate: " << i << endl;
    }
}

void findMissingAndDuplicate_3(vector<int> arr)
{
    int n = arr.size();
    int dup = -1, missing = -1;

    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i]) - 1;
        if (arr[index] < 0)
            dup = abs(arr[i]);
        else
            arr[index] = -arr[index];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            missing = i + 1;
            break;
        }
    }
    cout << "Missing: " << missing << endl;
    cout << "Duplicate: " << dup << endl;
}

void findMissingAndDuplicate_4(vector<int> &arr)
{
    int n = arr.size();
    long long arraySum = 0, array2Sum = 0;

    for (int i = 0; i < n; i++)
    {
        arraySum += arr[i];
        array2Sum += (long long)arr[i] * arr[i];
    }

    long long nSum = (long long)n * (n + 1) / 2;
    long long n2Sum = (long long)n * (n + 1) * (2 * n + 1) / 6;

    long long firstEq = nSum - arraySum;             // missing - duplicate
    long long secEq = (n2Sum - array2Sum) / firstEq; // missing + duplicate

    long long missing = (firstEq + secEq) / 2;
    long long duplicate = secEq - missing;

    cout << "Missing: " << missing << endl;
    cout << "Duplicate: " << duplicate << endl;
}
void findMissingAndDuplicate_5(vector<int> &arr)
{
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    findMissingAndDuplicate(arr);
    cout << "-------------------" << endl;
    findMissingAndDuplicate_1(arr);
    cout << "-------------------" << endl;
    findMissingAndDuplicate_2(arr);
    cout << "-------------------" << endl;
    findMissingAndDuplicate_3(arr);
    cout << "-------------------" << endl;
    findMissingAndDuplicate_4(arr);
    cout << "-------------------" << endl;
    return 0;
}