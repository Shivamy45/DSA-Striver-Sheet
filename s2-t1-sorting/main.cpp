#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

//? Utility to copy array - O(n)
void copyArr(int arr[], int temp[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

//? Utility to print array - O(n)
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//? Simple selection sort - O(n^2)
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minEle = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[minEle] > arr[j])
            {
                minEle = j;
            }
        }
        swap(arr[i], arr[minEle]);
        printArr(arr, n);
    }
}

//? Optimized bubble sort with early break - O(n^2)
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool isSorted = true;
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]){
                isSorted = false;
                swap(arr[j], arr[j + 1]);
            }
        printArr(arr, n);
        if(isSorted)
            break;
    }
}

//? Insertion sort - best: O(n), avg/worst: O(n^2)
void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]){
            swap(arr[j - 1], arr[j]);
            --j;
        }
        printArr(arr, n);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[6];
    int temp[6];
    for (int i = 0; i < n; i++)
        cin >> temp[i];

    copyArr(arr, temp, n);
    printArr(arr, n);
    selectionSort(arr, n);
    cout << "----------------" << endl;
    copyArr(arr, temp, n);
    printArr(arr, n);
    bubbleSort(arr, n);
    cout << "----------------" << endl;
    copyArr(arr, temp, n);
    printArr(arr, n);
    insertionSort(arr, n);
    cout << "----------------" << endl;

    return 0;
}