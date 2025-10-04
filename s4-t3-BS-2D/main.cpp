#include <iostream>
using namespace std;

// ------------------------------
// Row with Max Ones Functions
// ------------------------------

// Time Complexity: O(log m)
// Space Complexity: O(1)
// Explanation: Helper function to count number of ones in a sorted row using binary search
int helperNoOf1(vector<int> &row)
{
    int n = row.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (row[mid] == 1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return n - low;
}

// Time Complexity: O(n log m)
// Space Complexity: O(1)
// Explanation: Finds row with maximum number of ones in a binary matrix
int findRowWithMax1s(vector<vector<int>> &mat)
{
    // 0 0 0 0 0 0 0 0
    int maxCount = 0, maxCountIdx = -1;
    for (int i = 0; i < mat.size(); i++)
    {
        int countOf1 = helperNoOf1(mat[i]);
        if (maxCount < countOf1)
        {
            maxCount = countOf1;
            maxCountIdx = i;
        }
    }
    return maxCountIdx;
}

// ------------------------------
// Matrix Search Functions
// ------------------------------

// Time Complexity: O(log m)
// Space Complexity: O(1)
// Explanation: Helper function to search for target in a sorted row using binary search
bool helperFound(vector<int> &matRow, int target)
{
    int n = matRow.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (matRow[mid] == target)
            return true;
        else if (matRow[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
// Time Complexity: O(log n + log m)
// Space Complexity: O(1)
// Explanation: Searches for target in a row-wise sorted matrix using binary search
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (matrix[mid][0] <= target && target <= matrix[mid][m - 1])
        {
            return helperFound(matrix[mid], target);
        }
        else if (target < matrix[mid][0])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}

// Time Complexity: O(log(n*m))
// Space Complexity: O(1)
// Idea: Treat the 2D matrix as a flattened sorted array.

// Time Complexity: O(log(n*m))
// Space Complexity: O(1)
// Explanation: Searches in matrix by treating it as a flattened sorted array
bool searchMatrix_1(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    if (n == 0)
        return false;
    int m = matrix[0].size();
    if (m == 0)
        return false;

    int low = 0, high = n * m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Map 1D index back to 2D indices
        int row = mid / m;
        int col = mid % m;

        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

// Time Complexity: O(n + m)
// Space Complexity: O(1)
// Explanation: Searches matrix by starting from top-right and moving left/down
bool searchMatrixInBothDir(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();
    if (n == 0 || m == 0)
        return false;
    int row = 0, col = m - 1;
    while (row < n && col >= 0)
    {
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target)
            row++;
        else
            col--;
    }
    return false;
}

// ------------------------------
// Peak Element Functions
// ------------------------------

// Time Complexity: O(n log m)
// Space Complexity: O(1)
// Explanation: Finds a peak element that is greater than all its neighbors
void findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int maxEleIdx = 0;
        int mid = (low + high) / 2;
        for (int i = 1; i < m; i++)
            if (mat[mid][maxEleIdx] < mat[mid][i])
                maxEleIdx = i;
        if ((mid == 0 || (mat[mid][maxEleIdx] > mat[mid - 1][maxEleIdx])) &&
            (mid == n - 1 || (mat[mid][maxEleIdx] > mat[mid + 1][maxEleIdx])))
        {
            cout << "{" << mid << ", " << maxEleIdx << "}" << endl;
            return;
        }
        else if (mid == 0 || (mat[mid][maxEleIdx] < mat[mid + 1][maxEleIdx]))
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "{-1, -1}" << endl;
}

// ------------------------------
// Matrix Median Functions
// ------------------------------

// Time Complexity: O(32 * n * log m)
// Space Complexity: O(1)
// Explanation: Finds median element in row-wise sorted matrix using binary search
void findMedian(vector<vector<int>> &arr)
{
    int n = arr.size(), m = arr[0].size();
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++)
        low = min(low, arr[i][0]);
    for (int i = 0; i < n; i++)
        high = max(high, arr[i][m - 1]);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int low1 = 0, high1 = m - 1;
            while (low1 <= high1)
            {
                int mid1 = (low1 + high1) / 2;
                if (arr[i][mid1] <= mid)
                    low1 = mid1 + 1;
                else
                    high1 = mid1 - 1;
            }
            cnt += high1 + 1;
        }
        if (cnt - 1 >= m * n / 2)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << low << endl;
}

// ------------------------------
// Driver Code
// ------------------------------

// Time Complexity: O(1)
// Space Complexity: O(1)
// Explanation: Main function to test all implemented matrix search algorithms
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (auto &it : mat)
        for (int &a : it)
            cin >> a;
    cout << findRowWithMax1s(mat) << endl;
    cout << "----------------------" << endl;

    cin >> n >> m;
    mat = vector<vector<int>>(n, vector<int>(m));
    for (auto &it : mat)
        for (int &a : it)
            cin >> a;
    int k;
    cin >> k;
    cout << (searchMatrix(mat, k) ? "True" : "False") << endl;
    cout << "----------------------" << endl;
    cout << (searchMatrix_1(mat, k) ? "True" : "False") << endl;
    cout << "----------------------" << endl;

    cin >> n >> m;
    mat = vector<vector<int>>(n, vector<int>(m));
    for (auto &it : mat)
        for (int &a : it)
            cin >> a;
    cin >> k;
    cout << (searchMatrixInBothDir(mat, k) ? "True" : "False") << endl;
    cout << "----------------------" << endl;
    cin >> n >> m;
    mat = vector<vector<int>>(n, vector<int>(m));
    for (auto &it : mat)
        for (int &a : it)
            cin >> a;
    findPeakGrid(mat);
    cout << "----------------------" << endl;
    cin >> n >> m;
    mat = vector<vector<int>>(n, vector<int>(m));
    for (auto &it : mat)
        for (int &a : it)
            cin >> a;
    findMedian(mat);
    cout << "----------------------" << endl;

    return 0;
}