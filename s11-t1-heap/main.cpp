#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> heap;
    void initializeHeap()
    {
        heap.clear();
    }
    int parent(int idx)
    {
        return (idx - 1) / 2;
    }
    int left(int idx)
    {
        return 2 * idx + 1;
    }
    int right(int idx)
    {
        return 2 * idx + 2;
    }
    void shiftUP(int idx)
    {
        while (idx != 0 && heap[parent(idx)] > heap[idx])
        {
            swap(heap[parent(idx)], heap[idx]);
            idx = parent(idx);
        }
    }
    void heapify(int idx)
    {
        int li = left(idx);
        int ri = right(idx);
        int min = idx;
        if (li < heap.size() && heap[min] > heap[li])
            min = li;
        if (ri < heap.size() && heap[min] > heap[ri])
            min = ri;
        if (min == idx)
            return;
        swap(heap[min], heap[idx]);
        heapify(min);
    }
    void insert(int key)
    {
        heap.push_back(key);
        int idx = heap.size();
        shiftUP(idx);
    }

    void changeKey(int index, int new_val)
    {
        heap[index] = new_val;
        heapify(index);
        shiftUP(index);
    }

    void extractMin()
    {
        if (heap.size() == 0)
            return;
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        if (heap.size() == 0)
            return;
        heapify(0);
    }

    bool isEmpty()
    {
        return (heap.size() == 0);
    }

    int getMin()
    {
        if (heap.size() == 0)
            return INT_MAX;
        return heap[0];
    }

    int heapSize()
    {
        return heap.size();
    }
};

bool isHeap(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n / 2; i++)
    {
        int left = 2 * i + 1;
        if (left < n && nums[i] > nums[left])
            return false;
        int right = 2 * i + 2;
        if (right < n && nums[i] > nums[right])
            return false;
    }
    return true;
}

void heapify(vector<int> &arr, int idx, int N)
{
    int li = 2 * idx + 1;
    int ri = 2 * idx + 2;
    int min = idx;
    if (li < arr.size() && arr[min] < arr[li])
        min = li;
    if (ri < arr.size() && arr[min] < arr[ri])
        min = ri;
    if (min != idx)
    {
        swap(arr[min], arr[idx]);
        heapify(arr, min, N);
    }
}

void convertMinToMaxHeap(vector<int> &arr, int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, i, N);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    cout << isHeap(arr) << endl;
    cout << "--------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    convertMinToMaxHeap(arr, n);
    for (int &a : arr)
        cout << a << " ";
    cout << endl;
    cout << "--------------------" << endl;

    return 0;
}