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
    {
        mat[it.first].push_back(it.second);
    }
    return mat;
}

void dfs(vector<vector<int>> &mat, vector<bool> &vis, int node)
{
    for (int a : mat[node])
    {
        if (!vis[a])
        {
            vis[a] = true;
            dfs(mat, vis, a);
        }
    }
}

int connectedComponents(vector<pair<int, int>> &arr, int n, int e)
{
    vector<vector<int>> mat = adjacencyList(arr, n, e);
    vector<bool> visited(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(mat, visited, i); // can implement BFS also
            ans++;
        }
    }
    return ans;
}

void helperDfsVector(int node, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &res)
{
    vis[node] = true;
    res.push_back(node);

    for (int nei : adj[node])
        if (!vis[nei])
            helperDfsVector(nei, adj, vis, res);
}

// Works for disconnected graph too
vector<int> dfsVector(vector<pair<int, int>> &arr, int n, int e)
{
    vector<vector<int>> adj = adjacencyList(arr, n, e);
    vector<int> res;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
        if (!vis[i])
            helperDfsVector(i, adj, vis, res);
    return res;
}



int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> arr(e);
    for (auto &it : arr)
        cin >> it.first >> it.second;
    vector<vector<int>> mat = adjacencyMatrix(arr, n, e);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j] == 1)
                cout << i << "->" << j << endl;
    cout << "--------------" << endl;

    mat = adjacencyList(arr, n, e);
    for (int i = 0; i < n; i++)
    {
        cout << i << ": {";
        for (int a : mat[i])
            cout << a << ",";
        cout << "}" << endl;
    }
    cout << "--------------" << endl;

    cin >> n >> e;
    arr.resize(e);
    for (auto &it : arr)
        cin >> it.first >> it.second;
    cout << connectedComponents(arr, n, e) << endl;
    cout << "--------------" << endl;

    cin >> n >> e;
    arr.resize(e);
    for (auto &it : arr)
        cin >> it.first >> it.second;
    vector<int> res = dfsVector(arr, n, e);
    for (int a : res)
        cout << a << " ";
    cout << endl;
    cout << "--------------" << endl;

    return 0;
}