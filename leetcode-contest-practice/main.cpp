#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <queue>
using namespace std;

int helper(vector<vector<pair<int, int>>> &g, int node, int n, vector<bool> &isvisited)
{
    if (node == n - 1)
        return 0;
    int minCost = INT_MAX;
    for (auto &x : g[node])
    {
        if (!isvisited[x.first])
        {
            isvisited[x.first] = true;
            if (helper(g, x.first, n, isvisited) != -1)
                minCost = min(minCost, x.second + helper(g, x.first, n, isvisited));
            isvisited[x.first] = false;
        }
    }
    return (minCost == INT_MAX) ? -1 : minCost;
}

int minCost(int n, vector<vector<int>> &edges)
{
    vector<vector<pair<int, int>>> g(n);
    for (auto &it : edges)
    {
        g[it[0]].push_back(make_pair(it[1], it[2]));
        g[it[1]].push_back(make_pair(it[0], it[2] * 2));
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ":" << endl;
        for (auto &x : g[i])
        {
            cout << x.first << ", " << x.second << endl;
        }
    }
    vector<bool> isvisited(n, false);
    isvisited[0] = true;
    return helper(g, 0, n, isvisited);
}

int main()
{
    vector<vector<int>> edges = {{2, 0, 12}, {1, 0, 5}, {0, 1, 15}};
    int n = 3;
    cout << minCost(n, edges);
    return 0;
}