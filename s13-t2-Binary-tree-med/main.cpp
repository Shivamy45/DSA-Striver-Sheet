#include <iostream>
#include <map>
#include <set>
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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    queue<TreeNode *> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            int idx = (leftToRight) ? i : size - i - 1;
            temp[idx] = node->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        res.push_back(temp);
        leftToRight = !leftToRight;
    }
    return res;
}

bool isLeaf(TreeNode *root)
{
    return !root->left && !root->right;
}
void leftTraversal(TreeNode *root, vector<int> &res)
{
    TreeNode *curr = root->left;
    while (curr)
    {
        if (!(isLeaf(curr)))
            res.push_back(curr->val);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}
void leafTraversal(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    if (isLeaf(root))
        res.push_back(root->val);
    leafTraversal(root->left, res);
    leafTraversal(root->right, res);
}
void rightTraversal(TreeNode *root, vector<int> &res)
{
    if (!root)
        return;
    if (isLeaf(root))
        return;
    if (root->right)
        rightTraversal(root->right, res);
    else
        rightTraversal(root->left, res);
    res.push_back(root->val);
}

vector<int> boundaryTraversal(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    if (!isLeaf(root))
        res.push_back(root->val);
    leftTraversal(root, res);
    leafTraversal(root, res);
    rightTraversal(root->right, res);
    return res;
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> mpp;
    queue<tuple<TreeNode *, int, int>> q;
    // {node, {col, lvl}}
    q.push({root, 0, 0});
    while (!q.empty())
    {
        auto [node, col, lvl] = q.front();
        q.pop();
        mpp[col][lvl].insert(node->val);
        if (node->left)
            q.push({node->left, col - 1, lvl + 1});
        if (node->right)
            q.push({node->right, col + 1, lvl + 1});
    }
    vector<vector<int>> res;
    for (auto &col : mpp)
    {
        vector<int> temp;
        for (auto &lvl : col.second)
        {
            for (auto val : lvl.second)
            {
                temp.push_back(val);
            }
        }
        res.push_back(temp);
    }
    return res;
}

vector<int> topView(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    map<int, int> mpp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto [node, col] = q.front();
        q.pop();
        if (node->left)
            q.push({node->left, col - 1});
        if (node->right)
            q.push({node->right, col + 1});
        if (mpp.count(col) == 0)
            mpp[col] = node->val;
    }
    for (auto it : mpp)
        res.push_back(it.second);
    return res;
}

vector<int> bottomView(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    map<int, int> mpp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto [node, col] = q.front();
        q.pop();
        mpp[col] = node->val;
        if (node->left)
            q.push({node->left, col - 1});
        if (node->right)
            q.push({node->right, col + 1});
    }

    for (auto it : mpp)
        res.push_back(it.second);
    return res;
}

// on GFG
vector<int> leftView(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    map<int, int> mpp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto [node, y] = q.front();
        q.pop();
        if (mpp.find(y) == mpp.end())
            mpp[y] = node->val;
        if (node->left)
            q.push({node->left, y + 1});
        if (node->right)
            q.push({node->right, y + 1});
    }
    for (auto it : mpp)
        res.push_back(it.second);
    return res;
}

vector<int> rightSideView(TreeNode *root)
{
    vector<int> res;
    if (!root)
        return res;
    map<int, int> mpp;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto [node, y] = q.front();
        q.pop();
        mpp[y] = node->val;
        if (node->left)
            q.push({node->left, y + 1});
        if (node->right)
            q.push({node->right, y + 1});
    }
    for (auto it : mpp)
        res.push_back(it.second);
    return res;
}

bool helperIsSymmetric(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    if (p->val != q->val)
        return false;
    return helperIsSymmetric(p->left, q->right) && helperIsSymmetric(p->right, q->left);
}
bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    return helperIsSymmetric(root->left, root->right);
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

    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = createTree(arr);
    vector<int> ans2 = boundaryTraversal(root);
    for (int a : ans2)
        cout << a << " ";
    cout << endl;
    cout << "-------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = createTree(arr);
    ans = verticalTraversal(root);
    for (auto it : ans)
    {
        for (int a : it)
            cout << a << " ";
        cout << endl;
    }
    cout << "-------------------" << endl;
    
    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = createTree(arr);
    ans2 = topView(root);
    for (int a : ans2)
        cout << a << " ";
    cout << endl;
    cout << "-------------------" << endl;

    ans2 = bottomView(root);
    for (int a : ans2)
        cout << a << " ";
    cout << endl;
    cout << "-------------------" << endl;

    ans2 = leftView(root);
    for (int a : ans2)
        cout << a << " ";
    cout << endl;
    cout << "-------------------" << endl;

    ans2 = rightSideView(root);
    for (int a : ans2)
        cout << a << " ";
    cout << endl;
    cout << "-------------------" << endl;

    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = createTree(arr);
    cout << isSymmetric(root) << endl;
    cout << "-------------------" << endl;

    return 0;
}