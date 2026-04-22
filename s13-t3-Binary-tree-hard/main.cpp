#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {};
};

void bfs(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *temp = q.front();
            cout << temp->val << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            q.pop();
        }
        cout << endl;
    }
}

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

bool helperRootToNode(TreeNode *root, int val, vector<int> &res)
{
    if (!root)
        return false;
    res.push_back(root->val);
    if (root->val == val)
        return true;
    if (helperRootToNode(root->left, val, res) || helperRootToNode(root->right, val, res))
        return true;
    res.pop_back();
    return false;
}

vector<int> rootToNode(TreeNode *root, int val)
{
    vector<int> res;
    helperRootToNode(root, val, res);
    return res;
}

bool helperHelperLowestCommonAncestor(TreeNode *root, TreeNode *x, vector<TreeNode *> &res)
{
    if (!root)
        return false;
    res.push_back(root);
    if (root->val == x->val)
        return true;
    if (helperHelperLowestCommonAncestor(root->left, x, res) || helperHelperLowestCommonAncestor(root->right, x, res))
        return true;
    res.pop_back();
    return false;
}

vector<TreeNode *> helperLowestCommonAncestor(TreeNode *root, TreeNode *val)
{
    vector<TreeNode *> res;
    helperHelperLowestCommonAncestor(root, val, res);
    return res;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    vector<TreeNode *> pPath = helperLowestCommonAncestor(root, p);
    unordered_map<TreeNode *, int> mpp;
    for (auto it : pPath)
    {
        mpp[it] = 1;
    }
    vector<TreeNode *> qPath = helperLowestCommonAncestor(root, q);
    TreeNode *res = nullptr;
    for (auto it : qPath)
    {
        if (mpp.find(it) != mpp.end())
            res = it;
    }
    return res;
}

TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return nullptr;
    if (root == p || root == q)
        return root;
    TreeNode *left = lowestCommonAncestor2(root->left, p, q);
    TreeNode *right = lowestCommonAncestor2(root->right, p, q);
    if (left == nullptr && right == nullptr)
        return nullptr;
    else if (left == nullptr)
        return right;
    else if (right == nullptr)
        return left;
    return root;
}

int widthOfBinaryTree(TreeNode *root)
{
    int ans = 0;
    if (!root)
        return ans;
    queue<pair<TreeNode *, long long>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        long long front = q.front().second, back = q.back().second;
        ans = max(ans, (int)(back - front + 1));
        for (int i = 0; i < size; i++)
        {
            auto [node, idx] = q.front();
            idx -= front;
            q.pop();
            if (node->left)
                q.push({node->left, idx * 2 + 1});
            if (node->right)
                q.push({node->right, idx * 2 + 2});
        }
    }
    return ans;
}

// on GFG
bool isSumProperty(TreeNode *root)
{
    if (!root || (!root->left && !root->right))
        return true;
    int left = (root->left) ? root->left->val : 0;
    int right = (root->right) ? root->right->val : 0;
    return root->val == left + right && isSumProperty(root->left) && isSumProperty(root->right);
}

void changeToSumProperty(TreeNode *root)
{
    if (!root->left && !root->right)
        return;
    int child = 0;
    if (root->left)
        child += root->left->val;
    if (root->right)
        child += root->right->val;
    if (child >= root->val)
    {
        root->val = child;
    }
    else
    {
        if (root->left)
            root->left->val = root->val;
        else if (root->right)
            root->right->val = root->val;
    }
    changeToSumProperty(root->left);
    changeToSumProperty(root->right);
    int tot = 0;
    if (root->left)
        tot += root->left->val;
    if (root->right)
        tot += root->right->val;
    root->val = tot;
}

void helperDistanceK(unordered_map<TreeNode *, TreeNode *> &mpp, TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node->left)
        {
            mpp[node->left] = node;
            q.push(node->left);
        }
        if (node->right)
        {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
}

vector<int> helperDistanceK2(TreeNode *target, int k, unordered_map<TreeNode *, TreeNode *> &parentMap)
{
    unordered_set<TreeNode *> vis;
    queue<TreeNode *> q;
    TreeNode *curr = target;
    vis.insert(curr);
    q.push(curr);
    int lvl = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (lvl++ == k)
            break;
        for (int i = 0; i < size; i++)
        {
            curr = q.front();
            q.pop();
            if (curr->left && vis.find(curr->left) == vis.end())
            {
                vis.insert(curr->left);
                q.push(curr->left);
            }
            if (curr->right && vis.find(curr->right) == vis.end())
            {
                vis.insert(curr->right);
                q.push(curr->right);
            }
            if (parentMap.count(curr) && vis.find(parentMap[curr]) == vis.end())
            {
                vis.insert(parentMap[curr]);
                q.push(parentMap[curr]);
            }
        }
    }
    vector<int> res;
    while (!q.empty())
    {
        res.push_back(q.front()->val);
        q.pop();
    }

    return res;
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> parentMap;
    // update parent map
    helperDistanceK(parentMap, root);

    return helperDistanceK2(target, k, parentMap);
}

int timeToBurnBT(TreeNode *root, TreeNode *target)
{
    unordered_map<TreeNode *, TreeNode *> parentMap;
    helperDistanceK(parentMap, root);

    queue<TreeNode *> q;
    unordered_set<TreeNode *> vis;
    int time = 0;
    q.push(target);
    vis.insert(target);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left && vis.find(curr->left) == vis.end())
            {
                q.push(curr->left);
                vis.insert(curr->left);
            }
            if (curr->right && vis.find(curr->right) == vis.end())
            {
                q.push(curr->right);
                vis.insert(curr->right);
            }
            if (parentMap.count(curr) && vis.find(parentMap[curr]) == vis.end())
            {
                q.push(parentMap[curr]);
                vis.insert(parentMap[curr]);
            }
        }
        if (!q.empty())
            time++;
    }
    return time;
}

int helperCountNode(TreeNode *root, bool left)
{
    int h = 0;
    while (root)
    {
        h++;
        root = (left) ? root->left : root->right;
    }
    return h;
}

int countNodes(TreeNode *root)
{
    if (!root)
        return 0;
    int leftH = helperCountNode(root, true);
    int rightH = helperCountNode(root, false);
    if (leftH == rightH)
        return (1 << leftH) + 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}



int main()
{
    int n;
    cin >> n;
    vector<string> arr(n);
    for (string &a : arr)
        cin >> a;
    TreeNode *root = createTree(arr);
    vector<int> res = rootToNode(root, 6);
    for (int a : res)
        cout << a << " ";
    cout << endl;
    cout << "-----------------" << endl;

    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = createTree(arr);
    TreeNode *p = root->left, *q = root->left->right;
    TreeNode *ans = lowestCommonAncestor(root, p, q);
    cout << ans->val << endl;
    cout << "-----------------" << endl;
    ans = lowestCommonAncestor2(root, p, q);
    cout << ans->val << endl;
    cout << "-----------------" << endl;

    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = createTree(arr);
    cout << widthOfBinaryTree(root) << endl;
    cout << "-----------------" << endl;

    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = createTree(arr);
    cout << isSumProperty(root) << endl;
    cout << "-----------------" << endl;

    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = createTree(arr);
    changeToSumProperty(root);
    bfs(root);
    cout << "-----------------" << endl;

    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = createTree(arr);
    int k;
    cin >> k;
    TreeNode *tar = root->left;
    res = distanceK(root, tar, k);
    for (int a : res)
        cout << a << " ";
    cout << endl;
    cout << "-----------------" << endl;

    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = createTree(arr);
    TreeNode *target = root;
    cout << timeToBurnBT(root, target) << endl;
    cout << "-----------------" << endl;
    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = createTree(arr);
    cout << countNodes(root) << endl;
    cout << "-----------------" << endl;

    return 0;
}