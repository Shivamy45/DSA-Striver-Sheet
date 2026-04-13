#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {};
};

TreeNode *createTree(vector<string> &arr)
{
    if (arr.size() < 1 || arr[0] == "null")
        return nullptr;
    TreeNode *root = new TreeNode(stoi(arr[0]));
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (arr[i] != "null")
        {
            curr->left = new TreeNode(stoi(arr[i]));
            q.push(curr->left);
        }
        i++;
        if (i < arr.size() && arr[i] != "null")
        {
            curr->right = new TreeNode(stoi(arr[i]));
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

int maxDepth(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + max(left, right);
}

int helperIsBalanced(TreeNode *root)
{
    if (!root)
        return 0;
    int leftH = helperIsBalanced(root->left);
    if (leftH == -1)
        return -1;
    int rightH = helperIsBalanced(root->right);
    if (rightH == -1)
        return -1;
    if (abs(leftH - rightH) > 1)
        return -1;
    return 1 + max(leftH, rightH);
}
bool isBalanced(TreeNode *root)
{
    return helperIsBalanced(root) != -1;
}

int helperDiameterOfBinaryTree(TreeNode *root, int &diameter)
{
    if (root == nullptr)
        return 0;
    int left = helperDiameterOfBinaryTree(root->left, diameter);
    int right = helperDiameterOfBinaryTree(root->right, diameter);
    diameter = max(diameter, left + right);
    return 1 + max(left, right);
}
int diameterOfBinaryTree(TreeNode *root)
{
    if (!root)
        return 0;
    int diameter = 0;
    helperDiameterOfBinaryTree(root, diameter);
    return diameter;
}

int helperMaxPathSum(TreeNode *root, int &maxSum)
{
    if (!root)
        return 0;
    int left = max(0, helperMaxPathSum(root->left, maxSum));
    int right = max(0, helperMaxPathSum(root->right, maxSum));
    int maxNow = root->val + left + right;
    maxSum = max(maxSum, maxNow);
    return root->val + max(left, right);
}
int maxPathSum(TreeNode *root)
{
    int maxSum = INT_MIN;
    helperMaxPathSum(root, maxSum);
    return maxSum;
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (!p || !q)
        return p == q;
    if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

void helperZigzagLevelOrder(TreeNode *root, int lvl, vector<vector<int>> &res)
{
    if (res.size() >= lvl)
    {
        res[lvl].push_back(root->val);
    }
    else
    {
        res.push_back({root->val});
    }
    if(lvl % 2 == 0){

    }
}
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    helperZigzagLevelOrder(root, 1, res);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (string &a : arr)
        cin >> a;
    TreeNode *root = createTree(arr);
    cout << isBalanced(root) << endl;
    cout << "-------------------" << endl;
    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = createTree(arr);
    cout << diameterOfBinaryTree(root) << endl;
    cout << "-------------------" << endl;
    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = createTree(arr);
    cout << maxPathSum(root) << endl;
    cout << "-------------------" << endl;
    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = createTree(arr);
    int m;
    cin >> m;
    vector<string> arr2(m);
    for (string &a : arr2)
        cin >> a;
    TreeNode *root2 = createTree(arr2);
    cout << isSameTree(root, root2) << endl;
    cout << "-------------------" << endl;
    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = createTree(arr);
    vector<vector<int>> ans = zigzagLevelOrder(root);
    for (auto it : ans)
    {
        for (int a : it)
            cout << a << " ";
        cout << endl;
    }
    cout << "-------------------" << endl;

    return 0;
}