/*
 * Binary Search and its advanced applications
 * -------------------------------------------
 * This file contains implementations of binary search and its various applications,
 * including searching in rotated arrays, finding bounds, ceil/floor, and special problems.
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/* ==========================
   Basic Binary Search
   ========================== */

/*
 * Performs iterative binary search to find the index of target in arr.
 * Returns index if found, else -1.
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * Example: binarySearch(arr, 6)
 */
int binarySearch(vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

/*
 * Performs recursive binary search to find the index of target in arr.
 * Returns index if found, else -1.
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) due to recursion stack
 * Example: binarySeachUsingRecursion(arr, 6, 0, n - 1)
 */
int binarySeachUsingRecursion(vector<int> &arr, int target, int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySeachUsingRecursion(arr, target, mid + 1, high);
    else
        return binarySeachUsingRecursion(arr, target, low, mid - 1);
}

/* ==========================
   Bounds (Lower/Upper/Insert Position)
   ========================== */

/*
 * Finds the lower bound index of target in arr.
 * Returns the first index where arr[index] >= target.
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * Example: lowerBound(arr, 8)
 */
int lowerBound(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

/*
 * Finds the upper bound index of target in arr.
 * Returns the first index where arr[index] > target.
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * Example: upperBound(arr, 15)
 */
int upperBound(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

/*
 * Returns the insert position for target in arr (same as lower bound).
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * Example: insertPos(arr, 10)
 */
int insertPos(vector<int> &arr, int target)
{
    return lowerBound(arr, target);
}

/* ==========================
   Ceil and Floor
   ========================== */

/*
 * Finds and prints the floor and ceil of x in arr.
 * Floor: greatest element <= x
 * Ceil: smallest element >= x
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * Example: ceilAndFloor(arr, 10)
 */
void ceilAndFloor(vector<int> &arr, int x)
{
    int ceil = 0, floor = 0;
    int low = 0, high = arr.size() - 1;
    ceil = arr[lowerBound(arr, x)];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= x)
        {
            floor = arr[mid];
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << "Floor: " << floor << endl;
    cout << "Ceil: " << ceil << endl;
}

/* ==========================
   First/Last Occurrence and Count
   ========================== */

/*
 * Finds the first and last index of x in arr.
 * Returns pair(firstIndex, lastIndex).
 * If x not found, returns (-1, -1).
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * Example: firstAndLastIdx(arr, 9)
 */
pair<int, int> firstAndLastIdx(vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1, first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            high = mid - 1;
            first = mid;
        }
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    low = 0, high = arr.size() - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
        {
            low = mid + 1;
            last = mid;
        }
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return make_pair(first, last);
}

/*
 * Counts the occurrences of x in arr.
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * Example: countOccurence(arr, 9)
 */
int countOccurence(vector<int> &arr, int x)
{
    if (firstAndLastIdx(arr, x).first == -1)
        return 0;
    return firstAndLastIdx(arr, x).second - firstAndLastIdx(arr, x).first + 1;
}

/* ==========================
   Rotated Sorted Array
   ========================== */

/*
 * Searches for x in a rotated sorted array arr.
 * Returns index if found, else -1.
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * Example: searchEleInRotatedArray(arr, 6)
 */
int searchEleInRotatedArray(vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[low] <= arr[mid]) // left sorted
        {
            if (arr[low] <= x && arr[mid] >= x)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else // right sorted
            if (arr[mid] <= x && arr[high] >= x)
                low = mid + 1;
            else
                high = mid - 1;
    }
    return -1;
}

/*
 * Searches for x in a rotated sorted array arr that may contain duplicates.
 * Returns true if found, else false.
 * Time Complexity: O(n) in worst case due to duplicates
 * Space Complexity: O(1)
 * Example: searchElementInRotatedArrayWithDuplicates(arr, 1)
 */
bool searchElementInRotatedArrayWithDuplicates(vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == x)
            return true;
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }
        if (arr[low] <= arr[mid]) // left sorted
            if (arr[low] <= x && arr[mid] >= x)
                high = mid - 1;
            else
                low = mid + 1;
        else // right sorted
            if (arr[mid] <= x && arr[high] >= x)
                low = mid + 1;
            else
                high = mid - 1;
    }
    return false;
}

/*
 * Finds the minimum element in a rotated sorted array arr.
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * Example: minElementInRotatedArray(arr)
 */
int minElementInRotatedArray(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1, minVal = INT_MAX;
    if (arr.size() == 1)
        return arr[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[high])
        {
            minVal = min(minVal, arr[low]);
            break;
        }
        if (arr[low] <= arr[mid])
        {
            // left sorted
            minVal = min(minVal, arr[low]);
            low = mid + 1;
        }
        else
        {
            // right sorted
            minVal = min(minVal, arr[mid]);
            high = mid - 1;
        }
    }
    return minVal;
}

/*
 * Finds the number of times the array has been rotated.
 * Returns the index of the minimum element.
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * Example: findArrayRotatedTime(arr)
 */
int findArrayRotatedTime(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1, minIdx = 0;
    if (arr.size() == 1)
        return 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[high])
        {
            if (arr[low] < arr[minIdx])
                minIdx = low;
            break;
        }

        if (arr[low] <= arr[mid])
        {
            // left sorted
            if (arr[low] < arr[minIdx])
                minIdx = low;
            low = mid + 1;
        }
        else
        {
            // right sorted
            if (arr[mid] < arr[minIdx])
                minIdx = mid;
            high = mid - 1;
        }
    }
    return minIdx;
}

/* ==========================
   Special Binary Search Problems
   ========================== */

/*
 * Finds the single non-duplicate element in a sorted array where every other element appears twice.
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * Example: singleNonDuplicate(arr)
 */
int singleNonDuplicate(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            return arr[mid];

        if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) ||
            (mid % 2 == 1 && arr[mid] == arr[mid - 1]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

/*
 * Finds the index of a peak element in arr.
 * A peak element is greater than its neighbors.
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 * Example: peakElement(arr)
 */
int peakElement(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1 || arr[0] > arr[1])
        return 0;
    if (arr[n - 1] > arr[n - 2])
        return n - 1;
    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;
        else if (arr[mid - 1] < arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    cout << binarySearch(arr, 6) << endl;
    cout << "---------------------" << endl;
    cout << binarySeachUsingRecursion(arr, 6, 0, n - 1) << endl;
    cout << "---------------------" << endl;
    cout << lowerBound(arr, 8) << endl;
    cout << "---------------------" << endl;
    cout << upperBound(arr, 15) << endl;
    cout << "---------------------" << endl;
    cout << insertPos(arr, 10) << endl;
    cout << "---------------------" << endl;
    ceilAndFloor(arr, 10);
    cout << "---------------------" << endl;
    cout << "(" << firstAndLastIdx(arr, 9).first << "," << firstAndLastIdx(arr, 9).second << ")" << endl;
    cout << "---------------------" << endl;
    cout << "No. of 9 are: " << countOccurence(arr, 9) << endl;
    cout << "---------------------" << endl;
    cout << "6 is present at: " << searchEleInRotatedArray(arr, 6) << endl;
    cout << "---------------------" << endl;
    for (int &a : arr)
        cin >> a;
    cout << "Is 1 present: " << searchElementInRotatedArrayWithDuplicates(arr, 1) << endl;
    cout << "---------------------" << endl;
    for (int &a : arr)
        cin >> a;
    cout << "Min Element: " << minElementInRotatedArray(arr) << endl;
    cout << "---------------------" << endl;
    cout << "Array Rotation: " << findArrayRotatedTime(arr) << endl;
    cout << "---------------------" << endl;
    cout << "First Non Duplicate: " << singleNonDuplicate(arr) << endl;
    cout << "---------------------" << endl;
    cout << "Peak element at: " << peakElement(arr) << endl;
    cout << "---------------------" << endl;

    return 0;
}