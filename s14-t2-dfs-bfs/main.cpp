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

int findCircleNum(vector<vector<int>> &isConnected)
{
    
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (auto &it : graph)
        for (int &a : it)
            cin >> a;
    cout << findCircleNum(graph);
    cout << "----------------" << endl;

    return 0;
}