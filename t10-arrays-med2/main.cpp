#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


void printArr(vector<int> &arr)
{
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

void printMatrix(vector<vector<int>> &arr)
{
    for (auto i : arr)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
}

//! Only 1 transaction allowed - O(n)
void stockBuyAndSell(vector<int> &prices)
{
    int n = prices.size();
    int minPrice = INT_MAX, maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    cout << "Max Profit with 1 transaction: " << maxProfit << endl;
}

//? Multiple transactions allowed - O(n)
void stockBuyAndSell2(vector<int> &prices)
{
    bool buy = false;
    int n = prices.size();
    int boughtAt = 0, profit = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (prices[i + 1] > prices[i] && !buy)
        {
            buy = true;
            boughtAt = prices[i];
        }
        else if (buy && prices[i] > prices[i + 1])
        {
            buy = false;
            profit += prices[i] - boughtAt;
        }
    }
    if (buy)
    {
        profit += prices[n - 1] - boughtAt;
    }
    cout << "Max Profit with many transaction: " << profit << endl;
}

//! Works only when +ve and -ve counts are equal - O(n)
void alternatingarr(vector<int> &arr)
{
    int n = arr.size();
    vector<int> posArr;
    vector<int> negArr;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            posArr.push_back(arr[i]);
        else
            negArr.push_back(arr[i]);
    }
    for (int i = 0; i < n / 2; i++)
    {
        arr[2 * i] = posArr[i];
    }
    for (int i = 0; i < n / 2; i++)
    {
        arr[2 * i + 1] = negArr[i];
    }
}

//! Uses extra space - O(n)
void alternatingarr2(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n, 0);
    int posIdx = 0, negIdx = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            res[negIdx] = arr[i];
            negIdx += 2;
        }
        else
        {
            res[posIdx] = arr[i];
            posIdx += 2;
        }
    }
    arr = res;
}

//? Handles unequal counts of +ve and -ve - O(n)
void alternatingarr3(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n);
    int posIdx = 0, negIdx = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && posIdx < n)
        {
            res[posIdx] = arr[i];
            posIdx += 2;
        }
        else if (arr[i] < 0 && negIdx < n)
        {
            res[negIdx] = arr[i];
            negIdx += 2;
        }
    }
    // Fill remaining elements if any
    for (int i = 0; i < n; i++)
    {
        if (posIdx < n && arr[i] > 0)
        {
            res[posIdx] = arr[i];
            posIdx++;
        }
        else if (negIdx < n && arr[i] < 0)
        {
            res[negIdx] = arr[i];
            negIdx++;
        }
    }
    arr = res;
}

//! Uses STL function - O(n)
void nextPermutation(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
    cout << "Done next permutation" << endl;
}

//? Custom implementation - O(n)
void nextPermutation2(vector<int> &nums)
{
    int n = nums.size(), k = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            k = i;
            break;
        }
    }
    if (k == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    else
    {
        for (int j = n - 1; j > k; j--)
            if (nums[j] > nums[k])
            {
                swap(nums[j], nums[k]);
                break;
            }
        reverse(nums.begin() + k + 1, nums.end());
    }
    cout << "Done next permutation" << endl;
}

// O(n)
void leaderInarr(vector<int> &arr)
{
    int n = arr.size();
    int maxEle = INT_MIN;
    vector<int> res;
    for (int i = n - 1; i >= 0; i--)
    {
        if (maxEle < arr[i])
        {
            maxEle = arr[i];
            res.push_back(arr[i]);
        }
    }
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

//! Sorting based approach - O(n log n)
void longestConsSequence(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int maxSeq = 1, seq = 1, n = nums.size();
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1] + 1)
            seq++;
        else if (nums[i] != nums[i - 1])
            seq = 1;
        else
            continue;
        maxSeq = max(maxSeq, seq);
    }
    cout << "Longest Consecutive Sequence: " << maxSeq << endl;
}

//? Using unordered_set - O(n)
void longestConsSequence2(vector<int> &nums)
{
    unordered_set<int> s;
    int cnt = 0, longest = 1;
    for (int i : nums)
        s.insert(i);
    for (int it : s)
    {
        if (s.find(it - 1) == s.end())
        {
            int x = it;
            while (s.find(x) != s.end())
            {
                cnt++;
                x++;
            }
            longest = max(cnt, longest);
        }
        else
            cnt = 0;
    }
    cout << "Longest Consecutive Sequence: " << longest << endl;
}

//! Brute force with extra matrix - O(n*m*(n+m))
void setMatrixZero(vector<vector<int>> &matrix)
{
    vector<vector<int>> arr = matrix;
    int n = arr.size(), m = arr[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == 0)
            {
                for (int k = 0; k < n; k++)
                    arr[k][j] = 0;
                for (int k = 0; k < m; k++)
                    arr[i][k] = 0;
            }
    matrix = arr;
}

//! Marks using -1 in-place - O(n*m*(n+m))
void setMatrixZero2(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == 0)
            {
                for (int k = 0; k < n; k++)
                    if (matrix[k][j] != 0)
                        matrix[k][j] = -1;
                for (int k = 0; k < m; k++)
                    if (matrix[i][k] != 0)
                        matrix[i][k] = -1;
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == -1)
                matrix[i][j] = 0;
}

//! Uses extra row and col arrays - O(n*m)
void setMatrixZero3(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<int> row(n, 0), col(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

//? Optimized in-place marking - O(n*m)
void setMatrixZero4(vector<vector<int>> &matrix)
{
    int col0 = 1, n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j == 0)
                    col0 = 0;
                else
                    matrix[0][j] = 0;
            }

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            if (matrix[i][j] != 0)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
    if (matrix[0][0] == 0)
        for (int i = 0; i < m; i++)
            matrix[0][i] = 0;

    if (col0 == 0)
        for (int j = 0; j < n; j++)
            matrix[j][0] = 0;
}

//! Using extra matrix - O(n^2)
void rotateMatrixBy90Deg(vector<vector<int>> &matrix)
{
    // 1 2 3
    // 4 5 6
    // 7 8 9
    // 00 01 02
    // 10 11 12
    // 20 21 22
    // 7 4 1
    // 8 5 2
    // 9 6 3
    // 00 01 02
    // 10 11 12
    // 20 21 22
    int n = matrix.size();
    vector<vector<int>> res(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[j][n - i - 1] = matrix[i][j];
        }
    }
    matrix = res;
}

//? In-place transpose and reverse - O(n^2)
void rotateMatrixBy90Deg2(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i != j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    //! O(n^2) to reverse
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n / 2; j++)
    //     {
    //         swap(matrix[i][j], matrix[i][n - j - 1]);
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

//? Standard spiral traversal - O(n^2)
void spiralarr(vector<vector<int>> &arr)
{
    // 00 01 02 03
    // 10 11 12 13
    // 20 21 22 23
    // 30 31 32 33
    int n = arr.size();
    int row = 0, col = 0, endRow = n - 1, endCol = n - 1;
    while (row <= endRow && col <= endCol)
    {
        for (int i = col; i <= endCol; i++)
            cout << arr[row][i] << " ";
        row++;
        for (int i = row; i <= endRow; i++)
            cout << arr[i][endCol] << " ";
        endCol--;
        for (int i = endCol; i >= col; i--)
        {
            if (row == endRow)
                break;
            cout << arr[endRow][i] << " ";
        }
        endRow--;
        for (int i = endRow; i >= row; i--)
        {
            if (col == endCol)
                break;
            cout << arr[i][col] << " ";
        }
        col++;
    }
}

//! Brute force 3 loops - O(n^3)
void findAllSubarrsWithGivenSum(vector<int> &arr, int k)
{
    int n = arr.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int K = i; K <= j; K++)
                sum += arr[K];
            if (sum == k)
                cnt++;
        }
    }
    cout << cnt << endl;
}

//! Better with 2 loops - O(n^2)
void findAllSubarrsWithGivenSum2(vector<int> &arr, int k)
{
    int cnt = 0, sum = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
                cnt++;
        }
    }
    cout << cnt << endl;
}

//? Optimal using prefix sum + hashmap - O(n)
void findAllSubarrsWithGivenSum3(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> mpp;
    int sum = 0, cnt = 0;
    mpp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        cnt += mpp[sum - k];
        mpp[sum]++;
    }
    cout << cnt << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &a : arr)
        cin >> a;
    printArr(arr);
    stockBuyAndSell(arr);
    cout << "-----------------------------------" << endl;
    printArr(arr);
    stockBuyAndSell2(arr);
    cout << "-----------------------------------" << endl;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    printArr(arr);
    alternatingarr(arr);
    printArr(arr);
    cout << "-----------------------------------" << endl;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    printArr(arr);
    alternatingarr2(arr);
    printArr(arr);
    cout << "-----------------------------------" << endl;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    printArr(arr);
    alternatingarr3(arr);
    printArr(arr);
    cout << "-----------------------------------" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;
    printArr(arr);
    nextPermutation(arr);
    printArr(arr);
    cout << "-----------------------------------" << endl;
    printArr(arr);
    nextPermutation2(arr);
    printArr(arr);
    cout << "-----------------------------------" << endl;
    for (int &a : arr)
        cin >> a;
    printArr(arr);
    leaderInarr(arr);
    cout << "-----------------------------------" << endl;
    printArr(arr);
    longestConsSequence(arr);
    cout << "-----------------------------------" << endl;
    printArr(arr);
    longestConsSequence2(arr);
    cout << "-----------------------------------" << endl;
    int x, y;
    cin >> x >> y;
    vector<vector<int>> array2(x, vector<int>(y));
    for (int i = 0; i < x; i++)
        for (int j = 0; j < y; j++)
            cin >> array2[i][j];
    cout << "Original Matrix:" << endl;
    printMatrix(array2);
    setMatrixZero(array2);
    cout << "Matrix after setMatrixZero:" << endl;
    printMatrix(array2);
    cout << "-----------------------------------" << endl;
    cout << "Original Matrix:" << endl;
    printMatrix(array2);
    setMatrixZero2(array2);
    cout << "Matrix after setMatrixZero:" << endl;
    printMatrix(array2);
    cout << "-----------------------------------" << endl;
    cout << "Original Matrix:" << endl;
    printMatrix(array2);
    setMatrixZero3(array2);
    cout << "Matrix after setMatrixZero:" << endl;
    printMatrix(array2);
    cout << "-----------------------------------" << endl;
    cout << "Original Matrix:" << endl;
    printMatrix(array2);
    setMatrixZero4(array2);
    cout << "Matrix after setMatrixZero:" << endl;
    printMatrix(array2);
    cout << "-----------------------------------" << endl;
    cin >> n;
    array2.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> array2[i][j];
    cout << "Original Matrix:" << endl;
    printMatrix(array2);
    rotateMatrixBy90Deg(array2);
    cout << "Matrix after rotateMatrixBy90Deg:" << endl;
    printMatrix(array2);
    cout << "-----------------------------------" << endl;
    cout << "Original Matrix:" << endl;
    printMatrix(array2);
    rotateMatrixBy90Deg2(array2);
    cout << "Matrix after rotateMatrixBy90Deg:" << endl;
    printMatrix(array2);
    cout << "-----------------------------------" << endl;
    printMatrix(array2);
    cout << "Starting Spiral" << endl;
    spiralarr(array2);
    cout << "-----------------------------------" << endl;
    cin >> n;
    arr.resize(n);
    for (int &a : arr)
        cin >> a;

    printArr(arr);
    findAllSubarrsWithGivenSum(arr, 6);
    cout << "-----------------------------------" << endl;
    printArr(arr);
    findAllSubarrsWithGivenSum2(arr, 6);
    cout << "-----------------------------------" << endl;
    printArr(arr);
    findAllSubarrsWithGivenSum2(arr, 6);
    cout << "-----------------------------------" << endl;

    return 0;
}
