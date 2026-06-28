#include <iostream>
using namespace std;

vector<vector<int>> adjacencyMatrix(vector<pair<int, int>> &arr, int n, int e)
{
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (auto it : arr)
        mat[it.first][it.second] = 1;
    return mat;
}

vector<vector<int>> adjacencyList(vector<pair<int, int>> &arr, int n, int e)
{
    vector<vector<int>> mat(n);
    for (auto it : arr)
        mat[it.first].push_back(it.second);
    return mat;
}

void bfs(vector<vector<int>> &mat, vector<bool> &vis, int idx)
{
    queue<int> q;
    q.push(idx);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < mat.size(); i++)
        {
            if (mat[node][i] == 1 && !vis[i])
            {
                q.push(i);
                vis[i] = true;
            }
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<bool> vis(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            bfs(isConnected, vis, i);
            ans++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (auto &it : graph)
        for (int &a : it)
            cin >> a;
    cout << findCircleNum(graph) << endl;
    cout << "----------------" << endl;

    return 0;
}