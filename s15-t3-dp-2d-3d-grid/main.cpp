#include <iostream>
using namespace std;

const int NEG = -1e9;

int helperNinjaTraining(int idx, int prev, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (idx == n)
        return 0;
    if (prev != -1 && dp[idx][prev] != -1)
        return dp[idx][prev];
    int ans = INT_MIN;
    for (int i = 0; i < 3; i++)
    {
        if (i != prev)
        {
            int nextBest = helperNinjaTraining(idx + 1, i, n, matrix, dp);
            ans = max(ans, matrix[idx][i] + nextBest);
        }
    }
    if (prev != -1)
        dp[idx][prev] = ans;
    return ans;
}

int ninjaTraining(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(3, -1));
    return helperNinjaTraining(0, -1, n, matrix, dp);
}

int ninjaTraining2(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(3, -1));
    dp[0][0] = max(matrix[0][1], matrix[0][2]);
    dp[0][1] = max(matrix[0][0], matrix[0][2]);
    dp[0][2] = max(matrix[0][0], matrix[0][1]);

    for (int day = 1; day < n; day++)
    {
        dp[day][0] = max(matrix[day][1] + dp[day - 1][1], matrix[day][2] + dp[day - 1][2]);
        dp[day][1] = max(matrix[day][0] + dp[day - 1][0], matrix[day][2] + dp[day - 1][2]);
        dp[day][2] = max(matrix[day][0] + dp[day - 1][0], matrix[day][1] + dp[day - 1][1]);
        // for (int last = 0; last < 3; last++)
        // {
        //     int maxi = -1;
        //     for (int task = 0; task < 3; task++)
        //     {
        //         if (last != task){
        //             maxi = max(maxi, matrix[day][task] + dp[day - 1][task]);
        //         }
        //     }
        //     dp[day][last] = maxi;
        // }
    }
    int ans = INT_MIN;
    for (int &a : dp[n - 1])
        ans = max(ans, a);
    return ans;
}
int ninjaTraining3(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<int> dp(3, -1);
    dp[0] = max(matrix[0][1], matrix[0][2]);
    dp[1] = max(matrix[0][0], matrix[0][2]);
    dp[2] = max(matrix[0][0], matrix[0][1]);
    for (int day = 1; day < n; day++)
    {
        vector<int> temp(3);
        temp[0] = max(matrix[day][1] + dp[1], matrix[day][2] + dp[2]);
        temp[1] = max(matrix[day][0] + dp[0], matrix[day][2] + dp[2]);
        temp[2] = max(matrix[day][0] + dp[0], matrix[day][1] + dp[1]);
        dp = temp;
    }
    int ans = INT_MIN;
    for (int &a : dp)
        ans = max(ans, a);
    return ans;
}

int helperUniquePaths(vector<vector<int>> &dp, int m, int n, int i, int j)
{
    if (i == m - 1 && j == n - 1)
        return 1;
    if (i == m || j == n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = helperUniquePaths(dp, m, n, i + 1, j) + helperUniquePaths(dp, m, n, i, j + 1);
}
// Memoization
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helperUniquePaths(dp, m, n, 0, 0);
}

// Tabulation
int uniquePaths2(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                continue;
            dp[i][j] = ((i > 0) ? dp[i - 1][j] : 0) + ((j > 0) ? dp[i][j - 1] : 0);
        }
    }
    return dp[m - 1][n - 1];
}

// Tabulation - Space Optimised
int uniquePaths3(int m, int n)
{
    vector<int> prevRow(n, 0);
    prevRow[0] = 1;
    for (int i = 0; i < m; i++)
    {
        vector<int> row(n);
        for (int j = 0; j < n; j++)
        {
            row[j] = (j > 0 ? row[j - 1] : 0) + prevRow[j];
        }
        prevRow = row;
    }
    return prevRow[n - 1];
}
// Tabulation - Space Optimised
int uniquePaths4(int m, int n)
{
    vector<int> row(n, 1);
    for (int i = 1; i < m; i++)
    {
        for (int j = 01; j < n; j++)
        {
            row[j] += row[j - 1];
        }
    }
    return row[n - 1];
}

int helperUniquePathsWithObstacles(int i, int j, vector<vector<int>> &obstacleGrid,
                                   vector<vector<int>> &dp, int m, int n)
{
    if (i == m - 1 && j == n - 1 && obstacleGrid[i][j] == 0)
        return 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    if (i + 1 < m && obstacleGrid[i + 1][j] == 0)
        ans += helperUniquePathsWithObstacles(i + 1, j, obstacleGrid, dp, m, n);
    if (j + 1 < n && obstacleGrid[i][j + 1] == 0)
        ans += helperUniquePathsWithObstacles(i, j + 1, obstacleGrid, dp, m, n);
    return dp[i][j] = ans;
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int n = obstacleGrid[0].size(), m = obstacleGrid.size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    if (obstacleGrid[0][0] == 1)
        return 0;
    return helperUniquePathsWithObstacles(0, 0, obstacleGrid, dp, m, n);
}

int uniquePathsWithObstacles2(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1)
        return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1 || (i == 0 && j == 0))
                continue;
            int up = (i > 0 && obstacleGrid[i - 1][j] == 0) ? dp[i - 1][j] : 0;
            int left = (j > 0 && obstacleGrid[i][j - 1] == 0) ? dp[i][j - 1] : 0;
            dp[i][j] = up + left;
        }
    }
    return dp[m - 1][n - 1];
}
int uniquePathsWithObstacles3(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1)
        return 0;
    vector<int> prevRow(n, 0);
    prevRow[0] = 1;
    int prev;
    for (int i = 0; i < m; i++)
    {
        prev = 0;
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
            {
                prev = 0;
                prevRow[j] = 0;
                continue;
            }
            prevRow[j] = prevRow[j] + prev;
            prev = prevRow[j];
        }
    }
    return prev;
}

int helperMinimumTotal(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp, int n)
{
    if (i == n - 1)
        return triangle[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int same = helperMinimumTotal(i + 1, j, triangle, dp, n);
    int next = helperMinimumTotal(i + 1, j + 1, triangle, dp, n);
    return dp[i][j] = triangle[i][j] + min(same, next);
}

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return helperMinimumTotal(0, 0, triangle, dp, n);
}

int minimumTotal2(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int same = (j < i) ? dp[i - 1][j] : 1e9;
            int next = (j - 1 >= 0) ? dp[i - 1][j - 1] : 1e9;
            dp[i][j] = triangle[i][j] + min(same, next);
        }
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[n - 1][i]);
    return ans;
}

int minimumTotal3(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> prevRow(n, -1);
    prevRow[0] = triangle[0][0];
    for (int i = 1; i < n; i++)
    {
        vector<int> temp(n, -1);
        for (int j = 0; j <= i; j++)
        {
            int same = (j < i) ? prevRow[j] : 1e9;
            int prev = (j - 1 >= 0) ? prevRow[j - 1] : 1e9;
            temp[j] = triangle[i][j] + min(same, prev);
        }
        prevRow = temp;
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++)
        ans = min(ans, prevRow[i]);
    return ans;
}

int helperMinPathSum(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int n, int m)
{
    if (i == n - 1 && j == m - 1)
        return grid[i][j];
    if (i == n || j == m)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    int ans = 0;
    ans = grid[i][j] + min(helperMinPathSum(i + 1, j, grid, dp, n, m), helperMinPathSum(i, j + 1, grid, dp, n, m));
    return dp[i][j] = ans;
}
int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helperMinPathSum(0, 0, grid, dp, n, m);
}

int minPathSum2(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int up = (i > 0) ? dp[i - 1][j] : 1e9;
            int left = (j > 0) ? dp[i][j - 1] : 1e9;
            dp[i][j] = grid[i][j] + ((min(up, left) == 1e9) ? 0 : min(up, left));
        }
    }
    return dp[n - 1][m - 1];
}
int minPathSum3(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    vector<int> prevRow(m, 1e9);
    int prev;
    for (int i = 0; i < n; i++)
    {
        prev = 1e9;
        for (int j = 0; j < m; j++)
        {
            prevRow[j] = grid[i][j] + ((min(prevRow[j], prev) == 1e9) ? 0 : min(prevRow[j], prev));
            prev = prevRow[j];
        }
    }
    return prev;
}

int helperMaxChocolates(int i, int j1, int j2, vector<vector<int>> &g, int n, int m, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return NEG;

    if (i == n - 1)
        return (j1 == j2) ? g[i][j1] : g[i][j1] + g[i][j2];

    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];

    int curr = (j1 == j2) ? g[i][j1] : g[i][j1] + g[i][j2];

    int maxVal = NEG;
    for (int dj1 = -1; dj1 <= 1; dj1++)
        for (int dj2 = -1; dj2 <= 1; dj2++)
            maxVal = max(maxVal, curr + helperMaxChocolates(i + 1, j1 + dj1, j2 + dj2, g, n, m, dp));

    return dp[i][j1][j2] = maxVal;
}

int maxChocolates(vector<vector<int>> &g)
{
    int n = g.size(), m = g[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return helperMaxChocolates(0, 0, m - 1, g, n, m, dp);
}

int maxChocolates2(vector<vector<int>> &g)
{
    int n = g.size(), m = g[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
    for (int j1 = 0; j1 < m; j1++)
        for (int j2 = 0; j2 < m; j2++)
            dp[n - 1][j1][j2] = (j1 == j2) ? g[n - 1][j1] : g[n - 1][j1] + g[n - 1][j2];

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int curr = (j1 == j2) ? g[i][j1] : g[i][j1] + g[i][j2];

                int maxVal = NEG;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            maxVal = max(maxVal, curr + dp[i + 1][j1 + dj1][j2 + dj2]);

                dp[i][j1][j2] = maxVal;
            }
        }
    }
    return dp[0][0][m - 1];
}
int maxChocolates3(vector<vector<int>> &g)
{
    int n = g.size(), m = g[0].size();
    vector<vector<int>> dp(m, vector<int>(m, 0));
    // Base case - last row
    for (int j1 = 0; j1 < m; j1++)
        for (int j2 = 0; j2 < m; j2++)
            dp[j1][j2] = (j1 == j2) ? g[n - 1][j1] : g[n - 1][j1] + g[n - 1][j2];

    for (int i = n - 2; i >= 0; i--)
    {
        vector<vector<int>> temp(m, vector<int>(m, 0));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int curr = (j1 == j2) ? g[i][j1] : g[i][j1] + g[i][j2];

                int maxVal = NEG;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            maxVal = max(maxVal, curr + dp[j1 + dj1][j2 + dj2]);

                temp[j1][j2] = maxVal;
            }
        }
        dp = temp;
    }

    return dp[0][m - 1];
}

int main()
{
    int m, n;
    cin >> n;
    vector<vector<int>> work(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> work[i][0] >> work[i][1] >> work[i][2];
    cout << ninjaTraining(work) << endl;
    cout << "------------------" << endl;
    cout << ninjaTraining2(work) << endl;
    cout << "------------------" << endl;
    cout << ninjaTraining3(work) << endl;
    cout << "------------------" << endl;
    cin >> m >> n;
    cout << uniquePaths(m, n) << endl;
    cout << "------------------" << endl;
    cout << uniquePaths2(m, n) << endl;
    cout << "------------------" << endl;
    cout << uniquePaths3(m, n) << endl;
    cout << "------------------" << endl;
    cout << uniquePaths4(m, n) << endl;
    cout << "------------------" << endl;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (auto &it : grid)
        for (int &a : it)
            cin >> a;
    cout << uniquePathsWithObstacles(grid) << endl;
    cout << "------------------" << endl;
    cout << uniquePathsWithObstacles2(grid) << endl;
    cout << "------------------" << endl;
    cout << uniquePathsWithObstacles3(grid) << endl;
    cout << "------------------" << endl;

    cin >> n;
    vector<vector<int>> triangle(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> triangle[i][j];
    cout << minimumTotal(triangle) << endl;
    cout << "------------------" << endl;
    cout << minimumTotal2(triangle) << endl;
    cout << "------------------" << endl;
    cout << minimumTotal3(triangle) << endl;
    cout << "------------------" << endl;

    cin >> m >> n;
    vector<vector<int>> arr(m, vector<int>(n));
    for (auto &it : arr)
        for (int &a : it)
            cin >> a;
    cout << minPathSum(arr) << endl;
    cout << "------------------" << endl;
    cout << minPathSum2(arr) << endl;
    cout << "------------------" << endl;
    cout << minPathSum3(arr) << endl;
    cout << "------------------" << endl;

    cin >> m >> n;
    vector<vector<int>> g(m, vector<int>(n));
    for (auto &it : g)
        for (int &a : it)
            cin >> a;
    cout << maxChocolates(g) << endl;
    cout << "------------------" << endl;
    cout << maxChocolates2(g) << endl;
    cout << "------------------" << endl;
    cout << maxChocolates3(g) << endl;
    cout << "------------------" << endl;

    return 0;
}