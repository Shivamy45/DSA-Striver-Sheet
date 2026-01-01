#include <iostream>
using namespace std;

void helperPartition(string s, vector<vector<string>> &res, vector<string> &temp, int idx, vector<vector<bool>> &isPP)
{
    if (idx == s.length())
    {
        res.push_back(temp);
        return;
    }
    for (int i = idx; i < s.length(); i++)
    {
        if (isPP[idx][i])
        {
            temp.push_back(s.substr(idx, i - idx + 1));
            helperPartition(s, res, temp, i + 1, isPP);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    int n = s.length();
    vector<vector<string>> res;
    vector<string> temp;
    // precompute palidrome
    vector<vector<bool>> isPP(n, vector<bool>(n, false));
    for (int i = n - 1; i >= 0; i--)
        for (int j = i; j < n; j++)
            isPP[i][j] = (s[i] == s[j] && (j - i < 2 || isPP[i + 1][j - 1]));
    helperPartition(s, res, temp, 0, isPP);
    return res;
}

bool helperExist(vector<vector<char>> &board, string &word, int i, int j, int k)
{
    if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0)
        return false;
    if (word[k] != board[i][j])
        return false;
    if (k == word.size() - 1)
        return true;
    char saved = board[i][j];
    board[i][j] = '#';
    bool found = helperExist(board, word, i + 1, j, k + 1) || helperExist(board, word, i, j + 1, k + 1) || helperExist(board, word, i - 1, j, k + 1) || helperExist(board, word, i, j - 1, k + 1);
    board[i][j] = saved;
    return found;
}

bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size(), m = board[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (helperExist(board, word, i, j, 0))
                return true;
    return false;
}

bool isSafe(vector<string> &board, int row, int col)
{
    int rowCopy = row, colCopy = col;
    // left
    while (colCopy >= 0)
    {
        if (board[row][colCopy] == 'Q')
            return false;
        colCopy--;
    }
    // upper diag
    colCopy = col;
    while (rowCopy >= 0 && colCopy >= 0)
    {
        if (board[rowCopy][colCopy] == 'Q')
            return false;
        rowCopy--;
        colCopy--;
    }
    // lower diag
    rowCopy = row;
    colCopy = col;
    while (rowCopy < board.size() && colCopy >= 0)
    {
        if (board[rowCopy][colCopy] == 'Q')
            return false;
        rowCopy++;
        colCopy--;
    }
    return true;
}

void helperSolveNQueens(vector<vector<string>> &res, vector<string> &board, int col, int n, vector<bool> &left, vector<bool> &lowerDiag, vector<bool> &upperDiag)
{
    if (col == n)
    {
        res.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (!(upperDiag[n - 1 + col - row] || lowerDiag[row + col] || left[row]))
        {
            left[row] = lowerDiag[row + col] = upperDiag[n - 1 + col - row] = true;
            board[row][col] = 'Q';
            helperSolveNQueens(res, board, col + 1, n, left, lowerDiag, upperDiag);
            board[row][col] = '.';
            upperDiag[n - 1 + col - row] = lowerDiag[row + col] = left[row] = false;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    vector<bool> left(n, false);
    vector<bool> lowerDiag(n * 2 + 1, false);
    vector<bool> upperDiag(n * 2 + 1, false);
    helperSolveNQueens(res, board, 0, n, left, lowerDiag, upperDiag);
    return res;
}

void helperRatInMaze(vector<vector<int>> &maze, vector<string> &res, string &path, int row, int col, int n, int m, vector<vector<bool>> &isvisited)
{
    if (row == n - 1 && col == m - 1)
    {
        res.push_back(path);
        return;
    }
    isvisited[row][col] = true;
    // down
    if (row + 1 < n && maze[row + 1][col] == 1 && !isvisited[row + 1][col])
    {
        path.push_back('D');
        helperRatInMaze(maze, res, path, row + 1, col, n, m, isvisited);
        path.pop_back();
    }
    // left
    if (col - 1 >= 0 && maze[row][col - 1] == 1 && !isvisited[row][col - 1])
    {
        path.push_back('L');
        helperRatInMaze(maze, res, path, row, col - 1, n, m, isvisited);
        path.pop_back();
    }
    // right
    if (col + 1 < m && maze[row][col + 1] == 1 && !isvisited[row][col + 1])
    {
        path.push_back('R');
        helperRatInMaze(maze, res, path, row, col + 1, n, m, isvisited);
        path.pop_back();
    }
    // up
    if (row - 1 >= 0 && maze[row - 1][col] == 1 && !isvisited[row - 1][col])
    {
        path.push_back('U');
        helperRatInMaze(maze, res, path, row - 1, col, n, m, isvisited);
        path.pop_back();
    }
    isvisited[row][col] = false;
}

vector<string> ratInMaze(vector<vector<int>> &maze)
{
    int n = maze.size(), m = maze[0].size();
    vector<string> res;
    string path;
    vector<vector<bool>> isvisited(n, vector<bool>(n, false));
    if (maze[0][0] == 1)
        helperRatInMaze(maze, res, path, 0, 0, n, m, isvisited);
    return res;
}

// void helperWordBreak(string &temp, string &s, vector<string> &wordDict, int i, int n)
// {
//     if(i == n)
//         return;
//     temp += s[i];
//     auto it = find(wordDict.begin(), wordDict.end(), temp);
//     if(it != wordDict.end()){
//         temp = "";
//         helperWordBreak(temp, s, wordDict, i + 1, n);
//     }
//     else
//     {
//         helperWordBreak(temp, s, wordDict, i + 1, n);
//     }
// }

// bool wordBreak(string s, vector<string> &wordDict)
// {
//     int n = s.length();
//     string temp;
//     helperWordBreak(temp, s, wordDict, 0, n);
//     if(temp == "")
//         return true;
//     return false;
// }

bool isPossible(int n, vector<vector<int>> &graph, vector<int> &colored, int node)
{
    for (int i = 0; i < n; i++)
        if (i != node && graph[node][i] && colored[i] == colored[node])
            return false;
    return true;
}

bool helperPossibleMColoring(int n, int m, vector<vector<int>> &graph, vector<int> &colored, int node)
{
    if (node == n)
        return true;

    for (int i = 1; i <= m; i++)
    {
        colored[node] = i;
        if (isPossible(n, graph, colored, node))
            if (helperPossibleMColoring(n, m, graph, colored, node + 1))
                return true;
        colored[node] = 0;
    }
    return false;
}

bool possibleMColoring(int n, int m, int e, vector<pair<int, int>> &edges)
{
    vector<int> colored(n, 0);
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < e; i++)
    {
        graph[edges[i].first][edges[i].second] = 1;
        graph[edges[i].second][edges[i].first] = 1;
    }
    return helperPossibleMColoring(n, m, graph, colored, 0);
}

bool isPossible2(vector<vector<char>> &board, int x, int y, char c)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][y] == c)
            return false;
        if (board[x][i] == c)
            return false;
        if (board[3 * (x / 3) + i / 3][3 * (y / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool helperSolveSodoku(vector<vector<char>> &board, int row, int col)
{
    if (row == 9)
        return true;
    else if (col == 9)
        return helperSolveSodoku(board, row + 1, 0);
    else if (board[row][col] != '.')
        return helperSolveSodoku(board, row, col + 1);

    for (char c = '1'; c <= '9'; c++)
    {
        if (isPossible2(board, row, col, c))
        {
            board[row][col] = c;
            if (helperSolveSodoku(board, row, col + 1))
                return true;
            board[row][col] = '.';
        }
    }

    return false;
}

void solveSudoku(vector<vector<char>> &board)
{
    helperSolveSodoku(board, 0, 0);
}

// int solveExpression(string &exp)
// {
//     int ans = exp[0] - '0', i = 1;
//     while (i < exp.length())
//     {
//         if (exp[i] == '*')
//             ans *= exp[i+ 1] - '0';
//         else if (exp[i] == '+')
//             ans += exp[i+ 1] - '0';
//         else if (exp[i] == '-')
//             ans -= exp[i+ 1] - '0';
//         i += 2;
//     }
//     return ans;
// }

// void helperAddOperators(vector<string> &res, string &temp, string &num, int target, int i)
// {
//     temp.push_back(num[i]);
//     if (i >= num.length() - 1)
//     {
//         if (solveExpression(temp) == target)
//         {
//             res.push_back(temp);
//         }
//         temp.pop_back();
//         return;
//     }
//     temp.push_back('*');
//     helperAddOperators(res, temp, num, target, i + 1);
//     temp.pop_back();
//     temp.push_back('+');
//     helperAddOperators(res, temp, num, target, i + 1);
//     temp.pop_back();
//     temp.push_back('-');
//     helperAddOperators(res, temp, num, target, i + 1);
//     temp.pop_back();
//     temp.pop_back();
// }

// vector<string> addOperators(string num, int target)
// {
//     vector<string> res;
//     string temp;
//     helperAddOperators(res, temp, num, target, 0);
//     return res;
// }

int main()
{
    string s;
    getline(cin, s);
    vector<vector<string>> res = partition(s);
    for (auto &it : res)
    {
        for (string &a : it)
            cout << a << " ";
        cout << endl;
    }
    cout << "--------------------------" << endl;

    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (auto &it : board)
        for (char &c : it)
            cin >> c;
    string word;
    cin >> word;
    cout << exist(board, word) << endl;
    cout << "--------------------------" << endl;

    cin >> n;
    res = solveNQueens(n);
    for (auto &it : res)
    {
        for (string &a : it)
            cout << a << ", ";
        cout << endl;
    }
    cout << "--------------------------" << endl;

    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n));
    for (auto &it : maze)
        for (int &a : it)
            cin >> a;
    vector<string> ans = ratInMaze(maze);
    for (string &a : ans)
        cout << a << endl;
    cout << "--------------------------" << endl;

    // cin.ignore();
    // getline(cin, s);
    // cin >> n;
    // cin.ignore();
    // vector<string> wordDict(n);
    // for (string &a : wordDict)
    //     getline(cin, a);
    // cout << wordBreak(s, wordDict) << endl;
    // cout << "--------------------------" << endl;

    int e;
    cin >> n >> m >> e;
    vector<pair<int, int>> edges(e);
    for (auto &it : edges)
        cin >> it.first >> it.second;
    cout << possibleMColoring(n, m, e, edges) << endl;
    cout << "--------------------------" << endl;

    vector<vector<char>> sudoku(9, vector<char>(9));
    for (auto &it : sudoku)
        for (char &c : it)
            cin >> c;
    solveSudoku(sudoku);
    for (auto &it : sudoku)
    {
        for (char &c : it)
            cout << c;
        cout << endl;
    }
    cout << "--------------------------" << endl;

    // cin.ignore();
    // string num;
    // getline(cin, num);
    // int target;
    // cin >> target;
    // string g = "2*3*2";
    // ans = addOperators(num, target);
    // for (string &s : ans)
    //     cout << s << endl;
    // cout << "--------------------------" << endl;

    return 0;
}