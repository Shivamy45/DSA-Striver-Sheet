#include <iostream>
using namespace std;

void printArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }
    while (left <= mid)
        temp.push_back(arr[left++]);
    while (right <= high)
        temp.push_back(arr[right++]);
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
    printArr(arr);
}

void recursiveBubbleSort(vector<int> &arr, int n)
{
    if (n <= 1)
        return;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }
    printArr(arr);
    recursiveBubbleSort(arr, n - 1);
}

void recursiveInsertionSort(vector<int> &arr, int n)
{
    if (n < 1)
        return;
    recursiveInsertionSort(arr, n - 1);
    int j = n;
    while (j > 0 && arr[j - 1] > arr[j])
    {
        swap(arr[j - 1], arr[j]);
        --j;
    }
    printArr(arr);
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[j] > pivot && j >= low + 1)
            j--;
        if (i < j)
        {
            swap(arr[i], arr[j]);
            printArr(arr);
        }
    }

    swap(arr[low], arr[j]);
    printArr(arr);

    return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> temp = arr;
    printArr(arr);
    mergeSort(arr, 0, n - 1);
    arr = temp;
    cout << "------------" << endl;
    printArr(arr);
    recursiveBubbleSort(arr, n - 1);
    arr = temp;
    cout << "------------" << endl;
    printArr(arr);
    recursiveInsertionSort(arr, n - 1);
    arr = temp;
    cout << "------------" << endl;
    printArr(arr);
    quickSort(arr, 0, n - 1);
    arr = temp;
    cout << "------------" << endl;
    printArr(arr);

    return 0;
}