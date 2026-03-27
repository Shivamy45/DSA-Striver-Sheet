#include <iostream>
using namespace std;

bool helperIsSubsetSum(int i, int sum, vector<int> &arr, int target)
{
    if (sum == target)
        return true;
    if (sum > target || i == arr.size())
        return false;
    return helperIsSubsetSum(i + 1, sum, arr, target) || helperIsSubsetSum(i + 1, sum + arr[i], arr, target);
}

bool isSubsetSum(vector<int> arr, int target)
{
    return helperIsSubsetSum(0, 0, arr, target);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    int k;
    cin >> k;
    cout << isSubsetSum(arr, k) << endl;
    cout << "--------------" << endl;
    return 0;
}