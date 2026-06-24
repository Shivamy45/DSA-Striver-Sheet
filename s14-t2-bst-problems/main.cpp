#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

TreeNode *buildBST(vector<string> &arr)
{
    if (arr.empty() || arr[0] == "null")
        return nullptr;

    TreeNode *root = new TreeNode(stoi(arr[0]));
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (i < arr.size() && arr[i] != "null")
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

void inorderTraversal(TreeNode *root)
{
    if (!root)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// floor in BST
int findMaxFork(TreeNode *root, int k)
{
    // code here
    int ans = -1;
    while (root)
    {
        if (root->val < k)
        {
            ans = root->val;
            root = root->right;
        }
        else if (root->val > k)
        {
            root = root->left;
        }
        else
        {
            return root->val;
        }
    }
    return ans;
}

int findCeil(TreeNode *root, int x)
{
    // code here
    int ans = -1;
    while (root)
    {
        if (root->val > x)
        {
            ans = root->val;
            root = root->left;
        }
        else if (root->val < x)
        {
            root = root->right;
        }
        else
        {
            ans = root->val;
            return ans;
        }
    }
    return ans;
}

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);
    if (root->val > val)
    {
        if (!root->left)
            root->left = new TreeNode(val);
        else
            insertIntoBST(root->left, val);
    }
    else
    {
        if (!root->right)
            root->right = new TreeNode(val);
        else
            insertIntoBST(root->right, val);
    }
    return root;
}

TreeNode *findSuccessor(TreeNode *root)
{
    TreeNode *temp = root->right;
    while (temp && temp->left)
        temp = temp->left;
    return temp;
}
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return root;
    if (root->val < key)
        root->right = deleteNode(root->right, key);
    else if (root->val > key)
        root->left = deleteNode(root->left, key);
    else
    {
        if (!root->right)
            return root->left;
        else if (!root->left)
            return root->right;
        else
        {
            TreeNode *succ = findSuccessor(root);
            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
    return root;
}

int helperKthSmallest(TreeNode *root, int k, int &i)
{
    if (!root)
        return -1;
    int ans = helperKthSmallest(root->left, k, i);
    if (ans != -1)
        return ans;
    if (i == k)
        return root->val;
    i++;
    ans = helperKthSmallest(root->right, k, i);
    return ans;
}

int kthSmallest(TreeNode *root, int k)
{
    int i = 1;
    return helperKthSmallest(root, k, i);
}

bool helperIsValidBST(TreeNode *root, long long lMax, long long rMax)
{
    if (!root)
        return true;
    if (root->val <= lMax || root->val >= rMax)
        return false;
    return helperIsValidBST(root->left, lMax, root->val) && helperIsValidBST(root->right, root->val, rMax);
}
bool isValidBST(TreeNode *root)
{
    return helperIsValidBST(root, LLONG_MIN, LLONG_MAX);
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root || !p || !q)
        return nullptr;
    if (max(p->val, q->val) < root->val)
        return lowestCommonAncestor(root->left, p, q);
    if (min(p->val, q->val) > root->val)
        return lowestCommonAncestor(root->right, p, q);
    return root;
}

TreeNode *helper(vector<int> &preorder, int &idx, int bound)
{
    if (idx == preorder.size() || preorder[idx] > bound)
        return nullptr;
    TreeNode *root = new TreeNode(preorder[idx++]);
    root->left = helper(preorder, idx, root->val);
    root->right = helper(preorder, idx, bound);
    return root;
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int idx = 0, n = preorder.size();
    return helper(preorder, idx, INT_MAX);
}

int inOrderSuccessor(TreeNode *root, int k)
{
    TreeNode *temp = root;
    int ans = -1;
    while (temp)
    {
        if (temp->val <= k)
            temp = temp->right;
        else if (temp->val > k)
        {
            ans = temp->val;
            temp = temp->left;
        }
    }
    return ans;
}

bool search(TreeNode *root, TreeNode *curr, int key)
{
    if (!root)
        return false;
    if (root->val == key && root != curr)
        return true;
    else if (root->val < key)
        return search(root->right, curr, key);
    else if (root->val > key)
        return search(root->left, curr, key);
    return false;
}
bool traverse(TreeNode *root, TreeNode *curr, int k)
{
    if (!curr)
        return false;
    int key = k - curr->val;
    if (search(root, curr, key))
        return true;
    return traverse(root, curr->left, k) || traverse(root, curr->right, k);
}
bool findTarget(TreeNode *root, int k)
{
    return traverse(root, root, k);
}

void inorder(TreeNode *root, TreeNode *&first, TreeNode *&second, TreeNode *&prev)
{
    if (!root)
        return;
    inorder(root->left, first, second, prev);
    if (prev && prev->val >= root->val)
    {
        if (!first)
            first = prev;
        second = root;
    }
    prev = root;
    inorder(root->right, first, second, prev);
}

void recoverTree(TreeNode *root)
{
    TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
    inorder(root, first, second, prev);
    swap(first->val, second->val);
}

int main()
{
    int n, k;
    cin >> n;
    vector<string> arr(n);
    for (string &a : arr)
        cin >> a;
    TreeNode *root = buildBST(arr);
    cin >> k;
    cout << findMaxFork(root, k) << endl;
    cout << "-----------------" << endl;

    cin >> k;
    cout << findCeil(root, k) << endl;
    cout << "-----------------" << endl;

    cin >> k;
    inorderTraversal(root);
    cout << endl;
    root = insertIntoBST(root, k);
    inorderTraversal(root);
    cout << endl;
    cout << "-----------------" << endl;

    cin >> k;
    inorderTraversal(root);
    cout << endl;
    root = deleteNode(root, k);
    inorderTraversal(root);
    cout << endl;
    cout << "-----------------" << endl;

    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = buildBST(arr);
    cin >> k;
    cout << kthSmallest(root, k) << endl;
    cout << "-----------------" << endl;

    cout << isValidBST(root) << endl;
    cout << "-----------------" << endl;

    cout << lowestCommonAncestor(root, root->left, root->right)->val << endl;
    cout << "-----------------" << endl;

    cin >> n;
    vector<int> arr2(n);
    for (int &a : arr2)
        cin >> a;
    root = bstFromPreorder(arr2);
    inorderTraversal(root);
    cout << endl;
    cout << "-----------------" << endl;
    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = buildBST(arr);
    cin >> k;
    cout << inOrderSuccessor(root, k) << endl;
    cout << "-----------------" << endl;
    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = buildBST(arr);
    cin >> k;
    cout << findTarget(root, k) << endl;
    cout << "-----------------" << endl;
    cin >> n;
    arr.resize(n);
    for (string &a : arr)
        cin >> a;
    root = buildBST(arr);
    recoverTree(root);
    inorderTraversal(root);
    cout << endl;
    cout << "-----------------" << endl;

    return 0;
}