#include <iostream>
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

class Solution
{
public:
    int MOD = 1e9 + 7;
    int totalSum(TreeNode *root)
    {
        if (!root)
            return 0;
        return root->val + totalSum(root->left) + totalSum(root->right);
    }
    
    int maxProduct(TreeNode *root)
    {
        
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    root->right->left = new TreeNode(-7);
    root->right->right = new TreeNode(9);
    cout << maxLevelSum(root);
    return 0;
}