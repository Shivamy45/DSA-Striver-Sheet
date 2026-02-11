#include <iostream>
#include <map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

void helper(vector<vector<int>> &res, TreeNode *root, int row, int col, int x)
{
    if (!root)
        return;
    helper(res, root->left, row + 1, col - 1, x);
    res[col + x].push_back(root->val);
    helper(res, root->right, row + 1, col + 1, x);
}
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    int lHeight = 0, rHeight = 0;
    TreeNode *temp = root;
    while (temp != nullptr)
    {
        temp = temp->left;
        lHeight++;
    }
    temp = root;
    while (temp != nullptr)
    {
        temp = temp->right;
        rHeight++;
    }
    vector<vector<int>> res(lHeight + rHeight);
    helper(res, root, 0, 0, lHeight);
    return res;
}

bool kConsPartitions(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n % k != 0)
        return false;
    map<int, int> mpp;
    for (int x : arr)
        mpp[x]++;
    while (!mpp.empty())
    {
        int x = mpp.begin()->first;
        for (int i = 0; i < k; i++)
        {
            int cur = x + i;
            if (!mpp.count(cur))
                return false;
            mpp[cur]--;
            if (mpp[cur] == 0)
                mpp.erase(cur);
        }
    }
    return true;
}

// vector<vector<int>> kConsPartitions2(vector<int> &arr, int k)
// {
//     int n = arr.size();
//     if (n % k != 0)
//         return {};
//     vector<vector<int>> res(n / k, vector<int>(k));
//     for (int i = 0; i < n; i++)
//     {
//         for(auto &it : res){
//             if()
//         }
//     }
// }

int main()
{
    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);

    vector<int> arr = {1, 2, 2, 3, 4, 5};
    int k = 3;
    cout << kConsPartitions(arr, k);
    return 0;
}

/*
n +ve element(INT)
{1, 2, 2, 3, 4, 5}
k = 3

*/